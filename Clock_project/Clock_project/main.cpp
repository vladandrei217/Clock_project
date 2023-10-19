#include<iostream>
#include<iomanip>
#include<cmath>
#include<ctime>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>

void introducere_data_ora(int& a, int& l, int& z, int& o, int& m, int& s);
void afisare_data_ora(int& z, int& l, int& a, int& o, int& m, int& s);
void avans(int& s, int& m, int& o, int& z, int& l, int& a);
void avans_luni(int& z, int& l, int& a);
void afisare_finala(int& z, int& l, int& a, int& o, int& m, int& s);
void repetare_introducere(char& c);
void mesaj_final();

void main(void)
{
    int zi, luna, an;
    int ora, minut, secunda;
    char repetare,c;
 
    do {
        introducere_data_ora(an, luna, zi, ora, minut, secunda);

        do {
            afisare_data_ora(zi, luna, an, ora, minut, secunda);

            secunda++;

            //Sleep(1000);

            avans(secunda, minut, ora, zi, luna, an);

            system("cls");

        } while (!_kbhit());
        
        c = _getch();
        
        afisare_finala(zi, luna, an, ora, minut, secunda);

        repetare_introducere(repetare);

    } while (repetare =='D');

    mesaj_final();
    
}

void introducere_data_ora(int& a, int& l, int& z, int& o, int& m, int& s)
{
    printf("                                            Introducere data si ora: \n\n\n");
    printf("Introduceti anul: ");
    scanf_s("%d", &a);
    
    printf("Introduceti luna: ");
    scanf_s("%d", &l);
    while (l > 12)
    {
        printf("Luna introdusa nu exista, introduceti un numar corespunzator unei luni (1-12)!\n");
        printf("Introduceti luna: ");
        scanf_s("%d", &l);
    }
        
    printf("Introduceti ziua: ");
    scanf_s("%d", &z);
    while (z > 31)
    {
        printf("Ziua introdusa nu exista, introduceti un numar corespunzator unei zile calendaristice (1-31)!\n");
        printf("Introduceti ziua: ");
        scanf_s("%d", &z);
    }
    while ((l == 4 || l == 6 || l == 9 || l == 11) && z > 30)
    {
        printf("Ziua introdusa nu exista, introduceti un numar corespunzator zilei din luna aleasa (1-30)!\n");
        printf("Introduceti ziua: ");
        scanf_s("%d", &z);
    }
    while ((l == 2) && (a % 4 == 0) && (z > 29))
    {
        printf("Ziua introdusa nu exista, introduceti un numar corespunzator zilei din luna aleasa (1-29)!\n");
        printf("Introduceti ziua: ");
        scanf_s("%d", &z);
    }
    while ((l == 2) && (a % 4 != 0) && (z > 28))
    {
        printf("Ziua introdusa nu exista, introduceti un numar corespunzator zilei din luna aleasa (1-28)!\n");
        printf("Introduceti ziua: ");
        scanf_s("%d", &z);
    }

    printf("\nIntroduceti ora: ");
    scanf_s("%d", &o);
    while (o > 23)
    {
        printf("Ora introdusa nu exista, introduceti un numar corespunzator unei ore (0-23)!\n");
        printf("Introduceti ora: ");
        scanf_s("%d", &o);
    }
    
    printf("Introduceti minutul: ");
    scanf_s("%d", &m);
    while (m > 59)
    {
        printf("Minutul introdus nu exista, introduceti un numar corespunzator unui minut (0-59)!\n");
        printf("Introduceti minutul: ");
        scanf_s("%d", &m);
    }

    printf("Introduceti secunda: ");
    scanf_s("%d", &s);
    while (s > 59)
    {
        printf("Secunda introdusa nu exista, introduceti un numar corespunzator unei secunde (0-59)!\n");
        printf("Introduceti secunda: ");
        scanf_s("%d", &s);
    }
    system("cls");
}

void afisare_data_ora(int& z, int& l, int& a, int& o, int& m, int& s)
{
    printf("                                                Data si ora curenta\n");
    printf("                                 Apasati orice tasta pentru a iesi din program...\n\n\n\n\n\n\n\n\n\n\n");
    printf("                                                  Data: ");
    if (z < 10)
        printf("0%d", z);
    else
        printf("%d", z);
    if (l < 10)
        printf("/0%d/", l);
    else
        printf("/%d/", l);

    printf("%d", a);

    printf("\n");

    printf("                                                  Ora:  ");

    if (o < 10)
        printf("0%d", o);
    else
        printf("%d", o);

    if (m < 10)
        printf(":0%d:", m);
    else
        printf(":%d:", m);

    if (s < 10)
        printf("0%d", s);
    else
        printf("%d", s);

}

void avans(int& s, int& m, int& o, int& z, int& l, int& a)
{
    if (s >= 60)
    {
        s = 0;
        m++;
        if (m > 59)
        {
            m = 0;
            o++;
            if (o > 23)
            {
                o = 0;
                z++;
                avans_luni(z, l, a);
                    if (l > 12)
                    {
                        l = 1;
                        a++;
                    }
                
            }
        }
    }
}

void avans_luni(int& z, int& l, int& a)
{
    if ((l == 1 || l == 3 || l == 5 || l == 7 || l == 8 || l == 10 || l == 12) && z > 31)
    {
        z = 1;
        l++;
    }
    if ((l == 4 || l == 6 || l == 9 || l == 11) && z > 30)
    {
        z = 1;
        l++;
    }
    if ((l == 2) && (a % 4 == 0) && (z > 29))
    {
        z = 1;
        l++;
    }
    if ((l == 2) && (a % 4 != 0) && (z > 28))
    {
        z = 1;
        l++;
    }
}

void afisare_finala(int& z, int& l, int& a, int& o, int& m, int& s)
{
    printf("                                  Data si ora la momentul opririi progamului sunt: \n");
    printf("\n\n\n\n\n\n\n");
    printf("                                                  Data: ");
    if (z < 10)
        printf("0%d", z);
    else
        printf("%d", z);
    if (l < 10)
        printf("/0%d/", l);
    else
        printf("/%d/", l);

    printf("%d", a);

    printf("\n");

    printf("                                                  Ora:  ");

    if (o < 10)
        printf("0%d", o);
    else
        printf("%d", o);

    if (m < 10)
        printf(":0%d:", m);
    else
        printf(":%d:", m);

    if (s < 10)
        printf("0%d", s);
    else
        printf("%d", s);
   
    printf("\n\n\n\n");

}

void repetare_introducere(char& c)
{
    printf("\n\n\n");
    printf("                                        Doriti o noua introducere a datei ? (D/N)\n");
    c = _getch();
    c = toupper(c);
    while ((c != 'D') && (c != 'N'))
    {
        printf("Comanda introdusa nu este recunoscuta, alegeti intre tasta d-pentru continuare sau n-pentru iesirea din program!\n ");
        printf("                                        Doriti o nou introducere a datei ? (D/N)\n");
        c = _getch();
        c = toupper(c);
    }
    system("cls");
}

void mesaj_final()
{
    printf("\n\n\n");
    printf("                                 Multumesc pentru utilizarea aplicatiei de ceas!\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}
