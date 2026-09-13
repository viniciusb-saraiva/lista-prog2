/*

16. Consultas relacionando tabelas
Utilizando o banco da biblioteca, crie consultas SQL que apresentem:

nome do usuário e título do livro emprestado;
todos os empréstimos realizados;
empréstimos ainda não devolvidos;
quantidade de empréstimos realizada por usuário;
livros que nunca foram emprestados.
Utilize JOIN sempre que necessário.

*/

-- A) Nome do usuário e título do livro emprestado(Cruza as tabelas de empréstimos, usuários e livros para exibir os nomes em vez de IDs)

SELECT usuarios.nome AS nome_usuario, livros.titulo AS titulo_livro
FROM emprestimos
JOIN usuarios ON emprestimos.id_usuario = usuarios.id_usuario
JOIN livros ON emprestimos.id_livro = livros.id_livro;

-- B) Todos os empréstimos realizados(Mostra o relatório completo de histórico da biblioteca, incluindo datas)

SELECT 
    emprestimos.id_emprestimo,
    usuarios.nome AS usuario,
    livros.titulo AS livro,
    emprestimos.data_emprestimo,
    emprestimos.data_devolucao_real
FROM emprestimos
JOIN usuarios ON emprestimos.id_usuario = usuarios.id_usuario
JOIN livros ON emprestimos.id_livro = livros.id_livro;

-- C) Empréstimos ainda não devolvidos(Filtra os registros onde a data de devolução real está em branco/nula)

SELECT 
    usuarios.nome AS usuario,
    livros.titulo AS livro,
    emprestimos.data_emprestimo,
    emprestimos.data_devolucao_prevista
FROM emprestimos
JOIN usuarios ON emprestimos.id_usuario = usuarios.id_usuario
JOIN livros ON emprestimos.id_livro = livros.id_livro
WHERE emprestimos.data_devolucao_real IS NULL;

-- D) Quantidade de empréstimos realizada por usuário(Utiliza a função de agregação COUNT e agrupa os resultados pelo nome do usuário)

SELECT usuarios.nome AS usuario, COUNT(emprestimos.id_emprestimo) AS total_emprestimos
FROM usuarios
LEFT JOIN emprestimos ON usuarios.id_usuario = emprestimos.id_usuario
GROUP BY usuarios.id_usuario, usuarios.nome;

-- E) Livros que nunca foram emprestados(Utiliza LEFT JOIN para encontrar livros que não possuem correspondência na tabela de empréstimos)

SELECT livros.id_livro, livros.titulo
FROM livros
LEFT JOIN emprestimos ON livros.id_livro = emprestimos.id_livro
WHERE emprestimos.id_livro IS NULL;