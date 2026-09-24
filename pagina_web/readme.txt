Documento Explicativo: Conceitos Utilizados No Projeto "RAIZ PAISAGISMO"

1. Introdução e escopo do projeto

O projeto **Raiz Paisagismo** é um site institucional criado para uma empresa fictícia de paisagismo e jardinagem ecológica, com foco no uso de espécies nativas.

O site foi desenvolvido com HTML, CSS, front-end.
Acessibilidade, responsividade e organização das informações.

Neste documento, serão apresentados os principais conceitos técnicos, de design e de estrutura usados na criação das páginas index.html, sobre.html, servicos.html e contato.html, além do arquivo de estilos styles.css.

---

2. Conceitos de arquitetura e estruturação em HTML

O projeto segue uma abordagem semântica e modular para organizar o conteúdo em HTML.

HTML semântico
Foram usadas tags que dão significado ao conteúdo, melhorando a experiência em navegadores, leitores de tela e mecanismos de busca (SEO):

- <header> e <nav>: organizam o cabeçalho fixo e o menu principal de navegação.  
- <main>: delimita o conteúdo principal de cada página e está ligado a um “skip-link” para acessibilidade.  
- <section>: divide o conteúdo em blocos temáticos, como hero, diferenciais, estatísticas, etapas e equipe.  
- <footer>: padroniza o rodapé com links rápidos, informações de contato e avisos legais.

Formulários acessíveis
Na página de contato, os campos de formulário usam atributos adequados, como `type="email"`, `type="tel"` e `autocomplete="name"`. Além disso, cada `<label>` está corretamente associado ao seu campo por meio do atributo `for`, o que torna o preenchimento mais intuitivo e acessível.

---

3. Conceitos de estilização e Design System (CSS)

A identidade visual e a apresentação foram criadas do zero em uma folha de estilos própria, aplicando conceitos avançados de CSS.

Variáveis CSS
O arquivo styles.css usa bastante variáveis no seletor :root (--bg, --paper, --ink, --forest, --moss, --ochre, --line, etc.). Isso garante:
- consistência de cores em todo o site  
- facilidade para fazer ajustes e manutenções  
- um design system mais coeso e organizado

Paleta de cores
Foram escolhidos tons terrosos, verdes musgo, verde-mata profundo e um fundo em tom de papel quente (#f4f2e8). Essa paleta reforça o posicionamento ecológico e autoral da marca.

Tipografia responsiva e híbrida
- Duas famílias do Google Fonts: Fraunces (serifada, elegante e expressiva para títulos) e Work Sans (sans-serif, geométrica e limpa para o corpo de texto).  
- Uso da função clamp() para tamanhos de fonte fluidos em h1 e h2, garantindo que os títulos se adaptem de forma suave entre diferentes tamanhos de tela, sem “pulos” no layout.

Layouts modernos com Grid e Flexbox
- CSS Grid: usado de forma estrutural para grids de cartões assimétricos, listagens de serviços, blocos de equipe e rodapés, com controle preciso de linhas e colunas.
- Flexbox: aplicado para alinhar itens de navegação, botões e organizar espaçamentos internos dos componentes.

---

4. Acessibilidade e experiência do usuário

O projeto coloca a inclusão digital e a facilidade de navegação no centro das decisões:

- Skip Link (link de pular para o conteúdo): um link no topo do código que fica escondido visualmente até receber foco pelo teclado. Ele permite que quem usa leitores de tela ou navega só pelo teclado pule o menu repetitivo e vá direto ao conteúdo principal.  
- Indicadores de foco visíveis: estilização customizada de :focus-visible com bordas em cor de alto contraste (--ochre), facilitando a navegação sem mouse.  
- Atributos ARIA: uso de aria-label em navegações e formulários, além de aria-current="page para deixar bem claro qual página está ativa no menu principal.  
- Redução de movimento: respeito à preferência do usuário por meio da media query prefers-reduced-motion, que desativa animações e rolagem suave quando o sistema operacional do usuário pede menos movimento.

---

5. Responsividade e adaptabilidade

O layout foi pensado para funcionar bem em qualquer dispositivo:

- Abordagem adaptativa com breakpoints:  
  - Em telas abaixo de 860px e 560px, os grids de múltiplas colunas (como hero, lista de recursos, etapas, estatísticas e equipe) se reorganizam automaticamente para uma ou duas colunas, melhorando a leitura em tablets e smartphones.  
- Imagens e elementos flexíveis:  
  - Regras globais, como max-width: 100% aplicadas, garantem que nenhum elemento “vaze” horizontalmente na tela.

---

6. Conclusão

O projeto Raiz Paisagismo mostra na prática como fazer front-end limpo e eficiente, sem depender de frameworks pesados. O foco foi performance, acessibilidade nativa, semântica bem feita e um visual sofisticado que combina com os valores da marca.