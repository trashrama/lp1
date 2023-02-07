#include <stdio.h>
#include <stdlib.h>

typedef struct pessoas
{
    char nome[30];
    struct pessoas *prox;
} Pessoa;

Pessoa *ini = NULL;

void add(char nome[30])
{

    Pessoa *p = (Pessoa *)malloc(sizeof(Pessoa));
    Pessoa *aux = ini;
    strcpy(p->nome, nome);
    p->prox == NULL;

    if (ini == NULL)
    {
        ini = p;
    }
    else
    {
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }

        aux->prox = p;
    }
}

void remover()
{
    if (ini != NULL)
    {
        ini = ini->prox;
    }
}
void printar(Pessoa *p)
{
    if (p != NULL)
    {
        printf("%s\n", p->nome);
        printar(p->prox);
    }
}

int main()
{
    add("Santiago");
    add("Silva");
    add("Toledo");
    add("Gonzaga");
    add("Pedro");
    add("Kanye");
    add("Lula");

      printar(ini);

    return 0;
}