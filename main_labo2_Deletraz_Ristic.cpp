/*
  ---------------------------------------------------------------------------
  Fichier     : main_labo2_Deletraz_Ristic.cpp
  Nom du labo : à compléter
  Auteur(s)   : Delétraz Alexandre - Ristic Christopher
  Date        : 06.10.2022
  But         : Calculer la course d'un taxi

  Remarque(s) : Laboratoire 02 course de taxi

  Compilateur : gcc version 11.2.0
  ---------------------------------------------------------------------------
*/

#include <iostream>   // entrées / sorties
#include <limits>     // pour vider le buffer
#include <iomanip>    // gestion de l'affichage

using namespace std;

int main()
{
    const float PRISE_EN_CHARGE    = 5.0f;
    const float TAXE_DE_BAGAGE     = 2.0f;
    const float TARIF_MINUTE_JOUR  = 1.0f;
    const float TARIF_MINUTE_NUIT  = 1.6f;

    float nbreBagage;
    float distanceKm;
    float vitesseKmh;
    int   departHeure;

    // affichage de la carte de course d'un taxi

    cout << "Bonjour ce programme calculera le prix d'une course de Taxi."  << endl
         << "Voici les conditions"                                          << endl
         << "===================="                                          << endl

         << fixed << setprecision(2) // paramètre pour afficher 2 chiffres après
         // la virgule pour les réels

         << "- prise en charge \t: " << PRISE_EN_CHARGE                     << endl
         << "- supp par bagage \t: " << TAXE_DE_BAGAGE                      << endl
         << "- tarif/min (jour)\t: " << TARIF_MINUTE_JOUR                   << endl
         << "- tarif/min (nuit)\t: " << TARIF_MINUTE_NUIT                   << endl
         << "- heures de jour  \t: [ 8-20]"                                 << endl
         << endl << endl;

    // affichage et entrées pour la commande

    cout << "Votre commande" << endl
         << "==============" << endl
         << "- nbre de bagage   [0 - 4] : ";
    cin  >> nbreBagage;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // vide le buffer

    cout << endl
         << "- distance [km]    [0 - 500] : ";
    cin  >> distanceKm;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << endl
         << "- vitesse [km/h]  [50 - 120] : ";
    cin  >> vitesseKmh;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << endl
         << "depart              [0 - 23] : ";
    cin  >> departHeure;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');



    //TODO si on utilise trop de fois le meme chiffre dans setw(5) on fait un
    // define en haut
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
   return EXIT_SUCCESS;
}
