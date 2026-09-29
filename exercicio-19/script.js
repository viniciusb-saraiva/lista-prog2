const formulario = document.getElementById("cep-form");
const resultado = document.getElementById("resultado");

formulario.addEventListener("submit", async (event) => {
  event.preventDefault();

  const cep = document.getElementById("cep").value.replace(/\D/g, "");

  if (cep.length !== 8) {
    resultado.innerHTML = "<p>Digite um CEP válido.</p>";
    return;
  }

  resultado.innerHTML = "<p>Consultando...</p>";

  try {
    const resposta = await fetch(`https://brasilapi.com.br/api/cep/v2/${cep}`);

    if (!resposta.ok) {
      throw new Error(`Erro HTTP: ${resposta.status}`);
    }

    const dados = await resposta.json();

    resultado.innerHTML = `
          <h2>Resultado</h2>
          <p><strong>CEP:</strong> ${dados.cep}</p>
          <p><strong>Estado:</strong> ${dados.state}</p>
          <p><strong>Cidade:</strong> ${dados.city}</p>
          <p><strong>Bairro:</strong> ${dados.neighborhood}</p>
          <p><strong>Rua:</strong> ${dados.street}</p>
        `;
  } catch (erro) {
    resultado.innerHTML = `
          <p class="erro">
            Não foi possível realizar a consulta.
          </p>
        `;

    console.error(erro);
  }
});
