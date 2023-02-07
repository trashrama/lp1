#include <stdio.h>
#include <stdlib.h>

typedef struct livro
{
    char nome_livro[40];
    struct livro *prox;
} Livro;

Livro *topo = NULL;

void add(char nome[40])
{
    Livro *l = (Livro *)malloc(sizeof(Livro));
    strcpy(l->nome_livro, nome);
    l->prox = NULL;

    if (topo != NULL)
    {
        l->prox = topo;
    }

    topo = l;
}

void rem()
{
    if (topo != NULL)
    {
        topo = topo->prox;
    }
}

void printar(Livro *topo)
{
    if (topo != NULL)
    {
        printf("%s\n", topo->nome_livro);
        printar(topo->prox);
    }
}

int main()
{
    add("Pequeno Princípe");
    add("Katekyo Hitman Reborn!");
    add("Fortaleza Impossível");
    add("Diário de um Banana");
    add("A Batalha do Apocalipse");
    add("Veredas do Sol");
    add("Nihonjin");

    // printar(topo);

    rem();
    rem();
    rem();

    printar(topo);

    return 0;
}