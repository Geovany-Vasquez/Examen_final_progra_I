#pragma once
#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
using namespace std;
class Marca {
	// atributos
private: string marca;


	   // costructor
public:
	Marca() {
	}
	Marca(string mr) {
		marca = mr;


	}
	void setPuesto(string mr) { marca = mr; }
	string getPuesto() { return marca; }


	void deleteM(int id_auxM) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;

		cn.abrir_conexion();




		if (cn.getConectar()) {
			cout << "Conexion Exitosa..." << endl;

			string idM = to_string(id_auxM);
			string ss;
			cout << "---------------------------------------------------" << endl;

			ss = "DELETE FROM marcas WHERE id_marca= " + idM + " ";
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


	void updateM(int id_auxM) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;

		cn.abrir_conexion();
		if (cn.getConectar()) {
			cout << "Conexion Exitosa..." << endl;

			string idM = to_string(id_auxM);

			string update;
			cout << "---------------------------------------------------" << endl;

			update = "UPDATE marcas SET marca ='" + marca + "'  WHERE id_marca =" + idM + " ";
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


	void crearM() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {


			string insert = "INSERT INTO marcas(marca) VALUES('" + marca + "');";
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

	void leerM() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;

		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select * from marcas";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " | " << fila[1] << endl;


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

