#include <stdio.h>
#include <stdlib.h>

typedef struct dados
{
    int idade;
    char nome[30];
    struct dados *prox;
} Dados;

Dados *ini = NULL;

int contLista(Dados *aux)
{
    int i = 0;
    while (aux->prox)
    {
        aux = aux->prox;
        i++;
    }
    return i + 1;
}

void remover(int p)
{
    int i = 0;
    Dados *aux = (Dados *)malloc(sizeof(Dados));
    aux = ini;

    if (p == 0)
    {
        ini = ini->prox;
    }
    else
    {

        while (i != p - 1)
        {
            aux = aux->prox;
            i++;
        }

        if (aux->prox != NULL)
        {
            aux->prox = aux->prox->prox;
        }
    }
}
void addAnywhere(int n, int idade, char nome[30])
{
    int i = 0;
    Dados *aux = (Dados *)malloc(sizeof(Dados));
    aux = ini;

    if (aux == NULL)
    {
        Dados *aluno = (Dados *)malloc(sizeof(Dados));
        aluno->idade = idade;
        strcpy(aluno->nome, nome);
        aluno->prox = NULL;

        ini = aluno;
    }
    else
    {
        if (n > contLista(aux))
        {
            printf("Saindo.. Só vai até %i chapa.\n", contLista(aux));
            exit(0);
        }

        else if (n != 0)
        {
            while (i != n - 1)
            {
                aux = aux->prox;
                i++;
            }
        }

        Dados *aluno = (Dados *)malloc(sizeof(Dados));
        aluno->idade = idade;
        strcpy(aluno->nome, nome);
        if (n == 0)
        {
            aluno->prox = ini;
            ini = aluno;
        }
        else
        {
            aluno->prox = aux->prox;
            aux->prox = aluno;
        }
    }
}

void add(int idade, char nome[30])
{
    Dados *aluno = (Dados *)malloc(sizeof(Dados));
    aluno->idade = idade;
    strcpy(aluno->nome, nome);
    aluno->prox = ini;
    ini = aluno;
}

void printar(Dados *dado)
{
    if (dado->prox != NULL)
    {
        printar(dado->prox);
    }

    printf("%i\n", dado->idade);
    printf("%s\n", dado->nome);
}

void novoPrint(Dados *dado)
{
    if (dado != NULL)
    {
        printf("%i\n", dado->idade);
        printf("%s\n", dado->nome);
        novoPrint(dado->prox);
    }
}

Dados *percorrerLista(Dados *aux)
{
    if (aux->prox != NULL)
    {
        aux = aux->prox;
        percorrerLista(aux);
    }
    else
    {
        return aux;
    }
}

void addFinal(int idade, char nome[30])
{
    Dados *aluno = (Dados *)malloc(sizeof(Dados));
    aluno->idade = idade;
    strcpy(aluno->nome, nome);
    aluno->prox = NULL;

    if (ini == NULL)
    {
        ini = aluno;
    }
    else
    {
        Dados *aux = (Dados *)malloc(sizeof(Dados));
        aux = ini;
        aux = percorrerLista(aux);
        aux->prox = aluno;
    }
}

int main()
{
    add(16, "santiago");
    add(18, "arthur");
    add(20, "felipe");
    add(14, "gustavo");
    add(16, "jose");

    // printar(ini);

    // add(15, "thiaguim");
    addFinal(15, "thiaguim");
    // novoPrint(ini);

    addAnywhere(6, 14, "teto");

    remover(7);
    novoPrint(ini);

    return 0;
}