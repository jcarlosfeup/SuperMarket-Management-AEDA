/*
 * op.h
 *
 *  Created on: 4 de Nov de 2010
 *      Author: Jos� Pereira e Diogo Vaz
 */
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include "Produto.h"
#include "Fornecedor.h"
#include "Compra.h"
#include "Hipermercado.h"
#include "Empregado.h"

#ifndef OP_H_
#define OP_H_

using namespace std;

/**
 * Op��es relativamente aos empregados
 */
void opnovoempregados();
void opremoveempregado();
void opeditempregado();
void oplistaem_prod();

/**
 * Op��es relativamente aos produtos
 */
void opnovoproduto();
void opremproduto();
void opeditproduto();
void oplistaprod();
void opnovoforn();
/**
 * Op��es relativamente aos fornecedores
 */
void opeditfornc();
void opremforn();
void opinfoforn();
/**
 * Op��es relativamente �s compras
 */
void opcompra();
void opremcompra();
void oplistcompras();
void oplistrans();

/**
 * Op��es relativamente aos motoristas
 */

void opadmotor();
void opremmotor();
void oplistmotor();


#endif /* OP_H_ */
