# Estrutura do Modelo de Dados Bancário

## Hierarquia de Cliente

```
Cliente
├── Pessoa Física
│   ├── Dados Cadastrais
│   ├── Dados Financeiros
│   └── Dados de Crédito
│
└── Pessoa Jurídica
    ├── Dados da Empresa
    ├── Dados Societários
    ├── Dados Financeiros
    └── Dados Fiscais
```

## Comparativo Geral

| Categoria         | Pessoa Física | Pessoa Jurídica          |
|-------------------|---------------|--------------------------|
| Identificação     | CPF           | CNPJ                     |
| Nome              | Nome Completo | Razão Social             |
| Endereço          | Residencial   | Comercial                |
| Renda/Faturamento | Renda Mensal  | Faturamento              |
| Crédito           | Score PF      | Rating Empresarial       |
| Documentos        | RG, CNH       | Contrato Social          |
| Compliance        | KYC           | KYB                      |
| Relacionamentos   | Titular       | Sócios e Administradores |
