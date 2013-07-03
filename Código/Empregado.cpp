/*
 * Empregado.cpp
 *
 *  Created on: 13 de Out de 2010
 *      Author: José Pereira e Diogo Vaz
 */


#include "Empregado.h"

using namespace std;

Empregado::Empregado(string nome,string data_nasc,string cargo,float vencimento,unsigned int n_horas_dia)
{
	this->nome = nome;
	this->cargo = cargo;
	this->vencimento = vencimento;
	this->n_horas_dia= n_horas_dia;
	this->data_nasc = data_nasc;


}


Limpeza::Limpeza(string nome,string data_nasc,string cargo,float vencimento,unsigned int n_horas_dia,string divisao):Empregado(nome,data_nasc,cargo,vencimento,n_horas_dia)
{
	this->divisao = divisao;
}


Prateleiras::Prateleiras(string nome,string data_nasc,string cargo,float vencimento,unsigned int n_horas_dia,string divisao):Empregado(nome,data_nasc,cargo,vencimento,n_horas_dia)
{
	this->divisao = divisao;
}

Caixas::Caixas(string nome,string data_nasc,string cargo,float vencimento,unsigned int n_horas_dia): Empregado(nome,data_nasc,cargo,vencimento,n_horas_dia)
{

}
Empregado::~Empregado()
{
}

Limpeza::~Limpeza()
{
}

Prateleiras::~Prateleiras()
{
}

Caixas::~Caixas()
{
}

string Empregado::get_name()
{
	return nome;
}

void Empregado::set_name(string nome_ant)
{
	nome_ant = nome;
}

int Empregado::get_n_horas_dia()
{
	return n_horas_dia;
}

void Empregado::set_n_horas_dia(int horas_ant)
{
	horas_ant = n_horas_dia;
}
/*
string Empregado::show_Data(Data data_nasc)
{
	cout << data_nasc.dia << "/" << data_nasc.mes << "/" << data_nasc.ano;

	return 0;
}
*/
void Empregado::set_datanasc(string data_ant)
{
	data_nasc = data_ant;
}

string Empregado::get_datanasc() const
{
	return data_nasc;
}

string Empregado::get_cargo()
{
	return cargo;
}

void Empregado::set_cargo(string cargo_ant)
{
	cargo = cargo_ant;
}


float Empregado::get_vencimento()
{
	return vencimento;
}

void Empregado::set_vencimento(float vencimento_ant)
{
	vencimento = vencimento_ant;
}

void Empregado::imprime()
{
	cout << "Nome: " << get_name() <<endl;
	cout << "Data de nascimento: " << get_datanasc() <<endl;
	cout << "Cargo do empregado: " << get_cargo() <<endl;
	cout << "Vencimento do empregado: " << get_vencimento() <<endl;
	cout << "Numero de horas de trabalho por dia: " << get_n_horas_dia() <<endl;
}

void Empregado::guarda_fornecedores()
{
	int i = 0;
	int tam = fornecedores.size();
	ofstream myfile("Fornecedores.txt");
	if(myfile.is_open())
	{
		while(i < tam)
		myfile << fornecedores[i]->get_name() << endl;
		myfile << fornecedores[i]->get_morada() << endl;
		myfile << fornecedores[i]->get_localidade() <<endl;
		myfile << fornecedores[i]->get_nif() <<endl;
		myfile << fornecedores[i]->get_tipo_produto() << endl;
		i++;
	}

}

void Empregado::show_fornecedores() const
{
	int tam = fornecedores.size();
	for(int i = 0;i < tam;i++)
	{
		fornecedores[i]->imprime_tudo();
	}
}




void Empregado::adiciona_fornecedores(Fornecedor *fornc1)
{
	int tam_vec = fornecedores.size();
		for(int i = 0;i < tam_vec;i++)
			{
				if(fornc1->get_name() == fornecedores[i]->get_name() ) //quer dizer que esse empregado já se encontra no vector
					return;
				else

					fornecedores.push_back(fornc1);
			}}


void Empregado::remove_fornecedor(string nome)
{
	int tam_vec = fornecedores.size();
		for(int i = 0;i < tam_vec;i++)
			{
			if(fornecedores[i]->get_name() == nome)
				fornecedores.erase(fornecedores.begin() + i);

}
}
/*
string Empregado::convert_data_to_string(Data d)
{
	stringstream data_string;
	data_string << d.dia << "/" << d.mes << "/" << d.ano;

	return data_string.str();
}
*/

string Limpeza::get_divisao()
{
	return divisao;
}

void Limpeza::imprime()
{
	Empregado::imprime();
	cout << "Empregado de limpeza da divisão: "  << get_divisao() <<endl;
}

string Prateleiras::get_divisao()
{
	return divisao;
}

void Prateleiras::imprime()
{
	Empregado::imprime();
	cout << "Empregado das prateleiras da divisão: "  << get_divisao() <<endl;
}

void Caixas::imprime()
{
	Empregado::imprime();
}
