#include <stdlib.h>
#include <stdio.h>

typedef struct aluno
{
    int matricula;
    int idade;
    char nome[30];
    char curso[30];
    char data_insc[20];
} Aluno;

void registrar_aluno(FILE *arq)
{
    char aux = 'S';
    while (aux == 'S')
    {
        Aluno *estudante = (Aluno *)malloc(sizeof(estudante));
        printf("Digite sua matrícula\n");
        scanf("%i", &estudante->matricula);
        fprintf(arq, "%i;", estudante->matricula);

        setbuf(stdin, NULL);
        printf("Digite seu nome\n");
        setbuf(stdin, NULL);
        scanf("%[^\n]s", &estudante->nome);
        fprintf(arq, "%s;", estudante->nome);
        setbuf(stdin, NULL);

        printf("Digite sua idade\n");
        scanf("%i", &estudante->idade);
        fprintf(arq, "%i;", estudante->idade);

        setbuf(stdin, NULL);
        printf("Digite seu curso\n");
        setbuf(stdin, NULL);
        scanf("%[^\n]s", &estudante->curso);
        fprintf(arq, "%s;", estudante->curso);

        setbuf(stdin, NULL);

        printf("Digite a data de inscrição\n");
        setbuf(stdin, NULL);
        scanf("%[^\n]s", &estudante->data_insc);
        fprintf(arq, "%s;\n", estudante->data_insc);
        setbuf(stdin, NULL);

        free(estudante);

        setbuf(stdin, NULL);
        printf("Deseja continuar a registrar alunos?\n");
        scanf("%c", &aux);
        setbuf(stdin, NULL);
        aux = toupper(aux);
    }
}

int main()
{

    FILE *arq;
    arq = fopen("alunos.csv", "a");

    registrar_aluno(arq);

    fclose(arq);
    return 0;
}