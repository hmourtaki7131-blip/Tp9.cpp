
#include <iostream>
#include <string>
using namespace std;

// Classe Utilisateur
class Utilisateur {
protected:
    int identifiant;
    string login;

public:
    Utilisateur(int id, string l) {
        identifiant = id;
        login = l;
    }

    void afficherUtilisateur() {
        cout << "Identifiant : " << identifiant << endl;
        cout << "Login : " << login << endl;
    }
};

// Classe Administrateur
class Administrateur : virtual public Utilisateur {
protected:
    string droitsAcces;

public:
    Administrateur(int id, string l, string droits)
        : Utilisateur(id, l) {
        droitsAcces = droits;
    }

    void gererSysteme() {
        cout << "Gestion du systeme : autorisee" << endl;
        cout << "Droits d'acces : " << droitsAcces << endl;
    }
};

// Classe Moderateur
class Moderateur : virtual public Utilisateur {
protected:
    int niveauModeration;

public:
    Moderateur(int id, string l, int niveau)
        : Utilisateur(id, l) {
        niveauModeration = niveau;
    }

    void modererContenu() {
        cout << "Moderation du contenu : autorisee" << endl;
        cout << "Niveau de moderation : "
             << niveauModeration << endl;
    }
};

// Heritage multiple
class SuperUtilisateur : public Administrateur, public Moderateur {
public:
    SuperUtilisateur(int id, string l, string droits, int niveau)
        : Utilisateur(id, l),
          Administrateur(id, l, droits),
          Moderateur(id, l, niveau) {
    }

    void afficherInformations() {
        cout << "\n===== INFORMATIONS UTILISATEUR =====" << endl;
        afficherUtilisateur();
        gererSysteme();
        modererContenu();
    }
};

int main() {
    int choix;
    int id;
    string login;
    string droits;
    int niveau;

    SuperUtilisateur* utilisateur = nullptr;

    do {
        cout << "\n===== MENU SUPER UTILISATEUR =====" << endl;
        cout << "1. Creer un SuperUtilisateur" << endl;
        cout << "2. Afficher les informations" << endl;
        cout << "3. Gerer le systeme" << endl;
        cout << "4. Moderer le contenu" << endl;
        cout << "0. Quitter" << endl;
        cout << "Votre choix : ";
        cin >> choix;

        switch (choix) {
        case 1:
            if (utilisateur != nullptr) {
                delete utilisateur;
                utilisateur = nullptr;
            }

            cout << "Donner l'identifiant : ";
            cin >> id;

            cout << "Donner le login : ";
            cin >> login;

            cout << "Donner les droits d'acces : ";
            cin >> droits;

            cout << "Donner le niveau de moderation : ";
            cin >> niveau;

            utilisateur = new SuperUtilisateur(
                id, login, droits, niveau
            );

            cout << "SuperUtilisateur cree avec succes !" << endl;
            break;

        case 2:
            if (utilisateur != nullptr) {
                utilisateur->afficherInformations();
            } else {
                cout << "Veuillez d'abord creer un utilisateur !" << endl;
            }
            break;

        case 3:
            if (utilisateur != nullptr) {
                utilisateur->gererSysteme();
            } else {
                cout << "Aucun utilisateur cree !" << endl;
            }
            break;

        case 4:
            if (utilisateur != nullptr) {
                utilisateur->modererContenu();
            } else {
                cout << "Aucun utilisateur cree !" << endl;
            }
            break;

        case 0:
            cout << "Fin du programme." << endl;
            break;

        default:
            cout << "Choix invalide !" << endl;
        }

    } while (choix != 0);

    delete utilisateur;
    utilisateur = nullptr;

    return 0;
}
