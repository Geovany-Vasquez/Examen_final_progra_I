#include<iostream>
#include <string>
#include<stdlib.h>
#include"SerialPort.h"

using namespace std;

char output[MAX_DATA_LENGTH];
char incomingData[MAX_DATA_LENGTH];

char commport[] = "\\\\.\\COM3";
char* port = commport;

int main() {
	SerialPort arduino(port);
	if (arduino.isConnected()) {
		cout << "Conexion exitosa :D" << endl << endl;
	}
	else {
		cout << "Error en la conexion :(" << endl << endl;
	}
	while (arduino.isConnected()) {
		int control = 0;
		cout << "Ingrese un comando: " << endl;
		cin >> control;
		if (control == 1) {
			//declaramos una matriz para identificar las posiciones respectivas de las bobinas de nuestro motor paso a paso
			int data[8][4] =
			{   {1, 0, 0, 0},
				{1, 1, 0, 0},
				{0, 1, 0, 0},
				{0, 1, 1, 0},
			    {0, 0, 1, 0},
				{0, 0, 1, 1},
				{0, 0, 0, 1},
				{1, 0, 0, 1}
			};
			 string dt = to_string(data[8][4]);
			
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 4; j++) {
					
					dt = data[i][j]||",";
					char* charArray = new char[dt.size() + 1];
					copy(dt.begin(), dt.end(), charArray);
					charArray[dt.size()] = '\n';
					arduino.writeSerialPort(charArray, MAX_DATA_LENGTH); 
						arduino.readSerialPort(output, MAX_DATA_LENGTH);
				}
			}
			cout << "banda en funcionamiento" << endl;

		}
		else {
			cout << "numero no valido..." << endl;
			system("pause");
			return 0;
		}
	

		cout << ">> " << output << endl;

		
	}
	return 0;
}



