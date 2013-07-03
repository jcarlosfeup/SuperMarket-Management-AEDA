/*
 * Empregado.h
 *
 *  Created on: 13 de Out de 2010
 *      Author: José Pereira
 */

#ifndef EMPREGADO_H_
#define EMPREGADO_H_

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include "Fornecedor.h"

using namespace std;


struct Data
{
	int dia;
	int mes;
	int ano;

};

class Empregado {
protected:
	string nome;
	string data_nasc;
	string cargo;
	float vencimento;
	unsigned int n_horas_dia;
	vector<Fornecedor*> fornecedores;


public:
	/**
	 * constroi um objecto do tipo Empregado
	 * @name Empregado
	 * @param string nome
	 * @param string data_nasc
	 * @param string cargo
	 * @param float vencimento
	 * @param unsigned int n_horas_dia
	 */
	Empregado(string nome,string data_nasc,string cargo,float vencimento,unsigned int n_horas_dia);

	virtual ~Empregado();

	/**
	 * Getters
	 */
	string get_name();
	int get_n_horas_dia();
	//string show_Data(Data data_nasc);
	string get_datanasc() const;
	string get_cargo();
	float get_vencimento();

	/**
	 * Setters
	 */
	void set_name(string nome_ant);
	void set_n_horas_dia(int horas_ant);
	void set_cargo(string cargo_ant);
	void set_vencimento(float vencimento_ant);
	void set_datanasc(string data_ant);

	/**
	 * adiciona um fornecedor ao vector de fornecedores que cada Produto tem
	 * @name adiciona_fornecedores
	 * @param Fornecedor *fornc1
	 */
	void adiciona_fornecedores(Fornecedor *fornc1);

	/**
	* remove um fornecedor do vector de fornecedores que cada Produto tem
	* @name remove_fornecedor
	* @param string nome
	*/
	void remove_fornecedor(string nome);

	/**
	 * carrega a informação de vários fornecedores que se encontra num ficheiro de texto
	 * @name carrega_fornecedores
	 * @param string filename
	 */
	void carrega_fornecedores(string filename);

	/**
	 * guarda a informação de vários fornecedores que se encontra num vector de fornecedores
	 * @name guarda_fornecedores
	 */
	void guarda_fornecedores();

	/**
	 * imprime a informação de todos os fornecedores que se encontram no vector
	 * @name show_fornecedores
	 */
	void show_fornecedores() const;

	/**
	 * imprime os dados de um determinado Fornecedor
	 * @name imprime
	 */
	virtual void imprime();

	//string convert_data_to_string(Data d);
};

/**
 * Sub-Classes
 */

class Limpeza : public Empregado{
protected:
	string divisao;   //por exemplo divisão das frutas, electrodomésticos,etc...
public:
	Limpeza(string nome,string data_nasc,string cargo,float vencimento,unsigned int n_horas_dia,string divisao);
	~Limpeza();
	string get_divisao();
	void imprime();

};
class Prateleiras: public Empregado{
protected:
	string divisao;
public:
	Prateleiras(string nome,string data_nasc,string cargo,float vencimento,unsigned int n_horas_dia,string divisao);
	~Prateleiras();
	string get_divisao();
	void imprime();

};

class Caixas: public Empregado{
public:
	Caixas(string nome,string data_nasc,string cargo,float vencimento,unsigned int n_horas_dia);
	~Caixas();
	void imprime();
};


#endif /* EMPREGADO_H_ */
