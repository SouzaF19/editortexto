#ifndef _CABECALHO
#define _CABECALHO

#include "cabecalho_structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
	CRIAR,
	ABRIR,
	SALVAR
	
}EscolhaArquivo;

typedef enum
{
	FECHADO,
	ABERTO
	
}SituaArquivo;



/* --------------- Chamada de menus --------------- */


/* 
-- Menu principal, primeira intera��o do usu�rio. � onde o usuario podera navegar entre
todos os outros menus  
*/
void PrimeiraChamadaMenuPrincipal(void);
void DesenharMenuPrincipal(void);
void NavegarMenuPrincipal(EditorConfig editor, EventoTecla Evtecla);

/* 
-- Menu de arquivos, d� a op��o do usu�rio Criar, Abrir ou Salvar arquivo 
*/
void DesenharMenuArquivo(EditorConfig *editor);
void NavegarMenuArquivo(EditorConfig *editor, EventoTecla *Evtecla);

/* 
-- Menu de cor de fundo, d� a op��o do usu�rio mudar a cor de fundo da �rea de edi��o 
*/
void DesenharMenuDefinirCorEditor(void);
void NavegarMenuDefinirCorEditor(EditorConfig *editor);

/* 
-- Menu de cor de texto, d� a op��o do usu�rio mudar a cor de texto para editar
*/
void DesenharMenuDefinirCorDeTexto(void);
void NavegarMenuDefinirCorDeTexto(EditorConfig *editor);

/* 
-- Menu da tecla 'TAB', d� a op��o do usu�rio mudar a quantidade de pulos da tecla 'TAB'
*/

void NavegarMenuTab(EditorConfig *editor);
void DesenharMenuTab(EditorConfig *editor, int, int, int);

/* 
-- Menu de alinhamentos, d� a op��o do usu�rio mudar a forma que o texto fica na �rea de edi��o
Esquerda/Direita/Centralizado/Justificado
*/
void DesenharMenuAlinhamento(void);
void NavegarMenuAlinhamento(EditorConfig editor);


/* --------------- Chamada para inicializar estruturas --------------- */
/* 
-- Fun��o usada pela Primeira Chamada Menu Principal
Chama as fun��es para inicializar estruturas.
*/
void inicializarEstruturas(EditorConfig *editor);


/* 
-- Fun��o usada pelo menu TAB
Inicializa em 2 caracteres.
*/
void IncilizarEstruturaTAB(EditorConfig *editor);

/* 
-- Fun��o usada pelo menu CorDeFundo, muda a cor de fundo
Inicializa na cor BLACK.
*/
void InicializaCorDeFundo(EditorConfig *editor);

/*
-- Fun��o usada pelo menu CorDeFundo, define a area de edi��o
Inicializa SuperiorY = 18, InferiorY = 40.
*/
void InicializaLimiteSupeiorAreadeEditor(EditorConfig *editor);

/*
-- Fun��o usada pelo menu Arquivo, qual op��o est� sendo utilizada
Inicializa 4, para nenhuma op��o.
*/
void inicializaEscolhaMenuArquivo(EditorConfig *editor);



/* --------------- Chamada para fun��es de engrenagem --------------- */


/* 
-- Fun��o usada pelo menu CordeFundo
Define uma nova cor de fundo da area de edi��o.
*/
void MudarCordeFundo(EditorConfig *editor, int);

/* 
-- Fun��o usada pelo menu CordeFundo
Define uma nova cor de texto da area de edi��o.
*/
void MudarCordeTexto(EditorConfig *editor, int);

/* 
-- Fun��o usada pelo menu TAB
Define uma nova quantidade de caracters para TAB.
*/
void RealocarMovimentosTAB(EditorConfig *editor, int, int, int, int);

/* 
-- Fun��o usada pelo menu Arquivo
Manipula o arquivo no editor
*/
void ManipularArquivo(int, EditorConfig *editor, EventoTecla *Evtecla);

/* 
-- Fun��es usada pelo menu Arquivo
*/
void AbrirArquivo(char[], EditorConfig *editor);
void CriarArquivo(char[], EditorConfig *editor);
void SalvarArquivo(EditorConfig *editor);

/* 
-- Fun��o usada pelo menu Arquivo
Conta quantas linhas tem o arquivo aberto e aloca dinamicamente
*/
void contarLinhasArquivo(EditorConfig *editor);

/* 
-- Fun��o usada pelo menu Arquivo
Permite o usuario editar texto
*/
void TextoArquivo(EditorConfig *editor);

/* 
-- Fun��o para redesenhar  o texto depois de mudar 
a cor de fundo
*/
void MostrarTextoECor(EditorConfig *editor);


#endif /* CABECALHO */
