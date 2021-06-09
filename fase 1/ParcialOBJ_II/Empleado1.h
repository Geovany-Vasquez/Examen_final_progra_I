#pragma once
#include <mysql.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>
#include "ConexionBD.h"
#include "Persona.h"

using namespace std;
class Empleado1 : public Persona {
	// atributos
private: string id_puesto, fecha_inicio_labores, fecha_ingreso;
	   // constructor
public:
	Empleado1() {
	}
	Empleado1(string nom, string ape, string dir, int tel, string dp, int gn, string fn, string puesto, string inicio, string ingreso) : Persona(nom, ape, dir, tel, dp, gn, fn) {
		id_puesto = puesto;
		fecha_inicio_labores = inicio;
		fecha_ingreso = ingreso;



	}

	// METODOS
	//set (modificar)
	void setId_puesto(string puesto) { id_puesto = puesto; }
	void setFecha_inicio(string inicio) { fecha_inicio_labores = inicio; }
	void setFecha_ingreso(string ingreso) { fecha_ingreso = ingreso; }

	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }






	//get (mostrar)
	string getId_puesto() { return id_puesto; }
	string getFecha_inicio() { return fecha_inicio_labores; }
	string getFecha_ingreso() { return fecha_ingreso; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }






	// metodo

	void gotoxy(int x, int y)
	{
		COORD c = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	}

	void dele(int id_aux) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;

		cn.abrir_conexion();




		if (cn.getConectar()) {
			cout << "Conexion Exitosa..." << endl;

			string id1 = to_string(id_aux);
			string ss;
			cout << "---------------------------------------------------" << endl;

			ss = "DELETE FROM empleados WHERE id_empleado= " + id1 + " ";
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


	void update(int id_aux2,string auxg="") {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;

		cn.abrir_conexion();
		if (cn.getConectar()) {
			cout << "Conexion Exitosa..." << endl;

			string id2 = to_string(id_aux2);
			string t = to_string(telefono);
			
			cout << "---------------------------------------------------" << endl;
			int f = 1;
			int m = 0;
			string t2 = to_string(f);
			string t3 = to_string(m);
			string update;

			if (auxg == "f") {
				update = "UPDATE empleados SET nombres ='" + nombres + "' , apellidos = '" + apellidos + "',direccion ='" + direccion + "' ,telefono =" + t + " ,dpi ='" + dpi + "', genero =" + t2 + " ,fecha_nacimiento ='" + fecha_nacimiento + "' ,id_puesto='" + id_puesto + "' ,fecha_inicio_labores ='" + fecha_inicio_labores + "' ,fecha_ingreso='" + fecha_ingreso + "' WHERE id_empleado =" + id2 + " ";
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
				update = "UPDATE empleados SET nombres ='" + nombres + "' , apellidos = '" + apellidos + "',direccion ='" + direccion + "' ,telefono =" + t + " ,dpi ='" + dpi + "', genero =" + t3 + " ,fecha_nacimiento ='" + fecha_nacimiento + "' ,id_puesto='" + id_puesto + "' ,fecha_inicio_labores ='" + fecha_inicio_labores + "' ,fecha_ingreso='" + fecha_ingreso + "' WHERE id_empleado =" + id2 + " ";
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

	void crear(string auxg="") {
		int q_estado;
		
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string t = to_string(telefono);
			
			int f = 1;
			int m = 0;
			string t2 = to_string(f);
			string t3 = to_string(m);
			if (auxg=="f") {

				string insert = "INSERT INTO empleados(nombres,apellidos,direccion,telefono,dpi,genero,fecha_nacimiento,id_puesto,fecha_inicio_labores,fecha_ingreso) VALUES('" + nombres + "','" + apellidos + "','" + direccion + "'," + t + ",'" + dpi + "'," + t2 + ",'" + fecha_nacimiento + "','" + id_puesto + "','" + fecha_inicio_labores + "','" + fecha_ingreso + "');";
				const char* i = insert.c_str();
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					cout << "ingreso exitoso...." << endl;
				}
				else {
					cout << "error al ingresar..." << endl;
				}


			}else if (auxg == "m") {

				string insert = "INSERT INTO empleados(nombres,apellidos,direccion,telefono,dpi,genero,fecha_nacimiento,id_puesto,fecha_inicio_labores,fecha_ingreso) VALUES('" + nombres + "','" + apellidos + "','" + direccion + "'," + t + ",'" + dpi + "'," + t3 + ",'" + fecha_nacimiento + "','" + id_puesto + "','" + fecha_inicio_labores + "','" + fecha_ingreso + "');";
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

	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		string auxgnro;
		
		int cont = 1;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select e.id_empleado,e.nombres,e.apellidos,e.direccion,e.telefono,e.dpi,e.genero,e.fecha_nacimiento,p.puesto,e.fecha_inicio_labores, e.fecha_ingreso from empleados as e inner join puestos as p on e.id_puesto = p.id_puesto; ";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					string fe = "f";
					string ma = "m";
					string gnf;
					
						auxgnro = fila[6];
					
						if (auxgnro == "1") {
							gnf = fe;
						}
						else if (auxgnro == "0") {
							gnf = ma;
						}
					
					
						cout << fila[0] << " | " << fila[1] << " | " << fila[2] << " | " << fila[3] << " | " << fila[4] << " | " << fila[5] << " | " << gnf << " | " << fila[7] << " | " << fila[8] << " | " << fila[9] << " | " << fila[10] << endl;
					
					
					
							
						
						
							
					
					
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

