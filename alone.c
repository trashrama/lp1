#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int maiorIdade = 0;
int maiorIdadeAno;
int maiorIdadeMes;
int maiorIdadeDia;

char nomeMaIdade[50];

int menorIdade = 200;
int menorIdadeAno;
int menorIdadeMes;
int menorIdadeDia;

char nomeMeIdade[50];

void verificarMaiorIdade(int idade, char nome[50], int ano, int mes, int dia)
{

    if (idade > maiorIdade)
    {
        maiorIdade = idade;
        strcpy(nomeMaIdade, nome);
        maiorIdadeAno = ano;
        maiorIdadeDia = dia;
        maiorIdadeMes = mes;
    }
    else if (idade == maiorIdade)
    {
        if (ano == maiorIdadeAno)
        {
            if (mes == maiorIdadeMes)
            {
                if (dia < maiorIdadeDia)
                {
                    maiorIdade = idade;
                    strcpy(nomeMaIdade, nome);
                    maiorIdadeAno = ano;
                    maiorIdadeDia = dia;
                    maiorIdadeMes = mes;
                }
            }
        }
    }
}

void verificarMenorIdade(int idade, char nome[50], int ano, int mes, int dia)
{

    if (idade < menorIdade)
    {
        menorIdade = idade;
        strcpy(nomeMeIdade, nome);
        menorIdadeAno = ano;
        menorIdadeDia = dia;
        menorIdadeMes = mes;
    }
    else if (idade == menorIdade)
    {

        if (ano == menorIdadeAno)
        {
            if (mes == menorIdadeMes)
            {
                if (dia < menorIdadeDia)
                {

                    menorIdade = idade;
                    strcpy(nomeMeIdade, nome);
                    menorIdadeAno = ano;
                    menorIdadeDia = dia;
                    menorIdadeMes = mes;
                }
            }
        }
    }
}

int calcularIdade(int dia, int mes, int ano, char nome[50])
{

    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);

    int idade = (tm.tm_year + 1900) - ano;
    int porMeses = (tm.tm_mon + 1) - mes;

    if (porMeses < 0)
    {
        porMeses = porMeses * (-1);
    }

    if (mes < tm.tm_mon + 1)
    {
        idade += 1;
    }
    else if (mes == tm.tm_mon + 1)
    {
        if (tm.tm_mday >= dia)
        {
            idade += 1;
        }
    }
    verificarMaiorIdade(idade, nome, ano, mes, dia);
    verificarMenorIdade(idade, nome, ano, mes, dia);

    return idade;
}

int main(int argc, char *argv[])
{

    char nome[50];
    char aux[50];
    int dia, mes, ano;
    int idade;

    FILE *arq;
    arq = fopen("buceta.txt", "r");

    fscanf(arq, "%s %s", nome, aux);

    int i = 0;

    while (!feof(arq))
    {

        fscanf(arq, "%s %d / %d / %d ", nome, &dia, &mes, &ano);
        idade = calcularIdade(dia, mes, ano, nome);
        printf("%s: %i anos\n", nome, idade);
    }

    printf("%s tem a maior idade\n", nomeMaIdade);
    printf("%s tem a menor idade\n", nomeMeIdade);

    fclose(arq);

    return 0;
}