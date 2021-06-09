#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <windows.h> 
#include "ConexionBD.h"
#include "Ventas_detalle.h"
#include "Cliente1.h"
using namespace std;
class Ventas
{
private: string serie,fecha_factura,fecha_ingreso;
	   int no_factura = 0,id_cliente=0, id_empleado = 0;
	   
	   

	   // costructor
public:
	Ventas() {
	}
	Ventas(int nf,string sr,string ff,int idc,int ide, string fi) {
		no_factura = nf;
		serie = sr;
		fecha_factura = ff;
		id_cliente = idc;
		id_empleado = ide;
		fecha_ingreso = fi;

	}
	int cantidad=0;
	int id_venta = 0, id_producto = 0;
	float precio_unitario = 0,subtotal=0;
	

	void gotoxy(int x1, int y1)
	{
		HANDLE hcon;
		hcon = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD dwPos;
		dwPos.X = x1;
		dwPos.Y = y1;
		SetConsoleCursorPosition(hcon, dwPos);
	}

	void setNo_factura(int nf) { no_factura = nf; }
	void setSerie(string sr) { serie = sr; }
	void setFecha_factura(string ff) {fecha_factura = ff; }
	void setId_cliente(int  idc) {id_cliente= idc; }
	void setId_empleado(int  ide) { id_empleado = ide; }

	int  getNo_factura() { return no_factura; }
	string getSerie() { return serie; }
	string getFecha_facturada() { return fecha_factura; }
	int getId_cliente() { return id_cliente; }
	int getId_empleado() { return id_empleado; }
	string getFecha_ingreso() { return fecha_ingreso; }


	typedef std::basic_ifstream<TCHAR> tifstream;
	typedef std::basic_string<TCHAR> tstring;

	void Outtextxy(HDC hdc, int x, int y, tstring Msg)
	{
		TextOut(hdc, x, y, Msg.c_str(), static_cast<int>(Msg.length()));
	}

	void ShowError(tstring strMsg)
	{
		MessageBox(NULL, strMsg.c_str(), TEXT("Imprimir"), MB_ICONERROR);
		exit(1);
	}
	void ShowInformation(tstring strText)
	{
		MessageBox(NULL, strText.c_str(), TEXT("Imprimir"), MB_ICONINFORMATION);
	}
	void PrintFile(tifstream& f)
	{
		PRINTDLG pd;
		DOCINFO di;
		tstring strLine;
		int y = 300;

		memset(&pd, 0, sizeof(PRINTDLG));
		memset(&di, 0, sizeof(DOCINFO));

		di.cbSize = sizeof(DOCINFO);
		di.lpszDocName = TEXT("Imprimiendo");

		pd.lStructSize = sizeof(PRINTDLG);
		pd.Flags = PD_PAGENUMS | PD_RETURNDC;
		pd.nFromPage = 1;
		pd.nToPage = 1;
		pd.nMinPage = 1;
		pd.nMaxPage = 0xFFFF;


		if (f.fail())
			ShowError(TEXT("Error el archivo no se pudo abrir para lectura"));

		if (PrintDlg(&pd)) {
			if (pd.hDC) {
				if (StartDoc(pd.hDC, &di) != SP_ERROR) {
					cout << "Imprimiendo...\nEspere un momento" << endl;
					StartPage(pd.hDC);
					while (!f.eof()) {
						getline(f, strLine);
						Outtextxy(pd.hDC, 500, y, strLine.c_str());
						y += 100;
					}
					EndPage(pd.hDC);
					EndDoc(pd.hDC);

				}
				else
					ShowError(TEXT("Error: No se pudo comenzar a imprimir."));

			}
			else
				ShowError(TEXT("Error: No se pudo crear el contexto de dispositivo"));

		}
		else
			ShowInformation(TEXT("Se cancelo la impresion"));

		ShowInformation(TEXT("Termino la impresion correctamente."));
	}

	void impresion(int argc, char* argv[])
	{

		tifstream in(TEXT("prueba.txt"));
		PrintFile(in);
		in.close();
		system("pause");
	}
	

	void factura(float sub1 = 0.00) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		MYSQL_ROW fila1;
		MYSQL_RES* resultado1;
		int cl = 10;
		int cp = 15;
		int fn = 0, fn1 = 0;
		float efectivo = 0, cambio = 0;
		string id_auxFac, id_auxFac2;
		string auxnom;



		cn.abrir_conexion();
		ofstream archivo;
		archivo.open("prueba.txt", ios::out);
		if (archivo.fail()) {
			cout << "no se pudo abrir el archivo";
			exit(1);
		}
		if (cn.getConectar()) {
			string consulta = "SELECT MAX(id_venta) FROM ventas;";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {

					id_auxFac = fila[0];

				}


			}
			string consulta1 = "select c.id_venta,c.no_factura,c.serie,c.fecha_factura,p.nombres,p.apellidos,p.nit,f.nombres,c.fecha_ingreso from ventas as c inner join clientes as p on c.id_cliente = p.id_cliente inner join ventas as m on c.id_venta = m.id_venta inner join empleados as f on c.id_empleado = f.id_empleado Where c.id_venta = '" + id_auxFac + "'; ";
			const char* c1 = consulta1.c_str();
			q_estado = mysql_query(cn.getConectar(), c1);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {
					gotoxy(1, 1); cout << "----------------------------------------TIENDA SS------------------------------------" << endl;
					gotoxy(1, 2); cout << " ----------------------------------4ta calle antigua---------------------------------" << endl;
					gotoxy(1, 3); cout << "-------------------------------- -Telefono:7832-0000---------------------------------" << endl;
					gotoxy(1, 4); cout << "------------------------------------NIT: 293829382-----------------------------------" << endl;

					gotoxy(1, 1); archivo << "----------------------------------TIENDA SS------------------------------------" << endl;
					gotoxy(1, 2); archivo << "------------------------------4ta calle antigua---------------------------------" << endl;
					gotoxy(1, 3); archivo << "------------------------------Telefono:7832-0000---------------------------------" << endl;
					gotoxy(1, 4); archivo << "--------------------------------NIT: 293829382-----------------------------------" << endl;

					gotoxy(1, 11); cout << "No.Compra:" << fila[0] << endl;
					gotoxy(1, 7); cout << "No.Factura:" << fila[1] << endl;
					gotoxy(45, 7); cout << "Serie:" << fila[2] << endl;
					gotoxy(45, 8); cout << "Fecha:" << fila[3] << endl;
					gotoxy(1, 9); cout << "Nombre:" << fila[4] << endl;

					gotoxy(1, 11); archivo << "No.Compra:" << fila[0] << "                              Fecha Ingreso:" << fila[8] << endl;
					gotoxy(1, 7);  archivo << "No.Factura:" << fila[1] << "                           Serie:" << fila[2] << endl;


					gotoxy(1, 9); archivo << "Nombre:" << fila[4] << endl;

					auxnom = fila[6];
					if (auxnom == "cf") {
						gotoxy(1, 10); cout << "       " << endl;
						gotoxy(1, 10); archivo << "                                           Empleado:" << fila[7] << endl;
					}
					else {
						gotoxy(1, 10); cout << "Apellido:" << fila[5] << endl;
						gotoxy(1, 10); archivo << "Apellido:" << fila[5] << "                               Empleado:" << fila[7] << endl;

					}
					gotoxy(1, 8); cout << "Nit:" << fila[6] << endl;
					gotoxy(45, 10); cout << "Empleado:" << fila[7] << endl;
					gotoxy(45, 11); cout << "Fecha Ingreso:" << fila[8] << endl;

					gotoxy(1, 8); archivo << "Nit:" << fila[6] << "                                         Fecha:" << fila[3] << endl;
					gotoxy(3, 13); archivo << "CNT" << "        Producto" << "            Marca" << "                P/U" << "            SUBT" << endl;


				}


			}
			string consulta2 = "select c.id_venta,f.producto,ma.marca,c.cantidad,c.precio_unitario,c.subtotal from ventas_detalle as c inner join productos as f on c.id_producto = f.id_producto inner join marcas as ma on c.id_producto = ma.id_marca Where c.id_venta = '" + id_auxFac + "'; ";
			const char* c2 = consulta2.c_str();
			q_estado = mysql_query(cn.getConectar(), c2);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {
					cp++;
					fila[0];
					gotoxy(3, 13); cout << "Producto" << endl;
					gotoxy(22, 13);	cout << "Marca" << endl;
					gotoxy(35, 13);	cout << "Cantidad" << endl;
					gotoxy(50, 13);	cout << "P/U" << endl;
					gotoxy(65, 13);	cout << "SUBT" << endl;
					gotoxy(75, 13);	cout << "Total" << endl;




					gotoxy(3, cp);	cout << fila[1] << endl;
					gotoxy(22, cp); cout << fila[2] << endl;
					gotoxy(37, cp);	cout << fila[3] << endl;
					gotoxy(50, cp);	cout << fila[4] << endl;
					gotoxy(65, cp);	cout << fila[5] << endl;

					gotoxy(3, cp);	archivo << fila[3] << "          " << fila[1] << "               " << fila[2] << "                " << fila[4] << "           " << fila[5] << endl;


				}
				gotoxy(75, cp); cout << sub1 << endl;
				gotoxy(75, cp); archivo << "                                 Total:" << sub1 << endl;
				fn = cp + 1;
				do
				{
					gotoxy(84, fn); cout << "         " << endl;
					gotoxy(75, fn); cout << "Efectivo:", cin >> efectivo;


				} while (efectivo < sub1);
				gotoxy(75, fn); archivo << "                               " << "Efectivo:" << efectivo << endl;
				cambio = efectivo - sub1;
				fn1 = fn + 1;
				gotoxy(75, fn1); cout << "Cambio: " << cambio << endl;
				gotoxy(35, fn1); cout << "GRACIAS POR SU COMPRA" << endl;

				gotoxy(75, fn1); archivo << "                               " << "Cambio: " << cambio << endl;
				gotoxy(35, fn1); archivo << "                            " << "GRACIAS POR SU COMPRA" << endl;

				archivo.close();


			}


			else {
				cout << " xxx Error al ingresar informacion xxxx" << endl;
			}

		}
		else {
			cout << "error en la conexion" << endl;


		}

		cn.cerrar_conexion();
		void impresion(int argc, char* argv[]); {

			tifstream in(TEXT("prueba.txt"));
			PrintFile(in);
			in.close();
			system("pause");


		}

	}
	
	void autofecha(string id_auxVN2) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		
		


		char resp = 's';


		int cont = 13;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select  fecha_ingreso,fecha_factura from ventas where id_venta ='"+ id_auxVN2 +"'; ";
			const char* c = consulta.c_str();

			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {
				
					gotoxy(58, 1); cout << fila[0] << endl;
					gotoxy(58, 5); cout << fila[1] << endl;
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
	void autoNit(string id_auxNit) {
		int q_estado;
		
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		string consulta;
		string id_auxNit1;
		
		string id_auxapel;
		
		
		
		string cons = "";
		char se='A';
			string id_auxVN3;
			string nofac;
			
		int cont = 11;
		cn.abrir_conexion();
		if (cn.getConectar()) 
		{
			string consulta1 = "SELECT MAX(no_factura)+1 FROM ventas; ";
			const char* c1 = consulta1.c_str();

			q_estado = mysql_query(cn.getConectar(), c1);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {
					nofac = fila[0];
					gotoxy(1, 8); cout << "no_factura:" << nofac << endl;

				}
			}
		
			gotoxy(1, 9); cout << "serie:"<<se<< endl;
			
			
			
			
			
			if (id_auxNit=="cf") {
				 consulta = "select id_cliente, nombres from clientes Where nit = '" + id_auxNit + "'; ";
			}
			else {
				consulta = "select id_cliente, nombres, apellidos from clientes Where nit = " + id_auxNit + "; ";
			}
			
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					id_auxNit1 = fila[0];
					id_auxVN3 = id_auxNit1;
					if (id_auxNit == "cf") {
						gotoxy(8, 3); cout << fila[1] << endl;
					}
					else {
						gotoxy(8, 3); cout << fila[1] << endl;
						gotoxy(10, 5); cout << fila[2] << endl;
					}
					

				}
						
	
				gotoxy(52, 3); cin >> id_empleado; cin.ignore();
				
				
				Ventas v = Ventas(no_factura, serie, fecha_factura, id_cliente, id_empleado, fecha_ingreso);
				v.crearVENT(se, id_auxVN3,nofac);


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
		string id_auxVN2, id_auxVN5,id_auxVN6, id_auxVN7;
		float total = 0, total1 = 0, sub = 0, sub1 = 0.00, id_auxsubtotal=0;
		
		char resp = 's';
		
	
		int cont = 13;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "SELECT MAX(id_venta)  FROM ventas;";
			const char* c = consulta.c_str();

			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {
					id_auxVN2 = fila[0];


				}
				Ventas v = Ventas(no_factura, serie, fecha_factura, id_cliente, id_empleado, fecha_ingreso);
				v.autofecha(id_auxVN2);
			
					do {
						cont++;
						total = sub + sub;
						gotoxy(1, 13); cout << id_auxVN2 << endl;
						gotoxy(10, cont); cin >> id_producto; cin.ignore();
						
						string  id_auxVN6 = to_string(id_producto);
					
						string consulta3 = "select p.producto,n.marca from productos as p inner join marcas as n on p.id_marca = n.id_marca Where id_producto = '"+id_auxVN6+"';";
						const char* c2 = consulta3.c_str();

						q_estado = mysql_query(cn.getConectar(), c2);
						if (!q_estado) {
							resultado = mysql_store_result(cn.getConectar());

							while (fila = mysql_fetch_row(resultado)) {
								id_auxVN5 = fila[0];
								id_auxVN7=fila[1];


							}
						}


						gotoxy(25, cont); cout << id_auxVN5 << endl;
						gotoxy(45, cont); cout << id_auxVN7 << endl;
						gotoxy(62, cont); cin >> cantidad; cin.ignore();
						gotoxy(75, cont); cin >> precio_unitario; cin.ignore();
						
						sub= cantidad * precio_unitario;
						id_auxsubtotal = sub;
						gotoxy(95, cont);  cout <<sub<<endl;
						sub1 += sub;
						
						gotoxy(105, 13); cout << sub1 << endl;

						gotoxy(30, 11); cout << "desea ingresar otros datos[s/n]", cin >> resp;
						gotoxy(30, 11); cout << "                                    " << endl;

						Ventas_detalle vt = Ventas_detalle(id_venta, id_producto, cantidad, precio_unitario, subtotal);
						vt.crearVENT(id_auxVN2, id_auxsubtotal);
						

					} while (resp == 's');
					
					gotoxy(105, 13); cout <<"           "<< endl;
					gotoxy(105, cont); cout << sub1 << endl;
					
					system("pause");
					system("cls");
					Ventas v1 = Ventas(no_factura, serie, fecha_factura, id_cliente, id_empleado, fecha_ingreso);
					v1.factura(sub1);
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
	

	void crearVENT(char se, string id_auxVN3,string nofac) {
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		
		int q_estado;
		ConexionBD cn = ConexionBD();
		
		
		string nof = to_string(no_factura);
		string dcl = to_string(id_cliente);
		string dem = to_string(id_empleado);
		
		
		

		cn.abrir_conexion();
		if (cn.getConectar()) {
			

			string insert = "INSERT INTO ventas(no_factura,serie,id_cliente,id_empleado) VALUES('" + nofac + "','" + se + "','" + id_auxVN3 + "'," +  dem + ");";
			
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {
				gotoxy(1, 10);  cout << "ingreso exitoso...." << endl;
				
				
				Ventas v1 = Ventas(no_factura, serie, fecha_factura, id_cliente, id_empleado, fecha_ingreso);
				v1.autof();
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
			string consulta = "select c.id_venta,c.no_factura,c.serie,c.fecha_factura,p.nombres,m.nit,f.nombres,c.fecha_ingreso from ventas as c inner join clientes as p on c.id_cliente = p.id_cliente inner join clientes as m on c.id_cliente = m.id_cliente inner join empleados as f on c.id_empleado = f.id_empleado Where c.no_factura ="+ idventa +"; ";
			const char* c = consulta.c_str();
			
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {
					
					cl++;
					id_auxVN1 = fila[0];

					
					gotoxy(7, 3); cout << fila[2] << endl;
					gotoxy(50, 1); cout << fila[4] << endl;
					
					gotoxy(51, 3); cout << fila[6] << endl;
					gotoxy(78, 8); cout << fila[3] << endl;
					gotoxy(78, 15); cout << fila[7] << endl;
					

				
					

					
					Ventas_detalle vt = Ventas_detalle(id_venta, id_producto, cantidad, precio_unitario,subtotal);
					vt.leerVTll(id_auxVN1);

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

