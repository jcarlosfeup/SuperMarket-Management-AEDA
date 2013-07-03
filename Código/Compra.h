/*
 * Compra.h
 *
 *  Created on: 20 de Out de 2010
 *      Author: José Pereira
 */

#ifndef COMPRA_H_
#define COMPRA_H_

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "Produto.h"
#include "Fornecedor.h"
#include "Compra.h"
#include "Empregado.h"
#include "Produto.h"

using namespace std;


/**
 *  Classe Compra,regista uma compra efectuada no hipermercado
 *
 */

class Compra {
protected:
	long codigo_compra;
	int quant;
	Data data_comp;
	vector<Produto> carrinho;

public:
	/*
	 * Constructor de um objecto do tipo Compra
	 * @name Compra
	 * @param long codigo_compra
	 * @param int quant
	 * @param Data data_comp
	 */
	Compra(long codigo_compra, int quant, Data data_comp);

	/*
	 * Destructor de um objecto do tipo Compra
	 */
	virtual ~Compra();

	/**
	 * Getters
	 */
	long get_cod() const;
	int get_quant() const;

	/**
	 * Setters
	 */
	void set_cod(long cod_ant);
	void set_quant(unsigned int quant_ant);

	/*
	 * Imprime informação sobre uma determinada compra
	 * @name imprime
	 */
	void imprime() const;

	/**
	 * Funções de introdução e remoção de objectos do vector "carrinho".
	 */
	void adic_ao_carrinho(Produto p1);
	void remove_do_carrinho(long codigo);

	friend class Hipermercado;

};


#endif /* COMPRA_H_ */
