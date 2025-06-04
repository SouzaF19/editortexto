#ifndef cabecalho_structs
#define cabecalho_structs
#include <stdio.h> /* Tipo de variaveis */

typedef struct ConfigTAB
{
	unsigned int qntd_caracters_pulos;
	char *caracters_espaco;
	
}EventoTAB;


typedef struct LimitesEditor
{
	unsigned short int SuperiorY;
	unsigned short int InferiorY;
	
}LimiteAreaEditor;


typedef struct CorDeFundo
{
	unsigned short int CorAtual;
	
}CorFundo;

typedef struct CorDeTexto
{
	unsigned short int CorAtual;
	
}CorTexto;

typedef struct TextoSalvo
{
	char **TextoSalvo;

}ETextoSalvo;

typedef struct EventoTextoNaTela
{
	char **Texto;
	char *StringTexto;
	
	ETextoSalvo texto_s;
	
}TextoNaTela;

typedef struct ArquivoAtualAberto
{
	FILE *nome_arquivo;
	char *nome_arquivo_aberto;
	int opcao_escolhida;
	int quantidade_linhas;
	TextoNaTela texto_t;
	
}ArquivoAberto;


typedef struct ConfiguracoesSalvasMenu
{
	EventoTAB tab;
	LimiteAreaEditor area;
	ETextoSalvo texto;
	CorFundo cor_f;
	CorTexto cor_t;
	ArquivoAberto arquivo;
	
}EditorConfig;

typedef struct ConfCopiarEColar
{
	
	char *conteudo_copiado;
	
}EventoCEV;

typedef struct ConfiguracoesTeclas
{
	
	EventoCEV cc;
	
}EventoTecla;

 
#endif

