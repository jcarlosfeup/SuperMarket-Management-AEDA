/*
 * Hipermercado.cpp
 *
 *  Created on: 25 de Out de 2010
 *      Author: José Pereira
 */

#include "Hipermercado.h"


long Hipermercado::nulo = 0;

//Motorista(string nome,long bi,double salario,queue<Transporte> transp_efectuados);
Motorista MNULL = Motorista("",0,0.0,NULL);


/**
 * Construtor da classe Hipermercado
 * @param nome_hiper Nome do Hipermercado.
 * */
Hipermercado::Hipermercado(string nome_hiper):motoristas(MNULL) {
	this->nome_hiper = nome_hiper;
}

/**
 * Destructor da classe Hipermercado
 * */
Hipermercado::~Hipermercado() {
}

/**
 * Funcao que acede ao atributo nome_hiper da classe Hipermercado.
 * @return Retorna uma string com o nome do Hipermercado a que se acede.
 */
string Hipermercado::get_nome() const {
	return nome_hiper;
}

/**
 * Funcao que modifica o atributo nome_hiper da classe Hipermercado.
 * @param nome_hiper_ant String com nome a associar ao Hipermercado.
 */
void Hipermercado::set_nome(string nome_hiper_ant) {
	nome_hiper = nome_hiper_ant;
}

/**
 * Funcao que adiciona um objecto do tipo Empregado ao vector de empregados do Hipermercado.
 * @param emp1 Objecto do tipo Empregado
 */
void Hipermercado::adiciona_empregado(Empregado emp1) {
	int tam_vec = empregados.size();
	if (empregados.size() == 0)
		empregados.push_back(emp1);
	else {

		for (int i = 0; i < tam_vec; i++) {
			if (emp1.get_name() == empregados[i].get_name()) //quer dizer que esse empregado já se encontra no vector
				return;
			else

				empregados.push_back(emp1);
		}
	}
}

/**
 * Funcao que remove um objecto do tipo Empregado do vector de empregados do Hipermercado.
 * @param nome string pertencente ao empregado que se pretender remover
 */
void Hipermercado::remove_empregado(string nome) {
	int tam_vec = empregados.size();
	for (int i = 0; i < tam_vec; i++)
		if (empregados[i].get_name() == nome)
			empregados.erase(empregados.begin() + i);

}
void Hipermercado::adiciona_compra(Compra comp1) {
	int tam = compras.size();
	if (compras.size() == 0)
		compras.push_back(comp1);
	else {

		for (int i = 0; i < tam; i++) {
			if (comp1.get_cod() == compras[i].get_cod()) //quer dizer que esse empregado já se encontra no vector
				return;
			else

				compras.push_back(comp1);
		}
	}
}

void Hipermercado::remove_compra(long codigo) {
	int tam_vec = compras.size();
	for (int i = 0; i < tam_vec; i++) {
		if (compras[i].get_cod() == codigo)
			compras.erase(compras.begin() + i);

	}
}

void Hipermercado::adiciona_produto(Produto p1) {
	int tam_vec = produtos.size();
	if(produtos.size() == 0)
		produtos.push_back(p1);
	else{


	for (int i = 0; i < tam_vec; i++) {
		if (p1.get_nome() == produtos[i].get_nome()) //quer dizer que esse empregado já se encontra no vector
			return;
		else
			produtos.push_back(p1);
	}
}
}

void Hipermercado::remove_produto(string nome) {
	int tam_vec = produtos.size();
	for (int i = 0; i < tam_vec; i++) {
		if (produtos[i].get_nome() == nome)
			produtos.erase(produtos.begin() + i);

	}
}

void Hipermercado::imprime() {
	int tam1 = produtos.size();
	int tam2 = empregados.size();
	for (int i = 0; i < tam1; i++) {
		cout << "Produtos: ";
		produtos[i].imprime();
		cout << endl;
	}
	for (int i = 0; i < tam2; i++) {
		cout << "Empregados: ";
		empregados[i].imprime();
		cout << endl;
	}
}




void Hipermercado::carrega_empregados(){

ifstream file;
string filename = "Empregados.txt";
empregados.clear();
file.open(filename.c_str(), fstream::in);
if (file.is_open()) {
	string nome,cargo,data_nasc;
	float vencimento;
	unsigned int n_horas_dia;
	cout << endl << "Ficheiro Aberto" <<endl <<endl;
	int i = 1;
	while (!file.eof()) {
		cout << " Ciclos dentro do while " << i << endl;
		file >> nome;
		file >> data_nasc;
		file >> cargo;
		file >> vencimento;
		file >> n_horas_dia;
		empregados.push_back(Empregado(nome,data_nasc,cargo,vencimento,n_horas_dia));
		i++;

	}
	cout << "Vector empregados dentro do carrega " << empregados.size() << endl;
		//file >> next_name;
		//empregados[empregados.size() - 1].set_name(next_name);
		file.close();
//}
	//else
		//cout << " " <<endl;
}
}

void Hipermercado::carrega_produtos() {

	ifstream file;
	string filename = "Produtos.txt";
	produtos.clear();
	file.open(filename.c_str(), fstream::in);
	if (file.is_open()) {
		string nome_pro,descr;
		long cod;
		unsigned int quant;
		float preco_v,preco_c;
		int dias_emb, i= 1;
		while (!file.eof()) {
			cout << " Ciclos dentro do while " << i << endl;
			file >> nome_pro;
			file >> cod;
			file >> quant;
			file >> descr;
			file >> dias_emb;
			file >> preco_v;
			file >> preco_c;


			produtos.push_back(Produto(nome_pro,cod,descr,preco_v,preco_c,quant,dias_emb));
			i++;
}

			file.close();
	//}
		//else
			//cout << " " <<endl;
}
}

void Hipermercado::guarda_empregados() {
	int i = 0;
	int tam = empregados.size();
	ofstream myfile("Empregados.txt",ios_base::trunc);
	if (myfile.is_open()) {
		while (i < tam) {
			myfile << empregados[i].get_name() << endl;
			myfile << empregados[i].get_datanasc() <<endl;
			myfile << empregados[i].get_cargo() << endl;
			myfile << empregados[i].get_vencimento() << endl;
			if (i == tam-1) myfile << empregados[i].get_n_horas_dia();
			else myfile << empregados[i].get_n_horas_dia() << endl;
			i++;
		}
		myfile.close();

	}
}


void Hipermercado::guarda_produtos() {
	int i = 0;
	int tam = produtos.size();
	ofstream myfile("Produtos.txt",ios_base::trunc);
	if (myfile.is_open()) {
		while (i < tam) {
			myfile << produtos[i].get_nome() <<endl;
			myfile << produtos[i].get_cod() << endl;
			myfile << produtos[i].get_quant_disp() << endl;
			myfile << produtos[i].get_descr() << endl;
			myfile << produtos[i].get_dias_embalado() << endl;
			myfile << produtos[i].get_preco_vnd() << endl;
			if (i == tam-1) myfile << produtos[i].get_preco_cmp();
			else myfile << produtos[i].get_preco_cmp() << endl;
			i++;
		}
		myfile.close();
}
}

void Hipermercado::guarda_compras() {
	int i = 0;
	int tam = compras.size();
	ofstream myfile("Compras.txt");
	if (myfile.is_open()) {
		while (i < tam) {
			myfile << compras[i].get_cod() << endl;
			myfile << compras[i].get_quant() << endl;

			i++;
		}
		myfile.close();

	}
}

void Hipermercado::fich_fornecedores() {
	int tam = produtos.size();
	for (int i = 0; i < tam; i++) {
		produtos[i].guarda_fornecedores();
	}
}

void Hipermercado::lista_empregados() {

	int tam_emp = empregados.size();
	if(tam_emp == 0)
		cout << "VECTOR VAZIO!" <<endl;
	for (int i = 0; i < tam_emp; i++) {
		cout << "Nome: " << empregados[i].get_name() << endl;
		cout << "Data de nascimento: " << empregados[i].get_datanasc() <<endl;
		cout << "Cargo: " << empregados[i].get_cargo() << endl;
		cout << "Vencimento: " << empregados[i].get_vencimento() << endl;
		cout << "Nº de horas trabalho: " << empregados[i].get_n_horas_dia()<< endl << endl << endl;
	}
}

void Hipermercado::lista_produtos() {
	int tam_prod = produtos.size();
	if(tam_prod == 0)
		cout << "VECTOR VAZIO!" <<endl;
	for (int i = 0; i < tam_prod; i++) {
		cout << "Nome: " << produtos[i].get_nome() << endl;
		cout << "Código: " << produtos[i].get_cod() << endl;
		cout << "Quantidade disponivel: " << produtos[i].get_quant_disp()
				<< endl;
		cout << "Decrição do produto: " << produtos[i].get_descr() << endl;
		cout << "Nº de dias desde que foi embalado: "
				<< produtos[i].get_dias_embalado() << endl;
		cout << "Preço de venda pelo fornecedor: "
				<< produtos[i].get_preco_vnd() << endl;
		cout << "Preço para compra no hipermercado: "
				<< produtos[i].get_preco_cmp() << endl << endl << endl;
	}
}

void Hipermercado::lista_compras() {
	int tam = compras.size();
	for (int i = 0; i < tam; i++) {
		cout << "Código da compra: " << compras[i].get_cod() << endl;
		cout << "Quantidade de produtos: " << compras[i].get_quant() << endl;
	}
}

void Hipermercado::lista_forn() {
	int tam = produtos.size();
	for (int i = 0; i < tam; i++)
		cout << "Lista de fornecedores: " << endl << endl;
				//<< produtos[i].lista_fornecedores() << endl;

}




void Hipermercado::lista_nomes_empregados() {
	int tam_emp = empregados.size();
	for (int i = 0; i < tam_emp; i++) {
		cout << empregados[i].get_name() << endl;
	}
}

void Hipermercado::lista_nomes_produtos() {
	int tam_prod = produtos.size();
	for (int i = 0; i < tam_prod; i++)
		cout << produtos[i].get_nome() << endl;
}

void Hipermercado::remove_fornecedor(string nome) {
	int tam = produtos.size();
	for (int i = 0; i < tam; i++)
		produtos[i].remove_fornecedor(nome);
}

Produto Hipermercado::pesquisa_produto(string nome) {
	int tam_prod = produtos.size();
	for (int i = 0; i < tam_prod; i++) {
		if (produtos[i].get_nome() == nome)
			return produtos[i];
		else
			throw(ProdutoNaoEncontrado(nome));
	}
}

Empregado Hipermercado::pesquisa_empregado(string nome) {
	int tam = empregados.size();
	for (int i = 0; i < tam; i++) {
		if (empregados[i].get_name() == nome)
			return empregados[i];
		else
			throw EmpregadoNaoEncontrado(nome);
	}
}



/**
 * Funções relativamente á manipulação da frota de camiões
 */

Camiao Hipermercado::procuraCamiao(Camiao& cam)
{
	while ( !frota_camioes.empty() )
		{
			Camiao pri_cam = frota_camioes.top();   //primeiro camião da fila
			frota_camioes.pop();
			if ( pri_cam.get_matricula() == cam.get_matricula()) //se tiverem o mesmo numero de matricula quer dizer que são o mesmo camião

				return pri_cam;

			else
				frota_camioes.pop(); //põe as caixas não utilizadas num vector temporário
		}
}


//Lista os camiões juntamente com a sua informação que se encontram na frota
void Hipermercado::lista_camioes()
{

	if(frota_camioes.empty())
		cout << "Não existem camiões na frota " << endl;
	else {
		while(!frota_camioes.empty())
		{
			Camiao pri_camiao = frota_camioes.top();
			frota_camioes.pop();
			cout << "Matricula do camião: " << pri_camiao.get_matricula() <<endl;
			cout << "Carga máxima: " << pri_camiao.get_cargamax() <<endl;
			cout << "Tipo de produto transportado: "  << pri_camiao.get_tipo() <<endl;
		}
		}
}


//Retorna o camião que tiver maior carga máxima
Camiao Hipermercado::camiaoMaisCarga() const
{
	if( frota_camioes.empty() )
		cout << "Frota de camioes vazia! " <<endl;
		else {
			priority_queue<Camiao> temp = frota_camioes;
			Camiao maisCarga = temp.top();
			temp.pop();
			while(!frota_camioes.empty() ) {
				if( maisCarga.get_cargamax() < frota_camioes.top().get_cargamax()) maisCarga = temp.top();
				temp.pop();
			}

			return maisCarga;
}
}

//Retorna o camião que tiver menor carga máxima
Camiao Hipermercado::camiaoMenosCarga() const
{
	if( frota_camioes.empty() )
		cout << "Frota de camioes vazia! " <<endl;
		else {
		priority_queue<Camiao> temp = frota_camioes;
		Camiao menosCarga = temp.top();
		temp.pop();
		while(!frota_camioes.empty() ) {
		if( menosCarga.get_cargamax() > frota_camioes.top().get_cargamax()) menosCarga = temp.top();
			temp.pop();
		}

		return menosCarga;
	}
}




void Hipermercado::adiciona_motorista(const Motorista & m1)
{
	 BST<Motorista> it(motoristas);
	 it.insert(m1);

}

//Remove um motorista da árvore binaria de pesquisa
void Hipermercado::remove_motorista(const Motorista & m1)
{
	BST<Motorista> it2(motoristas);
	it2.remove(m1);
}

//Devolve uma string onde estão listados todos os motoristas
string Hipermercado::lista_motoristas()
{
	stringstream nova;
	BSTItrIn<Motorista> it(motoristas);
	while(!it.isAtEnd())
	{
		Motorista pri = it.retrieve();
		nova << "Nome do motorista: " <<pri.get_nome() <<endl;
		nova << "BI: " << pri.get_bi() <<endl;
		nova << "Salario: " << pri.get_salario() <<endl;
		nova << "Transportes efectuados: ";
		queue<Transporte> pri_trans = pri.get_transportes();
		while(!pri_trans.empty())
		{
			Transporte t1 = pri_trans.front();
			nova << "Tipo de produto transportado: " << t1.getTipo_produto() <<endl;
			nova << "Quantidade: " << t1.get_quant() <<endl;
			nova << "Data: " << t1.get_dia() << "/" << t1.get_mes() << "/" << t1.get_ano() <<endl;
			pri_trans.pop();
		}

		it.advance();
	}

	return nova.str();
}


//Lista os transportes efectuados por um determinado motorista entre dois dias, que estão passados como argumentos
void Hipermercado::lista_transp_dias(Motorista m1,int inf,int sup,int ano,int mes)
{
	queue<Transporte> m1_trans = m1.get_transportes();
	while(!m1_trans.empty())
	{
		Transporte m1 = m1_trans.front();
		int dia_m1 = m1.get_dia();
		int mes_m1 = m1.get_mes();
		int ano_m1 = m1.get_ano();
		if(ano_m1 == ano && mes_m1 == mes && dia_m1 >= inf && dia_m1 <= sup)
		{
			cout << "Tipo de produto transportado: " << m1.getTipo_produto() <<endl;
			cout << "Quantidade: " << m1.get_quant() <<endl;
			cout << "Data: " << m1.get_dia() << "/" << m1.get_mes() << "/" << m1.get_ano() <<endl;
		}
		m1_trans.pop();
	}
}

void Hipermercado::list_todos_transp_dias(int inf,int sup,int ano,int mes)
{
	BSTItrIn<Motorista> it(motoristas);
	while(!it.isAtEnd())
	{
		Motorista m1 = it.retrieve();
		queue<Transporte> trans_m1 = m1.get_transportes();
		while(!trans_m1.empty())
		{
			Transporte pri_t1 = trans_m1.front();
			int dia_pri = pri_t1.get_dia();
			int mes_pri = pri_t1.get_mes();
			int ano_pri = pri_t1.get_ano();
			if(ano_pri == ano && mes_pri == mes && dia_pri >= inf && dia_pri <= sup)
			{
				cout << "Tipo de produto transportado: " << pri_t1.getTipo_produto() <<endl;
				cout << "Quantidade: " << pri_t1.get_quant() <<endl;
				cout << "Data: " << pri_t1.get_dia() << "/" << pri_t1.get_mes() << "/" << pri_t1.get_ano() <<endl;
			}
			trans_m1.pop();
		}
		it.advance();
	}
}


void Hipermercado::guarda_motoristas()
{
	BSTItrIn<Motorista> it(motoristas);
	ofstream myfile("Motoristas.txt",ios_base::trunc);
	if (myfile.is_open()) {
			while (!it.isAtEnd()) {
				myfile << it.retrieve().get_nome() << endl;
				myfile << it.retrieve().get_bi() <<endl;
				myfile << it.retrieve().get_salario() << endl;
				queue<Transporte> novo = it.retrieve().get_transportes();
				while(!novo.empty())
				{
					Transporte pri = novo.front();
					myfile << pri.getTipo_produto() <<endl;
					myfile << pri.get_quant() <<endl;
					myfile << pri.get_dia() << "/" << pri.get_mes() << "/" << pri.get_ano() <<endl;

					novo.pop();
				}

				it.advance();
			}
			myfile.close();

		}
}


