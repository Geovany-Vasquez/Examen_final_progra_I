#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
using namespace std;
class Puesto {
	// atributos
private: string puesto;


	   // costructor
public:
	Puesto() {
	}
	Puesto(string ps) {
		puesto = ps;


	}
	void setPuesto(string ps) { puesto = ps; }


	string getPuesto() { return puesto; }


	void deletep(int id_auxp) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;

		cn.abrir_conexion();




		if (cn.getConectar()) {
			cout << "Conexion Exitosa..." << endl;

			string id2 = to_string(id_auxp);
			string ss;
			cout << "---------------------------------------------------" << endl;

			ss = "DELETE FROM puestos WHERE id_puesto= " + id2 + " ";
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


	void updatep(int id_auxp1) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;

		cn.abrir_conexion();
		if (cn.getConectar()) {
			cout << "Conexion Exitosa..." << endl;

			string id3 = to_string(id_auxp1);

			string update;
			cout << "---------------------------------------------------" << endl;

			update = "UPDATE puestos SET puesto ='" + puesto + "'  WHERE id_puesto =" + id3 + " ";
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


	void crear1() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {


			string insert = "INSERT INTO puestos(puesto) VALUES('" + puesto + "');";
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

	void leer1() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;

		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select * from puestos";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " , " << fila[1] << endl;


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
