/*
 * Produto.cpp
 *
 *  Created on: 20 de Out de 2010
 *      Author: José Pereira
 */

#include "Produto.h"


ostream & operator<<(ostream & o,Produto & p)
{
	o << "Nome: " << p.get_nome() <<endl;
	o << "Código do produto: " << p.get_cod() <<endl;
	o << "Descrição: " <<p.get_descr() <<endl;
	o << "Nº de dias embalado: " << p.get_dias_embalado() <<endl;
	o << "Preço de compra: " << p.get_preco_cmp() <<endl;
	o << "Preço de venda: " << p.get_preco_vnd() <<endl;
	o << "Quantidade: " << p.get_quant_disp() <<endl;

	return o;
}


Produto::Produto(string nome, long codigo, string descricao,
		float preco_pvenda, float preco_pcompra, unsigned int quant_disp,
		int dias_embalado) {
	this->nome = nome;
	this->codigo = codigo;
	this->descricao = descricao;
	this->preco_pvenda = preco_pvenda;
	//averigua consoante o preço de compra se o produto tem qualidade ou não,se não tiver lança uma excepção
	if (preco_pcompra > PRECO_QUE_DEFINE_QUALIDADE)
		this->preco_pcompra = preco_pcompra;
	else
		throw ProdutoSemQualidade(preco_pcompra);

	this->quant_disp = quant_disp;
	this->dias_embalado = dias_embalado;
}

Prod_validade::Prod_validade() :
	Produto(nome, codigo, descricao, preco_pvenda, preco_pcompra, quant_disp,
			dias_embalado) {

}

Produto::~Produto() {
}

string Produto::get_nome() const {
	return nome;
}

void Produto::set_nome(string nome_ant) {
	nome = nome_ant;
}

long Produto::get_cod() const {
	return codigo;
}

void Produto::set_cod(long cod_ant) {
	codigo = cod_ant;
}

string Produto::get_descr() {
	return descricao;
}
void Produto::set_descr(string desc_antiga) {
	desc_antiga = descricao;
}

unsigned int Produto::get_quant_disp() {
	return quant_disp;
}

void Produto::set_quant_disp(unsigned int quant) {
	quant = quant_disp;
}

int Produto::get_dias_embalado() {
	return dias_embalado;
}

float Produto::get_preco_cmp() {
	return preco_pcompra;
}

float Produto::get_preco_vnd() {
	return preco_pvenda;
}
void Produto::imprime() {
	cout << "Nome do produto: " << get_nome() << endl;
	cout << "Código: " << get_cod() << endl;
	cout << "Descrição do produto: " << get_descr() << endl;
	cout << "Quantidade de produtos disponiveis: " << get_quant_disp() << endl;
	cout << "Nº dias desde que o produto foi embalado: " << get_dias_embalado()
			<< endl;
	cout << "Preço de compra ao fornecedor: " << get_preco_cmp() << endl;
	cout << "Preço de venda ao cliente: " << get_preco_vnd() << endl;
}

void Produto::adiciona_fornecedores(Fornecedor fornc1) {
	int tam_vec = fornecedores.size();
	for (int i = 0; i < tam_vec; i++) {
		if (fornc1.get_name() == fornecedores[i].get_name()) //quer dizer que esse empregado já se encontra no vector
			return;
		else

			fornecedores.push_back(fornc1);
	}
}

void Produto::remove_fornecedor(string nome) {
	int tam_vec = fornecedores.size();
	for (int i = 0; i < tam_vec; i++) {
		if (fornecedores[i].nome == nome)
			fornecedores.erase(fornecedores.begin() + i);
		cout << "Nao quero mais os seus produtos!" << endl;
	}
}

bool Prod_validade::produto_c_validade(Produto prod) {
	int dias = prod.get_dias_embalado();
	if (dias <= VALIDADE)
		return true;
	else
		return false;
}

void Produto::lista_fornecedores() {
	int tam = fornecedores.size();
	for (int i = 0; i < tam; i++) {
		cout << "Nome: " << fornecedores[i].get_name() << endl;
		cout << "NIF: " << fornecedores[i].get_nif() << endl;
		cout << "Morada: " << fornecedores[i].get_morada() << endl;
		cout << "Localidade: " << fornecedores[i].get_localidade() << endl;
		cout << "Tipo de produto para venda: "
				<< fornecedores[i].get_tipo_produto() << endl;
	}
}

void Produto::guarda_fornecedores() {
	int i = 0;
	int tam = fornecedores.size();
	ofstream myfile("Fornecedores.txt");
	if (myfile.is_open()) {
		while (i < tam) {
			myfile << fornecedores[i].get_name() << endl;
			myfile << fornecedores[i].get_nif() << endl;
			myfile << fornecedores[i].get_morada() << endl;
			myfile << fornecedores[i].get_localidade() << endl;
			myfile << fornecedores[i].get_tipo_produto() << endl;
			i++;
		}
		myfile.close();

	}
}

void Produto::get_forn_info() {
	int tam = fornecedores.size();
	for (int i = 0; i < tam; i++) {
		fornecedores[i].get_name();
		fornecedores[i].get_nif();
		fornecedores[i].get_morada();
		fornecedores[i].get_localidade();
		fornecedores[i].get_tipo_produto();
	}
}

Fornecedor Produto::pesquisa_fornecedor(string nome) {
	int tam = fornecedores.size();
	for (int i = 0; i < tam; i++) {
		if (fornecedores[i].get_name() == nome)
			return fornecedores[i];
		else
			throw FornecedorNaoEncontrado(nome);
	}
}

/**
 *
 * Classe Produto_ant
 *
 */

Produto_ant::Produto_ant(){
}



Produto_ant::Produto_ant(string nome, long codigo, string descricao, float preco_pvenda,
		float preco_pcompra, unsigned int quant_disp, int dias_embalado)
{

	Produto tmp(nome,codigo,descricao,preco_pvenda,preco_pcompra,quant_disp,dias_embalado);
	if(tmp.get_dias_embalado() >= DOIS_ANOS)
		tab_produtos.insert(tmp);

}
void Produto_ant::insere(Produto & p){
	HASH_PRODS::iterator it = tab_produtos.find(p);
	while(it != tab_produtos.end()){
		if((*it) != p && p.get_dias_embalado() >= DOIS_ANOS)
			tab_produtos.insert(p);

		it++;
	}
}


Produto Produto_ant::procura(Produto & p)
{

	HASH_PRODS::iterator it = tab_produtos.find(p);
	while(it != tab_produtos.end()){
		if((*it) == p)
			return *it;
}
}



void Produto_ant::remove(Produto & p)
{

	HASH_PRODS::iterator it = tab_produtos.find(a);
	if(it != tabela.end()){

		tabela.erase(it);
	}

}


Transporte::Transporte(vector<Produto> produtos,string tipo_produto,unsigned int quant,int dia,int mes,int ano)
{
	this->produtos = produtos;
	this->tipo_produto = tipo_produto;
	this->quant = quant;
	this->dia = dia;
	this->mes = mes;
	this->ano = ano;
}

//Setters

void Transporte::setTipo_produto(string tipo)
{
	tipo_produto = tipo;
}

void Transporte::set_quant(unsigned int nova_quant)
{
	quant = nova_quant;
}


void Transporte::set_dia(int n_dia)
{
	dia = n_dia;
}

void Transporte::set_mes(int n_mes)
{
	mes = n_mes;
}

void Transporte::set_ano(int n_ano)
{
	ano = n_ano;
}

vector<Produto> Transporte::get_produto() const
{
	vector<Produto> produtos;

	return produtos;
}


void Transporte::imprime() const
{
	vector<Produto> prods = get_produto();
	cout << "Tipo de produto: " << getTipo_produto() <<endl;
	cout << "Quantidade: " << get_quant()<<endl;
	cout << "Dia do transporte: " << get_dia() << "/" << get_mes() << "/" << get_ano() <<endl;
	cout << "Informação sobre o produto transportado: ";
	int tam = prods.size();
	for(int i = 0;i < tam;i++)
	{
		prods[i].imprime();
	}

}





