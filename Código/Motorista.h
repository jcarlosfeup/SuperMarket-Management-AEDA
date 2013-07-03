/*
 * Motorista.h
 *
 *  Created on: 22 de Dez de 2010
 *      Author: José Pereira
 */

#ifndef MOTORISTA_H_
#define MOTORISTA_H_


#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include "Produto.h"


using namespace std;

/**
 * class Motorista cria um objecto do tipo motorista de camiões
 *
 * @param string nome
 * @param long bi
 * @param double salario
 * @param queue<Transporte> transp_efecutados
 */
class Motorista{

	string nome;
	long bi;
	double salario;
	queue<Transporte> transp_efectuados;

public:
	/**
	 * cria um novo Motorista
	 * @name Motorista
	 * @param string nome
	 * @param long bi
	 * @param double salario
	 * @param queue<Transporte> transp_efecutados
	 *
	 */
	Motorista(string nome,long bi,double salario,queue<Transporte> transp_efectuados);

	/**
	 * Getters
	 */
	string get_nome() const;
	long get_bi() const;
	double get_salario() const;
	queue<Transporte> get_transportes() const;

	/**
	 * Setters
	 */
	void set_nome(string novo);
	void set_bi(long novo);
	void set_salario(double novo);

	/**
	 * imprime dados sobre um Motorista
	 * @name imprime
	 */
	void imprime() const;

	/**
	* lista os transportes efecutados por um determinado Motorista
	* @name lista_transportes
	*/
	void lista_transportes();

	/**
	* adiciona um transporte á fila de transportes que cada Motorista tem
	* @name adiciona_transporte
	* @param Transporte t1
	*/
	void adiciona_transporte(Transporte t1);

	/**
	* remove um transporte da fila de transportes que cada Motorista tem
	* @name remove_transporte
	* @param Transporte t1
	*/
	void remove_transporte(Transporte t1);

	/**
	* operador que compara o numero de BI de dois motoristas
	* @name operator<
	* @param const Motorista & m1
	* @return retorna verdadeiro ou falso
	*/
	bool operator<(const Motorista & m1) {return m1.bi < bi;}

};



#endif /* MOTORISTA_H_ */
