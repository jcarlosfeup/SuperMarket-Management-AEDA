/*
 * Camiao.h
 *
 *  Created on: 7 de Dez de 2010
 *      Author: Jos� Pereira
 */


#ifndef CAMIAO_H_
#define CAMIAO_H_
#include <string>
#include <sstream>
#include <queue>
#include <iostream>


using namespace std;


class Camiao{

	string matricula;
	double carga_max;
	string tipo;  //transporte produtos frios, transporte produtos perigosos,etc...

public:


	/*
	 * Constroi um objecto do tipo cami�o
	 * @name Camiao
	 * @param string matricula
	 * @param carga_max
	 * @string tipo
	 */
	Camiao(string matricula,double carga_max,string tipo);

	/*
	 * Getters
	 */
	string get_matricula();
	double get_cargamax() const;
	string get_tipo();

	/*
	 * Setters
	 */
	void set_matricula(string n_matricula);
	void set_cargamax(double n_cargamax);
	void set_tipo(string n_tipo);

	/*
	 * Imprime informa��o sobre um determinado Camiao
	 * @name imprime
	 */
	virtual void imprime();

	//Converte uma matricula na forma de uma string
	//string converte_matricula(Matricula m1);

	/*
	 * Operador que permite ordenar os cami�es por carga m�xima
	 * @name <
	 * @param const Camiao& c1
	 * @return retorna verdadeiro ou falso
	 */
	bool operator<(const Camiao& c1) const;

	/*
	* Operador que permite determinar se dois camioes s�o o mesmo
	* @name ==
	* @param const Camiao& c1
	* @return retorna verdadeiro ou falso
	*/
	bool operator==(const Camiao& c1) const;
};

/**
 *
 * Sub-Classes
 *
 */

class Frigorifico: public Camiao
{
	/*
	 * Temperatura no reboque de um cami�o de transporte de produtos frios
	 */
	double temperatura;

public:
	Frigorifico(string matricula,double carga_max,string tipo,double temperatura);
	double get_temper() const;
	void set_temper(double temp);
	void imprime();
};

class Cisterna: public Camiao
{
	/*
	 * Descri��o do tipo de mercadoria que leva esse cami�o de tranporte de materiais perigosos ex: gasolina
	 */
	string descr_prod;
public:
	Cisterna(string matricula,double carga_max,string tipo,string descr_prod);
	string get_descr() const;
	void set_descr(string desc);
	void imprime();
};



#endif /* CAMIAO_H_ */
