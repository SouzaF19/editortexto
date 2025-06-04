#include "cabecalho.h"
#include "conio_v3.2.4.h" /* COLORS: BLACK & WHITE */



void IncilizarEstruturaTAB(EditorConfig *editor)
{
	 
	 editor->tab.qntd_caracters_pulos = 2;
     editor->tab.caracters_espaco = (char*)malloc(editor->tab.qntd_caracters_pulos * sizeof(char));
	 
	 editor->tab.caracters_espaco[0] = ' ';
	 editor->tab.caracters_espaco[1] = ' ';
	 
}

void InicializaLimiteSupeiorAreadeEditor(EditorConfig *editor)
{
	editor->area.SuperiorY = 18;
	editor->area.InferiorY = 40;
}

void InicializaCorDeFundo(EditorConfig *editor)
{
	editor->cor_f.CorAtual = BLACK;
	editor->cor_t.CorAtual = WHITE;
}

void inicializaEscolhaMenuArquivo(EditorConfig *editor)
{
	editor->arquivo.opcao_escolhida = FECHADO; /* Arquivo fechado */
	editor->arquivo.nome_arquivo = NULL;

	
}
void inicializarEstruturas(EditorConfig *editor)
{
	InicializaCorDeFundo(editor);
	InicializaLimiteSupeiorAreadeEditor(editor);
	IncilizarEstruturaTAB(editor);
	inicializaEscolhaMenuArquivo(editor);
	
	
}
