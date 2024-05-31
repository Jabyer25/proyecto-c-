#include <iostream>
#include <cstdlib> // Necesario para usar system()
using namespace std;

void limpiar_pantalla() {
#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#else
    system("clear");
#endif
}

void depositar(int& saldo_inicial) {
    limpiar_pantalla();
    float extra;
    cout << "Ingrese la Cantidad que Desea Depositar: " << endl;
    cin >> extra;
    saldo_inicial += extra;
    cout << "Dinero de Cuenta: " << saldo_inicial << endl;
}

void retirar(int& saldo_inicial) {
    limpiar_pantalla();
    int retiro;
    cout << "Que Cantidad desea Retirar?: " << endl;
    cin >> retiro;

    if (retiro > saldo_inicial) {
        cout << "Usted no puede retirar dicha cantidad" << endl;
    } else {
        saldo_inicial -= retiro;
        cout << "Dinero de Cuenta: " << saldo_inicial << endl;
    }
}

void menu_principal(int& saldo_inicial) {
    char dato;

    while (true) {
        limpiar_pantalla();
        cout << "\t Bienvenido al Cajero Automatico" << endl << endl;
        cout << " > Saldo Actual del Cajero: " << "Q" << saldo_inicial << ".00" << endl;
        cout << "Que Desea Hacer: " << endl;
        cout << "1. Depositar Dinero" << endl;
        cout << "2. Retirar Dinero" << endl;
        cout << "3. Salir" << endl;
        cin >> dato;

        switch (dato) {
            case '1':
                depositar(saldo_inicial);
                break;
            case '2':
                retirar(saldo_inicial);
                break;
            case '3':
                limpiar_pantalla();
                cout << "Usted ha decidido finalizar el proceso" << endl;
                return; // Salir de la función y terminar el programa
            default:
                cout << "Opción no válida, por favor intente de nuevo." << endl;
        }
    }
}

int cajero() {
    int saldo_inicial = 5000;
    menu_principal(saldo_inicial);
    return 0;
}
