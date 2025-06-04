#include "cabecalho.h"
#include "console_v1.5.4.h" /* Fun‡äes setDimensaoJanela(), setTituloConsole(),  */
#include "conio_v3.2.4.h" /* clrscr() */

void DesenharMenuPrincipal()
{
	
	int x, y; /* "x" representa a coluna e "y" a linha */
	 
	textbackground(BLACK);
	textcolor(WHITE);
	
	/* "Limpa" todo os espa‡äes de menu desenhado, colocando " " (caracteres de espa‡o)  */
	for(x=1; x<=160; x++)
	{
		for(y=1; y<17; y++)
		{
			gotoxy(x, y);
			printf(" ");
		}
	}
	
	/*Desenhar menu principal */
	for(y=1; y<=10; y++)
	{	
    for(x=1; x<=160; x++)
    {
        gotoxy(x,y);
		
		if((x==52 || x == 107) && (y>4 && y<10))
		{
			printf("|");
		}
        else
		{
			if (x==1 || x==160)
			{
            printf("|");
			}
			else 
			{
				if(y==1 || y==4 || y==7 || y == 10)
				{
				printf("-");
				}
				else
				{
					if(x==69 && y == 2)
					{
						printf("Editor de Texto simples");
						x+=23;
					} 
					else 
					{
						if(x==49 && y == 3)
						{
							printf("Navegue por esse menu apertando ALT + Letra do submenu desejado");
							x+=63;
						}
						else 
							{
								if(x==22 && y == 6)
								{
									printf("Arquivos");
									x+=8;
								}
								else 
								{
									if(x==61 && y == 6)
									{
										printf("Definir cor de fundo da area de editar ");
										x+=38;
									}
									else 
									{
										if(x==124 && y == 6)
										{
											printf("Alterar cor da fonte ");
											x+=20;	
										} 
										else 
										{
											if(x==5 && y == 9)
											{
												printf("Definir numero de movimentos da tecla 'TAB' ");
												x+=43;
											} 
											else 
											{
												if(x==69 && y == 9)
												{
												printf("Alinhamentos de texto ");
												x+=21;	
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
				}
			}
		}
	}   
}


void NavegarMenuPrincipal(EditorConfig editor, EventoTecla Evtecla)
{
	/* Variavel criada para evitar que o menu ficar se redesenhando 
	se qualquer tecla al‚m do ALT for pressionado */
	int VerificaSeAltON=0;
	
    EVENTO e;
	
	setCursorStatus(DESLIGAR);
	DesenharMenuPrincipal();
	
	do{
		
		e = Evento();

	 if (e.tipo_evento & KEY_EVENT)
	 {
						 
						 
						     if (e.teclado.status_teclas_controle & (LEFT_ALT_PRESSED | RIGHT_ALT_PRESSED))
						{
							      textbackground(BLUE);
								  gotoxy(24,5);
	                              printf(" A ");
	                              gotoxy(78,5);
	                              printf(" B ");
								  gotoxy(133,5);
								  printf(" C ");
								  gotoxy(24,8);
								  printf(" D ");
								  gotoxy(78,8);
								  printf(" E ");
								  
								  VerificaSeAltON = 1;
								  
								  
								  if(e.teclado.codigo_tecla == 'a' || e.teclado.codigo_tecla == 'A')
								  {
									  textbackground(BLACK);
									  DesenharMenuPrincipal();
									  textbackground(BLUE);
									  gotoxy(22,6);
									  printf("Arquivos ");
									  textbackground(BLACK);
									  NavegarMenuArquivo(&editor, &Evtecla);
									  DesenharMenuPrincipal();
								  }
								  
								  else if(e.teclado.codigo_tecla == 'b' || e.teclado.codigo_tecla == 'B')
								  {
									  textbackground(BLACK);
									  DesenharMenuPrincipal();
									  textbackground(BLUE);
									  gotoxy(61,6);
									  printf("Definir cor de fundo da area de editar");
									  textbackground(BLACK);
									  NavegarMenuDefinirCorEditor(&editor);									  
                                      DesenharMenuPrincipal();	
								  
								  }
								  
								  else if(e.teclado.codigo_tecla == 'c' || e.teclado.codigo_tecla == 'C')
								  {
									  textbackground(BLACK);
									  DesenharMenuPrincipal();									  
									  textbackground(BLUE);
									  gotoxy(124,6);
									  printf("Alterar cor da fonte");
									  textbackground(BLACK);
                                      NavegarMenuDefinirCorDeTexto(&editor);	
                                      DesenharMenuPrincipal();									  
								  }
								  
								  else if(e.teclado.codigo_tecla == 'd' || e.teclado.codigo_tecla == 'D')
								  {
									  textbackground(BLACK);
									  DesenharMenuPrincipal();
									  textbackground(BLUE);
									  gotoxy(5,9);
									  printf("Definir numero de movimentos da tecla 'TAB'");
									  textbackground(BLACK);
                                      NavegarMenuTab(&editor);	
                                      DesenharMenuPrincipal();									  
									  
								  }
								  else if(e.teclado.codigo_tecla == 'e' || e.teclado.codigo_tecla == 'E')
								  {
									  textbackground(BLACK);
									  DesenharMenuPrincipal();
									  textbackground(BLUE);
									  gotoxy(69,9);
									  printf("Alinhamentos de texto");
									  textbackground(BLACK);
                                      NavegarMenuAlinhamento(editor);	
                                      DesenharMenuPrincipal();
                  								  
									  
								  }
								  
								  
								 
						} 
						else 
							if(VerificaSeAltON == 1)
						{
							textbackground(BLACK);
							DesenharMenuPrincipal();
							VerificaSeAltON = 0;
						}
						
						
	 }
	 
	}while(1);
	
}



void PrimeiraChamadaMenuPrincipal()
{
	EditorConfig editor;
	EventoTecla Evtecla;
	inicializarEstruturas(&editor);

	setTituloConsole("Editor de Texto");
	setDimensaoJanela(160,40); /* Define tamanho do terminal, em caracteres */
	clrscr(); /* Limpa a tela */
	
	NavegarMenuPrincipal(editor, Evtecla);
}