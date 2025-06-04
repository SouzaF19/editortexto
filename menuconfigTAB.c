#include "cabecalho.h" 
#include "console_v1.5.4.h" /*Estrutura: EVENTO. Fun‡äes: Evento(), setDimensaoJanela(), setTituloConsole(),  */
#include "conio_v3.2.4.h" /* Fun‡äes gotoxy(), */ 

void DesenharMenuTab(EditorConfig *editor, int cima, int meio, int baixo)
{
	int x, y;
	setCursorStatus(DESLIGAR);
	
	/* Algortimo que desenha a caixa do menu */
	for(y=11; y<=13; y++)
	{
		for(x=1; x<= 160; x++)
		{
			gotoxy(x,y);
			
			if(x == 1 || x == 160)
			{
				printf("|");
			} 
			else 
			{
				if(y == 11 && x == 3)
				{
					printf("Defina a quantidade de caracters que 'TAB' vai pular: ");
					x+=53;
				}
				else 
				{
					if(y==12 && x == 3)
					{
						printf("Quantidade atual: %d ", editor->tab.qntd_caracters_pulos);
						x+= 20;
					}
					else 
					{
						if(y==13)
						{
							printf("-");
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
	
	/* Algortimo que desenha a caixa do menu dos numeros*/
	for(y=11; y<=15; y++)
	{
		for(x=57; x<=62; x++)
		{
			gotoxy(x,y);
			
			if(y == 11 || y == 15)
			{
				printf("-");	
			} 
		   else 
		    {
			   if(x == 57 || x == 62)
				{
					printf("|");
				} 
				else 
				{
					if(y==12 && x== 58)
					{
						printf("%d ", cima);
						x+=2;
					}
					else
					{
						if(y==13 && x== 58)
						{
							printf("%d  ", meio);
							x+=2;
						}
						else 
						{
							if(y==14 && x== 58)
							{	
								printf("%d ", baixo);
								x+=2;
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
	}
}

void NavegarMenuTab(EditorConfig *editor)
{
	
	int y = 13;
	int NumeroCima=0, NumeroBaixo=2, NumeroMeio=1;
	EVENTO e;
	
	editor = editor;
	DesenharMenuTab(editor, NumeroCima, NumeroMeio, NumeroBaixo);

	do{	
	
		  
	      e = Evento();
			
		 if(e.tipo_evento & KEY_EVENT)
		 {  
		    Evento();
	
	
			if(e.teclado.codigo_tecla == SETA_PARA_CIMA && NumeroCima != 0)
			{
				NumeroCima--;
				NumeroMeio--;
				NumeroBaixo--;
				y = 13;
				DesenharMenuTab(editor, NumeroCima, NumeroMeio, NumeroBaixo);
			    
			} 
			else 
			{
				if(e.teclado.codigo_tecla == SETA_PARA_CIMA && (NumeroCima == 0 && y != 12))
				{
				y--;
				DesenharMenuTab(editor, NumeroCima, NumeroMeio, NumeroBaixo);
				} 
				else 
				{
					
					if(e.teclado.codigo_tecla == SETA_PARA_BAIXO && (NumeroCima== 0 && y == 12))
					{
					NumeroMeio = 1;
					NumeroBaixo = 2;
					y = 13;
					DesenharMenuTab(editor, NumeroCima, NumeroMeio, NumeroBaixo);
					}				
					else 
					{
							
						if(e.teclado.codigo_tecla == SETA_PARA_BAIXO)
						{
						NumeroCima++;
						NumeroMeio++;
						NumeroBaixo++;
						y = 13;
						DesenharMenuTab(editor, NumeroCima, NumeroMeio, NumeroBaixo);
				
						}
					}
				}
			}
			
			if(y==13)
			{
			gotoxy(58,y);
			textbackground(GREEN);
			printf(">%d ", NumeroMeio);
			textbackground(BLACK);

			} 
			else 
			{
			gotoxy(58,y);
			textbackground(GREEN);
			printf(">%d ", NumeroCima);
			textbackground(BLACK);

			}
			
		
			if(e.teclado.codigo_tecla == ENTER)
			{
				RealocarMovimentosTAB(editor, y, NumeroCima, NumeroBaixo, NumeroMeio);
				/* Chamada para fun‡Æo que salva as informa‡äes do novo TAB */
	        }
			
			DesenharMenuTab(editor, NumeroCima, NumeroMeio, NumeroBaixo);
			
			if(y==13)
			{
			gotoxy(58,y);
			textbackground(GREEN);
			printf(">%d ", NumeroMeio);
			textbackground(BLACK);

			} 
			else 
			{
			gotoxy(58,y);
			textbackground(GREEN);
			printf(">%d ", NumeroCima);
			textbackground(BLACK);

			}
		}
			

		
	} while(e.teclado.codigo_tecla != ESC);
		

}