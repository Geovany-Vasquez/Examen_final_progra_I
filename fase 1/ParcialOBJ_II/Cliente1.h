#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <Windows.h>
#include "ConexionBD.h"
class Cliente1
{
private: string nombres, apellidos, nit,telefono,correo_electronico, fecha_ingreso;
	   int genero=0;
	  

	   // costructor
public:
	Cliente1() {
	}
	Cliente1(string nom, string apell, string n, int gen, string  tel, string cor, string fec) {
		nombres = nom;
		apellidos = apell;
		nit = n;
		genero = gen;
		telefono = tel;
		correo_electronico = cor;
		fecha_ingreso = fec;
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

	void setNombre(string nom) { nombres = nom; }
	void setApellidos(string apell) { apellidos = apell; }
	void setNit(string n) { nit = n; }
	void setGenero(int gen) { genero = gen; }
	void setTelefono(string tel) { telefono = tel; }
	void setCorreo_electronico(string cor) { correo_electronico = cor; }
	void setFecha_ingreso(string fec) { fecha_ingreso = fec; }


	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getNit() { return nit; }
	int getGenero() { return genero; }
	string getTelefono() { return telefono; }
	string getCorreo_electronico() { return correo_electronico; }
	string getFecha_ingreso() { return fecha_ingreso; }


	void deleteC(int id_auxC) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;

		cn.abrir_conexion();




		if (cn.getConectar()) {
			cout << "Conexion Exitosa..." << endl;

			string idC = to_string(id_auxC);
			string ss;
			cout << "---------------------------------------------------" << endl;

			ss = "DELETE FROM clientes WHERE id_cliente= " + idC + " ";
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

	void updateC(int id_auxC,string auxg="") {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		

		cn.abrir_conexion();
		if (cn.getConectar()) {
			cout << "Conexion Exitosa..." << endl;

			string idC = to_string(id_auxC);
			
			string update;
			cout << "---------------------------------------------------" << endl;
			int f = 1;
			int m = 0;
			string t2 = to_string(f);
			string t3 = to_string(m);

			if (auxg == "f") {
				update = "UPDATE clientes SET nombres ='" + nombres + "', apellidos='" + apellidos + "', nit='" + nit + "', genero=" + t2+ ",telefono='" + telefono + "', correo_electronico='" + correo_electronico + "',fecha_ingreso='" + fecha_ingreso + "'  WHERE id_cliente =" + idC + " ";
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

			if (auxg == "m") {
				update = "UPDATE clientes SET nombres ='" + nombres + "', apellidos='" + apellidos + "', nit='" + nit + "', genero=" + t3 + ",telefono='" + telefono + "', correo_electronico='" + correo_electronico + "',fecha_ingreso='" + fecha_ingreso + "'  WHERE id_cliente =" + idC + " ";
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


		}
		else {
			cout << "error en la conexion" << endl;
		}
		cn.cerrar_conexion();

	}

	void crearC(string auxg="") {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			int f = 1;
			int m = 0;
			string t2 = to_string(f);
			string t3 = to_string(m);
			
			if (auxg == "f") {

				string insert = "INSERT INTO clientes(nombres,apellidos,nit,genero,telefono,correo_electronico)VALUES('" + nombres + "','" + apellidos + "','" + nit + "'," + t2 + ",'" + telefono + "','" + correo_electronico + "');";
				const char* i = insert.c_str();
				q_estado = mysql_query(cn.getConectar(), i);

				if (!q_estado) {
					cout << "ingreso exitoso...." << endl;
				}
				else {
					cout << "error al ingresar..." << endl;
				}
			}

			if (auxg == "m") {

				string insert = "INSERT INTO clientes(nombres,apellidos,nit,genero,telefono,correo_electronico)VALUES('" + nombres + "','" + apellidos + "','" + nit + "'," + t3 + ",'" + telefono + "','" + correo_electronico + "');";
				const char* i = insert.c_str();
				q_estado = mysql_query(cn.getConectar(), i);

				if (!q_estado) {
					cout << "ingreso exitoso...." << endl;
				}
				else {
					cout << "error al ingresar..." << endl;
				}
			}

		
		}
		else {
			cout << "error en la conexion" << endl;


		}
		cn.cerrar_conexion();


	}

	void leerC() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		int cl = 3;
		string auxgnro;

		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select * from clientes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {
					
					cl++;
					string fe = "f";
					string ma = "m";
					string gnf,cf;

					auxgnro = fila[4];
					cf = fila[3];

					if (auxgnro == "1") {
						gnf = fe;
					}
					else if (auxgnro == "0") {
						gnf = ma;
					}
					if(cf=="cf"){
						gotoxy(1, cl); cout << fila[0] << endl;
						gotoxy(5, cl); cout << fila[1] << endl;
						gotoxy(45, cl); cout << fila[3] << endl;
					}
					else {
						gotoxy(1, cl); cout << fila[0] << endl;
						gotoxy(5, cl); cout << fila[1] << endl;
						gotoxy(25, cl); cout << fila[2] << endl;
						gotoxy(45, cl); cout << fila[3] << endl;
						gotoxy(60, cl); cout << gnf << endl;
						gotoxy(64, cl); cout << fila[5] << endl;
						gotoxy(76, cl); cout << fila[6] << endl;
						gotoxy(100, cl); cout << fila[7] << endl;
					}
				
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