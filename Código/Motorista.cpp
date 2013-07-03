/*
 * Motorista.cpp
 *
 *  Created on: 22 de Dez de 2010
 *      Author: Carlitos
 */

#include "Motorista.h"



Motorista::Motorista(string nome,long bi,double salario,queue<Transporte> transp_efectuados)
{
	this->nome = nome;
	this->bi = bi;
	this->salario = salario;
	this->transp_efectuados = transp_efectuados;
}

//Getters

string Motorista::get_nome() const
{
	return nome;
}

long Motorista::get_bi() const
{
	return bi;
}

double Motorista::get_salario() const
{
	return salario;
}


//Setters

void Motorista::set_nome(string novo)
{
	this->nome = novo;
}

void Motorista::set_bi(long novo)
{
	this->bi = novo;
}

void Motorista::set_salario(double novo)
{
	this->salario = novo;
}

queue<Transporte> Motorista::get_transportes() const
{
	queue<Transporte> transp_efectuados;

	return transp_efectuados;
}

void Motorista::adiciona_transporte(Transporte t1)
{
	transp_efectuados.push(t1);
}

void Motorista::remove_transporte(Transporte t1)
{
	while(!transp_efectuados.empty())
	{
		Transporte pri = transp_efectuados.front();
		transp_efectuados.pop();
		if(t1 == pri)
			return;
		else
			transp_efectuados.pop();

	}
}

void Motorista::lista_transportes()
{
	while(!transp_efectuados.empty())
	{
		Transporte t1 = transp_efectuados.front();
		cout << "Tipo de produto: " << t1.getTipo_produto() <<endl;
		cout << "Quantidade: " << t1.get_quant() <<endl;
		cout << "Data: " << t1.get_dia() << "/" << t1.get_mes() << "/" << t1.get_ano() <<endl;
	}
}





//Imprime dados do motorista
void Motorista::imprime() const
{
	cout << "Nome: " << get_nome() <<endl;
	cout << "BI: " << get_bi() <<endl;
	cout << "Salario: " << get_salario() <<endl;

}
