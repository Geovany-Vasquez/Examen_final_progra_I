#pragma once
#include <iostream>
using namespace std;

class Persona {
	// atributos
protected: string nombres, apellidos, direccion, dpi, fecha_nacimiento;
		 int telefono = 0;
		 int genero =0;


		 // costructor
protected:
	Persona() {
	}
	Persona(string nom, string ape, string dir, int tel, string dp, int gn, string fn) {
		nombres = nom;
		apellidos = ape;
		direccion = dir;
		telefono = tel;
		dpi = dp;
		genero = gn;
		fecha_nacimiento = fn;

	}

};
