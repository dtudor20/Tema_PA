#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "functii.h"
char text[10000];
static const char ucase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ()    ";
int main()
{
    int alegere;
    printf("Apasati 1 pentru a scrie un text sau apasati 2 pentru a genera un text");
    scanf("%d", &alegere);
    while (getchar() != '\n');
    if(alegere==1)
        {gets(text);}
    else if(alegere==2)
    {
        printf("Cate caractere doriti sa generati?");
        srand(time(NULL)); //generare caractere random
        int num,indice;
        scanf("%d", &num);//numarul de caractere generate
        for(indice=0;indice<num;indice++)
        {
            int random_index = (double)rand() / RAND_MAX * sizeof(ucase)-1;
            text[indice]=ucase[random_index];
        }
        puts(text);
    }
    else
        {printf("Apasati 1 sau 2");}

    int nr=1;
    char* cuvant=strtok(text, " ");
    while(cuvant!=NULL) //impartim textul in cuvinte
    {

        int d1=levenshtein(cuvant, "func(levenshtein)");
        int d2=levenshtein(cuvant, "func(afisare)");
        if(d1<d2) //vedem care dintre distante catre functii e mai mica si o afisam pe aceea
            afisare(d1,nr);
        else
            afisare(d2,nr);
        nr++;   //il crestem pe nr pentru a numara cuvintele
        cuvant=strtok(NULL, " ");
    }

    return 0;
}

