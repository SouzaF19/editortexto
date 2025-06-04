#include "cabecalho.h"
/*
Do cabecalho.h:
stdio.h: Fun‡äes: printf();
*/
#include "console_v1.5.4.h" /* Fun‡äes setDimensaoJanela(), setTituloConsole(),  */
#include "conio_v3.2.4.h" /* Fun‡äes: gotoxy() */

void DesenharMenuAlinhamento()
{
	int x,y;
	
	for(y=8; y<=13; y++)
	{
		for(x=90; x<=105; x++)
		{
			gotoxy(x,y);
			if(y==8 || y == 13)
			{
				printf("-");
			} 
			else 
			{
				if(x==90 || x == 105)
				{
				printf("|");
				} 
				else 
				{
					if(x==91)
					{
						switch(y)
						{
						case 9:
						printf("Esquerda ");
						x+=8;
						break;
					
						case 10:
						printf("Direita ");
						x+=7;
						break;
					
						case 11:
						printf("Centralizado ");
						x+=12;
						break;
					
						case 12:
						printf("Justificado ");
						x+=11;
						break;
						}
					} 
					else 
					{
						printf(" ");
					}
				}
			}
		}	
	}
}

void NavegarMenuAlinhamento(EditorConfig editor)
{
	
	int x,y;
	EVENTO e;
	editor = editor;

	y=9;
	x=91;
	
	DesenharMenuAlinhamento();
	
	do
	{
		e = Evento();

        if(e.tipo_evento & KEY_EVENT)
        {
			Evento();
			
			if(e.teclado.codigo_tecla == SETA_PARA_CIMA && y!=9)
			{
				y--;
				DesenharMenuAlinhamento();
				
			} else if(e.teclado.codigo_tecla == SETA_PARA_BAIXO && y!=12)
			{
				y++;
				DesenharMenuAlinhamento();
			}
		}
		
		switch(y)
		{
			case 9:
			
			gotoxy(x,y);
			textbackground(GREEN);
			printf(" Esquerda");
			textbackground(BLACK);
			break;
			
			case 10:
			
			gotoxy(x,y);
			textbackground(GREEN);
			printf(" Direita");
			textbackground(BLACK);
			break;
			
			case 11:
			
			gotoxy(x,y);
			textbackground(GREEN);
			printf(" Centralizado");
			textbackground(BLACK);
			break;
			
			case 12:
			
			gotoxy(x,y);
			textbackground(GREEN);
			printf(" Justificado");
			textbackground(BLACK);
			break;
		}
		
		
	}while(e.teclado.codigo_tecla != ESC);
	
	
	
}
