/*
 * op.cpp
 *
 *  Created on: 4 de Nov de 2010
 *      Author: José Pereira e Diogo Vaz
 */

#include "op.h"

int getInput(string prompt, int min, int max) {
	int choice;
#define MAX_STRING 256
	char start[MAX_STRING];
	char *end;

	while (true) {
		cout << prompt;
		if (cin.peek() == '\n')
			cin.ignore(1000, '\n');
		cin.getline(start, MAX_STRING);

		// converts char* to int, if possible. Use strtof() for float/double
		choice = strtol(start, &end, 10);

		// if strtol() fails end == start
		if (end != start && choice >= min && choice <= max)
			return choice;

	}
}

/**
 * Função que transforma palavras minúsculas em maisculas através do uso do algoritmo "toupper".
 * @param in string que queremos transformar em maiscula.
 */
string to_uppers(string in) //converte a palavra em maiusculas
{
	int tamanho = in.size();
	for (int r = 0; r < tamanho; ++r) {
		char letra = in[r];
		in[r] = toupper(letra);
	}
	return in;
}

//****************************************************************************************************************

//Construção de um Hipermercado
Hipermercado novo = Hipermercado("FEUPmarché");

/****************************************************************************************************************
 * Empregados
 ***************************************************************************************************************/

//Cria um novo empregado
void opnovoempregados() {
	string nome, cargo,new_data;
	string temp;
	float vencimento;
	int n_horas;
	cout << "Nome: ";
	getline(cin, nome);
	to_uppers(nome);
	cout << "Data de nascimento (dd/mm/aaaa): ";
	getline(cin,new_data);
	cout << "Vencimento do novo empregado: ";
	getline(cin,temp);
	istringstream nova(temp);
	nova >> vencimento;
	cout << "Cargo (Limpeza/Prateleiras/Caixas): ";
	getline(cin, cargo);
	cout << "Nº de horas de trabalho: ";
	getline(cin,temp);
	istringstream nov(temp);
	nov >> n_horas;
	Empregado emp_novo(nome,new_data, cargo,vencimento, n_horas);
	novo.adiciona_empregado(emp_novo);
	novo.guarda_empregados();
	cout << "Empregado adicionado com sucesso!";
}

//Remove um empregado
void opremoveempregado() {
	string nome_del,enter;
	to_uppers(nome_del);
	cout << "Lista dos nomes dos empregados:" << endl <<endl;
	if(novo.vector_tam_empregados() == 0)
		{cout << "Não existem empregados no hipermercado!" <<endl<<endl;
		cout << "Pressione enter para continuar" <<endl;
		getline(cin,enter);
		cout << "Voltando ao menu principal..." <<endl;}
	else{
	novo.lista_nomes_empregados();
	cout << endl;
	cout << "Indique o nome do empregado que pretende eliminar:";
	getline(cin, nome_del);
	novo.remove_empregado(nome_del);}
	novo.guarda_empregados();
	cout << "Empregado eliminado com sucesso";
}

//Edita informação sobre um empregado
void opeditempregado() {
	string nome, cargo,enter,temp,novo_nome;
	float vencimento;
	int n_horas;
	cout << "Lista de empregados: " << endl << endl;
	novo.lista_nomes_empregados();
	if(novo.vector_tam_empregados() ==0)
		{cout << "Não existem empregados no hipermercado!" <<endl<<endl;
		cout << "Pressione enter para continuar" <<endl;
		getline(cin,enter);
		cout << "Voltando ao menu principal..." <<endl;}
	else
	{cout << endl << "Indique o nome do empregado que pretende editar:";
	getline(cin, nome);
	Empregado empr1 = novo.pesquisa_empregado(nome);
	novo.remove_empregado(nome);
	cout << "Novo vencimento: ";
	getline(cin,temp);
	istringstream nova1(temp);   //aplicar isto a todos
	nova1 >> vencimento;
	empr1.set_vencimento(vencimento);
	cout << "Novo cargo (Limpeza/Prateleiras/Caixas): ";
	getline(cin,cargo);
	empr1.set_cargo(cargo);
	cout << "Novo nº de horas de trabalho: ";
	getline(cin,temp);
	istringstream nova2(temp);
	nova2 >> n_horas;
	empr1.set_n_horas_dia(n_horas);
	novo.adiciona_empregado(empr1);}
	novo.guarda_empregados();
	cout << "Empregado editado com sucesso!" << endl;
}

//Apresenta lista de empregados
void oplistaem_prod() {
	string enter;
	novo.carrega_empregados();
	cout << "Vector Empregados apos carrega " << novo.vector_tam_empregados() << endl;
	cout << "Lista de empregados: " << endl << endl;
	cout << novo.vector_tam_empregados() <<endl;
	if(novo.vector_tam_empregados() ==0)
		{cout << "Não existem empregados no hipermercado!" <<endl<<endl;
		cout << "Pressione enter para continuar" <<endl;
		getline(cin,enter);
		cout << "Voltando ao menu principal..." <<endl;}
	else{
	novo.lista_empregados();
	cout << "Vector Empregados apos Lista Empregados " << novo.vector_tam_empregados() << endl;
	cout << "Pressione enter para sair";
	getline(cin, enter);
	}
}

/****************************************************************************************************************
 * Produtos
 *
 ***************************************************************************************************************/

//Cria um novo produto
void opnovoproduto() {
	string nome, descr,temp;
	to_uppers(nome);
	to_uppers(descr);
	int dias;
	unsigned int quant;
	long cod, p_pvenda, p_pcompra;
	cout << "Nome: ";
	getline(cin, nome);
	cout << "Código do produto: ";
	getline(cin,temp);
	istringstream nova3(temp);
	nova3 >> cod;
	cout << "Quantidade disponivel: ";
	getline(cin,temp);
	istringstream nova4(temp);
	nova4 >> quant;
	cout << "Descricao do produto:";
	getline(cin, descr);
	cout << "Nº de dias desde que foi embalado: ";
	getline(cin,temp);
	istringstream nova5(temp);
	nova5 >> dias;
	cout << "Preço de venda pelo fornecedor: ";
	getline(cin,temp);
	istringstream nova6(temp);
	nova6 >> p_pvenda;
	cout << "Preço para compra no hipermercado: ";
	getline(cin,temp);
	istringstream nova7(temp);
	nova7 >> p_pcompra;
	try {
		Produto new_prod(nome, cod, descr, p_pvenda, p_pcompra, quant, dias);
		novo.adiciona_produto(new_prod);
	} catch (ProdutoSemQualidade &e) {
		cout << "Produto sem qualidade" << endl;
		cout << "Insira um preço superior a 10 euros: ";
		cout << e.get_preco() << endl;

	}
	novo.guarda_produtos();
	cout << "Produto adicionado com sucesso!";
}

//Remove um produto
void opremproduto() {
	string enter;
	cout << "Lista dos nomes dos produtos existentes: " << endl << endl;
	if(novo.vector_tam_produtos() == 0)
	{cout << "Não existem produtos no hipermercado!" <<endl <<endl;
	cout << "Pressione enter para continuar" <<endl;
	getline(cin,enter);
	cout << "Voltando ao menu principal..." <<endl;}
	else
	{
	novo.lista_nomes_produtos();
	cout << endl;
	cout << "Indicar o nome do produto que pretende remover: ";
	string nome_del3;
	to_uppers(nome_del3);
	getline(cin, nome_del3);
	novo.remove_produto(nome_del3);
	novo.guarda_produtos();
	cout << "Produto eliminado com sucesso!" << endl;
}}

//Edita um produto
void opeditproduto() {
	cout << "Editar produto:";

}


//Apresenta no ecrã a lista de todos os produtos
void oplistaprod() {
	string enter;
	novo.carrega_produtos();
	cout << "Lista de produtos:" << endl <<endl;
	if(novo.vector_tam_produtos() == 0)
	{cout << "Nao existem produtos no hipermercado!" <<endl <<endl;
	cout << "Pressione enter para continuar" <<endl;
	getline(cin,enter);
	cout << "Voltando ao menu principal..." <<endl;}
	else{
	novo.lista_produtos();
	cout << "Pressione enter para sair";
	getline(cin, enter);
}
}



/****************************************************************************************************************
 * Fornecedores
 *
 ***************************************************************************************************************/

//Cria um novo fornecedor
void opnovoforn() {
	string nome, morada, localidade, tipo_produto, nome_prod,temp;
	long nif;
	cout << "Nome: ";
	getline(cin, nome);
	to_uppers(nome);
	cout << "Morada: ";
	getline(cin, morada);
	to_uppers(morada);
	cout << "Localidade: ";
	getline(cin, localidade);
	to_uppers(localidade);
	cout << "Numero de Identificação Fiscal (NIF): ";
	getline(cin,temp);
	istringstream nova5(temp);
	nova5 >> nif;
	cout << "Tipo de produto que o fornecedor vende: ";
	getline(cin, tipo_produto);
	to_uppers(tipo_produto);
	cout<< "Pretende adicionar o fornecedor a que produto.Indique o nome do produto:";
	novo.lista_nomes_produtos();
	cout << endl << endl;
	cout << "Nome do produto: ";
	getline(cin, nome_prod);
	Fornecedor forn_novo(nome, morada, localidade, nif, tipo_produto);
	try {
		Produto prod1 = novo.pesquisa_produto(nome_prod);
		prod1.adiciona_fornecedores(forn_novo);
	} catch (ProdutoNaoEncontrado &e) {
		cout << "Produto nao encontrado" << endl;
		cout << "Insira um nome de um produto válido: ";
		cout << e.get_nome() << endl;

	}

	novo.fich_fornecedores();
	cout << "Fornecedor adicionado com sucesso!";
}

//Edita um fornecedor
void opeditfornc() {
	string nome, morada, localidade, tipo_produto, nome_prod;
	long nif;
	int tam = novo.produtos.size();
	cout << endl;
	novo.lista_forn();
	cout << endl << "Indique o nome do fornecedor que pretende editar:";
	getline(cin, nome);
	for (int i = 0; i < tam; i++)
		{Fornecedor fornc1 = novo.produtos[i].pesquisa_fornecedor(nome);
	cout << "Novo nome: ";
	getline(cin, nome);
	fornc1.set_name(nome);

	cout << "Nova morada: ";
	getline(cin, morada);
	fornc1.set_morada(morada);
	cout << "Nova localidade: ";
	cin.ignore(1000, '\n');
	getline(cin, localidade);
	fornc1.set_localidade(localidade);
	cout << "Novo NIF: ";
	cin >> nif;
	fornc1.set_nif(nif);
	cout << "Novo tipo de produto: ";
	getline(cin, tipo_produto);
	fornc1.set_tipo(tipo_produto);
	for (int i = 0; i < novo.produtos.size(); i++)
		novo.produtos[i].adiciona_fornecedores(fornc1);}
	novo.guarda_produtos();
	cout << "Fornecedor editado com sucesso!" << endl;

}

//Remove um fornecedor
void opremforn() {
	novo.lista_forn();
	cout << endl << "Indique o nome do fornecedor que pretende eliminar:";
	string nome_del2;
	to_uppers(nome_del2);
	getline(cin, nome_del2);
	novo.remove_fornecedor(nome_del2);
	novo.fich_fornecedores();
	cout << "Fornecedor eliminado com sucesso!" << endl;
}

//Apresenta no ecrã a lista de fornecedores
void opinfoforn() {
	string enter;
	novo.lista_forn();
	cout << endl << "Pressione enter para sair ";
	getline(cin, enter);

}
/**************************************************************************************************************
 * Compras
 *
 **************************************************************************************************************/

//Regista uma nova compra
void opcompra() {

	long cod;
	int quant;
	Data data_comp;
	cout << "Indique o código do produto que pretende adquirir: ";
	cin >> cod;
	cout << "Indique o nº de unidades:";
	cin >> quant;
	cout << "Data:";
	int dia, mes, ano;
	cout << endl << "Dia: ";
	cin >> dia;
	cout << "Mês: ";
	cin >> mes;
	cout << "Ano: ";
	cin >> ano;
	data_comp.dia = dia;
	data_comp.mes = mes;
	data_comp.ano = ano;
	Compra compra1(cod, quant, data_comp);
	novo.adiciona_compra(compra1);
	novo.guarda_compras();
	cout << "Compra adicionada com sucesso!" << endl;

}

//Remove uma compra
void opremcompra() {
	long cod_del;
	cout << "Lista dos nomes de todas as compras registadas:" << endl;
	novo.lista_compras();
	cout << endl;
	cout << "Indique o código da compra que pretende remover:";
	cin >> cod_del;
	novo.remove_compra(cod_del);
	novo.guarda_compras();
	cout << "Compra removida com sucesso";

}

//Apresenta no ecrã a lista de todas as compras registadas
void oplistcompras() {
	string enter;
	novo.lista_compras();
	cout << endl << "Pressione enter para sair ";
	getline(cin, enter);

}

/**
 * Motoristas
 */

void opadmotor()
{
	string nome,temp,tipo_prod,nome_prod,descr;
	long bi,cod;
	unsigned int quant,quant_disp;
	int d, m ,a,dias;
	float p_pcompra,p_pvenda;
	double salario;
	queue<Transporte> novo_trans;
	vector<Produto> novo_prods;

	cout << "Nome: ";
	getline(cin, nome);
	to_uppers(nome);
	cout << "BI: ";
	getline(cin,temp);
	istringstream nova6(temp);
	nova6 >> bi;
	cout << "Salário: ";
	getline(cin,temp);
	istringstream nova7(temp);
	nova7 >> salario;
	cout << "Adiciona novo transporte: " <<endl <<endl;
	cout << "Tipo de produto: ";
	getline(cin,tipo_prod);
	cout << "Quantidade: ";
	getline(cin,temp);
	istringstream nova8(temp);
	nova8 >> quant;
	cout << "Data do transporte: ";
	cout << "Dia: ";
	getline(cin,temp);
	istringstream nova9(temp);
	nova9 >> d;
	cout << "Mes: ";
	getline(cin,temp);
	istringstream nova10(temp);
	nova10 >> m;
	cout << "Ano: ";
	getline(cin,temp);
	istringstream nova11(temp);
	nova11 >> a;
	cout << "Produto transportado: " <<endl <<endl;
	cout << "Nome: ";
	getline(cin, nome_prod);
	cout << "Código do produto: ";
	getline(cin,temp);
	istringstream nova3(temp);
	nova3 >> cod;
	cout << "Quantidade disponivel: ";
	getline(cin,temp);
	istringstream nova4(temp);
	nova4 >> quant_disp;
	cout << "Descricao do produto:";
	getline(cin, descr);
	cout << "Nº de dias desde que foi embalado: ";
	getline(cin,temp);
	istringstream nova5(temp);
	nova5 >> dias;
	cout << "Preço de venda pelo fornecedor: ";
	getline(cin,temp);
	istringstream nova13(temp);
	nova13 >> p_pvenda;
	cout << "Preço para compra no hipermercado: ";
	getline(cin,temp);
	istringstream nova14(temp);
	nova14 >> p_pcompra;
	Produto novo = Produto(nome_prod,cod,descr,p_pvenda,p_pcompra,quant_disp,dias);
	novo_prods.push_back(novo);
	Transporte novo_t = Transporte(novo_prods,tipo_prod,quant,d,m,a);
	novo_trans.push(novo_t);
	Motorista novo_m = Motorista(nome,bi,salario,novo_trans);
	novo.adiciona_motorista(novo_m);
	novo.guarda_motoristas();
	cout << "Motorista adicionado com sucesso!";
}


void opremmotor()
{

}
void oplistmotor()
{
	string enter;
	//novo.carrega_motoristas(); //falta implementar
	cout << "Lista de motoristas: " << endl << endl;
	string lista_motoristas = novo.lista_motoristas();
	cout << lista_motoristas <<endl;
	cout << "Pressione enter para sair";
	getline(cin, enter);
}

void oplistrans()
{
	string temp,enter;
	int inf,sup,ano,mes;
	getline(cin,temp);
	istringstream nova15(temp);
	nova15 >> ano;

	getline(cin,temp);
	istringstream nova16(temp);
	nova16 >> inf;

	getline(cin,temp);
	istringstream nova17(temp);
	nova17 >> sup;

	getline(cin,temp);
	istringstream nova18(temp);
	nova18 >> mes;

	cout << "Lista de transportes entre os dias " << inf << " e " << sup << " no mes " << mes << "do ano " << ano <<endl <<endl;

	novo.list_todos_transp_dias(inf,sup,ano,mes);
	cout << "Pressione enter para sair";
	getline(cin, enter);

}

