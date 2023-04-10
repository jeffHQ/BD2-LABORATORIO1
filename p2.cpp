#include <iostream>
#include <fstream>
#include <cstring>
#include <utility>
#include <vector>
#include <sstream>
#include "string"

using namespace std;
struct Alumno{
    char codigo[5];
    char nombre[11];
    char apellidos[20];
    char carrera[15];

    int ciclo;
    int mensualidad;

    Alumno() = default;;

    Alumno(const string &codigo, const string &nombre, const string &apellidos, const string &carrera) {
        strcpy(this->codigo, codigo.c_str());
        strcpy(this->nombre, nombre.c_str());
        strcpy(this->apellidos, apellidos.c_str());
        strcpy(this->carrera, carrera.c_str());
    };

    void readFromConsole(char buffer[], string temp,int size){

        for (int i = 0; i < size; ++i) {
            buffer[i] = (i < temp.size()) ? temp[i] : buffer[size-1] = '\0';
        }

        cin.clear();
    };

};

class FixedRecord{
private:
    string archivo;
public:
    FixedRecord();
    FixedRecord(string archivo){
        this->archivo = archivo;
    };

    vector<Alumno> load(){
        ifstream inFile;
        inFile.open(archivo, ios::in | ios::binary);

        vector<Alumno> alumnoss;

        string linea;

        while(getline(inFile, linea)){
            Alumno alumno;
            inFile.read(alumno.codigo, sizeof(alumno.codigo));
            alumno.codigo[sizeof(alumno.codigo)-1] = '\0';

            inFile.read(alumno.nombre, 11);
            alumno.nombre[sizeof(alumno.nombre)-1] = '\0';

            inFile.read(alumno.apellidos, 20);
            alumno.apellidos[sizeof(alumno.apellidos)-1] = '\0';

            inFile.read(alumno.carrera, 15);
            alumno.carrera[sizeof(alumno.carrera)-1] = '\0';

            cout << alumno.codigo << endl;
            cout << alumno.nombre << endl;
            cout << alumno.apellidos << endl;
            cout << alumno.carrera << endl;
            break;
        }


        inFile.close();
    };
};

int main() {
    FixedRecord record("C:\\Users\\JEFF QUINTANA\\Desktop\\BASE DE DATOS II\\p2\\datos1.txt");

    vector<Alumno> al = record.load();

    return 0;
}
