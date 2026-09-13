/*
15. UPDATE e DELETE
Utilizando o mesmo banco de dados:

Crie comandos SQL para:

alterar o nome de um usuário;

alterar a disponibilidade de um livro;

atualizar a data de devolução de um empréstimo;

excluir um usuário;

excluir um livro.

Antes de executar os comandos DELETE, analise possíveis problemas relacionados às chaves estrangeiras.

Explique o que pode acontecer ao tentar excluir um registro relacionado a outros registros.

*/

-- 1. Alterar o nome de um usuário (Filtrando pelo ID)

UPDATE usuarios 
SET nome = 'Carlos Silva Sauro' 
WHERE id_usuario = 1;

-- 2. Alterar a disponibilidade de um livro
-- Como criamos uma query dinâmica baseada na tabela de empréstimos, 
-- para "alterar a disponibilidade" na prática, nós inserimos ou finalizamos um empréstimo.
-- Exemplo: Simulando a devolução do livro '1984' (id_livro = 3) do usuário 3 para torná-lo disponível.

UPDATE emprestimos 
SET data_devolucao_real = '2026-09-14' 
WHERE id_usuario = 3 AND id_livro = 3 AND data_devolucao_real IS NULL;

-- 3. Atualizar a data de devolução prevista de um empréstimo (Renovação)

UPDATE emprestimos 
SET data_devolucao_prevista = '2026-09-25' 
WHERE id_emprestimo = 2;

-- 4. Excluir um usuário

DELETE FROM usuarios 
WHERE id_usuario = 1;

-- 5. Excluir um livro

DELETE FROM livros 
WHERE id_livro = 5;

/*

PERGUNTAS:

Antes de executar os comandos DELETE, analise possíveis problemas relacionados às chaves estrangeiras.

Explique o que pode acontecer ao tentar excluir um registro relacionado a outros registros.

RESPOSTAS:

Possibilidades:
- Apagar em efeito cascata (CASCADE): É o que está configurado nesse banco. Se você apagar o Usuário 1, o sistema deleta automaticamente todos os empréstimos dele. O perigo é sumir com o histórico da biblioteca sem querer.
- Ficar como "Desconhecido" (SET NULL): O livro ou empréstimo continua existindo, mas o campo do dono fica vazio (NULL). Foi o que foi feito na tabela 'autores'.
- Bloquear a exclusão (RESTRICT): O banco de dados dá um erro e impede a exclusão. Ele obriga a apagar os empréstimos antes, protegendo os dados contra acidentes.

*/