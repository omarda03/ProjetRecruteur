#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Offre {
private:
    vector<string> criteres;
    int idOffre;
    string titre;
    string description;
public:
    const vector<string>& getCriteres() const {
        return criteres;
    }

    // Getter pour l'ID de l'offre
    int getId() const {
        return idOffre;
    }

    // Getter pour le titre de l'offre
    const string& getTitre() const {
        return titre;
    }

    // Getter pour la description de l'offre
    const string& getDescription() const {
        return description;
    }
    static Offre ajouterOffre(int idOffre, const string& titre, const string& description, const vector<string>& criteres) {
        // Cr�er une nouvelle instance de la classe Offre avec les informations fournies
        Offre nouvelleOffre;
        nouvelleOffre.setId(idOffre);
        nouvelleOffre.setTitre(titre);
        nouvelleOffre.setDescription(description);
        nouvelleOffre.setCriteres(criteres);
        return nouvelleOffre;
    }

    void setId(int id) {
        idOffre = id;
    }

    void setTitre(const string& titre) {
        this->titre = titre;
    }

    void setDescription(const string& description) {
        this->description = description;
    }

    void setCriteres(const vector<string>& criteres) {
        this->criteres = criteres;
    }

    static bool supprimerOffre(vector<Offre>& offres, int idOffre) {
        // Rechercher l'offre par son ID
        for (auto it = offres.begin(); it != offres.end(); ++it) {
            if (it->getId() == idOffre) {
                // Supprimer l'offre si elle est trouv�e
                offres.erase(it);
                return true; // Retourner true si l'offre est supprim�e avec succ�s
            }
        }
        return false; // Retourner false si l'offre n'est pas trouv�e
    }

    static bool modifierOffre(vector<Offre>& offres, int idOffre, const string& nouveauTitre, const string& nouvelleDescription, const vector<string>& nouveauxCriteres) {
        // Rechercher l'offre par son ID
        for (auto& offre : offres) {
            if (offre.getId() == idOffre) {
                // Mettre � jour les informations de l'offre si elle est trouv�e
                offre.setTitre(nouveauTitre);
                offre.setDescription(nouvelleDescription);
                offre.setCriteres(nouveauxCriteres);
                return true; // Retourner true si l'offre est modifi�e avec succ�s
            }
        }
        return false; // Retourner false si l'offre n'est pas trouv�e
    }
};

class Personne {
protected:
    int id;
    string nom;
    string prenom;
    int age;
    string email;
    string password;

public:
    virtual bool authentification(string email, string password) = 0;
    // Fonction virtuelle pure pour authentification, rendant la classe abstraite
};

bool Personne::authentification(string email, string password) {
    return (this->email == email && this->password == password);
    // Impl�mentation de la fonction authentification pour �tre utilis�e par les classes d�riv�es
}

class Recruteur : public Personne {
private:
    float salaire;
    vector<string> langues;
    string nom_entreprise;
    string secteur_activite;

public:
    bool authentification(string email, string password) override {
        // Impl�mentation sp�cifique de l'authentification pour les recruteurs
        return Personne::authentification(email, password); // Utilisation de l'authentification de la classe de base
    }

    void publierOffre(const string& titre, const string& description, const vector<string>& criteres) {
        // Cr�er une nouvelle instance d'Offre avec les informations fournies
        Offre nouvelleOffre;
        nouvelleOffre.setTitre(titre);
        nouvelleOffre.setDescription(description);
        nouvelleOffre.setCriteres(criteres);

    }

};

class Candidat : public Personne {
private:
    int IdC;
    string nom;
    string prenom;
    string diplome;
    string specialite;
    int experience;
    int code_postal;

public:

    const string& getNom() const {
        return nom;
    }

    const string& getPrenom() const {
        return prenom;
    }

    const string& getDiplome() const {
        return diplome;
    }

    const string& getSpecialite() const {
        return specialite;
    }

    int getIdC() const {
        return IdC;
    }

    int getExperience() const {
        return experience;
    }

    int getCodePostal() const {
        return code_postal;
    }
    void setNom(const string& nom) {
        this->nom = nom;
    }

    void setPrenom(const string& prenom) {
        this->prenom = prenom;
    }

    void setDiplome(const string& diplome) {
        this->diplome = diplome;
    }

    void setSpecialite(const string& specialite) {
        this->specialite = specialite;
    }

    void setExperience(int experience) {
        this->experience = experience;
    }

    void setCodePostal(int codePostal) {
        this->code_postal = codePostal;
    }
    bool authentification(string email, string password) override {
        // Impl�mentation sp�cifique de l'authentification pour les candidats
        return Personne::authentification(email, password); // Utilisation de l'authentification de la classe de base
    }

    void postulerOffre(const string& nom, const string& prenom, const string& diplome, const string& specialite, int experience, int codePostal, int idOffre) {
        // Remplir les informations n�cessaires pour postuler � l'offre
        this->nom = nom;
        this->prenom = prenom;
        this->diplome = diplome;
        this->specialite = specialite;
        this->experience = experience;
        this->code_postal = codePostal;

        // Vous pouvez impl�menter ici la logique de traitement de la demande de candidature,
        // par exemple, en enregistrant les informations du candidat et l'ID de l'offre dans une liste
        // ou en effectuant d'autres op�rations n�cessaires.
        cout << "Candidat postule � l'offre avec l'ID : " << idOffre << endl;
        cout << "Informations du candidat :" << endl;
        cout << "Nom : " << nom << endl;
        cout << "Pr�nom : " << prenom << endl;
        cout << "Dipl�me : " << diplome << endl;
        cout << "Sp�cialit� : " << specialite << endl;
        cout << "Exp�rience : " << experience << " ann�es" << endl;
        cout << "Code Postal : " << codePostal << endl;
    }

    // Ajoutez d'autres m�thodes sp�cifiques aux candidats ici
};

class Profil {
private:
    int idC;
    string type;

public:
    void modifierProfil(string& nom, string& prenom, string& diplome, string& specialite, int& experience, int& codePostal, Candidat& candidat) {
        // Modifier les informations du profil avec les nouvelles valeurs fournies
        // Ici, nous supposons que vous avez des attributs dans la classe Profil pour stocker ces informations
        // Vous pouvez les remplacer par les attributs r�els de votre application
        // Par exemple :
        candidat.setNom(nom);
        candidat.setPrenom(prenom);
        candidat.setDiplome(diplome);
        candidat.setSpecialite(specialite);
        candidat.setExperience(experience);
        candidat.setCodePostal(codePostal);

        // Mettre � jour les informations du candidat avec les nouvelles valeurs
    }

    void supprimerProfil(Candidat& candidat) {
        // Supprimer le profil du candidat correspondant
        // Par exemple, vous pouvez r�initialiser toutes les informations du candidat � des valeurs par d�faut ou vides
        candidat.setNom("");
        candidat.setPrenom("");
        candidat.setDiplome("");
        candidat.setSpecialite("");
        candidat.setExperience(0);
        candidat.setCodePostal(0);

        // Vous pouvez �galement supprimer d'autres informations du profil du candidat si n�cessaire
    }

    void consulterProfil(const Candidat& candidat) const {
        // Afficher les informations du profil du candidat
        cout << "Profil du candidat (ID: " << candidat.getIdC() << "):" << endl;
        cout << "Nom: " << candidat.getNom() << endl;
        cout << "Pr�nom: " << candidat.getPrenom() << endl;
        cout << "Dipl�me: " << candidat.getDiplome() << endl;
        cout << "Sp�cialit�: " << candidat.getSpecialite() << endl;
        cout << "Exp�rience: " << candidat.getExperience() << " ann�es" << endl;
        cout << "Code Postal: " << candidat.getCodePostal() << endl;
    }
};



class Demande {
public:
    void approuverDemande() {
        // Approuver une demande
        cout << "Approuver une demande" << endl;
    }

    void refuserDemande() {
        // Refuser une demande
        cout << "Refuser une demande" << endl;
    }

    void suivreDemande() {
        // Suivre l'�tat d'une demande
        cout << "Suivre l'�tat d'une demande" << endl;
    }

    void takeOffDemande() {
        // Annuler une demande
        cout << "Annuler une demande" << endl;
    }
};

class Inscription {
public:
    Candidat sInscrire() {
        string diplome, specialite, experience;
        int codePostal;

        cout << "Inscription d'un visiteur comme candidat" << endl;

        // Demander les informations n�cessaires � l'inscription
        cout << "Veuillez fournir les informations suivantes :" << endl;
        cout << "Dipl�me : ";
        cin >> diplome;
        cout << "Sp�cialit� : ";
        cin >> specialite;
        cout << "Exp�rience : ";
        cin >> experience;
        cout << "Code Postal : ";
        cin >> codePostal;

        // Cr�er et retourner un nouvel objet Candidat avec les informations fournies
        return Candidat nouveauCandidat(diplome, specialite, experience, codePostal);

    }
};

class Visiteur {
private:
    int idV;
    Inscription inscription;

public:
    void consulterOffres(vector<Offre>& offres) {
        // Afficher la liste des offres disponibles
        cout << "Liste des offres disponibles : " << endl;
        for (const Offre& offre : offres) {
            cout << "ID : " << offre.getId() << " - " << offre.getDescription() << endl;
        }

        // Demander � l'utilisateur de saisir l'ID de l'offre � consulter
        int idOffre;
        cout << "Veuillez saisir l'ID de l'offre que vous souhaitez consulter : ";
        cin >> idOffre;

        // Rechercher l'offre dans la liste des offres
        bool trouve = false;
        for (const Offre& offre : offres) {
            if (offre.getId() == idOffre) {
                // Afficher les d�tails de l'offre si elle est trouv�e
                cout << "D�tails de l'offre : " << endl;
                cout << "Titre : " << offre.getTitre() << endl;
                cout << "Description : " << offre.getDescription() << endl;
                cout << "Crit�res : ";
                for (const string& critere : offre.getCriteres()) {
                    cout << critere << ", ";
                }
                cout << endl;
                trouve = true;
                break;
            }
        }

        // Afficher un message si l'offre n'est pas trouv�e
        if (!trouve) {
            cout << "L'offre avec l'ID " << idOffre << " n'a pas �t� trouv�e." << endl;
        }
    }
};


int main() {
    int choix;
    bool quitter = false;
    Recruteur recruteur;
    Candidat candidat;
    Profil profil;
    Offre offre;
    Demande demande;
    Inscription inscription;
    Visiteur visiteur;

    while (!quitter) {
        cout << "Menu:" << endl;
        cout << "1. Publier une offre" << endl;
        cout << "2. Postuler � une offre" << endl;
        cout << "3. Modifier le profil" << endl;
        cout << "4. Ajouter une offre" << endl;
        cout << "5. Approuver une demande" << endl;
        cout << "6. S'inscrire comme candidat" << endl;
        cout << "7. Consulter les offres" << endl;
        cout << "8. Quitter" << endl;
        cout << "Choix: ";
        cin >> choix;

        switch (choix) {
        case 1:
            string titre, description, critere;
            cout << "Titre : ";
            cin.ignore(); // Pour vider le tampon d'entr�e avant d'utiliser getline
            getline(cin, titre);
            cout << "Description : ";
            getline(cin, description);
            cout << "Crit�res : ";
            getline(cin, critere);

            // Convertir la cha�ne de caract�res des crit�res en un vecteur de crit�res
            vector<string> criteres;
            criteres.push_back(critere);

            recruteur.publierOffre(titre, description, criteres);
            break;
        case 2:
            int idOffre, codePostal;
            string nom, prenom, diplome, specialite, experience;
            cout << "Id Offre : ";
            cin >> idOffre;
            cout << "Nom : ";
            cin >> nom;
            cout << "Prenom : ";
            cin >> prenom;
            cout << "Diplome : ";
            cin >> diplome;
            cout << "Sp�cialit� : ";
            cin >> specialite;
            cout << "Experience : ";
            cin >> experience;
            cout << "Code Postal : ";
            cin >> codePostal;
            candidat.postulerOffre(nom, prenom, diplome, specialite, experience, codePostal, idOffre);
            break;
        case 3:
            string nouveauNom, nouveauPrenom, nouveauDiplome, nouvelleSpecialite, nouvelleExperience;
            int nouveauCodePostal;
            cout << "Nouveau Nom : ";
            cin >> nouveauNom;
            cout << "Nouveau Pr�nom : ";
            cin >> nouveauPrenom;
            cout << "Nouveau Dipl�me : ";
            cin >> nouveauDiplome;
            cout << "Nouvelle Sp�cialit� : ";
            cin >> nouvelleSpecialite;
            cout << "Nouvelle Exp�rience : ";
            cin >> nouvelleExperience;
            cout << "Nouveau Code Postal : ";
            cin >> nouveauCodePostal;
            profil.modifierProfil(nouveauNom, nouveauPrenom, nouveauDiplome, nouvelleSpecialite, nouvelleExperience, nouveauCodePostal, candidat);
            break;
        case 4:
            string titreOffre, descriptionOffre;
            cout << "Titre de l'offre : ";
            cin.ignore(); // Pour vider le tampon d'entr�e avant d'utiliser getline
            getline(cin, titreOffre);
            cout << "Description de l'offre : ";
            getline(cin, descriptionOffre);
            offre.ajouterOffre(titreOffre, descriptionOffre);
            break;
        case 5:
            demande.approuverDemande();
            break;
        case 6:
        {
            // Demander � l'utilisateur de s'inscrire en tant que candidat
            Candidat nouveauCandidat = inscription.sInscrire();

            // Afficher un message pour indiquer que l'inscription a �t� effectu�e
            cout << "Inscription en tant que candidat r�ussie !" << endl;
            // Vous pouvez �galement effectuer d'autres actions avec le nouveau candidat ici, si n�cessaire
        }
        break;
        case 7:
            visiteur.consulterOffres(offres);
            break;
        case 8:
            quitter = true;
            break;
        default:
            cout << "Choix invalide. Veuillez s�lectionner un num�ro valide du menu." << endl;
            break;
        }
    }

    return 0;
}

