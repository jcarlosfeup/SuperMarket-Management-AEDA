/*
 * Camiao.cpp
 *
 *  Created on: 7 de Dez de 2010
 *      Author: Carlitos
 */

#include "Camiao.h"


Camiao::Camiao(string matricula,double carga_max,string tipo)
{
	this->matricula = matricula;
	this->carga_max = carga_max;
	this->tipo = tipo;
}

//Getters
string Camiao::get_matricula()
{
	return matricula;
}

double Camiao::get_cargamax() const
{
	return carga_max;
}

string Camiao::get_tipo(){
	return tipo;
}


//Setters

void Camiao::set_matricula(string n_matricula)
{
	this->matricula = n_matricula;
}

void Camiao::set_cargamax(double n_cargamax)
{
	this->carga_max = n_cargamax;
}

void Camiao::set_tipo(string n_tipo)
{
	this->tipo = n_tipo;
}


//Imprime informação sobre o camião

void Camiao::imprime(){

	cout << "Matricula: " << get_matricula() <<endl;
	cout << "Carga máxima: " << get_cargamax() <<endl;
	cout << "Tipo de produtos transportados: " << get_tipo() <<endl;
}

/*
 * Converte um objecto do tipo Matricula numa string de forma --/--/--

string Camiao::converte_matricula(Matricula m1)
{
	stringstream nova;
	nova << m1.esq << "-" << m1.meio << "-" <<m1.dir <<endl;

	return nova.str();
}*/

bool Camiao::operator<(const Camiao& c1) const
{
	if(carga_max < c1.carga_max)
		return true;
	else
		return false;
}

bool Camiao::operator==(const Camiao& c1) const
{
	if(c1.matricula == matricula)
		return true;
	else
		return false;
}

/*
 * Sub-classes
 */

Frigorifico::Frigorifico(string matricula,double carga_max,string tipo,double temperatura):Camiao(matricula,carga_max,tipo)
{
	this->temperatura = temperatura;
}

double Frigorifico::get_temper() const
{
	return temperatura;
}

void Frigorifico::set_temper(double temp)
{
	this->temperatura = temp;
}

void Frigorifico::imprime()
{
	Camiao::imprime();
	cout << "Temperatura: " << get_temper() <<endl;
}



Cisterna::Cisterna(string matricula,double carga_max,string tipo,string descr_prod):Camiao(matricula,carga_max,tipo)
{
	this->descr_prod = descr_prod;
}

string Cisterna::get_descr() const
{
	return descr_prod;
}

void Cisterna::set_descr(string desc)
{
	this->descr_prod = desc;
}

void Cisterna::imprime()
{
	Camiao::imprime();
	cout << "Descrição da mercadoria transportada: " << get_descr() <<endl;
}
