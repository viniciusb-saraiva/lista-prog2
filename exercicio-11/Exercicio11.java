import java.util.Scanner;

public class Exercicio11 {

  // A classe foi declarada como "static" pois ela está dentro de outra classe (Exercicio11), que é a classe utilizada para rodar o programa (e para padronizar os arquivos e pastas da atividade)
  public static class Produto {
    private int codigo;
    private String nome;
    private double preco;
    private int quantidadeEstoque;

    public Produto(int codigo, String nome, double preco, int quantidadeEstoque) {
      this.codigo = codigo;
      this.nome = nome;
      this.preco = preco;
      this.quantidadeEstoque = quantidadeEstoque;
    }

    public int getCodigo() { return codigo; }
    public String getNome() { return nome; }
    public double getPreco() { return preco; }
    public int getQuantidadeEstoque() { return quantidadeEstoque; }
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    scanner.useLocale(java.util.Locale.US); // Faz o input decimal do usuário funcionar com '.' (ponto), e não com ',' (vírgula)

    System.out.print("Quantos produtos deseja cadastrar? ");
    int quantidadeProdutos = scanner.nextInt();
    
    Produto[] listaProdutos = new Produto[quantidadeProdutos];

    for (int i = 0; i < quantidadeProdutos; i++) {
      System.out.println("\n--- Cadastrando o Produto " + (i + 1) + " ---");
      
      System.out.print("Código: ");
      int codigo = scanner.nextInt();
      scanner.nextLine(); 

      System.out.print("Nome: ");
      String nome = scanner.nextLine();

      System.out.print("Preço: ");
      double preco = scanner.nextDouble();

      System.out.print("Quantidade em Estoque: ");
      int qtdEstoque = scanner.nextInt();

      listaProdutos[i] = new Produto(codigo, nome, preco, qtdEstoque);
    }

    System.out.println("\nPRODUTOS DA LOJA");
    for (Produto produto : listaProdutos) {
      System.out.println("\n--Produto--");
      System.out.printf("Código: %d\nNome: %s\nPreço: %.2f\nQuantidade em Estoque: %d\n", 
          produto.getCodigo(), produto.getNome(), produto.getPreco(), produto.getQuantidadeEstoque());
    }

    scanner.close();
  }
}
