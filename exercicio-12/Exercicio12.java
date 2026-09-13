import java.util.Arrays;
import java.util.Scanner;

public class Exercicio12 {
  
  // A classe foi declarada como "static" pois ela está dentro de outra classe (Exercicio12), que é a classe utilizada para rodar o programa (e para padronizar os arquivos e pastas da atividade)
  public static class Pessoa {
    private String nome;
    private String dataNascimento;

    public Pessoa(String nome, String dataNascimento) {
      this.nome = nome;
      this.dataNascimento = dataNascimento;
    }

    public String getNome() { return nome; }
    public String getDataNascimento() { return dataNascimento; }
    
    public void exibirDados() {
      System.out.println("Nome: " + nome);
      System.out.println("Data de Nascimento: " + dataNascimento);
    }
  }

  // A classe foi declarada como "static" pois ela está dentro de outra classe (Exercicio12), que é a classe utilizada para rodar o programa (e para padronizar os arquivos e pastas da atividade)
  public static class Aluno extends Pessoa {
    private int matricula;
    private String curso;
    private double[] notas;

    public Aluno(String nome, String dataNascimento, int matricula, String curso, double[] notas) {
      super(nome, dataNascimento);
      this.matricula = matricula;
      this.curso = curso;
      this.notas = notas;
    }

    public int getMatricula() { return matricula; }
    public String getCurso() { return curso; }
    public double[] getNotas() { return notas; }
    
    public double calcularMedia() {
      double soma = 0;
      for (double nota : notas) {
        soma += nota;
      }
      return notas.length > 0 ? soma / notas.length : 0;
    }
    
    @Override
    public void exibirDados() {
      System.out.println("\n--- DADOS DO ALUNO ---");
      super.exibirDados();
      System.out.println("Matrícula: " + matricula);
      System.out.println("Curso: " + curso);
      System.out.println("Notas: " + Arrays.toString(notas));
      System.out.printf("Média Final: %.2f\n", calcularMedia());
    }
  }

  // A classe foi declarada como "static" pois ela está dentro de outra classe (Exercicio12), que é a classe utilizada para rodar o programa (e para padronizar os arquivos e pastas da atividade)
  public static class Professor extends Pessoa {
    private int matricula;
    private String disciplina; 

    public Professor(String nome, String dataNascimento, int matricula, String disciplina) {
      super(nome, dataNascimento);
      this.matricula = matricula;
      this.disciplina = disciplina;
    }

    public int getMatricula() { return matricula; }
    public String getDisciplina() { return disciplina; }
    
    @Override
    public void exibirDados() {
      System.out.println("\n--- DADOS DO PROFESSOR ---");
      super.exibirDados();
      System.out.println("Matrícula: " + matricula);
      System.out.println("Disciplina: " + disciplina);
    }
  }
  
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    System.out.println("===== CADASTRO DO SISTEMA ESCOLAR =====");

    System.out.println("\n[1] Cadastrando uma Pessoa Comum");
    System.out.print("Nome: ");
    String nomeP = scanner.nextLine();
    System.out.print("Data de Nascimento: ");
    String dataP = scanner.nextLine();
    Pessoa pessoa = new Pessoa(nomeP, dataP);

    System.out.println("\n[2] Cadastrando um Professor");
    System.out.print("Nome: ");
    String nomeProf = scanner.nextLine();
    System.out.print("Data de Nascimento: ");
    String dataProf = scanner.nextLine();
    System.out.print("Matrícula: ");
    int matProf = scanner.nextInt();
    scanner.nextLine(); 
    System.out.print("Disciplina: ");
    String disciplina = scanner.nextLine();
    Professor professor = new Professor(nomeProf, dataProf, matProf, disciplina);

    System.out.println("\n[3] Cadastrando um Aluno");
    System.out.print("Nome: ");
    String nomeAlu = scanner.nextLine();
    System.out.print("Data de Nascimento: ");
    String dataAlu = scanner.nextLine();
    System.out.print("Matrícula: ");
    int matAlu = scanner.nextInt();
    scanner.nextLine(); 
    System.out.print("Curso: ");
    String curso = scanner.nextLine();
    
    System.out.print("Quantas notas deseja registrar para o aluno? ");
    int qtdNotas = scanner.nextInt();
    double[] notasAluno = new double[qtdNotas];
    for (int i = 0; i < qtdNotas; i++) {
      System.out.print("Nota " + (i + 1) + ": ");
      notasAluno[i] = scanner.nextDouble();
    }
    Aluno aluno = new Aluno(nomeAlu, dataAlu, matAlu, curso, notasAluno);

    System.out.println("\n===== EXIBIÇÃO DOS DADOS CADASTRADOS =====");
    System.out.println("\n--- DADOS DA PESSOA ---");
    pessoa.exibirDados();
    professor.exibirDados();
    aluno.exibirDados();

    scanner.close();
  }
}
