/* 
    Programa: Editor de texto simples
    Descri��o: Oferece funcionalidades para a edi��o de arquivos de texto
    Programador: Ant�nio Carlos Figueiredo de Souza
    RGM: 49105
    Data da �ltima modifica��o: 20/05/2024 
*/
/* 
 Copie e cole a seguinte linha de comando no prompt de comando e compile:
	gcc main.c console_v1.5.4.c conio_v3.2.4.c menuprincipal.c menuarquivo.c menucordefundo.c menucordetexto.c menuconfigTAB.c inicializarestruturas.c menualinhamentotexto.c funcoes_de_engrenagem.c -o editor.exe -Wall -Wextra -Werror -pedantic

 Execute, no prompt de comando:
    editor.exe
	
*/
#include "cabecalho.h"
#include "console_v1.5.4.h" 
#include "conio_v3.2.4.h"
/*
Do cabecalho.h:
stdio.h: Fun��es: printf(), fopen(), fclose(), fprintf(), fseek(Altera posi��o do ponteiro no arquivo); 
stdlib.h: Fun��es: malloc(), realloc(), free();
string.h: fgets(), strlen(tamanho da string), strcat(contatena uma string em outra);
*/

int main(int argc, char *argv[])
{
	
    argc = argc;
    argv = argv;

	PrimeiraChamadaMenuPrincipal();
	
	return 0;
}


