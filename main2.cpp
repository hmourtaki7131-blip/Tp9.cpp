
#include <iostream>
using namespace std;

// Classe Technicien
class Technicien {
protected:
    float salaire;

public:
    Technicien(float s) {
        salaire = s;
    }

    void afficherSalaire() {
        cout << "Salaire Technicien : "
             << salaire << " DH" << endl;
    }
};

// Classe Comptable
class Comptable {
protected:
    float salaire;

public:
    Comptable(float s) {
        salaire = s;
    }

    void afficherSalaire() {
        cout << "Salaire Comptable : "
             << salaire << " DH" << endl;
    }
};

// Heritage multiple
class EmployePolyvalent : public Technicien, public Comptable {
public:
    EmployePolyvalent(float st, float sc)
        : Technicien(st), Comptable(sc) {
    }

    void afficherTousSalaires() {
        Technicien::afficherSalaire();
        Comptable::afficherSalaire();
    }
};

int main() {
    EmployePolyvalent e(5000, 6000);

    cout << "===== EMPLOYE POLYVALENT =====" << endl;

    e.afficherTousSalaires();

    return 0;
}
