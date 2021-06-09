#pragma once
#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
using namespace std;
class Compras_detalle
{
private: int cantidad = 0;
	   int id_compra = 0, id_producto = 0;
	   float precio_costo_unitario = 0, subtotal=0;

	   // costructor
public:
	Compras_detalle() {
	}
	Compras_detalle(int idc, int idp, int ct, float ctu, float subt) {
		id_compra = idc;
		id_producto = idp;
		cantidad = ct;
		precio_costo_unitario = ctu;
		subtotal = subt;
	}

	void gotoxy(int x1, int y1)
	{
		HANDLE hcon;
		hcon = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD dwPos;
		dwPos.X = x1;
		dwPos.Y = y1;
		SetConsoleCursorPosition(hcon, dwPos);
	}

	void setId_compra(int idc) { id_compra = idc; }
	void setId_producto(int idp) { id_producto = idp; }
	void setCantidad(int ct) { cantidad = ct; }
	void setPrecio_costo_unitario(float ctu) { precio_costo_unitario = ctu; }
	void setSubtotal(float subt) { subtotal = subt; }


	int  getId_compra() { return id_compra; }
	int getId_producto() { return id_producto; }
	int getCantidad() { return cantidad; }
	float getPrecio_costo_unitario() { return precio_costo_unitario; }
	float getSubtotal() { return subtotal; }

	void crearComprasD(string id_auxVN2, float id_auxsubtotal) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string vnt = to_string(id_compra);
			string dpr = to_string(id_producto);
			string cosu = to_string(precio_costo_unitario);
			string cantidads = to_string(cantidad);
			string subtotal1 = to_string(id_auxsubtotal);


			string insert = "INSERT INTO compras_detalle(id_compra,id_producto,cantidad,precio_costo_unitario,subtotal) VALUES(" + id_auxVN2 + "," + dpr + "," + cantidads + "," + cosu + "," + subtotal1 + ");";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {
				cout << " " << endl;
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

	void leerCMll(string id_auxVN1) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		int cl = 10;



		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select c.id_compra_detalle,c.id_compra,f.producto,c.cantidad,c.precio_costo_unitario,c.subtotal from compras_detalle as c inner join productos as f on c.id_producto = f.id_producto Where c.id_compra = " + id_auxVN1 + "; ";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {

					cl++;


					gotoxy(1, cl); cout << fila[0] << endl;
					gotoxy(8, cl); cout << fila[1] << endl;
					gotoxy(20, cl); cout << fila[2] << endl;
					gotoxy(36, cl); cout << fila[3] << endl;
					gotoxy(48, cl); cout << fila[4] << endl;


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

