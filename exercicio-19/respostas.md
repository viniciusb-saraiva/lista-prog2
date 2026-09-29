# Exercício 19 — Requisição HTTP e API

## 1. Qual URL foi utilizada?

Foi utilizada a seguinte URL da BrasilAPI:

```text
https://brasilapi.com.br/api/cep/v2/{CEP}
```

Por exemplo, para consultar o CEP `88301-000`:

```text
https://brasilapi.com.br/api/cep/v2/88301000
```

## 2. Qual método HTTP foi utilizado?

Foi utilizado o método **GET**, pois o programa realiza uma consulta e recebe informações da API.

```javascript
const resposta = await fetch(`https://brasilapi.com.br/api/cep/v2/${cep}`);
```

## 3. Qual código HTTP representa uma requisição bem-sucedida?

O código **200 (OK)** representa uma requisição bem-sucedida.

No programa, a resposta é verificada através da propriedade `ok`:

```javascript
if (!resposta.ok) {
  throw new Error(`Erro HTTP: ${resposta.status}`);
}
```

## 4. Em qual formato os dados foram recebidos?

Os dados foram recebidos no formato **JSON (JavaScript Object Notation)**.

O método `json()` é utilizado para interpretar os dados recebidos:

```javascript
const dados = await resposta.json();
```

Depois disso, é possível acessar as informações retornadas pela API, como:

```javascript
dados.cep;
dados.state;
dados.city;
dados.neighborhood;
dados.street;
```

## 5. Qual é a diferença entre uma requisição e uma resposta HTTP?

A **requisição HTTP** é enviada pelo cliente, neste caso o navegador, para um servidor. Ela informa o que o cliente deseja obter ou realizar.

Neste exercício, o navegador envia uma requisição `GET` para a BrasilAPI solicitando informações sobre um determinado CEP.

A **resposta HTTP** é enviada pelo servidor de volta ao cliente. Ela contém um código de status que indica o resultado da requisição e pode conter os dados solicitados.
