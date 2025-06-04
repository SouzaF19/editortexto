#include "cabecalho.h" /* Navegar MenuPrincipal() */
#include "console_v1.5.4.h" /* Fun‡äes setDimensaoJanela(), setTituloConsole(),  */
#include "conio_v3.2.4.h" /* Fun‡äes gotoxy() */ 

void DesenharMenuDefinirCorEditor()
{

    int x, y; /* "x" representa a coluna e "y" a linha */
	
	
		
	for(y=5; y<=16; y++)
	{
		for(x=100; x<=115; x++)
		{
				
			gotoxy(x,y);
			
			if(y==5 || y==16)
			{
				printf("-");
			}
			else 
			{
				if(x==100 || x == 115)
				{
					printf("|");
				} 
				else 
				{
					if(x==102)
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

void NavegarMenuDefinirCorEditor(EditorConfig *editor)
{
	int y, x;
	EVENTO e;
	
	
	DesenharMenuDefinirCorEditor();
	y = 6;
	x = 102;


    do
    {
        e = Evento();

        if(e.tipo_evento & KEY_EVENT)
        {
			Evento();
			
			
		
			if(e.teclado.codigo_tecla == SETA_PARA_CIMA && y != 6 )
			{
				y = y - 1; 
			    DesenharMenuDefinirCorEditor();
			} 
			else if(e.teclado.codigo_tecla == SETA_PARA_BAIXO && y != 15)
			{
				y = y + 1;
				DesenharMenuDefinirCorEditor();
			}
			
			
			
			switch(y)
			{
				case 6:
				
				gotoxy(x, y);
				textbackground(WHITE);
				textcolor(BLACK);
				printf(" PRETO");
				textcolor(WHITE);
				textbackground(BLACK);
				break;
				
				case 7:
				
				gotoxy(x,y);
				textbackground(BLUE);
				printf(" AZUL");
				textbackground(BLACK);
				break;
				
				case 8:
				
				gotoxy(x,y);
				textbackground(GREEN);
				printf(" VERDE");
				textbackground(BLACK);
				break;
				
				case 9:
				
				gotoxy(x,y);
				textbackground(RED);
				printf(" VERMELHO");
				textbackground(BLACK);
				break;
				
				case 10:
				
				gotoxy(x,y);
				textbackground(BROWN);
				printf(" MARROM");
				textbackground(BLACK);
				break;
				
				case 11:
				
				gotoxy(x,y);
				textbackground(YELLOW);
				textcolor(BLACK);
				printf(" AMARELO");
				textbackground(BLACK);
				textcolor(WHITE);
				break;
				
				case 12:
				
				gotoxy(x,y);
				textbackground(WHITE);
				textcolor(BLACK);
				printf(" BRANCO");
				textcolor(WHITE);
				textbackground(BLACK);
				break;
				
				case 13:
				
				gotoxy(x,y);
				textbackground(CYAN);
				printf(" CIANO");
				textbackground(BLACK);
				break;
				
				case 14:
				
				gotoxy(x,y);
				textbackground(MAGENTA);
				printf(" MAGENTA");
				textbackground(BLACK);
				break;
				
				case 15:
				
				gotoxy(x,y);
				textbackground(DARKGRAY);
				printf(" CINZA ESCURO");
				textbackground(BLACK);
				break;
				
			}
			
		}
		
		if(e.teclado.codigo_tecla == ENTER)
		{
			MudarCordeFundo(editor, y);
			e.teclado.codigo_tecla = ESC;
		}
		
		
		
	}while(e.teclado.codigo_tecla != ESC);
			
	
		
}