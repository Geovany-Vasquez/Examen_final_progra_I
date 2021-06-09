#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
#include "Compras_detalle.h"
class Compras
{
private: string  fecha_orden, fecha_ingreso;
	   int no_orden_compra = 0, id_proveedor = 0;



	   // costructor
public:
	Compras() {
	}
	Compras(int noor, int idp,string feor,string fein) {
		no_orden_compra = noor;
		id_proveedor = idp;
		fecha_orden = feor;
		fecha_ingreso = fein;
	}
	int cantidad = 0;
	int id_compra = 0, id_producto = 0;
	float precio_costo_unitario = 0, subtotal = 0;

	void gotoxy(int x1, int y1)
	{
		HANDLE hcon;
		hcon = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD dwPos;
		dwPos.X = x1;
		dwPos.Y = y1;
		SetConsoleCursorPosition(hcon, dwPos);
	}

	void setNo_orden_compra(int noor) { no_orden_compra = noor; }
	void setId_proveedor(int idp) { id_proveedor = idp; }
	void setFecha_orden(string feor) { fecha_orden= feor; }
	void setFecha_ingreso(string fein) { fecha_ingreso = fein; }
	

	int  getNo_orden_compra() { return no_orden_compra; }
	int getId_proveedor() { return id_proveedor; }
	string getFecha_orden() { return fecha_orden; }
	string getFecha_ingreso() { return fecha_ingreso; }

	void autofecha(string id_auxVN2) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;

		char resp = 's';


		int cont = 13;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select  fecha_ingreso from compras where id_compra ='" + id_auxVN2 + "'; ";
			const char* c = consulta.c_str();

			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {

					gotoxy(59, 1); cout << fila[0] << endl;

				}


			}

			else {
				cout << " xxx Error al ingresar informacion xxxx" << endl;
			}

		}
		else {
			cout << "error en la conexion" << endl;


		}

		cn.cerrar_conexion();

	}
	
	void autoNit() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;

		string id_auxNit1;
		string id_auxNit;


		
		string id_auxVN3;
		string nofac;

		int cont = 11;
		cn.abrir_conexion();
		if (cn.getConectar())
		{
			string consulta1 = "SELECT MAX(no_orden_compra)+1 FROM compras; ";
			const char* c1 = consulta1.c_str();

			q_estado = mysql_query(cn.getConectar(), c1);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {
					nofac = fila[0];
					gotoxy(1, 8); cout << "no_orden_compra:" << nofac << endl;

				}
			}

			
			gotoxy(1, 1);	cout << "nit:", cin >> id_auxNit;
			string consulta = "select id_proveedor, proveedor, direccion from proveedores Where nit = '" + id_auxNit + "'; ";
			const char* c = consulta.c_str();

			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {
					id_auxNit1 = fila[0];
					id_auxVN3 = id_auxNit1;

					gotoxy(12, 3); cout << fila[1] << endl;
					gotoxy(12, 5); cout << fila[2] << endl;



				}

				gotoxy(59, 3); cout <<  id_auxNit1 << endl; cin.ignore();
				
				gotoxy(63, 5); getline(cin, fecha_orden);



				Compras cm = Compras(no_orden_compra, id_proveedor, fecha_orden, fecha_ingreso);
				cm.crearCOMP(id_auxVN3, nofac);


			}

			else {
				cout << " xxx Error al ingresar informacion xxxx" << endl;
			}


		}
		else {
			cout << "error en la conexion" << endl;


		}

		cn.cerrar_conexion();

	}
	
	void autof() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_ROW fila1;
		MYSQL_RES* resultado;
		MYSQL_RES* resultado1;
		string id_auxVN2, id_auxVN5, id_auxVN6, id_auxVN7;
		float total = 0, total1 = 0, sub = 0, sub1 = 0, id_auxsubtotal = 0;

		char resp = 's';


		int cont = 13;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "SELECT MAX(id_compra)  FROM compras;";
			const char* c = consulta.c_str();

			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {
					id_auxVN2 = fila[0];


				}

				do {
					cont++;
					
					gotoxy(1, 13); cout << id_auxVN2 << endl; cin.ignore();
					gotoxy(10, cont); cin >> id_producto; cin.ignore();

					string  id_auxVN6 = to_string(id_producto);

					string consulta3 = "select p.producto,n.marca from productos as p inner join marcas as n on p.id_marca = n.id_marca Where id_producto = '" + id_auxVN6 + "';";
					const char* c2 = consulta3.c_str();

					q_estado = mysql_query(cn.getConectar(), c2);
					if (!q_estado) {
						resultado = mysql_store_result(cn.getConectar());

						while (fila = mysql_fetch_row(resultado)) {
							id_auxVN5 = fila[0];
							id_auxVN7 = fila[1];


						}
					}


					gotoxy(25, cont); cout << id_auxVN5 << endl;
					gotoxy(45, cont); cout << id_auxVN7 << endl;
					gotoxy(62, cont); cin >> cantidad; cin.ignore();
					gotoxy(75, cont); cin >> precio_costo_unitario; cin.ignore();

					sub = cantidad * precio_costo_unitario;
					id_auxsubtotal = sub;
					gotoxy(95, cont);  cout << sub << endl;
					sub1 += sub;



					gotoxy(30, 11); cout << "desea ingresar otros datos[s/n]", cin >> resp;
					gotoxy(30, 11); cout << "                                    " << endl;

					
					Compras_detalle cp = Compras_detalle(id_compra, id_producto, cantidad, precio_costo_unitario, subtotal);
					cp.crearComprasD(id_auxVN2, id_auxsubtotal);

					Compras cm = Compras(no_orden_compra,id_proveedor,fecha_orden,fecha_ingreso);
					cm.autofecha(id_auxVN2);


				} while (resp == 's');


				gotoxy(105, cont); cout << sub1 << endl;

				system("pause");
				system("cls");
				
			}

			else {
				cout << " xxx Error al ingresar informacion xxxx" << endl;
			}

		}
		else {
			cout << "error en la conexion" << endl;


		}

		cn.cerrar_conexion();

	}
	

	void crearCOMP(string id_auxVN3,string nofac) {
		MYSQL_ROW fila;
		MYSQL_RES* resultado;

		int q_estado;
		ConexionBD cn = ConexionBD();


		string nodc = to_string(no_orden_compra);
		string dpdr = to_string(id_proveedor);
		




		cn.abrir_conexion();
		if (cn.getConectar()) {


			string insert = "INSERT INTO compras(no_orden_compra,id_proveedor,fecha_orden) VALUES('" + nofac + "','" + id_auxVN3 + "','" + fecha_orden + "');";

			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {
				gotoxy(1, 10);  cout << "ingreso exitoso...." << endl;
				Compras cm1 = Compras(no_orden_compra, id_proveedor, fecha_orden, fecha_ingreso);
				cm1.autof();

				
			}
			else {
				cout << "error al ingresar..." << endl;
			}


		}
		else {
			cout << "error en la conexion" << endl;


		}

		cn.cerrar_conexion();


	}

	void leerVent(int id_auxVN) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		int cl = 10;
		string id_auxVN1;
		string idventa = to_string(id_auxVN);



		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select c.id_compra,c.no_orden_compra,p.proveedor,p.direccion,c.fecha_orden,c.fecha_ingreso from compras as c inner join proveedores as p on c.id_proveedor = p.id_proveedor Where c.no_orden_compra = "+ idventa +"; ";
			const char* c = consulta.c_str();

			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {

					cl++;
					id_auxVN1 = fila[0];


					gotoxy(12, 3); cout << fila[2] << endl;
					gotoxy(51, 1); cout << fila[3] << endl;
					gotoxy(60, cl); cout << fila[4] << endl;
					gotoxy(80, cl); cout << fila[5] << endl;
					gotoxy(102, cl); cout << fila[1] << endl;



					
					Compras_detalle cm = Compras_detalle(id_compra, id_producto, cantidad, precio_costo_unitario, subtotal);
					cm.leerCMll(id_auxVN1);
					
				}


			}

			else {
				cout << " xxx Error al ingresar informacion xxxx" << endl;
			}

		}
		else {
			cout << "error en la conexion" << endl;


		}
		cn.cerrar_conexion();

	}


};

