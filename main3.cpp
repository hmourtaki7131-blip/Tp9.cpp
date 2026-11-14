
#include <iostream>
#include <string>
using namespace std;

// Classe de base
class Vehicule {
protected:
    string marque;
    string modele;

public:
    Vehicule(string ma, string mo) {
        marque = ma;
        modele = mo;
    }
};

// Heritage virtuel
class Thermique : virtual public Vehicule {
protected:
    float consommation;

public:
    Thermique(string ma, string mo, float c)
        : Vehicule(ma, mo) {
        consommation = c;
    }
};

// Heritage virtuel
class Electrique : virtual public Vehicule {
protected:
    int autonomie;

public:
    Electrique(string ma, string mo, int a)
        : Vehicule(ma, mo) {
        autonomie = a;
    }
};

// Heritage multiple
class Hybride : public Thermique, public Electrique {
public:
    Hybride(string ma, string mo, float c, int a)
        : Vehicule(ma, mo),
          Thermique(ma, mo, c),
          Electrique(ma, mo, a) {
    }

    void afficherCaracteristiques() {
        cout << "Marque : " << marque << endl;
        cout << "Modele : " << modele << endl;
        cout << "Consommation : " << consommation
             << " L/100km" << endl;
        cout << "Autonomie : " << autonomie
             << " km" << endl;
    }
};

int main() {
    Hybride voiture("Toyota", "Prius", 4.5, 50);

    cout << "===== VEHICULE HYBRIDE =====" << endl;

    voiture.afficherCaracteristiques();

    return 0;
}
