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

            if (ponderationProg == "Excellent" && ponderationCyber == "Excellent"){
                write << classe.nom << endl;
            }

            cout << setw(19) << classe.nom 
            << setw(26) << ponderationProg
            << setw(24) << ponderationCyber << endl; 
		}
	}
	else
		cout << "Impossible d'ouvrir le fichier !" << endl;
}
// END OF FILE -------------------------------------------------------------------------------------
//                                                                                                                              
// ..                                                                                       ..                                 
// ..                                                                                     ..'.                                 
//  ..  .                          .     .     ...                                     .....           ..                      
//   '...                          'c,  .,.      .,'.                            .,'....               ..                      
//   .,;'                            .'.:c.        ..'.                        .cOkc..       .         .                       
//    .ld.                             ;Od.         ..:ol,                    .cd:.         ',        ..             ..        
//     .;,.   ..        ...            .OO.         .,,:ldl'  ;c:,....       .;;. ....      .        ..           ....         
//        .:;..;'        :o,.          '0k.               .;cdo,.....      .cdc'.....      ,'       ..           ...           
//          ,c:ld,       .,.:c.         ld.                .:cl;..    ..'ood,.            ';.      ..           .;.            
//            .:kOl.     .'  ,dc.  :l.  ;d.       ..      ,,. .,:c:,'',,.              ...        ';'            .;;:;.         
//             .:k0o.        cKk;'c0x. .xl      .'.    .;'  .''';cl:.       .,,.   .cc'.''..    ':.           ....:c.         
//                .:kO,        .;:lod0o. cO,   ..';    'dl:::;..    .::.     ,'    ,xxc,oO:      ,;        ...     ..          
//                  .ok'             ;kc .do.  ;dx;   :KXxc'          :l;,.  ;c. .od,   'l.      ;;      ...        .          
//                   .dx.             oO:.;kl   lKc  cXNl     .';,.    c0:   lX0dOO,    .,.      :,    .'.                     
//                   .xx.          .:0WXxdXXc  .xo.:XMWo    ,kNWNOc.  .kl  .OWXXWx.     .      .c,oo;',.                       
//                .,,.'kk.        .dXXN0,'kN0;  ;d;xWNWK,   ,0WNNNWO:. ox. .kWko00:     .      .o:.,'                         
//                 .xXOdONO,      .kNx:    .lXk. .kKN0oONl   .ON0k0WNX0dkKc .dWOxxloc.          'Od'.  ....                    
//                .;;,,;cdkOc.    oNK,       lx. .xWNd.cX0,  .kXd   lc0WNNx. oN0kk,.cc.    ..  .dx'.''.'.                      
//          .lc:;;,.       ,dxl' 'OWd.        ;. .kW0, '0Wx. '0Kk  OkKO:cx, lNklx;  ,ll;'..  .lk:..'.                         
//           ;do,          .,codxONNc           cXW0o:oKWXc .ONK0KWWKl.  ;:.lNOlkc   .xo.   .oo'                              
//         .,;.           o.   .cKWX:          :KWKoxdc0NN0,.kWNXXWW0'   .cokNOcxl    ';   .ol.                               
//         ..           'd.      :KNc        o lkWNo.:; :kKNo.dKkcdWWNo.   .lkK0cdd.    .  .ol.                                
//                     ,x,       .oNx.      .kXKXN0, ;' .:dXk.l0d:oNWNXd'    ;0O;ox.      .dx'                                 
//                     ,d'        .kK:      oNNNNNo  .. .,:OXlo0kco0dd0X0l.  ,00:ck,     .o0o;;;;ldo,                          
//                     .c.         .x0lo ..cKWWWWX;      ,;cXXXX0oxK: 'oKNO:.,OXocOc     ,0d.    .:odc'                        
//                     .;.          .l0XNOx.'.WWWk.  ..  ;:'kWWWNKKNk.  'dXN0OXN0OX0c,,,;xKc         ';;.   .'' .  .,:;'.        
//                     .:.            ,O0d;   NXo.      ''.oNWNX00NK;    ,dKN0dddxxkkxxO00k;          .':od:. ...,:xOd:.      
//                     ,c.           'do.    ;okKd.      .. ;O000c.d0;      'dl.        ...l0x,          ,0x.       ':..,,.    
//                    ;kc           ,xl.    .: xk.       . ':,lx; .ll.      .l;            'oko'        .ol        ..   .;'   
//                   ,cl,          .o:       .  ;x,         .. .c,  .c;       .l,             .oOc.       cd.              '.  
//                  'c.,;          ;c.          .oo.        .. .;,.  'd;       ;d,            'dKKk:.     ;d:.              .. 
//                 .d: ;c.        .l,           .oKd.        ..'ll.  .lc       .xKl.         'OX0dc'      .......              
//                 l0; ,l.        cd.           .cdx,          .;;.   ,:.       oXOl,.       .d0l.         .   .....           
//                 cx' ,l.       .dx.           :, ;l.          .'.   ':.      'OXl.cc.       .:d;                .'..         
//                 .c'  .        'Ok.          .;.  cdc:,.       ..   .,       ;Kk'  ''         .;,.                           
//                  :,           :KKd;.        ..   .oo o:.           ';       ,k;    '.          .'.                          
//                  ,:           .lxkkk,            ,,               ,;       :k,    ...           ',.                        
//                 .;.             ...;oc.          .'.             ,o'       :k'     ..            .,,.                      
//                  ''                 .:c.          ..            .:d,       'd;      .              'c;                     
//                  .'.                 .c:          .:'          .'.;:       .lc                      .c:.                   
//                   ,,                  .l'          ..          .. .:.       ;l.                       .;,.                 
//                    .:.                  cl.                        .;.       .o,                         ,'                 
//                     cd.                 .dc                         '.       .l:                         .'.                
//                     .'.                  :o.                        '.        ;c.                         .'                
//                                          .c,                        ',        'c.                         .,.               
//                                           ':.                       ,:.       .:'                         .;.               
//                                            ''                       ',         .'                         .;.               
//                                             '.                      ..          .                         .,.               
//                                             .'.                     ..                                     ''               
//                                              .,.                    ..                                     .'               
//                                               ',                     .                                      .               
//                                                                     ..                                     .               
//                                                                      ..                                                     
//                                                                      ..                                                     
//                                                                       .                                                                                                                                                                                                                                                                                                       
