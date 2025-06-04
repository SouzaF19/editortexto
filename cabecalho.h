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
-- Menu principal, primeira interaá∆o do usu†rio. ê onde o usuario podera navegar entre
todos os outros menus  
*/
void PrimeiraChamadaMenuPrincipal(void);
void DesenharMenuPrincipal(void);
void NavegarMenuPrincipal(EditorConfig editor, EventoTecla Evtecla);

/* 
-- Menu de arquivos, d† a opá∆o do usu†rio Criar, Abrir ou Salvar arquivo 
*/
void DesenharMenuArquivo(EditorConfig *editor);
void NavegarMenuArquivo(EditorConfig *editor, EventoTecla *Evtecla);

/* 
-- Menu de cor de fundo, d† a opá∆o do usu†rio mudar a cor de fundo da †rea de ediá∆o 
*/
void DesenharMenuDefinirCorEditor(void);
void NavegarMenuDefinirCorEditor(EditorConfig *editor);

/* 
-- Menu de cor de texto, d† a opá∆o do usu†rio mudar a cor de texto para editar
*/
void DesenharMenuDefinirCorDeTexto(void);
void NavegarMenuDefinirCorDeTexto(EditorConfig *editor);

/* 
-- Menu da tecla 'TAB', d† a opá∆o do usu†rio mudar a quantidade de pulos da tecla 'TAB'
*/

void NavegarMenuTab(EditorConfig *editor);
void DesenharMenuTab(EditorConfig *editor, int, int, int);

/* 
-- Menu de alinhamentos, d† a opá∆o do usu†rio mudar a forma que o texto fica na †rea de ediá∆o
Esquerda/Direita/Centralizado/Justificado
*/
void DesenharMenuAlinhamento(void);
void NavegarMenuAlinhamento(EditorConfig editor);


/* --------------- Chamada para inicializar estruturas --------------- */
/* 
-- Funá∆o usada pela Primeira Chamada Menu Principal
Chama as funá‰es para inicializar estruturas.
*/
void inicializarEstruturas(EditorConfig *editor);


/* 
-- Funá∆o usada pelo menu TAB
Inicializa em 2 caracteres.
*/
void IncilizarEstruturaTAB(EditorConfig *editor);

/* 
-- Funá∆o usada pelo menu CorDeFundo, muda a cor de fundo
Inicializa na cor BLACK.
*/
void InicializaCorDeFundo(EditorConfig *editor);

/*
-- Funá∆o usada pelo menu CorDeFundo, define a area de ediá∆o
Inicializa SuperiorY = 18, InferiorY = 40.
*/
void InicializaLimiteSupeiorAreadeEditor(EditorConfig *editor);

/*
-- Funá∆o usada pelo menu Arquivo, qual opá∆o est† sendo utilizada
Inicializa 4, para nenhuma opá∆o.
*/
void inicializaEscolhaMenuArquivo(EditorConfig *editor);



/* --------------- Chamada para funá‰es de engrenagem --------------- */


/* 
-- Funá∆o usada pelo menu CordeFundo
Define uma nova cor de fundo da area de ediá∆o.
*/
void MudarCordeFundo(EditorConfig *editor, int);

/* 
-- Funá∆o usada pelo menu CordeFundo
Define uma nova cor de texto da area de ediá∆o.
*/
void MudarCordeTexto(EditorConfig *editor, int);

/* 
-- Funá∆o usada pelo menu TAB
Define uma nova quantidade de caracters para TAB.
*/
void RealocarMovimentosTAB(EditorConfig *editor, int, int, int, int);

/* 
-- Funá∆o usada pelo menu Arquivo
Manipula o arquivo no editor
*/
void ManipularArquivo(int, EditorConfig *editor, EventoTecla *Evtecla);

/* 
-- Funá‰es usada pelo menu Arquivo
*/
void AbrirArquivo(char[], EditorConfig *editor);
void CriarArquivo(char[], EditorConfig *editor);
void SalvarArquivo(EditorConfig *editor);

/* 
-- Funá∆o usada pelo menu Arquivo
Conta quantas linhas tem o arquivo aberto e aloca dinamicamente
*/
void contarLinhasArquivo(EditorConfig *editor);

/* 
-- Funá∆o usada pelo menu Arquivo
Permite o usuario editar texto
*/
void TextoArquivo(EditorConfig *editor);

/* 
-- Funá∆o para redesenhar  o texto depois de mudar 
a cor de fundo
*/
void MostrarTextoECor(EditorConfig *editor);


#endif /* CABECALHO */
