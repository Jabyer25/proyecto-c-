#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <shlobj.h>

using namespace std;

struct Producto {
    string nombrep;
    int cantidadp;
    float preciop;
};

void agregarProducto(ofstream& archivo) {
    Producto nuevoProducto;
    cout << "Ingrese el nombre del producto: ";
    getline(cin, nuevoProducto.nombrep);
    cout << "Ingrese la cantidad disponible: ";
    cin >> nuevoProducto.cantidadp;
    cout << "Ingrese el precio del producto: ";
    cin >> nuevoProducto.preciop;

    cin.ignore();

    archivo << "Nombre del producto" << ": " << nuevoProducto.nombrep << "----------" << "Cantidad" << ":" << nuevoProducto.cantidadp << "----------" << "Precio" << ":" << nuevoProducto.preciop << endl;

    cout << "Producto agregado correctamente." << endl;
}

void mostrarInventario(ifstream& archivo) {
    string linea;
    cout << "Inventario:" << endl;
    while (getline(archivo, linea)) {
        cout << linea << endl;
    }
    archivo.clear();
    archivo.seekg(0);
}

int inventario() {
    int opcion;
    ofstream archivo;
    ifstream archivoLectura;

    // Obtener la ubicación del escritorio
    char escritorio[MAX_PATH];
    if (SHGetFolderPath(NULL, CSIDL_DESKTOPDIRECTORY, NULL, 0, escritorio) != S_OK) {
        cerr << "No se pudo obtener la ubicación del escritorio." << endl;
        return 1;
    }

    // Construir la ruta completa del archivo de inventario
    string rutaInventario = string(escritorio) + "\\INVENTARIO\\inventario.txt";

    cout << "Bienvenido al Menu Principal." << endl;
    cout << "Ingrese el numero correspondiente a la opcion deseada:" << endl;
    cout << "1. Sistema de Gestion de Inventario" << endl;
    cout << "2. Salir" << endl;
    cout << "Opcion: ";
    cin >> opcion;

    cin.ignore();

    switch (opcion) {
        case 1:
            archivo.open(rutaInventario, ios::app);
            if (!archivo.is_open()) {
                cout << "Error al abrir el archivo." << endl;
                return 1;
            }

            cout << "\nBienvenido al Sistema de Gestion de Inventario." << endl;
            cout << "Ingrese el numero correspondiente a la opcion deseada:" << endl;
            cout << "1. Agregar producto al inventario" << endl;
            cout << "2. Mostrar inventario" << endl;
            cout << "3. Salir" << endl;
            cout << "Opcion: ";
            cin >> opcion;

            cin.ignore();

            switch (opcion) {
                case 1:
                    agregarProducto(archivo);
                    break;
                case 2:
                    archivoLectura.open(rutaInventario);
                    mostrarInventario(archivoLectura);
                    archivoLectura.close();
                    break;
                case 3:
                    cout << "Saliendo del programa." << endl;
                    break;
                default:
                    cout << "Opción no válida. Saliendo del programa." << endl;
                    break;
            }

            archivo.close();
            break;
        case 2:
            cout << "Saliendo del programa." << endl;
            break;
        default:
            cout << "Opción no válida. Saliendo del programa." << endl;
            break;
    }

    return 0;
}

int intentario() {
    inventario();
    return 0;
}
