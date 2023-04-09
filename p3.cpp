#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;

struct Alumno{
	string Nombre;
	string Apellidos;
	string Carrera;
	float mensualidad;
	Alumno(){}

	Alumno(string name){
		
	}


	
	

};

vector<Alumno> load(){
		vector<Alumno>v1;
		fstream myfile;
		myfile.open("datos2.txt", ios::in);
		string var;
		Alumno A;
		while (myfile)
		{
		getline(myfile,A.Nombre,'|');
		getline(myfile,A.Apellidos,'|');
		getline(myfile,A.Carrera,'|');
		getline(myfile,var,'\n');
		A.mensualidad = stod(var);
		v1.push_back(A);
		}
		
		
		myfile.close();	
		
		return v1;	
	}

ostream & operator << (ostream & stream, Alumno & p)
{	
	stream << p.Nombre;
	stream << p.Apellidos;
	stream << "\n";
	stream << flush;
	return stream;
}

void add(Alumno record){
	fstream Archivo ("datos2.txt", std::ios::app);
	
	string line;
	line= record.Nombre + "|"+record.Apellidos+ "|"+record.Carrera+ "|"+to_string(record.mensualidad);
	Archivo<<"\n";
	Archivo<<line;
	Archivo.close();
}

Alumno readRecords(int pos){
	fstream myfile;
		myfile.open("datos2.txt", ios::in);
		string var;
		Alumno A;
		for(int x = 0; x<pos;x++){
		getline(myfile,A.Nombre,'|');
		getline(myfile,A.Apellidos,'|');
		getline(myfile,A.Carrera,'|');
		getline(myfile,var,'\n');
		A.mensualidad = stod(var);
		}
		myfile.close();
		return A;	
}

void readFromConsole(char buffer[], int size){
	string temp;			
	cin >> temp;
	for(int i=0; i<size; i++)		
		buffer[i] = (i < temp.size())? temp[i] : ' ';
	buffer[size-1] = '\0';
	cin.clear();
}

int main()
{

	vector<Alumno>alum = load();

	Alumno a;
	a.Nombre="Jase";
	a.Apellidos="Hitler";
	a.Carrera="Artes";
	a.mensualidad = 1236.122;
	add(a);
	cout<<readRecords(3).Apellidos;
	return 0;
}