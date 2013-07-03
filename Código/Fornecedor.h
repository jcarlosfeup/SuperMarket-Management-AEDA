/*
 * Fornecedor.h
 *
 *  Created on: 13 de Out de 2010
 *      Author:  José Pereira
 */

#ifndef FORNECEDOR_H_
#define FORNECEDOR_H_

#include <string>
#include <vector>
#include <iostream>
using namespace std;


class Fornecedor{
public:
	string nome;
	string morada;
	string localidade;
	long nif;
	//Tipo de produto que o fornecedor vende
	string tipo_produto;

	/*
	 * Constructor de um objecto do tipo Fornecedor
	 * @name Fornecedor
	 * @param string nome
	 * @param string morada
	 * @param string localidade
	 * @param long nif
	 * @param string tipo_produto
	 */
	Fornecedor(string nome, string morada,string localidade,long nif,string tipo_produto);

	/*
	 * Destructor de um objecto do tipo Fornecedor
	 */
	~Fornecedor();

	/*
	 * Getters
	 */
	string get_name();
	string get_morada();
	string get_localidade();
	long get_nif() const;
	string get_tipo_produto();

	/*
	 * Setters
	 */
	void set_name(string nome_ant);
	void set_morada(string morada_ant);
	void set_localidade(string loc_ant);
	void set_nif(long nif_ant);
	void set_tipo(string tipo_prod);

	/*
	 * Imprime informação sobre um determinado Fornecedor
	 * @name imprime_tudo
	 */
	void imprime_tudo();
};




#endif /* FORNECEDOR_H_ */
