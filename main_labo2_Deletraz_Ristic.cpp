/*
  ---------------------------------------------------------------------------
  Fichier     : main_labo2_Deletraz_Ristic.cpp
  Nom du labo : à compléter
  Auteur(s)   : Delétraz Alexandre - Ristic Christopher
  Date        : 06.10.2022
  But         : Calculer la course d'un taxi

  Remarque(s) : Le programme ne gère pas les erreurs de saisie
                Le programme gère les valeurs incorrectes. Dans un tel cas, le
                programme s'interrompt et affiche un message d'erreur.

  Compilateur : gcc version 11.2.0
  ---------------------------------------------------------------------------
*/

#include <iostream>   // entrées / sorties
#include <limits>     // pour vider le buffer
#include <iomanip>    // gestion de l'affichage
#define VIDER_BUFFER cin.ignore(numeric_limits<streamsize>::max(), '\n')

using namespace std;

int main()
{
    //-------------------------------------------------------------------
    //                  Déclaration des constantes
    //-------------------------------------------------------------------
    const float PRISE_EN_CHARGE    = 5.0f;
    const float TAXE_DE_BAGAGE     = 2.60f;
    const float TARIF_MINUTE_JOUR  = 1.0f;
    const float TARIF_MINUTE_NUIT  = 1.6f;

    //-------------------------------------------------------------------
    //                  Affichage du début du programme
    //-------------------------------------------------------------------

    int   precision = 2;  // paramètre pour afficher 2 chiffres après la virgule
    int   nbreCara  = 18; // plus grand nombre de caractères pour une condition.

    // affichage de la carte de course d'un taxi

    cout << "Bonjour ce programme calculera le prix d'une course de Taxi."  << endl
         << "Voici les conditions"                                          << endl
         << "==========================="                                   << endl

         << fixed << setprecision(precision)
         << left
         << setw(nbreCara) << "- prise en charge"  << " : "  << PRISE_EN_CHARGE  <<
         endl
         << setw(nbreCara) << "- supp par bagage"  << " : " << TAXE_DE_BAGAGE    <<
         endl
         << setw(nbreCara) << "- tarif/min (jour)" << " : " << TARIF_MINUTE_JOUR <<
         endl
         << setw(nbreCara) << "- tarif/min (nuit)" << " : " << TARIF_MINUTE_NUIT <<
         endl
         << setw(nbreCara) << "- heures de jour"   << " : [8-20]" << endl
         << endl << endl;

    //-------------------------------------------------------------------
    //                  Bloc des saisies utilisateur
    //-------------------------------------------------------------------

    // affichage et entrées pour la commande
    float nbreBagage;
    float distanceKm;
    float vitesseKmh;
    int   departHeure;
    int   nbreCarCommande = 18;  // plus grand nombre de caractères pour la commande.
    int   nbreCarInterval = 11;  // nombre de caractères pour afficher l'intervalle.
    int   nbreCarPoint    = 3;   // nombre de caractères pour les deux points.

    //Le left suivant n'est pas nécessaire, mais par esthétisme avec le right
    // de la ligne suivante, nous l'avons ajouté.
    cout << "Votre commande"   << endl
         << "=============="   << endl
         << left               << setw(nbreCarCommande) << "- nbre de bagage"
         << right              << setw(nbreCarInterval) << "[0 - 4]"
         << setw(nbreCarPoint) << " :";
    cin  >> nbreBagage;
    VIDER_BUFFER;

    // vérification de la valeur, si incorrecte, message d'erreur et interruption du
    // programme

    if(nbreBagage < 0 || nbreBagage > 4)
    {
        cout << "Nombre " << nbreBagage << " est hors champ";
        return EXIT_FAILURE;
    }

    cout << left               << setw(nbreCarCommande) << "- distance [km]"
         << right              << setw(nbreCarInterval) << "[0 - 500]"
         << setw(nbreCarPoint) << " :";
    cin  >> distanceKm;
    VIDER_BUFFER;

    if(distanceKm < 0 || distanceKm > 500)
    {
        cout << "Nombre " << distanceKm << " est hors champ";
        return EXIT_FAILURE;
    }

    cout << left               << setw(nbreCarCommande) << "- vitesse [km/h]"
         << right              << setw(nbreCarInterval) << "[50 - 120]"
         << setw(nbreCarPoint) << " :";
    cin  >> vitesseKmh;
    VIDER_BUFFER;

    cout << left               << setw(nbreCarCommande) << "- depart"
         << right              << setw(nbreCarInterval) << "[0 - 23]"
         << setw(nbreCarPoint) << " :";
    cin  >> departHeure;
    VIDER_BUFFER;

    //-------------------------------------------------------------------
    //             Bloc de calcul et affichage ticket final
    //-------------------------------------------------------------------
    //Affichage de la course

    double prixBagage     = nbreBagage * TAXE_DE_BAGAGE;
    double prixCourse     = (departHeure < 20 ?
                            8 < departHeure ?
                            TARIF_MINUTE_JOUR : TARIF_MINUTE_NUIT :
                            TARIF_MINUTE_NUIT) * ((distanceKm / vitesseKmh) * 60);
    double total          = prixCourse + prixBagage + PRISE_EN_CHARGE;
    int    nbreCarTicket  = 20; // plus grand nombre de caractères du ticket.
    int    nbreCarResult  = 5;  // nombre de caractères pour les totaux.

    cout << "Votre ticket"                                 << endl
         << "============"                                 << endl
         << left
         << setw(nbreCarTicket)  << "- Prise en charge"
         << right
         << setw(nbreCarPoint)   << " : "
         << setw(nbreCarResult)  << PRISE_EN_CHARGE        << endl
         << left
         << setw(nbreCarTicket)  << "- supp bagages"
         << right
         << setw(nbreCarPoint)   << " : "
         << setw(nbreCarResult)  << prixBagage             << endl
         << left
         << setw(nbreCarTicket)  << "- prix de la course"
         << right
         << setw(nbreCarPoint)   << " : "
         << setw(nbreCarResult)  << prixCourse             << endl
         << "TOTAL : "           << total                  << endl
         << endl;

    //-------------------------------------------------------------------
    //                          Fin du programme
    //-------------------------------------------------------------------
    cout << "Merci d'avoir utiliser notre service."                 << endl
         << "Veuillez appuyer sur enter pour quitter le programme." << endl;
    VIDER_BUFFER;

    return EXIT_SUCCESS;
}
