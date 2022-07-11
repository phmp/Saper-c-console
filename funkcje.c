#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include "naglowek.h"

void wyswietl(char* tab)
{
int i,j;
char a=201, b=200 ,c=187 , e=188;
char l=204, p=185;
char g=203, d=202;
char h=205, v=186;
char k=206;
//pierwszy wers z literkami
printf("\n      ");
for(i=0;i<X;i++)
    printf("%c   ",(char)(i+65) );
printf("\n");
//pierwsza krawedz tabeli
printf("    %c",a);
for(i=0;i<X-1;i++)
    printf("%c%c%c%c",h,h,h,g);
printf("%c%c%c%c\n",h,h,h,c);    
//reszta tabeli
for(j=0;j<Y;j++)
{
    printf(" %2d %c",(j+1),v );
    for(i=0;i<X;i++)
        printf(" %c %c", tab[i+j*X] ,v);
    printf(" %2d\n",j+1);
    if (j!=Y-1)
    {
	    printf("    %c",l);
	    for(i=0;i<X-1;i++)
	        printf("%c%c%c%c",h,h,h,k);
	    printf("%c%c%c%c\n",h,h,h,p);
	}
	
}
printf("    %c",b);
for(i=0;i<X-1;i++)
    printf("%c%c%c%c",h,h,h,d);
printf("%c%c%c%c\n",h,h,h,e);  
printf("      ");
for(i=0;i<X;i++)
    printf("%c   ",(char)(i+65) );
printf("\n");
}



void poczatek(int* x,int* y, int* ile)
{
 	 puts("Podaj liczbe kolumn. \n");
 	 scanf("%d",x);

 	 puts("Podaj liczbe wierszy. \n");
 	 scanf("%d",y);

 	 puts("Podaj liczbe min. \n");
 	 scanf("%d",ile);
	 
	 system("cls");
}

void put_bombs(int* pole, int ile)
{
    int los;
    if (ile > 0)
    {
        do
        {
		    los = rand()%(X*Y);
		}
		while(pole[los] == 9);
		pole[los]=9;
	    put_bombs(pole, ile-1);
    }
}


void put_numbers(int* pole)
{
 	 int pole1[X*Y];
 	 int bomby;
 	 int i,j;
 	 
 	 for(j=1;j<Y-1;j++) //srodek
         for(i=1;i<X-1;i++)
		     pole1[i+j*X] = (pole[i+j*X-1]==9) + (pole[i+j*X+1]==9) + (pole[i+j*X+X]==9) + (pole[i+j*X-X]==9) + (pole[i+j*X+1+X]==9) + (pole[i+j*X+1-X]==9) + (pole[i+j*X-1-X]==9) + (pole[i+j*X-1+X]==9);
     
	 j=0; //gora
     for(i=1;i<X-1;i++)
         pole1[i+j*X] = (pole[i+j*X-1]==9) + (pole[i+j*X+1]==9) + (pole[i+j*X+X]==9) + (pole[i+j*X+1+X]==9) + (pole[i+j*X-1+X]==9);
     
	 j=Y-1; //dol
     for(i=1;i<X-1;i++)
         pole1[i+j*X] = (pole[i+j*X-1]==9) + (pole[i+j*X+1]==9) + (pole[i+j*X-X]==9) + (pole[i+j*X+1-X]==9) + (pole[i+j*X-1-X]==9);     

     i=0; //lewo
     for(j=1;j<Y-1;j++)
         pole1[i+j*X] = (pole[i+j*X+1]==9) + (pole[i+j*X+X]==9) + (pole[i+j*X-X]==9) + (pole[i+j*X+1+X]==9) + (pole[i+j*X+1-X]==9);
     
     i=X-1; //prawo
     for(j=1;j<Y-1;j++)
         pole1[i+j*X] = (pole[i+j*X-1]==9) + (pole[i+j*X+X]==9) + (pole[i+j*X-X]==9) + (pole[i+j*X-1+X]==9) + (pole[i+j*X-1-X]==9);

     pole1[0]    = (pole[1]==9) + (pole[X]==9) + (pole[X+1]==9);
     pole1[X-1]  = (pole[X-2]==9) + (pole[2*X-1]==9) + (pole[2*X-2]==9);
     pole1[X*Y-1]= (pole[X*Y-2]==9) + (pole[X*Y-2-X]==9) + (pole[X*Y-1-X]==9);
     pole1[X*Y-X]= (pole[X*Y-X+1]==9) + (pole[X*Y-X-X]==9) + (pole[X*Y-X-X+1]==9);
     
     for(i=0;i<X*Y;i++)
         if (pole[i] != 9)
             pole[i] = pole1[i];
}

void miny_na_ekran(int* miny, char* ekran, char m)
{
    int i,j;
	for(j=0;j<Y;j++)
        for(i=0;i<X;i++)
	        if (miny[i+j*X] == 0)
			    ekran[i+j*X] = ' ';
            else if (miny[i+j*X] == 9)
                ekran[i+j*X] = m;
			else ekran[i+j*X] = (char)(miny[i+j*X] + 48);
}
int pobierz()
{
    char x;

    int y;
    int i,j;
    
	puts("\nPodaj komune. ");
	//scanf("%c",&x);
	x=getchar();
	puts("\nPodaj wiersz. ");
	scanf("%d",&y);
	i=(int)(x-97);
	j=y-1;
	getchar();
	//dopisz zaberpieczenia
	return (i+j*X); 	
}
int  sprawdz(int* miny, char* ekran, char m, int komorka, int* zostalo)
{
    int i =komorka%X;
    int j =komorka/X;
    if (ekran[komorka] == (char)(177) )
	{
	    (*zostalo)--;
	    if (miny[komorka] == 0)
	    {
	        ekran[komorka] = ' ';
	        //nie wiem dlaczego nie dzia³a... dzia³a³o dla pierwszych 3 pól
			
	        if(i > 0 && i < X-1 && j > 0 && j<Y-1) //srodek
	        {
		        sprawdz(miny, ekran,m, i+X*(j-1) -1, zostalo);
	 	        sprawdz(miny, ekran,m, i+X*(j  ) -1, zostalo);
	 	        sprawdz(miny, ekran,m, i+X*(j+1) -1, zostalo);
	 	        sprawdz(miny, ekran,m, i+X*(j-1)   , zostalo);
	 	        sprawdz(miny, ekran,m, i+X*(j+1)   , zostalo);
	  	        sprawdz(miny, ekran,m, i+X*(j-1) +1, zostalo);
	  	        sprawdz(miny, ekran,m, i+X*(j  ) +1, zostalo);
	 	        sprawdz(miny, ekran,m, i+X*(j+1) +1, zostalo);
			}
			else if(i == 0 && j > 0 && j<Y-1)//lewo
	        {
	 	        sprawdz(miny, ekran,m, i+X*(j-1)   , zostalo);
	 	        sprawdz(miny, ekran,m, i+X*(j+1)   , zostalo);
	  	        sprawdz(miny, ekran,m, i+X*(j-1) +1, zostalo);
	  	        sprawdz(miny, ekran,m, i+X*(j  ) +1, zostalo);
	 	        sprawdz(miny, ekran,m, i+X*(j+1) +1, zostalo);
			}
			else if(i ==X-1 && j > 0 && j<Y-1)//prawo
	        {
		        sprawdz(miny, ekran,m, i+X*(j-1) -1, zostalo);
	 	        sprawdz(miny, ekran,m, i+X*(j  ) -1, zostalo);
	 	        sprawdz(miny, ekran,m, i+X*(j+1) -1, zostalo);
	 	        sprawdz(miny, ekran,m, i+X*(j-1)   , zostalo);
	 	        sprawdz(miny, ekran,m, i+X*(j+1)   , zostalo);
			}
			else if(i > 0 && i < X-1 && j==Y-1) //dol
	        {
		        sprawdz(miny, ekran,m, i+X*(j-1) -1, zostalo);
	 	        sprawdz(miny, ekran,m, i+X*(j  ) -1, zostalo);
	 	        sprawdz(miny, ekran,m, i+X*(j-1)   , zostalo);
	  	        sprawdz(miny, ekran,m, i+X*(j-1) +1, zostalo);
	  	        sprawdz(miny, ekran,m, i+X*(j  ) +1, zostalo);
	 	        
			}
			else if(i > 0 && i < X-1 && j ==0) //gora
	        {
	 	        sprawdz(miny, ekran,m, i+X*(j  ) -1, zostalo);
	 	        sprawdz(miny, ekran,m, i+X*(j+1) -1, zostalo);
	 	        sprawdz(miny, ekran,m, i+X*(j+1)   , zostalo);
	  	        sprawdz(miny, ekran,m, i+X*(j  ) +1, zostalo);
	 	        sprawdz(miny, ekran,m, i+X*(j+1) +1, zostalo);
			}
			else if(i ==0 && j==0) // naro¿nik lg
	        {
	 	        sprawdz(miny, ekran,m, i+X*(j+1)   , zostalo);
	  	        sprawdz(miny, ekran,m, i+X*(j  ) +1, zostalo);
	 	        sprawdz(miny, ekran,m, i+X*(j+1) +1, zostalo);
			}
			else if(i==X-1 && j==Y-1) //naroznik pd
	        {
		        sprawdz(miny, ekran,m, i+X*(j-1) -1, zostalo);
	 	        sprawdz(miny, ekran,m, i+X*(j  ) -1, zostalo);
	 	        sprawdz(miny, ekran,m, i+X*(j-1)   , zostalo);
			}
			else if(i ==0 && j ==Y-1) //naroznik ld
	        {
	
	 	        sprawdz(miny, ekran,m, i+X*(j-1)   , zostalo);
	  	        sprawdz(miny, ekran,m, i+X*(j-1) +1, zostalo);
	  	        sprawdz(miny, ekran,m, i+X*(j  ) +1, zostalo);
			}
			else if(i ==X-1 && j==0) //naroznik pg
	        {
	 	        sprawdz(miny, ekran,m, i+X*(j  ) -1, zostalo);
	 	        sprawdz(miny, ekran,m, i+X*(j+1) -1, zostalo);
	 	        sprawdz(miny, ekran,m, i+X*(j+1)   , zostalo);
			}
	    }
	    else if (miny[komorka] == 9)
	        miny_na_ekran(miny, ekran, m);
	    else ekran[komorka] = (char)(miny[komorka] + 48);
	}
	return miny[komorka];
}

int koniec(int wynik)
{
 	 char dalej;
 	 char smiec;
 	 if(wynik)
 	     puts("Wygrana! Gratulacje!\n");
	 else
     	 puts("Nastepnym razem siê uda!\n");
 	 
 	 puts("Koniec\n");
 	 puts("Jeszcze raz? (n-nie t-tak)\n");
 	 scanf("%c",&dalej);
 	 getchar();
 	 
 	 
 	 if (dalej == 't')
     	 return 1;
 	 else
 	     return 0;
}



/*

     a   b   c   d   e   f   g   h   i  
   +---+---+---+---+---+---+---+---+---+
 1 |   |   |   |   |   |   |   |   |   |
   +---+---+---+---+---+---+---+---+---+
 2 |   |   |   |   |   |   |   |   |   |
   +---+---+---+---+---+---+---+---+---+
 3 |   |   |   |   |   |   |   |   |   |
   +---+---+---+---+---+---+---+---+---+
 4 |   |   |   |   |   |   |   |   |   |
   +---+---+---+---+---+---+---+---+---+
 5 |   |   |   |   |   |   |   |   |   |
   +---+---+---+---+---+---+---+---+---+
 6 |   |   |   |   |   |   |   |   |   |
   +---+---+---+---+---+---+---+---+---+
 7 |   |   |   |   |   |   |   |   |   |
   +---+---+---+---+---+---+---+---+---+
 8 |   |   |   |   |   |   |   |   |   |
   +---+---+---+---+---+---+---+---+---+
 9 |   |   |   |   |   |   |   |   |   |
   +---+---+---+---+---+---+---+---+---+

*/
