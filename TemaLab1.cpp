#include <iostream>
#include <string>

using namespace std;

void afisareCont(const string& numeTitular, double sold) {
    cout << "Titular cont: " << numeTitular << " | Sold curent: " << sold << " RON\n";
}

void depunere(double& sold, double suma = 100.0) {
    if (suma > 0) {
        sold += suma;
        cout << "Depunere reusita de " << suma << " RON.\n";
    } else {
        cout << "Suma depusa trebuie să fie pozitiva!\n";
    }
}

bool retragere(double& sold, double suma) {
    if (suma > 0 && sold >= suma) {
        sold -= suma;
        cout << "Retragere reusita de " << suma << " RON.\n";
        return true;
    } else {
        cout << "Retragere esuata: Fonduri insuficiente sau suma invalida!\n";
        return false;
    }
}

bool retragere(double& sold, double suma, double limitaMaxima) {
    if (suma > 0 && suma <= limitaMaxima && sold >= suma) {
        sold -= suma;
        cout << "Retragere cu limita reusita de " << suma << " RON (limita: " << limitaMaxima << ").\n";
        return true;
    } else {
        cout << "Retragere esuata: Fonduri insuficiente, suma invalida sau limita depasita!\n";
        return false;
    }
}

bool transfer(double& soldSursa, double& soldDestinatie, double suma) {
    if (suma > 0 && soldSursa >= suma) {
        soldSursa -= suma;
        soldDestinatie += suma;
        cout << "Transfer reusit de " << suma << " RON.\n";
        return true;
    } else {
        cout << "Transfer esuat: Fonduri insuficiente sau suma invalida!\n";
        return false;
    }
}

int main() {
    string titular1 = "Mara Anghel";
    double sold1 = 1500.0;

    string titular2 = "Mihai Tomescu";
    double sold2 = 500.0;

    cout << "--- STARE INITIALA ---\n";
    afisareCont(titular1, sold1);
    afisareCont(titular2, sold2);
    cout << "\n";

    cout << "--- TESTARE DEPUNERE ---\n";
    depunere(sold1, 300.0);
    depunere(sold2);
    afisareCont(titular1, sold1);
    afisareCont(titular2, sold2);
    cout << "\n";

    cout << "--- TESTARE RETRAGERE ---\n";
    retragere(sold1, 200.0);
    retragere(sold1, 5000.0);
    cout << "\n";

    cout << "--- TESTARE SUPRADEFINIRE RETRAGERE (CU LIMITA) ---\n";
    retragere(sold1, 400.0, 500.0);
    retragere(sold1, 600.0, 500.0);
    cout << "\n";

    cout << "--- TESTARE TRANSFER ---\n";
    transfer(sold1, sold2, 300.0);
    cout << "\n";

    cout << "--- STARE FINALA ---\n";
    afisareCont(titular1, sold1);
    afisareCont(titular2, sold2);

    return 0;
}
