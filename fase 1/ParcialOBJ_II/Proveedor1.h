#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
using namespace std;
class Proveedor1 {
	// atributos
private: string proveedor, nit, direccion,telefono;


	   // costructor
public:
	Proveedor1() {
	}
	Proveedor1(string pr,string ni,string dir,string tf) {
		proveedor = pr;
		nit = ni;
		direccion = dir;
		telefono = tf;



	}
	void setProveedor(string pr) { proveedor = pr; }
	void setNit(string ni) { nit = ni; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(string tf) { telefono = tf; }

	string getProveedor() { return proveedor; }
	string getNit() { return nit; }
	string getDireccion() { return direccion; }
	string getTelefono() { return telefono; }


	void deletePR(int id_auxPR) {
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

			ss = "DELETE FROM proveedores WHERE id_proveedor= " + idPR + " ";
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


	void updatePR(int id_auxPR) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;

		cn.abrir_conexion();
		if (cn.getConectar()) {
			cout << "Conexion Exitosa..." << endl;

			string idPR = to_string(id_auxPR);

			string update;
			cout << "---------------------------------------------------" << endl;

			update = "UPDATE proveedores SET proveedor ='" + proveedor + "', nit ='" + nit + "', direccion='" + direccion + "', telefono='" + telefono + "'  WHERE id_proveedor =" + idPR + " ";
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


	void crearPR() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {


			string insert = "INSERT INTO proveedores(proveedor,nit,direccion,telefono) VALUES('" + proveedor + "','" + nit + "','" + direccion + "','" + telefono + "');";
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

	void leerPR() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;

		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select * from proveedores";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " | " << fila[1] << " | " << fila[2] << " | " << fila[3] << " | " << fila[4] << endl;


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
