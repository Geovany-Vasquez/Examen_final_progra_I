// ParcialOBJ_II.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include <windows.h> 
#include <fstream> 
#include "Empleado1.h"
#include "Cliente1.h"
#include "puesto.h"
#include "Marca.h"
#include "Proveedor1.h"
#include "Productos.h"
#include "Ventas_detalle.h"
#include "Ventas.h"
#include "Compras_detalle.h"
#include "Compras.h"
using namespace std;
int q_estado;

void gotoxy(int x1, int y1);
int main() {
	string nombres, apellidos, direccion, dpi, fecha_nacimiento, id_puesto, fecha_inicio_labores, fecha_ingreso,correo_electronico;
	string puesto,proveedor;
	string producto, descripcion;
	string marca;
	string telefonoC, nitC, nitp, telefonop;
	int existencia = 0, id_marca=0;
	float precio_venta = 0, precio_costo = 0;
	int nit = 0;
	int genero =0;
	
	int telefono = 0;
	int id_auxp = 0, id_auxp1 = 0,id_aux2 = 0,id_aux = 0;
	int id_auxC = 0, id_auxM = 0,id_auxPR=0;
	int id_auxVN = 0;
	string serie, fecha_factura,cantidad,id_auxVN2;
	int no_factura = 0, id_cliente = 0, id_empleado = 0;
	int id_auxVN1 = 0;
	int id_compra = 0, id_venta = 0,id_producto=0;
	float precio_costo_unitario = 0,subtotal=0;

	string  fecha_orden, idcli;
	int no_orden_compra = 0, id_proveedor = 0;
	string auxg="";
	string id_auxNit = "";
	

	int op = 0;

	int op1 = 0;


do {
	system("cls");
		cout << "-----------------menu-----------------" << endl;
		cout << "1. Empleados" << endl;
		cout << "2. Puestos" << endl;
		cout << "3. Clientes" << endl;
		cout << "4. Marcas"<<endl;
		cout << "5. Proveedores" << endl;
		cout << "6. Productos" << endl;
		cout << "7. Ventas[detalle]" << endl;
		cout << "8. Compras[detalle]" << endl;
		cout << "9. Salir" << endl;
		cout << "ingrese su opcion: "; cin >> op; cin.ignore();
		switch (op) {

		case 1:
			do {
				system("cls");
				cout << "1. INGRESAR" << endl;
				cout << "2. MOSTRAR" << endl;
				cout << "3. ELIMINAR" << endl;
				cout << "4. ACTUALIZAR" << endl;
				cout << "5. SALIR" << endl;

				cout << "ingrese su opcion: "; cin >> op1; cin.ignore();
				if (op1 == 1) {
					system("cls");
					cout << "ingrese sus nombres:" << endl;
					getline(cin, nombres);
					cout << "ingrese sus apellidos:" << endl;
					getline(cin, apellidos);
					cout << "ingrese direccion:" << endl;
					getline(cin, direccion);
					cout << "ingrese telefono" << endl;
					cin >> telefono;
					cin.ignore();
					cout << "ingrese dpi" << endl;
					getline(cin, dpi);
					cout << "ingrese genero masculino m /femenino f:" << endl;
					getline(cin, auxg);
					
					cout << "ingrese fecha de nacimiento" << endl;
					getline(cin, fecha_nacimiento);
					cout << "ingrese id_puesto" << endl;
					getline(cin, id_puesto);
					cout << "ingrese fecha de inicio de labores" << endl;
					getline(cin, fecha_inicio_labores);
					cout << "ingrese fecha ingreso" << endl;
					getline(cin, fecha_ingreso);


					Empleado1 c = Empleado1(nombres, apellidos, direccion, telefono, dpi, genero, fecha_nacimiento, id_puesto, fecha_inicio_labores, fecha_ingreso);
					c.crear(auxg);
					system("pause");
				}
				if (op1 == 2) {
					system("cls");
					Empleado1 c = Empleado1(nombres, apellidos, direccion, telefono, dpi, genero, fecha_nacimiento, id_puesto, fecha_inicio_labores, fecha_ingreso);
					c.leer();
					system("pause");
				}
				if (op1 == 3) {
					system("cls");
					
					cout << "ingrese el id del registro a eliminar: "; cin >> id_aux;
					Empleado1 c = Empleado1(nombres, apellidos, direccion, telefono, dpi, genero, fecha_nacimiento, id_puesto, fecha_inicio_labores, fecha_ingreso);
					c.dele(id_aux);
					system("pause");
				}
				if (op1 == 4) {
					system("cls");
					cout << "ingrese id del registro a modificar: "; cin >> id_aux2; cin.ignore();
					cout << "ingrese sus nombres:" << endl;
					getline(cin, nombres);
					cout << "ingrese sus apellidos:" << endl;
					getline(cin, apellidos);
					cout << "ingrese direccion:" << endl;
					getline(cin, direccion);
					cout << "ingrese telefono" << endl;
					cin >> telefono;
					cin.ignore();
					cout << "ingrese dpi" << endl;
					getline(cin, dpi);
					cout << "ingrese genero hombre m /mujer f :" << endl;
					getline(cin, auxg);
					cout << "ingrese fecha de nacimiento" << endl;
					getline(cin, fecha_nacimiento);
					cout << "ingrese id_puesto" << endl;
					getline(cin, id_puesto);
					cout << "ingrese fecha de inicio de labores" << endl;
					getline(cin, fecha_inicio_labores);
					cout << "ingrese ingreso" << endl;
					getline(cin, fecha_ingreso);

					Empleado1 c1 = Empleado1(nombres, apellidos, direccion, telefono, dpi, genero, fecha_nacimiento, id_puesto, fecha_inicio_labores, fecha_ingreso);
					c1.update(id_aux2,auxg);
					system("pause");

				}
				if (op1 == 5) { system("cls"); main(); }
			} while (op <= 5);
			break;

		case 2:
			do {
				system("cls");
				cout << "1. INGRESAR" << endl;
				cout << "2. MOSTRAR" << endl;
				cout << "3. ELIMINAR" << endl;
				cout << "4. ACTUALIZAR" << endl;
				cout << "5. SALIR" << endl;

				cout << "ingrese su opcion: "; cin >> op1; cin.ignore();

				if (op1 == 1) {
					system("cls");
					cout << "ingrese un puesto: ";
					getline(cin, puesto);

					Puesto p = Puesto(puesto);
					p.crear1();
					system("pause");
				}
				if (op1 == 2) {
					system("cls");
					Puesto p = Puesto(puesto);
					p.leer1();
					system("pause");
				}
				if (op1 == 3) {
					system("cls");
					cout << "ingrese el id del registro a eliminar: "; cin >> id_auxp;
					Puesto p = Puesto(puesto);
					p.deletep(id_auxp);
					system("pause");
				}
				if (op1 == 4) {
					system("cls");
					cout << "ingrese el id del registro a actualizar: "; cin >> id_auxp1; cin.ignore();
					cout << "ingrese el nuevo puesto" << endl;
					getline(cin, puesto);
					Puesto p1 = Puesto(puesto);
					p1.updatep(id_auxp1);
					system("pause");
				}
				if (op1 == 5) { system("cls"); main(); }
			} while (op <= 5);
			break;
		
		case 3:
			do {
			system("cls");
			cout << "1. INGRESAR" << endl;
			cout << "2. MOSTRAR" << endl;
			cout << "3. ELIMINAR" << endl;
			cout << "4. ACTUALIZAR" << endl;
			cout << "5. SALIR" << endl;

			cout << "ingrese su opcion: "; cin >> op1; cin.ignore();
			if (op1 == 1) {
				system("cls");
				cout << "ingrese sus nombres:" << endl;
				getline(cin, nombres);
				cout << "ingrese sus apellidos:" << endl;
				getline(cin, apellidos);
				cout << "ingrese nit:" << endl;
				getline(cin, nitC);
				cout << "ingrese genero hombre m / mujer f " << endl;
				getline(cin, auxg);
				
				cout << "ingrese telefono" << endl;
				getline(cin, telefonoC);
				cout << "ingrese correo electronico" << endl;
				getline(cin, correo_electronico);
				
				Cliente1 t = Cliente1(nombres, apellidos, nitC, genero, telefonoC, correo_electronico, fecha_ingreso);
				t.crearC(auxg);
				system("pause");
			}
			if (op1 == 2) {
				system("cls");
				Cliente1 t = Cliente1(nombres, apellidos, nitC, genero, telefonoC, correo_electronico, fecha_ingreso);
				t.leerC();
				system("pause");
			}
			if (op1 == 3) {
				system("cls");
				cout << "ingrese el id del registro a eliminar: "; cin >> id_auxC;
				Cliente1 t = Cliente1(nombres, apellidos, nitC, genero, telefonoC, correo_electronico, fecha_ingreso);
				t.deleteC(id_auxC);
				system("pause");
			}
			if (op1 == 4) {
				system("cls");
				
cout << "ingrese id del registro a modificar: "; cin >> id_auxC; cin.ignore();

	cout << "ingrese sus nombres:" << endl;
	getline(cin, nombres);
	cout << "ingrese sus apellidos:" << endl;
	getline(cin, apellidos);
	cout << "ingrese nit:" << endl;
	getline(cin, nitC);
	cout << "ingrese genero hombre 0 / mujer 1 " << endl;
	getline(cin, auxg);
	cout << "ingrese telefono" << endl;
	getline(cin, telefonoC);
	cout << "ingrese correo electronico" << endl;
	getline(cin, correo_electronico);
	cout << "ingrese fecha de ingreso" << endl;
	getline(cin, fecha_ingreso);
	Cliente1 t = Cliente1(nombres, apellidos, nitC, genero, telefonoC, correo_electronico, fecha_ingreso);
	t.updateC(id_auxC,auxg);
	system("pause");
			}
			if (op1 == 5) { system("cls"); main(); }
			} while (op <= 5);


break;

	

case 4:
	do {
		system("cls");
		cout << "1. INGRESAR" << endl;
		cout << "2. MOSTRAR" << endl;
		cout << "3. ELIMINAR" << endl;
		cout << "4. ACTUALIZAR" << endl;
		cout << "5. SALIR" << endl;

		cout << "ingrese su opcion: "; cin >> op1; cin.ignore();

		if (op1 == 1) {
			system("cls");
		    cout << "ingrese una marca: " << endl;
			getline(cin, marca);
			Marca m = Marca(marca);
			m.crearM();
			system("pause");
		}
		if (op1 == 2) {
			system("cls");
			Marca m = Marca(marca);
		   m.leerM();
			system("pause");
		}
		if (op1 == 3) {
			system("cls");
			cout << "ingrese el id del registro a eliminar: "; cin >> id_auxM;
			Marca m = Marca(marca);
			m.deleteM(id_auxM);
			system("pause");
		}
		if (op1 == 4) {
			system("cls");
			cout << "ingrese el id de la marca para actualizar: "; cin >> id_auxM; cin.ignore();
			cout << "ingrese nueva marca" << endl;
			getline(cin, marca);
			Marca m = Marca(marca);
			m.updateM(id_auxM);
			system("pause");
		}
		if (op1 == 5) { system("cls"); main(); }
	} while (op <= 6);
	break;
	



case 5:
	do {
		system("cls");
		cout << "1. INGRESAR" << endl;
		cout << "2. MOSTRAR" << endl;
		cout << "3. ELIMINAR" << endl;
		cout << "4. ACTUALIZAR" << endl;
		cout << "5. SALIR" << endl;

		cout << "ingrese su opcion: "; cin >> op1; cin.ignore();

if (op1 == 1) {
	system("cls");
	
	cout << "ingrese un proveedor: " << endl;
	getline(cin, proveedor);
	cout << "ingrese nit: " << endl;
	getline(cin, nitC);
	cout << "ingrese una direccion: " << endl;
	getline(cin, direccion);
	cout << "ingrese el numero de telefono: " << endl;
	getline(cin, telefonoC);

	Proveedor1 pv = Proveedor1(proveedor, nitp, direccion, telefonop);
	pv.crearPR();
	system("pause");
}

if (op1 == 2) {
	
	system("cls");
	Proveedor1 pv1 = Proveedor1(proveedor, nitp, direccion, telefonop);
	pv1.leerPR();
	system("pause");
}
		if (op1 == 3) {
			system("cls");
			cout << "ingrese el id del registro a eliminar: "; cin >> id_auxPR;
			Proveedor1 pv = Proveedor1(proveedor, nitp, direccion, telefonop);
			pv.deletePR(id_auxPR);
			system("pause");
		}

		if (op1 == 4) {
			system("cls");
			cout << "ingrese id del registro a modificar: "; cin >> id_auxPR; cin.ignore();
			cout << "ingrese un proveedor: " << endl;
			getline(cin, proveedor);
			cout << "ingrese nit: " << endl;
			getline(cin, nitC);
			cout << "ingrese una direccion: " << endl;
			getline(cin, direccion);
			cout << "ingrese el numero de telefono: " << endl;
			getline(cin, telefonoC);

			Proveedor1 pv2 = Proveedor1(proveedor, nitC, direccion, telefonoC);
			pv2.updatePR(id_auxPR);

			system("pause");

		}
		if (op1 == 5) { system("cls"); main(); }

		} while (op <= 5);
		break;
		
	

case 6:
	do {
		system("cls");
		cout << "1. INGRESAR" << endl;
		cout << "2. MOSTRAR" << endl;
		cout << "3. ELIMINAR" << endl;
		cout << "4. ACTUALIZAR" << endl;
		cout << "5. SALIR" << endl;

		cout << "ingrese su opcion: "; cin >> op1; cin.ignore();
	
		if (op1 == 1) {
			system("cls");
			cout << "ingrese producto:" << endl;
			getline(cin, producto);
			cout << "ingrese id_marca:" << endl;
			cin >> id_marca;
			cin.ignore();
			cout << "ingrese descripcion:" << endl;
			getline(cin, descripcion);
			cout << "precio costo: " << endl;
			cin >> precio_costo;
			cin.ignore();
			cout << "ingrese precio venta: " << endl;
			cin >> precio_venta;
			cin.ignore();
			cout << "ingrese existencia :" << endl;
			cin >> existencia;
			cin.ignore();
			cout << "ingrese fecha de ingreso: " << endl;
			getline(cin, fecha_ingreso);

			Productos pr = Productos(producto, id_marca, descripcion, precio_costo, precio_venta, existencia, fecha_ingreso);
			pr.crearPRD();
			system("pause");
		}

		if (op1 == 2) {
			system("cls");
			gotoxy(1,1); cout << "Id" << endl;
			gotoxy(5, 1); cout <<"PDTO"<< endl;
			gotoxy(20, 1); cout <<"MRC" << endl;
			gotoxy(40, 1); cout <<"DES"<< endl;
			gotoxy(70, 1); cout << "P.COSTO"<< endl;
			gotoxy(78, 1); cout << "P.VENTA"<< endl;
			gotoxy(90, 1); cout <<"EXT"<< endl;
			gotoxy(95, 1); cout <<"FCH ING"<< endl;
			Productos pr = Productos(producto, id_marca, descripcion, precio_costo, precio_venta, existencia, fecha_ingreso);
			pr.leerPRD();
			system("pause");
		}
		
		if (op1 == 3) {
		system("cls");
		cout << "ingrese el id del registro a eliminar: "; cin >> id_auxPR;
		Productos pr = Productos(producto, id_marca, descripcion, precio_costo, precio_venta, existencia, fecha_ingreso);
		pr.deletePRD(id_auxPR);
		system("pause");
	}


if (op1 == 4) {
			system("cls");
cout << "ingrese id del registro a modificar: "; cin >> id_auxPR; cin.ignore();
cout << "ingrese producto:" << endl;
getline(cin, producto);
cout << "ingrese id_marca:" << endl;
cin>>id_marca;
cin.ignore();
cout << "ingrese descripcion:" << endl;
getline(cin, descripcion);
cout << "precio costo: " << endl;
cin >> precio_costo;
cin.ignore();
cout << "ingrese precio venta: " << endl;
cin>>precio_venta;
cin.ignore();
cout << "ingrese existencia :" << endl;
cin >> existencia;
cin.ignore();
cout << "ingrese fecha de ingreso: " << endl;
getline(cin, fecha_ingreso);

Productos pr = Productos(producto,id_marca,descripcion,precio_costo,precio_venta,existencia,fecha_ingreso);
pr.updatePRD(id_auxPR);
system("pause");
}
if (op1 == 5) { system("cls"); main(); }

	} while (op <= 5);
	break;
		
	
	case 7:
		do {
			system("cls");
		
		cout << "1. MOSTRAR" << endl;
		cout << "2. INGRESAR" << endl;	
		cout << "3. SALIR" << endl;

		cout << "ingrese su opcion: "; cin >> op1; cin.ignore();
		
		if (op1 == 1) {
			
			
			system("cls");
			gotoxy(1, 3); cout << "SERIE:" << endl;
			gotoxy(60, 8); cout << "FECHA FACTURADA:" << endl;
			gotoxy(40, 1); cout << "CLIENTE:" << endl;
			gotoxy(40, 3); cout << "EMPLEADO:" << endl;
			gotoxy(60, 15); cout << "FECHA INGRESO:" << endl;
			gotoxy(1, 8); cout << "ID" << endl;
			gotoxy(5, 8); cout << "ID VENTA" << endl;
			gotoxy(20, 8); cout << "PRODUCTO" << endl;
			gotoxy(35, 8); cout << "CANTIDAD" << endl;
			gotoxy(48, 8); cout << "PRECIO U" << endl;

			gotoxy(1, 1); cout << "NO.FACTURA: ", cin >> id_auxVN; cin.ignore();


			Ventas v = Ventas(no_factura, serie, fecha_factura, id_cliente, id_empleado, fecha_ingreso);
			v.leerVent(id_auxVN);
			system("pause");
		}

		if (op1 == 2) {
			system("cls");

			cout << "Ingresar nuevo cliente s/n:", getline(cin, idcli);
			if(idcli=="s"){
				cout << "" << endl;
				cout << "ingrese sus nombres:" << endl;
				getline(cin, nombres);
				cout << "ingrese sus apellidos:" << endl;
				getline(cin, apellidos);
				cout << "ingrese nit:" << endl;
				getline(cin, id_auxNit);
				cout << "ingrese genero hombre m / mujer f " << endl;
				getline(cin, auxg);
				nitC = id_auxNit;
				cout << "ingrese telefono" << endl;
				getline(cin, telefonoC);
				cout << "ingrese correo electronico" << endl;
				getline(cin, correo_electronico);
				
				Cliente1 t = Cliente1(nombres, apellidos, nitC, genero, telefonoC, correo_electronico, fecha_ingreso);
				t.crearC(auxg);
			}
			else {
				gotoxy(1, 1);	cout << "nit:", getline(cin, id_auxNit);
				

			}
			system("cls");
			gotoxy(1, 1);	cout << "nit:"<< id_auxNit<<endl;
			gotoxy(1, 12); cout <<"Venta" << endl;
gotoxy(95, 12); cout <<"Subtotal" <<endl;
gotoxy(105, 12); cout <<"Total" <<endl;
gotoxy(10, 12); cout <<"IdProducto"<< endl;
gotoxy(25, 12); cout <<"Producto"<< endl;
gotoxy(45, 12); cout << "Marca" << endl;
gotoxy(62, 12); cout <<"Cantidad"<< endl;
gotoxy(75, 12); cout <<"Precio Unitario" << endl;
gotoxy(1, 3); cout <<"Nombre: " << endl;
gotoxy(1, 5); cout <<"Apellido: " << endl;
gotoxy(40, 1); cout << "Fecha_Ingreso: " << endl;
gotoxy(40, 3); cout << "id_empleado: " << endl;
gotoxy(40, 5); cout << "fecha facturada: " << endl;

Ventas v = Ventas(no_factura, serie, fecha_factura, id_cliente, id_empleado, fecha_ingreso);
v.autoNit(id_auxNit);

			
			system("pause");
		}
		if (op1 == 3) { system("cls"); main(); }

		} while (op <= 3);
		break;
	case 8:
		do {
			system("cls");

			cout << "1. MOSTRAR" << endl;
			cout << "2. INGRESAR" << endl;
			cout << "3. SALIR" << endl;

			cout << "ingrese su opcion: "; cin >> op1; cin.ignore();

			if (op1 == 1) {
				system("cls");
gotoxy(1, 3); cout << "PROVEEDOR: " << endl;
gotoxy(60, 8); cout << "FECHA FACTURADA:" << endl;
gotoxy(40, 1); cout << "DIRECCION: " << endl;

gotoxy(80, 8); cout << "FECHA INGRESO:" << endl;
gotoxy(1, 8); cout << "ID" << endl;
gotoxy(5, 8); cout << "ID COMPRA" << endl;
gotoxy(20, 8); cout << "PRODUCTO" << endl;
gotoxy(35, 8); cout << "CANTIDAD" << endl;
gotoxy(48, 8); cout << "PRECIO U" << endl;
gotoxy(102,8 ); cout << "NO.COMPRA" << endl;

gotoxy(1, 1); cout << "NIT: ", cin >> id_auxVN; cin.ignore();
Compras cm = Compras(no_orden_compra, id_proveedor, fecha_orden, fecha_ingreso);
cm.leerVent(id_auxVN);
system("pause");
		}

if (op1 == 2) {
	system("cls");
gotoxy(1, 12); cout << "Compra" << endl;
gotoxy(95, 12); cout << "Subtotal" << endl;
gotoxy(105, 12); cout << "Total" << endl;
gotoxy(10, 12); cout << "IdProducto" << endl;
gotoxy(25, 12); cout << "Producto" << endl;
gotoxy(45, 12); cout << "Marca" << endl;
gotoxy(62, 12); cout << "Cantidad" << endl;
gotoxy(75, 12); cout << "Precio Unitario" << endl;
gotoxy(1, 3); cout << "Proveedor: " << endl;
gotoxy(1, 5); cout << "Direccion: " << endl;
gotoxy(45, 1); cout << "Fecha_orden: " << endl;
gotoxy(45, 3); cout << "id_proveedor: " << endl;
gotoxy(45, 5); cout << "fecha facturada: " << endl;

	Compras cm = Compras(no_orden_compra, id_proveedor, fecha_orden, fecha_ingreso);
	cm.autoNit();

	system("pause");
		}
		if (op1 == 3) { system("cls"); main(); }

		} while (op <= 3);
	break;
}
	} while (op <= 8);

	system("pause");
	return 0;
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





