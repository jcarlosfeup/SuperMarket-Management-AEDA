/*
 * Produto.h
 *
 *  Created on: 20 de Out de 2010
 *      Author: José Pereira
 */

#ifndef PRODUTO_H_
#define PRODUTO_H_

#include <string>
#include <vector>
#include <iostream>
//#include <hash_set.h>
#include <ext/hash_set>
#include "Fornecedor.h"
#include "Empregado.h"


using namespace std;

class Produto {
protected:
	string nome;
	long codigo;
	string descricao;
	vector<Fornecedor> fornecedores;
	//Preço de venda pelo fornecedor
	float preco_pvenda;
	unsigned int quant_disp;
	//Preço de compra no hipermercado
	float preco_pcompra;
	int dias_embalado;


public:
	/*
	 * Constroi um objecto do tipo Produto
	 * @name Produto
	 * @param string nome
	 * @param long codigo
	 * @param string descricao
	 * @param float preco_pvenda
	 * @param float preco_pcompra
	 * @param unsigned int quant_disp
	 * @param int dias_embalado
	 */
	Produto(string nome, long codigo, string descricao, float preco_pvenda,
			float preco_pcompra, unsigned int quant_disp, int dias_embalado);

	/*
	 * Destrutor de um objecto do tipo Produto
	 */
	~Produto();

	/*
	 * Getters
	 */
	string get_nome() const;
	long get_cod() const;
	string get_descr();
	unsigned int get_quant_disp();
	int get_dias_embalado();
	float get_preco_vnd();
	float get_preco_cmp();

	/*
	 * Setters
	 */
	void set_nome(string nome_ant);
	void set_cod(long cod_ant);
	void set_descr(string desc_antiga);
	void set_quant_disp(unsigned int quant);
	void set_dias(int n_dias) {this->dias_embalado = n_dias;}
	void set_preco_venda(float n_preco) {this->preco_pvenda = n_preco;}
	void set_preco_compra(float n_preco) {this->preco_pcompra = n_preco;}


	/*
	 * Adiciona um fornecedor a um determinado Produto
	 * @name adiciona_fornecedores
	 * @param Fornecedor fornc1
	 */
	void adiciona_fornecedores(Fornecedor fornc1);

	/*
	 * Remove um fornecedor de um determinado produto
	 * @name remove_fornecedor
	 * @param string nome
	 */
	void remove_fornecedor(string nome);

	/*
	 * Guarda informação sobre os produtos num ficheiro de texto
	 * @name guarda_produtos
	 * @param string filename
	 */
	void guarda_produtos(string filename);

	/*
	 * Imprime informação sobre um determinado Produto
	 * @name imprime
	 *
	 */
	void imprime();

	/*
	 * Lista informação sobre os fornecedores
	 * @name lista_fornecedores
	 *
	 */
	void lista_fornecedores();
	void guarda_fornecedores();
	void get_forn_info();

	/*
	 * Pesquisa no vector de fornecedores um determinado fornecedor
	 * @name pesquisa_fornecedor
	 * @param string nome
	 * @return retorna o Fornecedor encontrado
	 */
	Fornecedor pesquisa_fornecedor(string nome);

	/*
	 * Mostra informação de um determinado Produto
	 * @bame <<
	 * @param ostream & o
	 * @param const Produto & p
	 *
	 */
	friend ostream & operator<<(ostream & o, const Produto & p);
	bool operator==(const Fornecedor f1);


};
const float PRECO_QUE_DEFINE_QUALIDADE = 10.0;
const int VALIDADE = 30;

class Prod_validade: public Produto {
public:
	Prod_validade();
	bool produto_c_validade(Produto prod);
};

/**
 * Excepções
 */

/*
 * Excepção produto sem qualidade
 */
class ProdutoSemQualidade {
public:
	float preco;
	ProdutoSemQualidade(float preco) {this->preco = preco;}
	float get_preco() {return preco;}
};

/*
 * Excepção fornecedor nao encontrado
 */
class FornecedorNaoEncontrado{
public:
	string nome;
		FornecedorNaoEncontrado(string nome) {this->nome = nome;}
		string get_name() {return nome;}
};
//*********************************************************************************************************

/**
 *
 * Classe dos produtos antigos
 *
 */


const int DOIS_ANOS = 730;


struct hprod {
	int operator() (Produto p) const {
		int v = 0;
		string s1 = p.get_nome();
		for (unsigned int i=0; i< s1.size(); i++)
			v = 37*v + s1[i];
		return v;
	}
};

struct eqprod {
	bool operator() (Produto p1,Produto p2) const {
		return p1.get_cod() == p2.get_cod();
	}
};

/**
 * creating a hash_table
 * @name tabelaprodutos
 * @return a hash_table
 */
/*
typedef hash_set<Produto,hprod,eqprod> HASH_PRODS;

class Produto_ant{

	HASH_PRODS tab_produtos;

public:

	Produto_ant();
	Produto_ant(string nome, long codigo, string descricao, float preco_pvenda,
			float preco_pcompra, unsigned int quant_disp, int dias_embalado);

	/**
	 * Insere um produto na hash table
	 * @name insere
	 * @param Produto & p
	 */
	/*void insere(Produto & p);

	/**
	* Retorna um vector de produtos que estão na hash table
	* @name getProdutos
	* @retorna um vector de produtos
	*/
	/*vector<Produto> getProdutos(){
		vector<Produto> temp;
		for(HASH_PRODS::iterator it = tab_produtos.begin();it!=tab_produtos.end();it++){
			temp.push_back(*it);
		}
		return temp;
	}

	/**
	 * procura nas tabela um determinado produto
	 * @name procura
	 * @param Produto & p
	 * @return o Produto encontrado
	 */
	/*Produto procura(Produto & p);

	/**
	 * remove um determinado produto da tabela
	 * @name remove
	 * @param Produto & p
	 */
	/*void remove(Produto & p);

	/**
	 * retorna a tabela de produtos antigos
	 * @name getTabela
	 * @return the hash table
	 */
	/*HASH_PRODS getTabela(){
		return tab_produtos;
	}

	/**
	 *	permite ao utilizador ver o conteudo da tabela
	 *@name operator<<
	 *@param ostream & out
	 *@param Produto_ant & p
	 *@return out
	 */
	/*friend ostream & operator<<(ostream & out, Produto_ant & p){
		HASH_PRODS copia = p.getTabela();
		for(HASH_PRODS::iterator it = copia.begin(); it!=copia.end();it++){
			out<<*it;
		}
		return out;
	}


	};


	*/





/**
 *
 *
 * Classe Transporte
 *
 *
 *
 */


class Transporte{

	vector<Produto> produtos;
	string tipo_produto;
	unsigned int quant;
	//Data do transporte
	int dia;
	int mes;
	int ano;

public:
	/*
	 * Constructor de um objecto do tipo Transporte
	 * @name Transporte
	 * @param vector<Produto> produtos
	 * @param string tipo_produto
	 * @param unsigned int quant
	 * @param int dia
	 * @param int mes
	 * @param int ano
	 */
	Transporte(vector<Produto> produtos,string tipo_produto,unsigned int quant,int dia,int mes,int ano);
	/*
	 * Getters
	 */
	string getTipo_produto() const {return tipo_produto;}
	unsigned int get_quant() const {return quant;}
	int get_dia() const {return dia;}
	int get_mes() const {return mes;}
	int get_ano() const {return ano;}
	vector<Produto> get_produto() const;

	/*
	 * Setters
	 */
	void setTipo_produto(string tipo);
	void set_quant(unsigned int nova_quant);
	void set_dia(int n_dia);
	void set_mes(int n_mes);
	void set_ano(int n_ano);

	/*
	 * Imprime informação sobre um determinado Trasporte
	 * @name imprime
	 */
	void imprime() const;

	/*
	 * Operador que permite determinar se se trata do mesmo transporte
	 * @name ==
	 * @param Transporte t1
	 * @return retorna verdadeiro ou falso
	 */
	bool operator==(Transporte t1) {return t1.tipo_produto == tipo_produto;}

};





#endif /* PRODUTO_H_ */

