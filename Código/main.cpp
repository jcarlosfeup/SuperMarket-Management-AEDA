/*
 * main.cpp
 *
 *  Created on: Oct 21, 2010
 *      Author: José Pereira e Diogo Vaz
 */

#include "menu.h"
#include "op.h"
#include <iostream>
using namespace std;

int main() {

	Menu menuPrincipal, menuEmpregados, menuProdutos, menuFornecedores,menuCompras, menuMotoristas;

	menuPrincipal = Menu("Bem-Vindo ao FEUPmarché", "SAIR");
	menuPrincipal.add("Empregados", menuEmpregados);
	menuPrincipal.add("Produtos", menuProdutos);
	menuPrincipal.add("Fornecedores", menuFornecedores);
	menuPrincipal.add("Compras", menuCompras);

	menuEmpregados = Menu("Empregados", "SAIR");
	menuEmpregados.add("Novo empregado", opnovoempregados);
	menuEmpregados.add("Remove empregado", opremoveempregado);
	menuEmpregados.add("Editar informação sobre empregado", opeditempregado);
	menuEmpregados.add("Lista de empregados", oplistaem_prod);

	menuProdutos = Menu("Produtos", "SAIR");
	menuProdutos.add("Adiciona novo produto", opnovoproduto);
	menuProdutos.add("Remove produto", opremproduto);
	menuProdutos.add("Editar produto", opeditproduto);
	menuProdutos.add("Lista de produtos", oplistaprod);

	menuFornecedores = Menu("Fornecedores", "SAIR");
	menuFornecedores.add("Novo fornecedor", opnovoforn);
	menuFornecedores.add("Remove fornecedor", opremforn);
	menuFornecedores.add("Editar fornecedor", opeditfornc);
	menuFornecedores.add("Ver informação sobre os fornecedores", opinfoforn);

	menuCompras = Menu("Compras", "SAIR");
	menuCompras.add("Efectuar compra",opcompra);
	menuCompras.add("Remover compra", opremcompra);
	menuCompras.add("Ver lista de compras", oplistcompras);

	menuMotoristas = Menu("Motoristas","SAIR");
	menuMotoristas.add("Adiciona motorista",opadmotor);
	menuMotoristas.add("Remove motorista",opremmotor);
	menuMotoristas.add("Lista de motoristas",oplistmotor);
	menuMotoristas.add("Lista todos os transportes num determinado periodo",oplistrans);



	menuPrincipal.go();

	return 0;
}
