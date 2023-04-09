#include <iostream>
#include <fstream>
#include <cstring>
#include <utility>
#include <vector>
#include <sstream>
#include "string"
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma clang diagnostic pop
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"


using namespace std;

struct Alumno {
    char codigo[5]{};
    char nombre[11]{};
    char apellidos[20]{};
    char carrera[15]{};

    Alumno() = default;;

    Alumno(const string &codigo, const string &nombre, const string &apellidos, const string &carrera) {
        strcpy(this->codigo, codigo.c_str());
        strcpy(this->nombre, nombre.c_str());
        strcpy(this->apellidos, apellidos.c_str());
        strcpy(this->carrera, carrera.c_str());
    };

};


class FixedRecord {
private:
    string archivo;
    vector<Alumno> alumnos;
public:
    explicit FixedRecord(string archivo) : archivo(std::move(archivo)) {
    }

    vector<Alumno> load() {
        ifstream inFile;
        string fila;
        inFile.open(archivo, ios::in | ios::binary);
        Alumno alumno;
        //iteramos
        while (getline(inFile, fila)) {
            string codigo;
            string nombre;
            string apellidos;
            string carrera;
            stringstream linea(fila);
            //[0-4][5-15][16-35][36-47]
            //4    10    19     14
            for (int i = 0; i < 4; ++i) {
                codigo = codigo + fila[i];
            }
            for (int i = 5; i < 15; ++i) {
                nombre = nombre + fila[i];
            }
            for (int i = 16; i < 35; ++i) {
                apellidos = apellidos + fila[i];
            }
            for (int i = 36; i < fila.size(); ++i) {
                carrera = carrera + fila[i];
            }


            strcpy(alumno.codigo, codigo.c_str());
            strcpy(alumno.nombre, nombre.c_str());
            strcpy(alumno.apellidos, apellidos.c_str());
            strcpy(alumno.carrera, carrera.c_str());
            alumnos.push_back(alumno);
        }

        inFile.close();

        return alumnos;
    }

    void add(Alumno record) {
        int t_codigo = strlen(record.codigo); // NOLINT(cppcoreguidelines-narrowing-conversions)
        int t_nombre = strlen(record.nombre); // NOLINT(cppcoreguidelines-narrowing-conversions)
        int t_apellidos = strlen(record.apellidos); // NOLINT(cppcoreguidelines-narrowing-conversions)
        int t_carrera = strlen(record.carrera); // NOLINT(cppcoreguidelines-narrowing-conversions)

        string espacio = " ";

        if (t_codigo < 5) {
            if (t_nombre < 11) {
                if (t_apellidos < 20) {
                    if (t_carrera < 15) {

                        //Espacio adicional para "codigo"
                        if (t_codigo != 4) {
                            for (int i = t_codigo + 1; i < 5; ++i) {
                                strcat(record.codigo, espacio.c_str());
                            }
                        }

                        //Espacio adicional para "nombre"
                        if (t_nombre != 10) {
                            for (int i = t_nombre + 1; i < 11; ++i) {
                                strcat(record.nombre, espacio.c_str());
                            }
                        }

                        //Espacio adicional para "apellidos"
                        if (t_apellidos != 19) {
                            for (int i = t_apellidos + 1; i < 20; ++i) {
                                strcat(record.apellidos, espacio.c_str());
                            }
                        }

                        //Espacio adicional para "carrera"
                        if (t_carrera != 14) {
                            for (int i = t_carrera + 1; i < 15; ++i) {
                                strcat(record.carrera, espacio.c_str());
                            }
                        }
                        ofstream texto;
                        texto.open(archivo, ios::app);
                        cout << endl;

                        char final[58];
                        string a = "\n";
                        strcat(final, a.c_str());
                        strcat(final, record.codigo);
                        strcat(final, espacio.c_str());
                        strcat(final, record.nombre);
                        strcat(final, espacio.c_str());
                        strcat(final, record.apellidos);
                        strcat(final, espacio.c_str());
                        strcat(final, record.carrera);

                        int dist = strlen(record.codigo) + strlen(record.nombre) + strlen(record.apellidos) + // NOLINT(cppcoreguidelines-narrowing-conversions)
                                   strlen(record.carrera);

                        texto.write(final, dist);
                        texto.close();
                        alumnos.push_back(record);
                    } else { cerr << "El nombre de la carrera es muy grande" << endl; }
                } else { cerr << "El apellido es muy grande" << endl; }
            } else { cerr << "El nombre es muy grande" << endl; }
        } else { cerr << "El codigo es muy grande" << endl; }


    }

    void mostrar() {
        for (auto &alumno: alumnos) {
            cout << alumno.codigo;
            cout << alumno.nombre;
            cout << alumno.apellidos;
            cout << alumno.carrera << endl;
        }
    }

    Alumno readRecord(int pos) {
        ifstream inFile;
        string fila;
        inFile.open(archivo, ios::in | ios::binary);

        int cont = 0;
        while (getline(inFile, fila)) {
            if (cont == pos - 1) {
                cout << fila << endl;
                string codigo;
                string nombre;
                string apellidos;
                string carrera;
                stringstream linea(fila);
                //[0-4][5-15][16-35][36-47]
                //4    10    19     14
                for (int i = 0; i < 4; ++i) {
                    codigo = codigo + fila[i];
                }
                for (int i = 5; i < 15; ++i) {
                    nombre = nombre + fila[i];
                }
                for (int i = 16; i < 35; ++i) {
                    apellidos = apellidos + fila[i];
                }
                for (int i = 36; i < fila.size(); ++i) {
                    carrera = carrera + fila[i];
                }
                Alumno alumno(codigo, nombre, apellidos, carrera);
                return alumno;
            } else {
                cont++;
            }
        }

        inFile.close();
    }

    [[nodiscard]] vector<Alumno> getAlumnos() const {
        return alumnos;
    }
};   

int main() {

    FixedRecord record(R"(C:\Users\JEFF QUINTANA\Desktop\BASE DE DATOS II\tarea\datos1.txt)");

    vector<Alumno> alumnos = record.load();

    record.mostrar();

    //Alumno jeff("7777", "Jeff", "Quintana", "CS");
    //record.add(jeff);
    //record.load();
    //Alumno al = record.readRecord(4);
    //
    //cout << al.codigo << endl;
    //cout << al.nombre << endl;
    //cout << al.apellidos << endl;
    //cout << al.carrera << endl;

    return 0;
}