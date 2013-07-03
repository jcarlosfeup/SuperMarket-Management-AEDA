/*
 * Fornecedor.cpp
 *
 *  Created on: 13 de Out de 2010
 *      Author: José Pereira
 */

#include "Fornecedor.h"

using namespace std;

Fornecedor::Fornecedor(string nome, string morada,string localidade,long nif,string tipo_produto)
{
	this->nome = nome;
	this->morada = morada;
	this->nif = nif;
	this->localidade = localidade;
	this->tipo_produto = tipo_produto;
}

Fornecedor::~Fornecedor()
{
}

string Fornecedor::get_name()
{
	return nome;
}


void Fornecedor::set_name(string nome_ant)
{
	nome = nome_ant;
}

string Fornecedor::get_morada()
{
	return morada;
}

void Fornecedor::set_morada(string morada_ant)
{
	morada = morada_ant;
}

string Fornecedor::get_localidade()
{
	return localidade;
}

void Fornecedor::set_localidade(string loc_ant)
{
	localidade = loc_ant;
}

long Fornecedor::get_nif() const
{
	return nif;
}

void Fornecedor::set_nif(long nif_ant)
{
	nif = nif_ant;
}

string Fornecedor::get_tipo_produto()
{
	return tipo_produto;
}

void Fornecedor::set_tipo(string tipo_prod)
{
	tipo_produto = tipo_prod;
}

void Fornecedor::imprime_tudo()
{
	cout << "Nome do fornecedor: " << get_name() <<endl;
	cout << "Morada: " << get_morada() <<endl;
	cout << "Localidade: " << get_localidade() <<endl;
	cout << "Tipo de produtos que o fornecedor " << get_name() << " vende: " << get_tipo_produto() <<endl;
}





