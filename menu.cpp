#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <windows.h>
#include <shlobj.h>
#include <conio.h>
using namespace std;

void limpiarPantalla();

char nombre[250];
char nombrenv[250];
string nombreArchivo;
string frase;
ofstream archivo;
string valor;

void indentificador() {
    cout << "Digite el nombre del archivo: ";
    cin >> nombre;
    ofstream file;
}

void escribir() {
    char band;
    cout << "Digite el nombre del archivo: ";
    cin >> nombreArchivo;
    archivo.open(nombreArchivo.c_str(), ios::app);

    if (archivo.fail()) {
        cout << "No se pudo abrir el archivo";
        exit(1);
    }

    do {
        fflush(stdin);

        cout << "\nDigite el texto del archivo: ";
        getline(cin, frase);

        archivo << frase << endl;

        cout << "\nDesea agregar mas texto al archivo? (s/n)";
        cin >> band;
    } while ((band == 's') || (band == 'S'));

    archivo.close();

    // Limpiar la pantalla después de realizar la operación
    limpiarPantalla();
}

void comprimirArchivo(const string& nombreArchivo) {
    string comando = "7z a " + nombreArchivo + ".7z " + nombreArchivo;
    int resultado = system(comando.c_str());

    if (resultado == 0) {
        cout << "Archivo comprimido exitosamente como " << nombreArchivo << ".7z" << endl;
    } else {
        cerr << "Error al comprimir el archivo." << endl;
    }

    // Limpiar la pantalla después de realizar la operación
    limpiarPantalla();
}

void eliminar() {
    indentificador();
    remove(nombre);

    // Limpiar la pantalla después de realizar la operación
    limpiarPantalla();
}

void renombrar() {
    cout << "Ingresar el nombre del archivo que desea renombrar: \n";
    cin >> nombre;
    cout << "Ingresar el nuevo nombre del archivo: \n";
    cin >> nombrenv;
    rename(nombre, nombrenv);

    // Limpiar la pantalla después de realizar la operación
    limpiarPantalla();
}

void moverArchivoAlEscritorio(const string& nombreArchivo) {
    char escritorio[MAX_PATH];
    if (SHGetFolderPath(NULL, CSIDL_DESKTOPDIRECTORY, NULL, 0, escritorio) != S_OK) {
        cerr << "No se pudo obtener la ubicación del escritorio." << endl;
        return;
    }

    // Concatenar el nombre del archivo con la ubicación del escritorio y la carpeta "ARCHIVOS"
    string destino = string(escritorio) + "\\ARCHIVOS\\" + nombreArchivo;

    // Mover el archivo al escritorio
    if (rename(nombreArchivo.c_str(), destino.c_str()) == 0) {
        cout << "Archivo movido exitosamente al escritorio." << endl;
    } else {
        cerr << "Error al mover el archivo." << endl;
    }

    // Limpiar la pantalla después de realizar la operación
    limpiarPantalla();
}

void encriptarArchivo(const string& nombreArchivo, int clave) {
    ifstream archivoEntrada(nombreArchivo);
    ofstream archivoSalida("encriptado_" + nombreArchivo);

    if (!archivoEntrada || !archivoSalida) {
        cerr << "Error al abrir el archivo." << endl;
        return;
    }

    char caracter;
    while (archivoEntrada.get(caracter)) {
        caracter = caracter + clave; // Cifrado César
        archivoSalida << caracter;
    }

    archivoEntrada.close();
    archivoSalida.close();

    cout << "Archivo encriptado exitosamente." << endl;
}

// Declaración del prototipo de la función del juego
void iniciarJuego();

void leerArchivo(const string& nombreArchivo) {
    ifstream archivoLectura(nombreArchivo);
    string linea;

    if (!archivoLectura) {
        cerr << "Error al abrir el archivo." << endl;
        return;
    }

    cout << "Contenido del archivo \"" << nombreArchivo << "\":" << endl;
    while (getline(archivoLectura, linea)) {
        cout << linea << endl;
    }

    archivoLectura.close();

    // Espera hasta que el usuario presione una tecla antes de limpiar la pantalla
    cout << "Presione cualquier tecla para continuar...";
    _getch();

    // Limpiar la pantalla después de realizar la operación
    limpiarPantalla();
    return;
}



int inventario(); // Prototipo de la función inventario
int cajero();

int main() {
    int opcion;

    do {
        limpiarPantalla();
        cout << "0================================================================0\n";
        cout << "0----------------------------------------------------------------0\n";
        cout << " |       Opcion 1 Crear un archivo o editar uno existente       | \n";
        cout << " |       Opcion 2 Comprimir archivo                             | \n";
        cout << " |       Opcion 3 Editar un archivo                             | \n";
        cout << " |       Opcion 4 Mover un archivo al escritorio                | \n";
        cout << " |       Opcion 5 Eliminar un archivo                           | \n";
        cout << " |       Opcion 6 juego                                         | \n";
        cout << " |       Opcion 7 Encriptar archivo                             | \n";
        cout << " |       Opcion 8 leer archivo                                  | \n";
        cout << " |       Opcion 9 programa de gestion de inventario             | \n";
        cout << " |       Opcion 10 programa de cajero                           | \n";
        cout << " |       Opcion 11 Salir                                        | \n";
        cout << "0----------------------------------------------------------------0\n";
        cout << "0================================================================0\n";
        cout << "Opcion escogida ==> ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                escribir();
                break;
            case 2:
                cout << "Ingrese el nombre del archivo que desea comprimir: ";
                cin >> nombreArchivo;
                comprimirArchivo(nombreArchivo);
                break;
            case 3:
                renombrar();
                break;
            case 4:
                cout << "Ingrese el nombre del archivo que desea mover: ";
                cin >> nombreArchivo;
                moverArchivoAlEscritorio(nombreArchivo);
                break;
            case 5:
                eliminar();
                break;
            case 6:
                iniciarJuego();
                break;
            case 7:
                cout << "Ingrese el nombre del archivo que desea encriptar: ";
                cin >> nombreArchivo;
                int clave;
                cout << "Ingrese la clave de encriptacion: ";
                cin >> clave;
                encriptarArchivo(nombreArchivo, clave);
                break;
            case 8:
                cout << "Ingrese el nombre del archivo que desea leer: ";
                cin >> nombreArchivo;
                leerArchivo(nombreArchivo);
                break;
            case 9:
                inventario();
                break;
            case 10:
                cajero();
                break;
            case 11:
                cout << "Gracias por usar el programa :)" << endl;
                break;
            default:
                cout << "Opción no válida, por favor seleccione una opción del 1 al 10" << endl;
                break;
        }
    } while (opcion != 11);  // Se cambia la condición para que salga del bucle al seleccionar la opción 9

    return 0;
}

// Implementación de la función para limpiar la pantalla
void limpiarPantalla() {
    system("cls");
}
