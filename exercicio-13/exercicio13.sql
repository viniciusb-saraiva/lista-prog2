/*
13. Modelagem de banco de dados
Projete um banco de dados para uma biblioteca.

O sistema deverá armazenar informações sobre:

a) livros;

b) autores;

c) usuários;

d) empréstimos.

Defina:

tabelas;

campos;

tipos de dados;

chaves primárias;

chaves estrangeiras;

relacionamentos.

Em seguida, escreva os comandos SQL necessários para criar as tabelas

utilizando CREATE TABLE.

OBS: sql nesse arquivo, modelagem em si no arquivo 'modelagem.md'
*/

CREATE TABLE autores (
  id_autor INTEGER PRIMARY KEY AUTOINCREMENT,
  nome TEXT NOT NULL,
  nacionalidade TEXT
);

CREATE TABLE livros (
  id_livro INTEGER PRIMARY KEY AUTOINCREMENT,
  titulo TEXT NOT NULL,
  ano_publicacao INTEGER,
  id_autor INTEGER,
  FOREIGN KEY (id_autor) REFERENCES autores (id_autor) 
    ON DELETE SET NULL 
    ON UPDATE CASCADE
);

CREATE TABLE usuarios (
  id_usuario INTEGER PRIMARY KEY AUTOINCREMENT,
  nome TEXT NOT NULL,
  email TEXT NOT NULL UNIQUE,
  telefone TEXT,
  data_cadastro TEXT NOT NULL DEFAULT (DATE('now'))
);

CREATE TABLE emprestimos (
  id_emprestimo INTEGER PRIMARY KEY AUTOINCREMENT,
  id_usuario INTEGER NOT NULL,
  id_livro INTEGER NOT NULL,
  data_emprestimo TEXT NOT NULL DEFAULT (DATE('now')),
  data_devolucao_prevista TEXT NOT NULL,
  data_devolucao_real TEXT,
  FOREIGN KEY (id_usuario) REFERENCES usuarios (id_usuario) 
    ON DELETE CASCADE 
    ON UPDATE CASCADE,
  FOREIGN KEY (id_livro) REFERENCES livros (id_livro) 
    ON DELETE CASCADE 
    ON UPDATE CASCADE
);