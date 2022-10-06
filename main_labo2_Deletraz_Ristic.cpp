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
#include <string>     // affichage de texte type string

using namespace std;

int main()
{
    const float PRISE_EN_CHARGE    = 5.0f;
    const float TAXE_DE_BAGAGE     = 2.0f;
    const float TARIF_MINUTE_JOUR  = 1.0f;
    const float TARIF_MINUTE_NUIT  = 1.6f;

    // affichage de la carte de course d'un taxi

    cout << "Bonjour ce programme calculera le prix d'une course de Taxi."  << endl
         << "Voici les conditions"                                          << endl
         << "===================="                                          << endl

         << fixed << setprecision(2) // paramètre pour afficher 2 chiffres après
         // la virgule pour les réels

         << "- prise en charge \t: " << PRISE_EN_CHARGE                     << endl
         << "- supp par bagag  \t: " << TAXE_DE_BAGAGE                      << endl
         << "- tarif/min (jour)\t: " << TARIF_MINUTE_JOUR                   << endl
         << "- tarif/min (nuit)\t: " << TARIF_MINUTE_NUIT                   << endl
         << "- heures de jour  \t: [ 8-20]"                                 << endl
         << endl << endl;

    // affichage et entrées pour la commande



    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // vide le buffer


    //TODO si on utilise trop de fois le meme chiffre dans setw(5) on fait un
    // define en haut

   return EXIT_SUCCESS;
}
