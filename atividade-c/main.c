#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUTOS_POR_CAIXA 10

typedef struct {
    int id;
    char nome[50];
} Produto;

typedef struct NoCaixa {
    int caixaId; // Representa a faixa (ex: 10 para IDs 100-109)
    Produto produtos[MAX_PRODUTOS_POR_CAIXA];
    int quantidade;
    struct NoCaixa *esquerda, *direita;
} NoCaixa;

// Função para criar um novo nó de caixa
NoCaixa* criarCaixa(int idBase) {
    NoCaixa* nova = (NoCaixa*)calloc(1, sizeof(NoCaixa)); // calloc limpa a memória (zera tudo)
    if (nova == NULL) {
        fprintf(stderr, "Erro de memoria: Falha ao alocar nova caixa.\n");
        exit(1);
    }
    nova->caixaId = idBase;
    nova->quantidade = 0;
    nova->esquerda = nova->direita = NULL;
    return nova;
}

// Insere o produto de forma ordenada dentro do array da caixa
void inserirNaCaixa(NoCaixa* caixa, int id, char* nome) {
    // Verificar se já existe
    for (int i = 0; i < caixa->quantidade; i++) {
        if (caixa->produtos[i].id == id) {
            printf("Erro: Produto com ID %d ja cadastrado.\n", id);
            return;
        }
    }

    if (caixa->quantidade >= MAX_PRODUTOS_POR_CAIXA) {
        printf("Erro: Caixa %d (IDs %d-%d) cheia! Limite de %d produtos atingido.\n", 
                caixa->caixaId, caixa->caixaId * 10, (caixa->caixaId * 10) + 9, MAX_PRODUTOS_POR_CAIXA);
        return;
    }

    // Inserção mantendo a ordem crescente (Insertion Sort logic)
    int i = caixa->quantidade - 1;
    while (i >= 0 && caixa->produtos[i].id > id) {
        caixa->produtos[i + 1] = caixa->produtos[i];
        i--;
    }
    
    caixa->produtos[i + 1].id = id;
    strncpy(caixa->produtos[i + 1].nome, nome, sizeof(caixa->produtos[i + 1].nome) - 1);
    caixa->produtos[i + 1].nome[sizeof(caixa->produtos[i + 1].nome) - 1] = '\0'; // Garante o terminador nulo
    caixa->quantidade++;
    printf("Produto '%s' (ID %d) guardado na Caixa %d.\n", nome, id, caixa->caixaId);
}

// Insere na Árvore Binária de Busca
NoCaixa* inserir(NoCaixa* raiz, int id, char* nome) {
    int idBase = id / 10; // Define a qual caixa o ID pertence

    if (raiz == NULL) {
        NoCaixa* nova = criarCaixa(idBase);
        inserirNaCaixa(nova, id, nome);
        return nova;
    }

    if (idBase < raiz->caixaId) {
        raiz->esquerda = inserir(raiz->esquerda, id, nome);
    } else if (idBase > raiz->caixaId) {
        raiz->direita = inserir(raiz->direita, id, nome);
    } else {
        // Encontrou a caixa correta
        inserirNaCaixa(raiz, id, nome);
    }

    return raiz;
}

// Busca eficiente: primeiro localiza a caixa, depois o produto
void buscar(NoCaixa* raiz, int id) {
    if (raiz == NULL) {
        printf("Produto com ID %d nao encontrado (Caixa inexistente).\n", id);
        return;
    }

    int idBase = id / 10;

    if (idBase < raiz->caixaId) {
        buscar(raiz->esquerda, id);
    } else if (idBase > raiz->caixaId) {
        buscar(raiz->direita, id);
    } else {
        // Estamos na caixa correta, agora busca linear no array (max 10 itens)
        for (int i = 0; i < raiz->quantidade; i++) {
            if (raiz->produtos[i].id == id) {
                printf("Produto encontrado: ID %d - Nome: %s (Na Caixa %d)\n", 
                        raiz->produtos[i].id, raiz->produtos[i].nome, raiz->caixaId);
                return;
            }
        }
        printf("Produto com ID %d nao encontrado na Caixa %d.\n", id, raiz->caixaId);
    }
}

// Listagem em ordem (In-order traversal)
void listar(NoCaixa* raiz) {
    if (raiz != NULL) {
        listar(raiz->esquerda);
        for (int i = 0; i < raiz->quantidade; i++) {
            printf("%d - %s\n", raiz->produtos[i].id, raiz->produtos[i].nome);
        }
        listar(raiz->direita);
    }
}

void liberarMemoria(NoCaixa* raiz) {
    if (raiz != NULL) {
        liberarMemoria(raiz->esquerda);
        liberarMemoria(raiz->direita);
        free(raiz);
    }
}

int main() {
    NoCaixa* estoque = NULL;
    int opcao, id;
    char nome[50];

    printf("=== Sistema de Controle de Estoque (Loja de Eletronicos) ===\n");

    do {
        printf("\n1. Cadastrar Produto\n2. Listar Produtos\n3. Buscar por Codigo\n4. Sair\nEscolha: ");
        if (scanf("%d", &opcao) != 1) { // Verifica se a entrada é um número
            printf("Entrada invalida. Digite um numero.\n");
            while (getchar() != '\n'); // Limpa o buffer
            continue;
        }

        switch (opcao) {
            case 1:
                printf("ID do produto: ");
                if (scanf("%d", &id) != 1) {
                    printf("Erro: ID invalido. Digite um numero inteiro.\n");
                    while (getchar() != '\n'); // Limpa o buffer
                    break;
                }
                while (getchar() != '\n'); // Limpa o buffer apos ler o ID

                if (id <= 0) {
                    printf("Erro: O ID do produto deve ser um numero inteiro positivo.\n");
                    break;
                }

                printf("Nome do produto (max 49 caracteres): ");
                // Usando fgets para leitura mais segura do nome
                if (fgets(nome, sizeof(nome), stdin) == NULL) {
                    printf("Erro: Falha ao ler o nome do produto.\n");
                    break;
                }
                nome[strcspn(nome, "\n")] = '\0'; // Remove o '\n' lido por fgets
                if (strlen(nome) == 0) {
                    printf("Erro: O nome do produto nao pode ser vazio.\n");
                    break;
                }
                estoque = inserir(estoque, id, nome);
                break;
            case 2:
                printf("\n--- Relatorio de Estoque ---\n");
                if (estoque == NULL) printf("Estoque vazio.\n");
                else listar(estoque);
                break;
            case 3:
                printf("Digite o ID para busca: ");
                if (scanf("%d", &id) != 1) {
                    printf("Erro: ID invalido para busca. Digite um numero inteiro.\n");
                    while (getchar() != '\n'); // Limpa o buffer
                    break;
                }
                while (getchar() != '\n'); // Limpa o buffer apos ler o ID
                buscar(estoque, id);
                break;
            case 4:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 4);

    liberarMemoria(estoque);
    return 0;
}