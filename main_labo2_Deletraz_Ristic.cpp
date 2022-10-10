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
    const float PRISE_EN_CHARGE    = 5.0f;
    const float TAXE_DE_BAGAGE     = 2.60f;
    const float TARIF_MINUTE_JOUR  = 1.0f;
    const float TARIF_MINUTE_NUIT  = 1.6f;float nbreBagage;

    int   precision = 2;  // paramètre pour afficher 2 chiffres après la virgule
    int   nbreCara  = 18; // plus grand nombre de caractères pour une condition.

    // affichage de la carte de course d'un taxi

    cout << "Bonjour ce programme calculera le prix d'une course de Taxi."  << endl
         << "Voici les conditions"                                          << endl
         << "==========================="                                   << endl

         << fixed << setprecision(precision)

         << setw(nbreCara) << "- prise en charge" << " : "  << PRISE_EN_CHARGE   <<
         endl
         << setw(nbreCara) << "- supp par bagage " << " : " << TAXE_DE_BAGAGE    <<
         endl
         << setw(nbreCara) << "- tarif/min (jour)" << " : " << TARIF_MINUTE_JOUR <<
         endl
         << setw(nbreCara) << "- tarif/min (nuit)" << " : " << TARIF_MINUTE_NUIT <<
         endl
         << setw(nbreCara) << "- heures de jour  " << " : [8-20]" << endl
         << endl << endl;

    // affichage et entrées pour la commande
    float distanceKm;
    float vitesseKmh;
    int   departHeure;

    cout << "Votre commande" << endl
         << "==============" << endl
         << "- nbre de bagage   [0 - 4] : ";
    cin  >> nbreBagage;
    VIDER_BUFFER;
    //cout << endl;

    // vérification de la valeur, si incorrecte, message d'erreur et interruption du
    // programme

    if(nbreBagage < 0 || nbreBagage > 4)
    {
        cout << "Nombre " << nbreBagage << " est hors champ";
        return EXIT_FAILURE;
    }

    cout << "- distance [km]    [0 - 500] : ";
    cin  >> distanceKm;
    VIDER_BUFFER;
    //cout << endl;

    if(distanceKm < 0 || distanceKm > 500)
    {
        cout << "Nombre " << distanceKm << " est hors champ";
        return EXIT_FAILURE;
    }

    cout << "- vitesse [km/h]  [50 - 120] : ";
    cin  >> vitesseKmh;
    VIDER_BUFFER;
   // cout << endl;

    cout << "- depart              [0 - 23] : ";
    cin  >> departHeure;
    VIDER_BUFFER;
    //cout << endl;


    //Affichage de la course

    double prixBagage     = nbreBagage * TAXE_DE_BAGAGE;
    double prixCourse     = (departHeure < 20 ?
                            8 < departHeure ?
                            TARIF_MINUTE_JOUR : TARIF_MINUTE_NUIT :
                            TARIF_MINUTE_NUIT) * distanceKm;
    double total          = prixCourse + prixBagage + PRISE_EN_CHARGE;
    int    nbreCaraTicket = 16; // plus grand nombre de caractères du ticket.

    cout << "Votre ticket"                                    << endl
         << "============"                                    << endl
         << setw(nbreCaraTicket) << "- Prise en charge"       << " : "
         << PRISE_EN_CHARGE                                   << endl
         << setw(nbreCaraTicket) << "- supp bagages"          << " : "
         << prixBagage                                        << endl
         << setw(nbreCaraTicket) << "- prix de la course"     << " : "
         << prixCourse                                        << endl
         << "TOTAL : "           << total                     << endl
         << endl;

    cout << "Merci d'avoir utiliser notre service."                 << endl
         << "Veuillez appuyer sur enter pour quitter le programme." << endl;

    VIDER_BUFFER;
    return EXIT_SUCCESS;
}
