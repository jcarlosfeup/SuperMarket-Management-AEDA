/*
 * Compra.cpp
 *
 *  Created on: 20 de Out de 2010
 *      Author: José Pereira
 */

#include "Compra.h"

/**
 * Construtor da classe Compra
 * @param codigo_compra long do código da compra que se pretende "construir".
 * @param quant inteiro com a quantidade de produtos dessa compra.
 * @param data_comp obejecto do tipo Data que indica a data em que se efectuou a compra.
 * */
Compra::Compra(long codigo_compra, int quant, Data data_comp) {
	this->codigo_compra = codigo_compra;
	this->quant = quant;
	this->data_comp = data_comp;
}

/**
 * Destructor da classe Compra
 */
Compra::~Compra() {
}

/**
 * Funcao que acede ao atributo codigo_compra da classe Compra.
 * @return Retorna um long com o código da compra a que se acede.
 */
long Compra::get_cod() const {
	return codigo_compra;
}

/**
 * Funcao que acede ao atributo quant da classe Compra.
 * @return Retorna um int com a quantidade de produtos dessa compra.
 */
int Compra::get_quant() const {
	return quant;
}

/**
 * Funcao que modifica o atributo codigo_compra da classe Compra.
 * @param cod_ant long com o código que se pretende associar ao objecto do tipo Compra.
 */
void Compra::set_cod(long cod_ant)
{
	codigo_compra = cod_ant;
}


/**
 * Funcao que modifica o atributo quant da classe Compra.
 * @param quant_ant unsigned int com a quantidade a associar ao objecto do tipo Compra
 */
void Compra::set_quant(unsigned int quant_ant) {
	quant = quant_ant;
}

/**
 * Funcao que imprime no ecrã o valor dos atributos de objecto do tipo Compra
 */

void Compra::imprime() const {
	cout << "Codigo: " << get_cod() << endl;
	cout << "Quantidade: " << get_quant() << endl;
}

/**
 * Função que adiciona ao vector de produtos "carrinho" um novo produto.
 * @param p1 objecto do tipo Produto que vai ser adicionado ao vector
 */
void Compra::adic_ao_carrinho(Produto p1) {
	int tam_vec = carrinho.size();
	for (int i = 0; i < tam_vec; i++) {
		if (p1.get_cod() == carrinho[i].get_cod())
			return;
		else
			carrinho.push_back(p1);
	}
}

/**
 * Função que remove do vector de produtos "carrinho" um produto.
 * @param codigo long que indica o código do produto que se pretende remover do carrinho.
 */
void Compra::remove_do_carrinho(long codigo) {
	int tam_vec = carrinho.size();
	for (int i = 0; i < tam_vec; i++) {
		if (carrinho[i].get_cod() == codigo)
			carrinho.erase(carrinho.begin() + i);
	}
}
