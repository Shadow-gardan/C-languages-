#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main() {

    const int size = 80;
    char country[size];
    char capital[size];

    ifstream fin1("country");
    ifstream fin2("capital");

    if (!fin1.is_open() || !fin2.is_open()) {
        cout << "Error opening files." << endl;
        return 1;
    }

    for (int i = 0; i < 10; i++) {
        if (!fin1.getline(country, size)) {
            cout << "No more countries." << endl;
            break;
        }
        if (!fin2.getline(capital, size)) {
            cout << "No more capitals." << endl;
            break;
        }
        cout << "capital of " << country << " is " << capital << endl;
    }

    return 0;
}