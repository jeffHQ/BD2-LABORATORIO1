#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;
    
    struct Matricula
	{
		string codigo;
		int ciclo;
		float mensualidad;
		string observaciones;
        Matricula(){};
        Matricula(string codigo, int ciclo, float mensualidad, string observaciones): codigo{codigo}, ciclo{ciclo}, mensualidad{mensualidad},observaciones{observaciones}{};
	};

ostream & operator << (ostream & stream, Matricula &m)
{	
	stream << m.codigo;
	stream << m.observaciones;
	stream << "\n";
	stream << flush;
	return stream;
}   

void add(Matricula record){
    fstream myfile;
    myfile.open("datos3.dat", ios::out);
    size_t num = record.codigo.size();
    myfile.write((char*)&num,sizeof(size_t));
    myfile.write(record.codigo.c_str(),record.codigo.size());
    myfile.write((char*)&record.ciclo,sizeof(int));
    myfile.write((char*)&record.mensualidad,sizeof(int));
    num = record.observaciones.size();
    myfile.write((char*)&num,sizeof(size_t));
    myfile.write(record.codigo.c_str(),record.codigo.size());
    myfile.close();
}

vector<Matricula> load(){
    Matricula mat;
    size_t num;
    fstream myfile;
    myfile.open("datos3.dat", ios::in);
    myfile.read((char*)&num,sizeof(size_t));
    char *buffer = new char[num + 1];
    myfile.read(buffer,num);
    buffer[num] =  '\n';
    mat.codigo = buffer;
    myfile.read((char*)&mat.ciclo,sizeof(int));
    myfile.read((char*)&mat.mensualidad,sizeof(float));
    myfile.read((char*)&num,sizeof(size_t));
    char *buffer = new char[num + 1];
    myfile.read(buffer,num);
    buffer[num] =  '\n';
    mat.observaciones = buffer;

    myfile.close();
}

int main()
{
    Matricula m1("001",5,2000.40,"falta mucho a clase");
    add(m1);



	return 0;
}


