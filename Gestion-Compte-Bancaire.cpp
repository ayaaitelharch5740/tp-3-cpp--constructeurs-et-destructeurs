#include <iostream>
#include <string>
using namespace std;

class CompteBancaire {
private:
    string titulaire;
    double solde;

public:
    
    CompteBancaire() {
        titulaire = "Inconnu";
        solde = 0.0;
        cout << "[Création] Compte par défaut créé pour " << titulaire << " avec un solde de " << solde << "€" << endl;
    }

    
    CompteBancaire(const string& nomTitulaire, double soldeInitial) {
        titulaire = nomTitulaire;
        solde = soldeInitial;
        cout << "[Création] Compte créé pour " << titulaire << " avec un solde de " << solde << "€" << endl;
    }

    
    CompteBancaire(const CompteBancaire& autre) {
        titulaire = autre.titulaire;
        solde = autre.solde;
        cout << "[Copie] Compte copié depuis celui de " << autre.titulaire << endl;
    }

    
    void afficher() const {
        cout << "Titulaire : " << titulaire << ", Solde : " << solde << "€" << endl;
    }

    
    ~CompteBancaire() {
        cout << "[Destruction] Compte de " << titulaire << " supprimé." << endl;
    }
};


int main() {
    CompteBancaire compte1;                           
    CompteBancaire compte2("Alice", 1500.0);          
    CompteBancaire compte3 = compte2;                 

    cout << "\n--- Informations sur les comptes ---" << endl;
    compte1.afficher();
    compte2.afficher();
    compte3.afficher();

    cout << "\n--- Fin du programme ---" << endl;
    return 0; 
}
