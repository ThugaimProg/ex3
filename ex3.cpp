// FILE INCLUSION ---------------------------------------------------------------------------------
#include <iostream>                                                             // Pour cout et cin
#include <cmath>                                                                // Pour utiliser les fonctions mathématiques
#include <string>                                                               // Pour utiliser les chaînes de caractères
#include <iomanip>                                                              // Pour utiliser setw()
#include <fstream>                                                              // Pour utiliser les fichiers
using namespace std;                                                            // Pour éviter d'écrire std:: devant les fonctions

struct Etudiant
{	                                        // Declaration de type enregistrement
    string titre;
    string entete;
    char nom[20];
    char prenom[20];
    char matricule[6];
    float moyenneProg;
    float moyenneCyber;
};

// MAIN FUNCTION ----------------------------------------------------------------------------------
int main(){     
    
    string ponderationProg;
    string ponderationCyber;

    ifstream read;                                                                      // Déclaration du fichier en lecture
    read.open("notes.txt");                                                          // Ouverture du fichier en lecture
    
    ofstream write;                                                                     // Déclaration du fichier en écriture
    write.open("excellence.txt");                                                       // Ouverture du fichier en écriture
 	
    Etudiant classe;
	if (read){
        cout  << "\t\tNOM\t\tPROGRAMMATION\t\tCYBERSECURITE" << endl;
	    cout  << "\t\t---\t\t-------------\t\t-------------" << endl;
		while (!read.eof()) {
            getline(read, classe.titre);
            getline(read, classe.entete);
            read >> classe.nom >> classe.prenom >> classe.matricule >> classe.moyenneProg >> classe.moyenneCyber;

            if (classe.moyenneProg >= 85){
                ponderationProg = "Excellent";
                write << classe.nom << endl;
            }
            if (classe.moyenneProg < 85 && classe.moyenneProg >= 75){
                ponderationProg = "Tres Bien";
            }
            if (classe.moyenneProg < 75 && classe.moyenneProg >= 65){
                ponderationProg = "Bien";
            }
            if (classe.moyenneProg < 65 && classe.moyenneProg >= 60){
                ponderationProg = "Passable";
            }
            if (classe.moyenneProg < 60){
                ponderationProg = "Echec";
            }

            if (classe.moyenneCyber >= 85){
                ponderationCyber = "Excellent";
            }
            if (classe.moyenneCyber < 85 && classe.moyenneCyber >= 75){
                ponderationCyber = "Tres Bien";
            }
            if (classe.moyenneCyber < 75 && classe.moyenneCyber >= 65){
                ponderationCyber = "Bien";
            }
            if (classe.moyenneCyber < 65 && classe.moyenneCyber >= 60){
                ponderationCyber = "Passable";
            }
            if (classe.moyenneCyber < 60){
                ponderationCyber = "Echec";
            }


            cout << setw(19) << classe.nom 
            << setw(26) << ponderationProg
            << setw(24) << ponderationCyber << endl; 

		}
	}
	else
		cout << "Impossible d'ouvrir le fichier !" << endl;
}
// END OF FILE
