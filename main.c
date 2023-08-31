#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ALUNOS 50

typedef struct {
  char nome[50];
  float notas[4];
  int ativo;
} Aluno;

Aluno alunos[MAX_ALUNOS];

void menu();
void cadastrar();
void remover();
void reprovados();
void pesquisar();
void listar();

int main(int argc, char const *argv[]) {
  menu();
  return 0;
}

void menu() {
  int op;

  do {
    system("clear");
    printf("\n1 - Cadastrar aluno\n2 - Remover aluno");
    printf("\n3 - Alunos reprovados\n4 - Pesquisar aluno\n5 - Listar");
    printf("\n0 - Sair\n");
    scanf("%d", &op);
    getchar();

    switch (op) {
    case 1:
      cadastrar();
      break;
    case 2:
      remover();
      break;
    case 4:
      pesquisar();
      break;
    case 5:
      listar();
      break;
    }
    getchar();
  } while (op != 0);
}

void cadastrar() {
  char nome[50];
  float notas[4];
  int op;
  FILE *file;

  do {
    printf("\nNome: ");
    fgets(nome, sizeof(nome), stdin);
    printf("\n1 Bimestre: ");
    scanf("%f", &notas[0]);
    printf("\n2 Bimestre: ");
    scanf("%f", &notas[1]);
    printf("\n3 Bimestre: ");
    scanf("%f", &notas[2]);
    printf("\n4 Bimestre: ");
    scanf("%f", &notas[3]);

    for (int i = 0; i < MAX_ALUNOS; i++) {
      if (alunos[i].ativo == 0) {
        alunos[i].notas[0] = notas[0];
        alunos[i].notas[1] = notas[1];
        alunos[i].notas[2] = notas[2];
        alunos[i].notas[3] = notas[3];
        strcpy(alunos[i].nome, nome);
        getchar();
        alunos[i].ativo = 1;

        file = fopen("listaDeAlunos.txt", "a");
        fprintf(file, "Nome do Aluno: %s\n", alunos[i].nome);
        fprintf(file, "Nota 1 : %.2f\n", alunos[i].notas[0]);
        fprintf(file, "Nota 2 : %.2f\n", alunos[i].notas[1]);
        fprintf(file, "Nota 3 : %.2f\n", alunos[i].notas[2]);
        fprintf(file, "Nota 4 : %.2f\n", alunos[i].notas[3]);
        fprintf(file, "Matricula : %d\n", 1 + i);
        fprintf(file,
                "-------------------------------------------------------\n");
        fclose(file);
        break;
      }
    }
    printf("\nAluno cadastrado com sucesso!");
    printf("\n1 - Continuar cadastrando\n2 e Enter - Sair\n");
    scanf("%d", &op);
    getchar();
  } while (op != 2);
}
void listar() {
  system("clear");
  printf("n Lista de alunos");
  for (int i = 0; i < MAX_ALUNOS; ++i) {

    if (alunos[i].ativo == 1) {
      printf("Nome: %s\n", alunos[i].nome);
      printf("Matricula: %d\n", i + 1);
      printf("1 Bim: %0.2f\n", alunos[i].notas[0]);
      printf("2 Bim: %0.2f\n", alunos[i].notas[1]);
      printf("3 Bim: %0.2f\n", alunos[i].notas[2]);
      printf("4 Bim: %0.2f\n", alunos[i].notas[3]);

      printf("\n ------------------- \n");
    }
  }
  getchar();
}
void remover() {
  int matricula;
  listar();
  getchar();
  printf("\n Digite a matricula do aluno a ser  removido: \n");
  scanf("%d", &matricula);
  --matricula;
  alunos[matricula].ativo = 0;
  printf("\nAluno excluido com sucesso!\n");
  getchar();
}
void pesquisar() {
  char nome[50];
  int op;

  do {
    system("clear");
    printf("\nDigite o nome do aluno: ");
    fgets(nome, sizeof(nome), stdin);
    for (int i = 0; i < MAX_ALUNOS; ++i) {
      if (strstr(alunos[i].nome, nome) != NULL) {
        printf("Matricula: %d\n", i + 1);
        printf("Nome: %s\n", alunos[i].nome);
        printf("1 Bim: %0.2f\n", alunos[i].notas[0]);
        printf("2 Bim: %0.2f\n", alunos[i].notas[1]);
        printf("3 Bim: %0.2f\n", alunos[i].notas[2]);
        printf("4 Bim: %0.2f\n", alunos[i].notas[3]);
      }
    }
    printf("\nDigite 0 para sair ou 1 para nova pesquisa: ");
    scanf("%d", &op);
    getchar();
  } while (op != 0);
}