# Modelagem Lógica do Banco de Dados - Biblioteca

Este documento apresenta a estrutura de tabelas, campos, chaves e relacionamentos para o sistema de gerenciamento da biblioteca utilizando **SQLite**.

---

## Relacionamentos (Cardinalidade)

- **Autores** `(1) --------- (N)` **Livros**: Um autor pode escrever vários livros.
- **Usuários** `(1) --------- (N)` **Empréstimos**: Um usuário pode realizar múltiplos empréstimos ao longo do tempo.
- **Livros** `(1) --------- (N)` **Empréstimos**: Um livro pode ser emprestado várias vezes.

---

## Estrutura das Tabelas

### 1. Tabela: `autores`

| Campo           | Tipo de Dado | Restrições               | Descrição                     |
| :-------------- | :----------- | :----------------------- | :---------------------------- |
| `id_autor`      | `INTEGER`    | **PK**, Auto-incremental | Identificador único do autor. |
| `nome`          | `TEXT`       | `NOT NULL`               | Nome completo do autor.       |
| `nacionalidade` | `TEXT`       | Opcional                 | País de origem do autor.      |

### 2. Tabela: `livros`

| Campo            | Tipo de Dado | Restrições                  | Descrição                       |
| :--------------- | :----------- | :-------------------------- | :------------------------------ |
| `id_livro`       | `INTEGER`    | **PK**, Auto-incremental    | Identificador único do livro.   |
| `titulo`         | `TEXT`       | `NOT NULL`                  | Título da obra.                 |
| `ano_publicacao` | `INTEGER`    | Opcional                    | Ano em que o livro foi lançado. |
| `id_autor`       | `INTEGER`    | **FK** (`autores.id_autor`) | Identifica o autor do livro.    |

### 3. Tabela: `usuarios`

| Campo           | Tipo de Dado | Restrições               | Descrição                                      |
| :-------------- | :----------- | :----------------------- | :--------------------------------------------- |
| `id_usuario`    | `INTEGER`    | **PK**, Auto-incremental | Identificador único do usuário.                |
| `nome`          | `TEXT`       | `NOT NULL`               | Nome completo do usuário.                      |
| `email`         | `TEXT`       | `NOT NULL`, `UNIQUE`     | Endereço de e-mail (usado para login/contato). |
| `telefone`      | `TEXT`       | Opcional                 | Telefone de contato.                           |
| `data_cadastro` | `TEXT`       | `NOT NULL` (Formato ISO) | Data de registro no sistema (`YYYY-MM-DD`).    |

### 4. Tabela: `emprestimos`

| Campo                     | Tipo de Dado | Restrições                     | Descrição                                        |
| :------------------------ | :----------- | :----------------------------- | :----------------------------------------------- |
| `id_emprestimo`           | `INTEGER`    | **PK**, Auto-incremental       | Identificador único da transação.                |
| `id_usuario`              | `INTEGER`    | **FK** (`usuarios.id_usuario`) | Identifica quem pegou o livro.                   |
| `id_livro`                | `INTEGER`    | **FK** (`livros.id_livro`)     | Identifica o livro emprestado.                   |
| `data_emprestimo`         | `TEXT`       | `NOT NULL` (Formato ISO)       | Data em que o livro foi retirado (`YYYY-MM-DD`). |
| `data_devolucao_prevista` | `TEXT`       | `NOT NULL` (Formato ISO)       | Prazo limite para a devolução.                   |
| `data_devolucao_real`     | `TEXT`       | Opcional                       | Data em que o livro foi devolvido de fato.       |

---

💡 _Nota sobre os tipos de dados:_ Como o SQLite não possui um tipo específico para `DATE`, foi utilizado o tipo `TEXT` no padrão ISO8601 (`YYYY-MM-DD`), que permite ordenação e o uso de funções nativas de dados.
