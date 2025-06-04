#include "cabecalho.h"
/*
Do cabecalho.h:
stdio.h: Fun‡äes: printf(), fopen(), fclose(), fprintf(), fseek(Altera posi‡Æo do ponteiro no arquivo); 
stdlib.h: Fun‡äes: malloc(), realloc(), free();
string.h: fgets(), strlen(tamanho da string), strcat(contatena uma string em outra);
*/
#include "console_v1.5.4.h" 
#include "conio_v3.2.4.h" /* Estrutura COLORS, gotoxy(),  */

void MudarCordeFundo(EditorConfig *editor, int y)
{
    int x;

	switch(y)
	{
	    case 6:
		textbackground(BLACK);
		editor->cor_f.CorAtual = BLACK;
		break;
						
		case 7:
		textbackground(BLUE);
		editor->cor_f.CorAtual = BLUE;
		break;
						
		case 8:
		textbackground(GREEN);
		editor->cor_f.CorAtual = GREEN;
		break;
						
		case 9:
		textbackground(RED);
		editor->cor_f.CorAtual = RED;
		break;
						
		case 10:
		textbackground(BROWN);
		editor->cor_f.CorAtual = BROWN;
		break;
				
		case 11:
		textbackground(YELLOW);
		editor->cor_f.CorAtual = YELLOW;
		break;
						
		case 12:
		textbackground(WHITE);
		editor->cor_f.CorAtual = WHITE;
		break;
						
		case 13:
		textbackground(CYAN);
		editor->cor_f.CorAtual = CYAN;
		break;
						
		case 14:
		textbackground(MAGENTA);
		editor->cor_f.CorAtual = MAGENTA;
		break;
						
		case 15:
		textbackground(DARKGRAY);
		editor->cor_f.CorAtual = DARKGRAY;
		break;
	}
		for(y=editor->area.SuperiorY; y<=editor->area.InferiorY; y++)
		{
			for(x=1; x<=160; x++)
			{
			    gotoxy(x,y);
				printf(" ");
			}
		}
		
		
		if(editor->arquivo.opcao_escolhida == ABERTO)
		{
			MostrarTextoECor(editor);
		}
		
}
void MudarCordeTexto(EditorConfig *editor, int y)
{
	switch(y)
	{
	    case 6:
		textbackground(BLACK);
		editor->cor_t.CorAtual = BLACK;
		break;
						
		case 7:
		textbackground(BLUE);
		editor->cor_t.CorAtual = BLUE;
		break;
						
		case 8:
		textbackground(GREEN);
		editor->cor_t.CorAtual = GREEN;
		break;
						
		case 9:
		textbackground(RED);
		editor->cor_t.CorAtual = RED;
		break;
						
		case 10:
		textbackground(BROWN);
		editor->cor_t.CorAtual = BROWN;
		break;
				
		case 11:
		textbackground(YELLOW);
		editor->cor_t.CorAtual = YELLOW;
		break;
						
		case 12:
		textbackground(WHITE);
		editor->cor_t.CorAtual = WHITE;
		break;
						
		case 13:
		textbackground(CYAN);
		editor->cor_t.CorAtual = CYAN;
		break;
						
		case 14:
		textbackground(MAGENTA);
		editor->cor_t.CorAtual = MAGENTA;
		break;
						
		case 15:
		textbackground(DARKGRAY);
		editor->cor_t.CorAtual = DARKGRAY;
		break;
	}

		
		
		if(editor->arquivo.opcao_escolhida == ABERTO)
		{
		
			MostrarTextoECor(editor);
		}
}


void RealocarMovimentosTAB(EditorConfig *editor, int y, int NumeroCima, int NumeroBaixo, int NumeroMeio)
{
	int i;
	
	switch(y)
	{
		
		case 12:
		editor->tab.qntd_caracters_pulos = NumeroCima;
		break;
	
		case 13:
		editor->tab.qntd_caracters_pulos = NumeroMeio;
		break;
					
		case 14:
		editor->tab.qntd_caracters_pulos = NumeroBaixo;
		break;
					
	}
				
	if(editor->tab.qntd_caracters_pulos > strlen(editor->tab.caracters_espaco))
	{
	     editor->tab.caracters_espaco = (char*)malloc((sizeof(char) * editor->tab.qntd_caracters_pulos));

				
		for(i=0; editor->tab.caracters_espaco[i]!='\0'; i++)
		{
					editor->tab.caracters_espaco[i] = ' ';
		}
	}
			editor->tab.caracters_espaco[editor->tab.qntd_caracters_pulos+1] = '\0';
			
}

void AbrirArquivo(char *nome, EditorConfig *editor)
{

     editor->arquivo.nome_arquivo = fopen(nome, "r+");
     editor->arquivo.nome_arquivo_aberto = (char*)malloc((sizeof(char) * strlen(nome)));
     strcpy(editor->arquivo.nome_arquivo_aberto, nome);
	
	if(editor->arquivo.nome_arquivo == NULL)
	{
		gotoxy(39,12);
		printf(" Erro ao abrir arquivo, voltando para o menu principal...");
		Sleep(2500);
	}
	else 
	{
	editor->arquivo.opcao_escolhida = ABERTO;
	}


}

void CriarArquivo(char *nome, EditorConfig *editor)
{
	
	if(editor->arquivo.nome_arquivo != NULL) /* Fecha arquivo anterior caso aberto */
	{
		fclose(editor->arquivo.nome_arquivo);
	}
	
	editor->arquivo.nome_arquivo = fopen(nome, "w+");
	editor->arquivo.nome_arquivo_aberto = (char*)malloc((sizeof(char) * strlen(nome)));
	strcpy(editor->arquivo.nome_arquivo_aberto, nome);
	
	if(editor->arquivo.nome_arquivo == NULL)
	{
		gotoxy(39,12);
		printf(" Erro ao criar arquivo, voltando para o menu principal...");
		Sleep(2500);
	}
	else 
	{
	editor->arquivo.opcao_escolhida = ABERTO;
	}
	
	editor->arquivo.quantidade_linhas = 0;
	editor->arquivo.texto_t.Texto = (char **)malloc((editor->arquivo.quantidade_linhas+1) * sizeof(char));
}

void SalvarArquivo(EditorConfig *editor)
{
	
	int x, y;
	int i;
	fclose(editor->arquivo.nome_arquivo);
	/* Evita que escreva duas coisas no mesmo arquivo. EntÆo fecha o arquivo anterior, e abre um novo arquivo
	com o mesmo nome, mas "limpo", e logo ap¢s, reescreve toda a informa‡Æo na matriz de strings para o novo arquivo */
	
	editor->arquivo.nome_arquivo = fopen(editor->arquivo.nome_arquivo_aberto, "w");
	
	
	for(i=0; i<editor->arquivo.quantidade_linhas; i++)
	{
		fprintf(editor->arquivo.nome_arquivo,"%s", editor->arquivo.texto_t.Texto[i]);
	}
	
	
	fclose(editor->arquivo.nome_arquivo); /* Fecha o arquivo */
	free(editor->arquivo.nome_arquivo);  /* Libera mem¢ria do ponteiro de arquivo */
	editor->arquivo.texto_t.StringTexto = NULL;
	editor->arquivo.opcao_escolhida = FECHADO;
	
	for(i=0; i<editor->arquivo.quantidade_linhas; i++)
	{
		free(editor->arquivo.texto_t.Texto[i]);  /* Libera mem¢ria de cada ponteiro da matriz */
	}
	
	free(editor->arquivo.texto_t.Texto);  /* Libera mem¢ria do ponteiro da matriz */
	
	for(x=1; x<=160; x++)
	{
		for(y=17; y<=40; y++)
		{
			gotoxy(x,y);
			printf(" ");
			 /* "Limpa" a  rea de edi‡Æo */
		}
	}
	
	
	
	
	
}

void contarLinhasArquivo(EditorConfig *editor)
{
	int total_linhas=0;
	char NumeroDeLinhas[160];
	int TamanhoString;
	int i, j;

   
	while (fgets(NumeroDeLinhas, 160, editor->arquivo.nome_arquivo) != NULL)
	 {
		 
	  total_linhas++;
      
     }
	  
	 editor->arquivo.quantidade_linhas = total_linhas;
	  
	 if(total_linhas != 0)
	{
		editor->arquivo.texto_t.Texto = (char **)malloc(total_linhas * sizeof(char)); /* Aloca dinamicamente a quantidade de linhas do arquivo j  aberto */
	   
	  
		for (i = 0; i < total_linhas; i++) 
		{
		   /* Aloca dinamicamente a quantidade m xima de carac na matriz (colunas) */
			editor->arquivo.texto_t.Texto[i] = (char *)malloc(161 * sizeof(char)); 
		}
	   
		editor->arquivo.texto_t.StringTexto = (char *)malloc((160 * total_linhas) * sizeof(char));

		fseek(stdin, 0, SEEK_END);
	
		for (j = 0; j < total_linhas; j++) 
		{
		    
			editor->arquivo.texto_t.Texto[j][0] = '\0';
			
		}
	
		i = 0;
	 
		fseek(editor->arquivo.nome_arquivo, 0, SEEK_SET); /* Coloca o ponteiro arquivo no come‡o do arquivo */
		
		while ((fgets(NumeroDeLinhas, 160, editor->arquivo.nome_arquivo) != NULL) && i<total_linhas)
		{

			strcat(editor->arquivo.texto_t.Texto[i], NumeroDeLinhas);
			TamanhoString = strlen(editor->arquivo.texto_t.Texto[i]);
			editor->arquivo.texto_t.Texto[i][TamanhoString] = ' ';
			editor->arquivo.texto_t.Texto[i][160] = '\0';
			i++;

		}
	} 
	else 
	{

		editor->arquivo.texto_t.Texto = (char **)malloc((editor->arquivo.quantidade_linhas+1) * sizeof(char));
		editor->arquivo.texto_t.Texto[0] = (char *)malloc(161 * sizeof(char)); 
	
		for(i=0; i<160; i++)
		{
			editor->arquivo.texto_t.Texto[0][i] = ' ';
		}
		
		editor->arquivo.texto_t.Texto[0][160] = '\0';
		
	}
}

void ManipularArquivo(int tipo_escolha, EditorConfig *editor, EventoTecla *Evtecla)
{
	int x, y, novoTamanho=1, i = 0;
	int LimiteDelete;
 	char *nome_arq=NULL;
	EVENTO e;
	

	/* Cria a caixinha onde pergunta para o usu rio o nome do arquivo */
	for(y=11; y<=13; y++)
		{
			for(x=1; x<=160; x++)
			{
				gotoxy(x,y);
				
				if(y == 13)
				{
					printf("-");
				} 
				else
				{
					if(x==1 || x == 160)
					{
					printf("|");
					}
				 
				    else 
				    {
					  if(y==12 && x == 3)
				      {
						
					    switch (tipo_escolha)
						{
					
						 case CRIAR:
						 printf("Crie o nome do arquivo:");
						 x+=22;
						 break;
					
						 case ABRIR:
						 printf("Digite o nome do arquivo para abrir:");
						 x+=35;
						 break;
					
						 case SALVAR:
						 if(editor->arquivo.opcao_escolhida == 1)
						 {
							printf("Arquivo salvo!");
							x+=13;
						 } 
						 else 
						 {
							printf("NÆo ha arquivos para salvar!");
							x+=28;
						 }
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
		
	y = 12;
	
	switch (tipo_escolha)
	
	{
		
		case CRIAR:
		case ABRIR:
		
	
        if(tipo_escolha == CRIAR){
		   x = 26;
		   LimiteDelete = 26;
		   gotoxy(x,y);
		   setCursorStatus(LIGAR);
		}
		else
		{
		   x = 39;
		   LimiteDelete = 39;
		   gotoxy(x,y);
		   setCursorStatus(LIGAR);
		}			
			
		
		  do
		  {

			  e = Evento();
			  
			 
			if(e.tipo_evento & KEY_EVENT)
			{
				 Evento();
				 
				
                     /* Armazena ou exclue dinanicamente o nome do arquivo */
					 if(e.teclado.codigo_tecla == 189)
					 {
				 
					 gotoxy(x,y);
					 printf("_");
					  x++;
					  
					 nome_arq = (char *)realloc(nome_arq, novoTamanho * sizeof(char));
					 nome_arq[i] = 95;
					 novoTamanho++;
					 i++;
				    }
					
				 
					 
				 else if(e.teclado.codigo_tecla >= 65 && e.teclado.codigo_tecla <= 90)
				 {
					 if(e.teclado.status_teclas_controle & (CAPSLOCK_ON | SHIFT_PRESSED))
					 {
					 gotoxy(x,y);
					 printf("%c", (int) e.teclado.codigo_tecla);
					 x++;
					 
					 nome_arq = (char *)realloc(nome_arq, novoTamanho * sizeof(char));
					 nome_arq[i] = (char) e.teclado.codigo_tecla;
					 novoTamanho++;
					 i++;
					 
				     } 
				     else 
				    {
					 gotoxy(x,y);
					 printf("%c", (int) e.teclado.codigo_tecla+32);
					 x++;
					 
					 nome_arq = (char *)realloc(nome_arq, novoTamanho * sizeof(char));
					 nome_arq[i] = (char) e.teclado.codigo_tecla+32;
					 novoTamanho++;
					 i++;
					 
				    }
			    } 
				else if(e.teclado.codigo_tecla == BACKSPACE && x != LimiteDelete)
				{
					x--;
					i--;
					novoTamanho--;
					
					gotoxy(x,y);
					printf(" ");
					gotoxy(x,y);
					nome_arq = (char *)realloc(nome_arq, novoTamanho * sizeof(char));
					
				}
			}

				if(e.teclado.codigo_tecla == ESC)
				{
					NavegarMenuPrincipal(*editor, *Evtecla);
				}
				
		  }while(e.teclado.codigo_tecla != ENTER);
		  
		    /*Define no final da string nome_arq, .txt */
			x++;
			novoTamanho+=10;
			nome_arq = (char *)realloc(nome_arq, novoTamanho * sizeof(char));
			nome_arq[i] = '\0';
			nome_arq = (char *)realloc(nome_arq, novoTamanho * sizeof(char));
            strcat(nome_arq, ".txt");
			
		 
		  if(tipo_escolha == CRIAR)
		  {
			  
			  CriarArquivo(nome_arq, editor);


		  }
			if(tipo_escolha == ABRIR)
			{
			  
			  AbrirArquivo(nome_arq, editor);
			  
			 /* Conta linha apenas se o arquivo nao for NULL */
			if(editor->arquivo.nome_arquivo != NULL)
			{
			  contarLinhasArquivo(editor);
			}

		  }
		  break;
	
	     case 2:
	
	     if(editor->arquivo.opcao_escolhida == 1)
		 {
	     SalvarArquivo(editor);
		 
		 /* "Dorme" a tela por x/1000 segundos */
	     Sleep(1500);
		 } 
		 else
		 {
	     Sleep(1500);
		 }
	     break;
   }
   
   
	if(editor->arquivo.nome_arquivo == NULL || tipo_escolha == SALVAR)
	{
		NavegarMenuPrincipal(*editor, *Evtecla);
		
	} 
	else 
	{
		TextoArquivo(editor);
	}	
}


void MostrarTextoECor(EditorConfig *editor)
{

	int x, y;
	int i, j; /* i: Controla onde est  a linha da matriz. j: Controla onde est  a coluna da matriz */
	setCursorStatus(DESLIGAR);
	textbackground(editor->cor_f.CorAtual);
	
	
	for(x=1; x<=160; x++)
	{
		for(y=17; y<=40; y++)
		{
			gotoxy(x,y);
			printf(" ");
		}
	}

	gotoxy(1,17);
	textcolor(editor->cor_t.CorAtual);
	


	for(i=0; i<editor->arquivo.quantidade_linhas; i++)
	{
		for(j=0; editor->arquivo.texto_t.Texto[i][j] != '\0'; j++)
		{		
		printf("%c", editor->arquivo.texto_t.Texto[i][j]);
		}
	}
		
}
void TextoArquivo(EditorConfig *editor)
{
	int x, y;
	int i=0, j=0, k=0;
	int NovoTamanho, total_linhas = 0;
	int TamanhoString=0;
	char NumeroDeLinhas[160], carac;

	EVENTO e;
	x = 1;
	y = 17;

	MostrarTextoECor(editor);
	gotoxy(x,y);
	
	while (fgets(NumeroDeLinhas, 160, editor->arquivo.nome_arquivo) != NULL)
	{
		 
	  total_linhas++;
      
    }
	
	if(total_linhas == 0)
	{
    editor->arquivo.quantidade_linhas = 1;
	}
	

	do
	{
		gotoxy(x,y);
		setCursorStatus(LIGAR);
		e = Evento();
		

		
		if (e.tipo_evento & KEY_EVENT)
		{
			Evento();	
		 
			if(e.teclado.codigo_tecla == SETA_PARA_DIREITA && x != 160)
			{
			
			 x++;
			 gotoxy(x,y);
			 j++;
			} 
			else
			{
				if(e.teclado.codigo_tecla == SETA_PARA_ESQUERDA && x!=1)
				{
		 
				x--;
				gotoxy(x,y);
				j--;
			 
				} 
				else
				{
					if(e.teclado.codigo_tecla == SETA_PARA_CIMA && y != 17)
					{
						y--;
						gotoxy(x,y);
						i--;
					}
					else
					{
						if(e.teclado.codigo_tecla == SETA_PARA_BAIXO && y != 40)
						{
							y++;
							gotoxy(x,y);
							i++;
						}
					}
				}
			}
		
			if((e.teclado.codigo_tecla == BACKSPACE && x != 1) || (e.teclado.codigo_tecla == DEL && x>=1))
			{
				TamanhoString = strlen(editor->arquivo.texto_t.Texto[i]) - 1;
				
				if(e.teclado.codigo_tecla == DEL)
				{
					j++;
				} 
				else 
				{
					x--;
				}
			
				gotoxy(x,y);
				printf(" ");
            
				for(k=j-1; k<TamanhoString; k++)
				{
					/* Retira o carac e joga todos os carac da frente da string, para traz */
					editor->arquivo.texto_t.Texto[i][k] = editor->arquivo.texto_t.Texto[i][k+1];						
				}
			
				NovoTamanho = strlen(editor->arquivo.texto_t.Texto[i])-1; 
				editor->arquivo.texto_t.Texto[i][NovoTamanho-1] = '\n';
				
				DesenharMenuPrincipal();
				MostrarTextoECor(editor);
			
				j--;			

			}
		
			if(e.teclado.codigo_tecla == HOME)
			{
				/* Direciona o cursor para o come‡o da linha */
				x = 1;
				gotoxy(x,y);
				j=0;
			}
		
			if(e.teclado.codigo_tecla == END)
			{
				/* Direciona o cursor para o final da linha */
				x = strlen(editor->arquivo.texto_t.Texto[i]);
				gotoxy(x,y);
				j = x - 1;
			}
		
			if(e.teclado.codigo_tecla == TAB)
			{
				TamanhoString = 0;
				for(i=j; editor->arquivo.texto_t.Texto[i] != '\0'; i++)
				{
				TamanhoString++;
				}				
			}
		
			if(e.teclado.codigo_tecla == 32)
			{
				x++;
				gotoxy(x,y);
				printf(" ");
			}
	
			if(e.teclado.codigo_tecla >= 65 && e.teclado.codigo_tecla <= 90)
			{
				if(editor->arquivo.quantidade_linhas <= (y - 16))
				{
					editor->arquivo.quantidade_linhas++;
					editor->arquivo.texto_t.Texto = (char **)malloc((editor->arquivo.quantidade_linhas+1) * sizeof(char));
			
					editor->arquivo.texto_t.Texto[i] = (char *)malloc(161 * sizeof(char)); 
			
				}
		
				if(e.teclado.status_teclas_controle & (CAPSLOCK_ON | SHIFT_PRESSED))
				{
					gotoxy(x,y);
					printf("%c", (int) e.teclado.codigo_tecla);
					x++;
			
			
					carac = (char) e.teclado.codigo_tecla;
					editor->arquivo.texto_t.Texto[i][j] = carac;
					j++;
				} 
				else 
				{
					gotoxy(x,y);
					printf("%c", (int) e.teclado.codigo_tecla+32);
					x++;
			
			
					carac = (char) e.teclado.codigo_tecla+32;
					editor->arquivo.texto_t.Texto[i][j] = carac;
					j++;
			
				}
			}
		}
	 
	}while(e.teclado.codigo_tecla != ESC);
	
	setCursorStatus(DESLIGAR);
	
}