/*
14. INSERT e SELECT
Utilizando o banco de dados da biblioteca do exercício anterior:

Cadastre pelo menos 5 livros.
Cadastre pelo menos 3 usuários.
Cadastre pelo menos 3 empréstimos.
Utilize comandos INSERT.

Depois escreva consultas SELECT para:

listar todos os livros;

mostrar somente título e autor;

buscar livros de determinado autor;

mostrar os livros ordenados alfabeticamente;

mostrar apenas livros disponíveis.
*/

/* INSERTs */

-- Cadastrar Autores (necessário para os livros)
INSERT INTO autores (nome, nacionalidade) VALUES 
('J.R.R. Tolkien', 'Inglaterra'),
('George Orwell', 'Inglaterra'),
('Machado de Assis', 'Brasil');

-- Cadastrar 5 Livros (usando os IDs dos autores acima)
INSERT INTO livros (titulo, ano_publicacao, id_autor) VALUES 
('O Hobbit', 1937, 1),
('A Sociedade do Anel', 1954, 1),
('1984', 1949, 2),
('A Revolução dos Bichos', 1945, 2),
('Dom Casmurro', 1899, 3);

-- Cadastrar 3 Usuários
INSERT INTO usuarios (nome, email, telefone) VALUES 
('Carlos Silva', 'carlos@email.com', '11999999999'),
('Ana Souza', 'ana.souza@email.com', '11888888888'),
('Mariana Lima', 'mariana@email.com', '11777777777');

-- Cadastrar 3 Empréstimos
INSERT INTO emprestimos (id_usuario, id_livro, data_emprestimo, data_devolucao_prevista, data_devolucao_real) VALUES 
(1, 1, '2026-09-01', '2026-09-08', '2026-09-07'), -- Devolvido
(2, 2, '2026-09-10', '2026-09-17', NULL),          -- Pendente
(3, 3, '2026-09-12', '2026-09-19', NULL);          -- Pendente

/* SELECTs */

-- A) Listar todos os livros

SELECT * FROM livros;

-- B) Mostrar somente título e autor(Utiliza JOIN para buscar o nome do autor na tabela correspondente)

SELECT livros.titulo, autores.nome AS autor
FROM livros
JOIN autores ON livros.id_autor = autores.id_autor;

-- C) Buscar livros de determinado autor(Exemplo buscando livros do autor 'George Orwell')

SELECT livros.titulo, livros.ano_publicacao
FROM livros
JOIN autores ON livros.id_autor = autores.id_autor
WHERE autores.nome = 'George Orwell';

-- D) Mostrar os livros ordenados alfabeticamente

SELECT titulo, ano_publicacao 
FROM livros
ORDER BY titulo ASC;

-- E) Mostrar apenas livros disponíveis(Um livro está disponível se ele nunca foi emprestado OU se o seu último empréstimo já possui uma data de devolução real)

SELECT id_livro, titulo 
FROM livros 
WHERE id_livro NOT IN (
    SELECT id_livro 
    FROM emprestimos 
    WHERE data_devolucao_real IS NULL
);
