#include "cabecalho.h" 
#include "console_v1.5.4.h" /*Estrutura: EVENTO. Fun‡äes: Evento(), setDimensaoJanela(), setTituloConsole(),  */
#include "conio_v3.2.4.h" /* Fun‡äes gotoxy(), */ 

void DesenharMenuArquivo(EditorConfig *editor)
{

    int x, y; /* "x" representa a coluna e "y" a linha */
	
	
	
	for(y=5; y<=9; y++)
	{
			for(x=31; x<=48; x++)
			{
				
				gotoxy(x,y);
				
				if(y==5 || y==9)
				{
					printf("-");
				}
				else 
				{
					if(x==31 || x == 48)
					{
						printf("|");
					} 
					else 
					{
						if(x==32)
						{
							switch(y)
							{
							case 6:
						
							if(editor->arquivo.opcao_escolhida == 1)
							{
							printf("Editar arquivo ");
							x+=14;
							}
							else
							{
						    printf("Abrir arquivo ");
						    x+=13;
							}
							break;
						
							case 7:
							printf("Criar arquivo ");
							x+=13;
							break;
						
							case 8:
							printf("Salvar arquivo ");
							x+=14;
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

void NavegarMenuArquivo(EditorConfig *editor, EventoTecla *Evtecla)
{
    int y;
	EVENTO e;
	
	
    DesenharMenuArquivo(editor);
	setCursorStatus(DESLIGAR);
	
	y = 6;

 

    do
    {

        e = Evento();

        if(e.tipo_evento & KEY_EVENT)
        {
			Evento();
			
			if(e.teclado.codigo_tecla == SETA_PARA_CIMA && y!=6)
			{
				y--;
				DesenharMenuArquivo(editor);
			
			} 
			else if(e.teclado.codigo_tecla == SETA_PARA_BAIXO && y != 8)
			{
				y++;
				DesenharMenuArquivo(editor);
			}
			
			switch(y)
			{
			  case 6:
			    
				textbackground(GREEN);
                gotoxy(32,y);
				
				if(editor->arquivo.opcao_escolhida == 1)
				{
					printf(" Editar arquivo");
				}
				else
				{
					printf(" Abrir arquivo");
				}
                
				textbackground(BLACK);
				break;
			
			
			  case 7:
			
                gotoxy(32,y);
                textbackground(GREEN);
                printf(" Criar Arquivo");
                textbackground(BLACK);
				break;
			
			
			  case 8:
				
                gotoxy(32,y);
                textbackground(GREEN);
                printf(" Salvar Arquivo");
                textbackground(BLACK);
				break;
				
			}
			
			if(e.teclado.codigo_tecla == ENTER)
			{
				switch(y)
				{
				
				case 6:
				if(editor->arquivo.opcao_escolhida == 1)
				{
					TextoArquivo(editor);
					e.teclado.codigo_tecla = ESC;
				} 
				else 
				{
					ManipularArquivo(ABRIR, editor, Evtecla);
					e.teclado.codigo_tecla = ESC;
				}
				break;
				
				case 7:
				ManipularArquivo(CRIAR, editor, Evtecla);
				e.teclado.codigo_tecla = ESC;
				break;
				
				case 8:		
				ManipularArquivo(SALVAR, editor, Evtecla);
				e.teclado.codigo_tecla = ESC;
				break;
				}
			}
			
		}


    }
    while(e.teclado.codigo_tecla != ESC);

}
