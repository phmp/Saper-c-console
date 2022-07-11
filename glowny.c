#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include "naglowek.h"

int main(void)
{
 	int i,j;
	int ile=35; 	 
	X=10;
	Y=10;
	//poczatek(&X,&Y,&ile);
 	


	int  miny [X*Y];
	char ekran[X*Y];
	char bomba = (char)(3);
	int zostalo;
	int wynik;
	int win_or_not;
	int count_win=0, count_defeat=0;


	srand(time(NULL));	
	
	do
	{
	    zostalo=X*Y;
	    for(j=0;j<Y;j++)
	        for(i=0;i<X;i++)
		        ekran[i+j*X] = (char)(177);
	     
	    for(j=0;j<Y;j++)
	        for(i=0;i<X;i++)
		        miny[i+j*X] = 0;
		        
		put_bombs(miny,ile);
		put_numbers(miny);		
		
	    do
	    {		
		    system("cls");	
			printf("zosta³o: %d licznik wygranych i przegranych: +%d -%d\n", zostalo, count_win, count_defeat);
		    wyswietl(ekran);
			wynik=sprawdz(miny, ekran, bomba,  pobierz() , &zostalo);
			
		}
		while(wynik != 9 && zostalo>ile);
		
		if(wynik == 9)
		{
		    win_or_not=0;
		    count_defeat++;
		}
		else
		{
		    win_or_not=1;
		    count_win++;
		}
		
	    system("cls");
		wyswietl(ekran);
	}while(koniec(win_or_not)==1);
    puts("\nDziêkuje, do widzenia :)");
    getch();
}
