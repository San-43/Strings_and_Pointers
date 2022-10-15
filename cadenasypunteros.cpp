#include <iostream>
#include <vector>
#include <windows.h>
#include <clocale>

void prinSTR(std::string str);
void posic(std::string str);
void reverse(std::string str);

using namespace std;

int main() {
    string str;
    setlocale(LC_CTYPE, "spanish");
    SetConsoleCP(1252); // Cambiar STDIN -  Para máquinas Windows
    SetConsoleOutputCP(1252); // Cambiar STDOUT - Para máquinas Windows
    system("color 0c");

    cout<< "Introduzca una frase: "<< endl;
    getline(cin, str);


    prinSTR(str);
    system("pause");

    posic(str);
    system("pause");
    reverse(str);
    cout << endl << endl;
    system("pause");

    cout << "Gracias por usar mi programa";

    return 0;
}

void prinSTR(string str) {
    char const *ptr = &str[0];
    system("cls");

    cout << "La frase es: "<<endl;
    for (int i = 0; i < str.size(); ++i) {
        cout << *ptr << endl;
        ptr++;
    }
}

void reverse(string str) {
    char const *ptr = &str[str.size() - 1];
    system("cls");

    cout << "La frase al revés es: "<<endl;
    for (int i = 0; i < str.size(); ++i) {
        cout << *ptr;
        ptr--;
    }
}

void posic(string str) {
    char const *ptr = &str[0];
    system("cls");
    vector<int> space;
    vector<int> pto;
    vector<int> pto_coma;
    vector<int> coma;
    int comac = 0;
    int ptoc = 0;
    int spacec = 0;
    int pto_comac = 0;

    for (int i = 0; i < str.size(); ++i) {
        if (*ptr == ' ') {
            space.push_back(i);
            spacec++;
        } else if (*ptr == ',') {
            coma.push_back(i);
            comac++;
        } else if (*ptr == '.') {
            pto.push_back(i);
            ptoc++;
        } else if (*ptr == ';') {
            pto_coma.push_back(i);
            pto_comac++;
        }
        cout << *ptr;
        ptr++;
    }

    cout << endl << endl;
    cout << "Existen espacios en las posiciones: ";
    for (int i: space) {
        cout << i << ", ";
    }
    cout << ".En total son " << spacec << endl;

    cout << endl << endl;
    cout << "Existen puntos en las posiciones: ";
    for (int i: pto) {
        cout << i << ", ";
    }
    cout << ".En total son " << ptoc << endl;

    cout << endl << endl;
    cout << "Existen puntos y comas en las posiciones: ";
    for (int i: pto_coma) {
        cout << i << ", ";
    }
    cout << ".En total son " << pto_comac << endl;

    cout << endl << endl;
    cout << "Existen comas en las posiciones: ";
    for (int i: coma) {
        cout << i << ", ";
    }
    cout << ".En total son " << comac << endl;

    cout << endl << endl;
}