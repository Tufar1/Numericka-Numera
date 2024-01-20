#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <string>

//TOUŽIM PO ODVETĚ A KŘIČÍÍM: "SLOVA JSOU JEN KAPKY DEŠTĚ A TY VOLÁŠ, POSER MĚ JEŠTĚ, SLOVA JSOU JEN KAPKY DEŠTĚ A TY VOLÁÁÁŠ"

using namespace std;

ofstream file;

void zapisovani(string vstup) {
    cout << vstup;
    file << vstup;
}

void vypis(vector<int> pole, int cislopole) {

    zapisovani(std::to_string(cislopole) + ">> ");

    for (int i : pole) {    
        zapisovani(std::to_string(i) + ",");
    }
    zapisovani("\r\n");
}

int main()
{
    file.open("output.txt", fstream::app);

    int length;
    int repeattime;

    cout << "Hello World!\n";

    cout << "Jak velke udelame pole?";
    cin >> length;

    cout << "Kolikrat provedeme cyklus?";
    cin >> repeattime;

    for (int i = 0; i < repeattime; i++) {

        int citacka = 0;

        vector<int> arr;

        for (int x = 0; x < length; x++) {
            arr.push_back(rand());
        }

        vypis(arr, i);

        auto start = chrono::high_resolution_clock::now();
        do {
            citacka++;
            random_shuffle(begin(arr), end(arr));
        } while (!is_sorted(arr.begin(), arr.end()));
        auto stop = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
        zapisovani("pole cislo " + std::to_string(i) + " se protocilo tolikrat: " + std::to_string(citacka) + " trvalo to tolik milisekund: " + std::to_string(duration.count())+ "\r\n");

        vypis(arr, i);
    }

    file.close();
}