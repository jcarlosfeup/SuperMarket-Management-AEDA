/*
 * Hipermercado.h
 *
 *  Created on: 25 de Out de 2010
 *      Author: Jos� Pereira
 */

#ifndef HIPERMERCADO_H_
#define HIPERMERCADO_H_


#include "Produto.h"
#include "Fornecedor.h"
#include "Compra.h"
#include "Empregado.h"
#include "Produto.h"
#include "Camiao.h"
#include "Motorista.h"
#include "BST.h"
#include <string>
#include <vector>
#include <iostream>
#include <list>
#include <queue>
#include <algorithm>
#include <stack>
#include <sstream>


using namespace std;

class Hipermercado{

	string nome_hiper;
	vector<Empregado> empregados;
	vector<Compra> compras;
	BST<Motorista> motoristas;
	priority_queue<Camiao> frota_camioes;
	static long nulo;



public:
	/*
	 * Constructor de um objecto do tipo Hipermercado
	 * @name Hipermercado
	 * @param string nome_hiper
	 */
	Hipermercado(string nome_hiper);
	/*
	 * Destructor de um objecto do tipo Hipermercado
	 */
	~Hipermercado();

	vector<Produto> produtos;
	Motorista inicia_motorista();


	/*
	 * Get e set nome do hipermercado
	 */
	string get_nome() const;
	void set_nome(string nome_hiper_ant);

	/*
	 * Adders
	 */
	void adiciona_produto(Produto p1);
	void adiciona_empregado(Empregado emp1);
	void adiciona_compra(Compra comp1);
	void adiciona_fornecedor();

	/*
	 * Removers
	 */
	void remove_produto(string nome);
	void remove_empregado(string nome);
	void remove_compra(long codigo);
	void remove_fornecedor(string nome);

	/*
	 * Imprime o conteudo dos vectores que contem todos os produtos e a informa��o dos empregados
	 * @name imprime
	 */
	void imprime();

	/*
	 * Fun��es que guardam informa��o nos ficheiros de texto
	 */
	void guarda_empregados();
	void guarda_produtos();
	void fich_fornecedores();
	void guarda_compras();
	void guarda_motoristas();

	/*
	 * Fun��es que carregam informa��o dos ficheiros de texto
	 */
	void carrega_empregados();
	void carrega_produtos();
	void carrega_fornecedores();
	void carrega_compras();

	/*
	 * Fun��es de pesquisa em vectores que mediante a indica��o de um nome, devolvem um objecto com esse nome
	 */
	Empregado pesquisa_empregado(string nome);
	Produto pesquisa_produto(string nome);

	/*
	 * Listas com informa��o dos objectos
	 */
	void lista_nomes_empregados();
	void lista_nomes_produtos();
	void lista_empregados();
	void lista_produtos();
	void lista_forn();
	void lista_compras();

	/*
	 * Retorna o tamanho do vector de empregados
	 * @name vector_tam_empregados
	 * @return inteiro com o tamanho do vector
	 */
	int vector_tam_empregados() {return empregados.size();}

	/*
	* Retorna o tamanho do vector de produtos
	* @name vector_tam_produtos
	* @return inteiro com o tamanho do vector
	*/
	int vector_tam_produtos() {return produtos.size();}




	/*
	 * Retorna o numero de cami�es que existem na frota
	 * @name numCamioes
	 * @return inteiro com o tamanho
	 */
	int numCamioes() { return frota_camioes.size(); }

	/*
	 * Adiciona um cami�o � parte de tr�s da fila de prioridade "frota_camioes"
	 * @name adicionaCamiao
	 * @param Camiao& c1
	 * @return retorna um inteiro com o tamanho da frota
	 */
	int adicionaCamiao(Camiao& c1) { frota_camioes.push(c1); return frota_camioes.size(); }

	/*
	 * Remove um cami�o da parte da frente da fila de prioridade "frota_camioes"
	 * @name removeCamiao
	 * @return retorna um inteiro com o tamanho da frota
	 */
	int removeCamiao() {frota_camioes.pop(); return frota_camioes.size();}

	/*
	 * Procura um determinado Camiao passado como argumento na frota de cami�es e retorna-o
	 */
	Camiao procuraCamiao(Camiao& cam);

	/*
	 * Lista os cami�es juntamente com a sua informa��o que se encontram na frota
	 * @name lista_camioes
	 */
	void lista_camioes();

	/*
	 * Retorna o cami�o que tiver maior carga m�xima
	 */
	Camiao camiaoMaisCarga() const;

	/*
	 * Retorna o cami�o que tiver menor carga m�xima
	 */
	Camiao camiaoMenosCarga() const;




	/*
	 * Adiciona um motorista � �rvore binaria de pesquisa
	 * @name adiciona_motorista
	 * @param const Motorista & m1
	 */
	void adiciona_motorista(const Motorista & m1);

	/*
	 * Remove um motorista da �rvore binaria de pesquisa
	 * @name remove_motorista
	 * @param const Motorista & m1
	 */
	void remove_motorista(const Motorista & m1);

	/*
	 * Devolve uma string onde est�o listados todos os motoristas
	 * @name lista_motoristas
	 * @return devolve string com a informa��o
	 */
	string lista_motoristas();

	/*
	 * Lista os transportes efectuados por um determinado motorista entre dois dias, que est�o passados como argumentos
	 * @name lista_transp_dias
	 * @param Motorista m1
	 * @param int inf
	 * @param int sup
	 * @param ano
	 * @param mes
	 */
	void lista_transp_dias(Motorista m1,int inf,int sup,int ano,int mes);

	/*
	 * Lista todos os transportes efectuados entre dois dias que est�o passados como argumentos
	 * @name list_todos_transp_dias
	 * @param inf
	 * @param sup
	 * @param ano
	 * @param mes
	 */
	void list_todos_transp_dias(int inf,int sup,int ano,int mes);


	friend class Produto;
};


/**
 * Excep��es
 */

class ProdutoNaoEncontrado
{
public:
	string nome;
	ProdutoNaoEncontrado(string nome) {this->nome = nome;}
	string get_nome() {return nome;}

};

class EmpregadoNaoEncontrado
{
public:
	string nome;
	EmpregadoNaoEncontrado(string nome) {this->nome = nome;}
	string get_name() {return nome;}

};



#endif /* HIPERMERCADO_H_ */
