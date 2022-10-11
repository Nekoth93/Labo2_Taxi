/*
---------------------------------------------------------------------------
Fichier     : main_labo2_Deletraz_Ristic.cpp
Nom du labo : Labo2 - Taxi
Auteur(s)   : Delétraz Alexandre - Ristic Christopher
Date        : 06.10.2022
But         : Calculer la course d'un taxi.

Remarque(s) : Le programme ne gère pas les erreurs de saisie (caractères spéciaux
              et lettres).
              Le programme traite les valeurs incorrectes (hors champ).
              Dans un tel cas, le programme s'interrompt et affiche un message
              d'erreur.

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

   const int PRECISION = 2;  // paramètre pour afficher 2 chiffres après la virgule
   const int NBRE_CAR  = 18; // plus grand nombre de caractères pour une condition.

   // affichage de la carte de course d'un taxi

   cout << "Bonjour ce programme calculera le prix d'une course de Taxi." << endl
        << "Voici les conditions"                                         << endl
        << "==========================="                                  << endl

        << fixed << setprecision(PRECISION)
        << left
        << setw(NBRE_CAR)    << "- prise en charge"  << " : "
        << PRISE_EN_CHARGE   << endl
        << setw(NBRE_CAR)    << "- supp par bagage"  << " : "
        << TAXE_DE_BAGAGE    << endl
        << setw(NBRE_CAR)    << "- tarif/min (jour)" << " : "
        << TARIF_MINUTE_JOUR << endl
        << setw(NBRE_CAR)    << "- tarif/min (nuit)" << " : "
        << TARIF_MINUTE_NUIT << endl
        << setw(NBRE_CAR)    << "- heures de jour"   << " : [8-20]"
        << endl
        << endl << endl;

   //-------------------------------------------------------------------
   //                  Bloc des saisies utilisateur
   //-------------------------------------------------------------------

   // affichage et entrées pour la commande
         int nbreBagage;
         int heureDepart;
       float distanceKm;              // Est en float pour la partie calcul.
       float vitesseKmh;              // Est en float pour la partie calcul.
   const int NBR_CAR_COMMANDE   = 18; // nombre de caractères pour la commande.
   const int NBR_CAR_INTERVALLE = 11;
   const int NBR_CAR_POINTS     = 2;  // nombre de caractères pour les deux points.
   const int BAGAGE_MAX         = 4;
   const int DISTANCE_MAX       = 500;
   const int VIT_MOY_MIN        = 50;
   const int VIT_MOY_MAX        = 120;
   const int DERNIERE_HEURE     = 23;  // défini l'heure de fin de l'horloge

   // Dans ce bloc, il aurait fallu utiliser les constantes que nous avons pour les
   // afficher au lieu d'utiliser des valeurs en dur. Malheureusement, nous
   // n'avons pas réussi à garder un affichage correctement aligné en utilisant
   // que des setw().
   // Nous avons donc choisi de laisser le code tel quel en connaissance de cause.

   cout << "Votre commande" << endl
        << "==============" << endl
        << setw(NBR_CAR_COMMANDE)   << "- nbre de bagage"
        << right
        << setw(NBR_CAR_INTERVALLE) << "[0 - 4]"
        << setw(NBR_CAR_POINTS)     << " :";
   cin  >> nbreBagage;
   VIDER_BUFFER;

   // vérification de la valeur, si incorrecte, message d'erreur et interruption du
   // programme
   if(nbreBagage < 0 || nbreBagage > BAGAGE_MAX)
   {
      cout << "Nombre " << nbreBagage << " est hors champ";
      return EXIT_FAILURE;
   }

   cout << left
        << setw(NBR_CAR_COMMANDE)   << "- distance [km]"
        << right
        << setw(NBR_CAR_INTERVALLE) << "[0 - 500]"
        << setw(NBR_CAR_POINTS)     << " :";
   cin  >> distanceKm;
   VIDER_BUFFER;

   if(distanceKm < 0 || distanceKm > DISTANCE_MAX)
   {
      cout << "Nombre " << distanceKm << " est hors champ";
      return EXIT_FAILURE;
   }

   cout << left
        << setw(NBR_CAR_COMMANDE)   << "- vitesse [km/h]"
        << right
        << setw(NBR_CAR_INTERVALLE) << "[50 - 120]"
        << setw(NBR_CAR_POINTS)     << " :";
   cin  >> vitesseKmh;
   VIDER_BUFFER;

   if(vitesseKmh < VIT_MOY_MIN || vitesseKmh > VIT_MOY_MAX)
   {
      cout << "Nombre " << vitesseKmh << " est hors champ";
      return EXIT_FAILURE;
   }

   cout << left
        << setw(NBR_CAR_COMMANDE)   << "- depart"
        << right
        << setw(NBR_CAR_INTERVALLE) << "[0 - 23]"
        << setw(NBR_CAR_POINTS)     << " :";
   cin  >> heureDepart;
   VIDER_BUFFER;

   if(heureDepart < 0 || heureDepart > DERNIERE_HEURE)
   {
      cout << "Nombre " << heureDepart << " est hors champ";
      return EXIT_FAILURE;
   }

   //-------------------------------------------------------------------
   //             Bloc de calcul et affichage ticket final
   //-------------------------------------------------------------------
   //Affichage de la course

   const int DEBUT_HEURE_NUIT = 20;
   const int DEBUT_HEURE_JOUR = 8;

   // Opérateur ternaire qui permet de déterminer si l'on est en tarif de
   // jour ou de nuit. Le résultat est multiplié par le temps en minutes.
       float prixCourse       = (heureDepart < DEBUT_HEURE_NUIT?
                                DEBUT_HEURE_JOUR < heureDepart ?
                                TARIF_MINUTE_JOUR : TARIF_MINUTE_NUIT :
                                TARIF_MINUTE_NUIT) * (distanceKm / vitesseKmh * 60);
       float prixBagage       = nbreBagage * TAXE_DE_BAGAGE; // Conversion en float
       float total            = prixCourse + prixBagage + PRISE_EN_CHARGE;
   const int NBRE_CAR_TICKET  = 20; // plus grand nombre de caractères du ticket.
   const int NBRE_CAR_RESULT  = 5;  // nombre de caractères pour les totaux.

   cout << "Votre ticket"        << endl
        << "============"        << endl
        << left
        << setw(NBRE_CAR_TICKET) << "- Prise en charge"
        << right
        << setw(NBR_CAR_POINTS)  << " : "
        << setw(NBRE_CAR_RESULT) << PRISE_EN_CHARGE        << endl
        << left
        << setw(NBRE_CAR_TICKET) << "- supp bagages"
        << right
        << setw(NBR_CAR_POINTS)  << " : "
        << setw(NBRE_CAR_RESULT) << prixBagage             << endl
        << left
        << setw(NBRE_CAR_TICKET) << "- prix de la course"
        << right
        << setw(NBR_CAR_POINTS)  << " : "
        << setw(NBRE_CAR_RESULT) << prixCourse             << endl
        << "TOTAL : "            << total                  << endl
        << endl;

   //-------------------------------------------------------------------
   //                          Fin du programme
   //-------------------------------------------------------------------
   cout << "Merci d'avoir utiliser notre service."                 << endl
        << "Veuillez appuyer sur enter pour quitter le programme." << endl;
   VIDER_BUFFER;

   return EXIT_SUCCESS;
}