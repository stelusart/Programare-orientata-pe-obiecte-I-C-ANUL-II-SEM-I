#include <iostream>

using namespace std;

class Cafea {
private:
    int totalNrCafele;
    int totalNrCuburiZahar;
    double sumaIncasari;
    double pretCafeaIndulcita;
    double pretCafeaNeindulcita;

public:
    Cafea() {
        totalNrCafele = 0;
        totalNrCuburiZahar = 0;
        sumaIncasari = 0.0;
        pretCafeaIndulcita = 7.0;
        pretCafeaNeindulcita = 5.0;
    }

    void initializare(int cafele, int zahar) {
        totalNrCafele = cafele;
        totalNrCuburiZahar = zahar;
        sumaIncasari = 0.0;
    }

    void CafeaIndulcita() {
        if (totalNrCafele < 1) {
            cout << "Nu mai este cafea disponibila!\n";
        } else if (totalNrCuburiZahar < 2) {
            cout << "Nu mai este suficient zahar pentru o cafea indulcita!\n";
        } else {
            totalNrCafele--;
            totalNrCuburiZahar -= 2;
            sumaIncasari += pretCafeaIndulcita;
            cout << "Ati cumparat o cafea indulcita.\n";
        }
    }

    void CafeaNeindulcita() {
        if (totalNrCafele < 1) {
            cout << "Nu mai este cafea disponibila!\n";
        } else {
            totalNrCafele--;
            sumaIncasari += pretCafeaNeindulcita;
            cout << "Ati cumparat o cafea neindulcita.\n";
        }
    }

    void afisareTotalIncasari() const {
        cout << "Total incasari: " << sumaIncasari << " RON\n";
    }
};

int main() {
    Cafea aparat;
    aparat.initializare(10, 15);

    int optiune = 0;

    do {
        cout << "\nMeniu:\n";
        cout << "1. O cafea indulcita\n";
        cout << "2. O cafea neindulcita\n";
        cout << "3. Afisare total incasari\n";
        cout << "4. Iesire\n";
        cout << "Alege o optiune: ";
        cin >> optiune;

        switch (optiune) {
            case 1:
                aparat.CafeaIndulcita();
                break;
            case 2:
                aparat.CafeaNeindulcita();
                break;
            case 3:
                aparat.afisareTotalIncasari();
                break;
            case 4:
                cout << "La revedere!\n";
                break;
            default:
                cout << "Optiune invalida!\n";
                break;
        }
    } while (optiune != 4);

    return 0;
}