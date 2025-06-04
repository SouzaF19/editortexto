#include "cabecalho.h" /* Navegar MenuPrincipal() */
#include "console_v1.5.4.h" /* Fun‡äes setDimensaoJanela(), setTituloConsole(),  */
#include "conio_v3.2.4.h"


void DesenharMenuDefinirCorDeTexto()
{
	   int x, y; /* "x" representa a coluna e "y" a linha */
	
	

	for(y=5; y<=16; y++)
	{
		for(x=145; x<=160; x++)
		{
				
			gotoxy(x,y);
				
			if(y==5 || y==16)
			{
				printf("-");
					
			}
			else 
			{
				if((x==145 || x == 160) && (y>=5 && y<=16))
				{	
				printf("|");
				} 
				else 
				{
					if(x==147)
					{
						switch(y)
						{
						case 6:
						printf("PRETO ");
						x+=5;
						break;
						
						case 7:
						printf("AZUL ");
						x+=4;
						break;
						
						case 8:
						printf("VERDE ");
						x+=5;
						break;
						
						case 9:
						printf("VERMELHO ");
						x+=8;
						break;
						
						case 10:
						printf("MARROM ");
						x+=6;
						break;
						
						case 11:
						printf("AMARELO ");
						x+=7;
						break;
						
						case 12:
						printf("BRANCO ");
						x+=6;
						break;
						
						case 13:
						printf("CIANO ");
						x+=5;
						break;
						
						case 14:
						printf("MAGENTA ");
						x+=7;
						break;
						
						case 15:
						printf("CINZA ESCURO ");
						x+=12;
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

void NavegarMenuDefinirCorDeTexto(EditorConfig *editor)
{
	int y, x;
    EVENTO e;
	
	DesenharMenuDefinirCorDeTexto();
	y = 6;
	x = 147;


    do
    {
        e = Evento();

        if(e.tipo_evento & KEY_EVENT)
        {
			Evento();
			
			
			if(e.teclado.codigo_tecla == SETA_PARA_CIMA && y != 6 )
			{
				y = y - 1; 
			    DesenharMenuDefinirCorDeTexto();
			} 
			else if(e.teclado.codigo_tecla == SETA_PARA_BAIXO && y != 15)
			{
				y = y + 1;
				DesenharMenuDefinirCorDeTexto();
			}
			
			
			
			switch(y)
			{
				case 6:
				
				gotoxy(x, y);
				printf(" PRETO");
				break;
				
				case 7:
				
				gotoxy(x,y);
				textcolor(BLUE);
				printf(" AZUL");
				textcolor(WHITE);
				break;
				
				case 8:
				
				gotoxy(x,y);
				textcolor(GREEN);
				printf(" VERDE");
				textcolor(WHITE);
				break;
				
				case 9:

				gotoxy(x,y);
				textcolor(RED);
				printf(" VERMELHO");
				textcolor(WHITE);
				break;
				
				case 10:
				
	
				gotoxy(x,y);
				textcolor(BROWN);
				printf(" MARROM");
				textcolor(WHITE);
				break;
				
				case 11:
				
	
				gotoxy(x,y);
				textcolor(YELLOW);
				printf(" AMARELO");
				textcolor(WHITE);
				break;
				
				case 12:
				
				printf(" ");
				gotoxy(x,y);
				printf(" BRANCO");
				break;
				
				case 13:
				
	
				gotoxy(x,y);
				textcolor(CYAN);
				printf(" CIANO");
				textcolor(WHITE);
				break;
				
				case 14:
				
				printf(" ");
				gotoxy(x,y);
				textcolor(MAGENTA);
				printf(" MAGENTA");
				textcolor(WHITE);
				break;
				
				case 15:
				

				gotoxy(x,y);
				textcolor(DARKGRAY);
				printf(" CINZA ESCURO");
				textcolor(WHITE);
				break;
				
			}
			
			
		}
		
		if(e.teclado.codigo_tecla == ENTER)
		{
			MudarCordeTexto(editor, y);
			e.teclado.codigo_tecla = ESC;
		}
		

		
	}while(e.teclado.codigo_tecla != ESC);
		

}