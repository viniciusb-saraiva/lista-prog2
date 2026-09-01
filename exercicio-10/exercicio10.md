# Questões do Exercício 10 e suas respostas

# 10. Comparando lista, pilha e fila

Considere os seguintes problemas:

## A. Histórico do navegador.

### Resposta

- Pilha. Pois, para seguirmos a lógica de que o último link a ser visitado deve ser o primeiro a aparecer no histório (o mais recente), precisamos seguir o princípio LIFO (Last-in, First-out). Que é exatamente o que a pilha oferece.

## B. Pessoas aguardando atendimento.

### Resposta

- Fila. Pois, para seguirmos a lógica de que a primeira pessoa a entrar na fila de atendimento deve ser a primeira atendida, devemos seguir o princípip FIFO (First-in, First-out). Que é exatamente o que a filas oferece.

## C. Catálogo de produtos.

- Lista (dinâmica). Pois será necessário uma estrutura de dados que não possui tamanho fixo (como uma Array/Vetor), é de fácil modificação na ordem dos produtos, e de fácil inserção de produtos no início, meio e fim.

## D. Função “desfazer” de um editor de texto.

- Pilha. Pois, para seguirmos a lógica de que a última modificação realizada a ser feita deve ser a primeira a ser desfeita, precisamos seguir o princípio LIFO (Last-in, First-out). Que é exatamente o que a pilha oferece.

## E. Playlist de músicas que pode ser acessada por posição.

- Lista (sequencial) [Vetor/Array em C]. Pois, quando a prioridade é acesso à músicas de determinados índices, a melhor opção é uma lista sequencial (que guarda os elementos em espaços de memória sequencias), onde a complexidade de busca é O(1) (constante).

Para cada situação, indique qual estrutura seria mais adequada entre:

lista;

pilha;

fila.

Justifique cada resposta.
