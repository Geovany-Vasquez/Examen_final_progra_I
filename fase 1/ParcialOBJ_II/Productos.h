#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
using namespace std;

class Productos
{
private: string producto,descripcion,fecha_ingreso;
	   int id_marca = 0, existencia = 0;
	   float precio_costo = 0, precio_venta = 0;

	   // costructor
public:
	Productos() {
	}
	Productos(string pr,int idm,string des,float prc,float prv,int ex,string fci) {
		producto = pr;
		id_marca = idm;
		descripcion = des;
		precio_costo = prc;
		precio_venta = prv;
		existencia = ex;
		fecha_ingreso = fci;
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


	void setProducto(string pr) { producto = pr; }
	void setId_marca(int idm) { id_marca = idm; }
	void setDescripcion(string des) { descripcion = des; }
	void setPrecio_costo(float prc) { precio_costo = prc; }
	void setPrecio_venta(float prv) { precio_venta = prv; }
	void setExistencia(int ex) { existencia = ex; }
	void setFecha_ingreso(string fci) { fecha_ingreso = fci; }


	string getProducto() { return producto; }
    int  getId_marca() { return id_marca; }
	string getDescripcion() { return descripcion; }
	float getPrecio_costo() { return precio_costo; }
	float getPrecio_venta() { return precio_venta; }
	int getExistencia() { return existencia; }
	string getFecha_ingreso() { return fecha_ingreso; }


	void deletePRD(int id_auxPR) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;

		cn.abrir_conexion();




		if (cn.getConectar()) {
			cout << "Conexion Exitosa..." << endl;

			string idPR = to_string(id_auxPR);
			string ss;
			cout << "---------------------------------------------------" << endl;

			ss = "DELETE FROM productos WHERE id_producto= " + idPR + " ";
			string query = ss.c_str();
			const char* q = query.c_str();
			q_estado = mysql_query(cn.getConectar(), q);
			if (!q_estado)
			{
				cout << "REGISTRO ELIMINADO. . ." << endl;
			}
			else
			{
				cout << "ERROR. . ." << endl;
			}



		}
		else {
			cout << "error en la conexion" << endl;
		}
		cn.cerrar_conexion();

	}



	void updatePRD(int id_auxPR) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;

		cn.abrir_conexion();
		if (cn.getConectar()) {
			cout << "Conexion Exitosa..." << endl;

			string idPR = to_string(id_auxPR);
			string ma = to_string(id_marca);
			string pc = to_string(precio_costo);
			string pv = to_string(precio_venta);
			string et = to_string(existencia);
			
			string update;
			cout << "---------------------------------------------------" << endl;

			update = "UPDATE productos SET producto ='"+ producto+" ' , id_marca = "+ma+", descripcion='"+descripcion+"', precio_costo ="+pc+", precio_venta ="+pv+", existencia ="+et+", fecha_ingreso='"+ fecha_ingreso +"' WHERE id_producto ="+idPR+"";
			string query = update.c_str();
			const char* q = query.c_str();
			q_estado = mysql_query(cn.getConectar(), q);
			if (!q_estado)
			{
				cout << "actualizado. . ." << endl;
			}
			else
			{
				cout << "error en la actualizacion. . ." << endl;
			}



		}
		else {
			cout << "error en la conexion" << endl;
		}
		cn.cerrar_conexion();

	}



	void crearPRD() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string ma = to_string(id_marca);
			string pc= to_string(precio_costo);
			string pv = to_string(precio_venta);
			string et = to_string(existencia);

			string insert = "INSERT INTO productos(producto,id_marca,descripcion,precio_costo,precio_venta,existencia,fecha_ingreso) VALUES('"+producto+"',"+ma+",'"+ descripcion +"',"+ pc +","+ pv +","+ et +",'"+ fecha_ingreso +"');";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {
				cout << "ingreso exitoso...." << endl;
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



	void leerPRD() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		int cl = 3;


		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select c.id_producto,c.producto,p.marca,c.descripcion,c.precio_costo,c.precio_venta,c.existencia,c.fecha_ingreso from productos as c inner join marcas as p on c.id_marca = p.id_marca; ";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {

					cl++;

					gotoxy(1, cl); cout << fila[0] << endl;
					gotoxy(5, cl); cout << fila[1] << endl;
					gotoxy(20, cl); cout << fila[2] << endl;
					gotoxy(40, cl); cout << fila[3] << endl;
					gotoxy(70, cl); cout << fila[4] << endl;
					gotoxy(78, cl); cout << fila[5] << endl;
					gotoxy(90, cl); cout << fila[6] << endl;
					gotoxy(95, cl); cout << fila[7] << endl;

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

