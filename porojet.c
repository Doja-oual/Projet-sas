// bibliothèque pour effectuer des opérations d'entrée/sortie
#include <stdio.h>
// bibliothèque standard pour la gestion de la mémoire
#include <stdlib.h>
//bibliothèque de manipulation de chaînes de caractères
#include <string.h>

#define Max_Reservation 200
// ==================================== structure ==============================================================================

// date structure
typedef struct 
{ 
    int reference;
    char Nom[50];
    char Prenom[50];
    char TeleNume[50];
    int age;
    char statut[30];
    char Date[20];
} reservation;

reservation reservations[Max_Reservation] = {
    {1, "Ahmed", "El Mansouri", "0601234567", 30, "Valide", "2024-09-12"},
    {2, "Fatima", "Zahra", "0612345678", 25, "Valide", "2024-09-05"},
    {3, "Youssef", "Bouzid", "0623456789", 22, "Valide", "2024-09-14"},
    {4, "Amina", "El Fassi", "0634567890", 28, "reporte", "2024-09-19"},
    {5, "Omar", "Benali", "0645678901", 27, "Valide", "2024-09-08"},
    {6, "Leila", "Amari", "0656789012", 32, "Valide", "2024-09-02"},
    {7, "Samir", "Bouchareb", "0667890123", 21, "Valide", "2024-09-10"},
    {8, "Salma", "Ouardani", "0678901234", 26, "annule", "2024-09-11"},
    {9, "Khalid", "El Idrissi", "0689012345", 29, "traite", "2024-09-22"},
    {10, "Hana", "Jbari", "0690123456", 24, "Valide", "2024-09-17"}
};

int NbrReservation = 10;
int nouvelleReference = 10;
// +++++++++++++++++++++fontion qui affiche "projet fin sas++++++++++++++++++++++++++++++"
void Sas(){

    printf("\n\n\n");
		printf("\t\t			.---.               _        .-.   .---.  _          .--.  .--.  .--. \n");
		printf("\t\t			: .; :             :_;      .' `.  : .--':_;        : .--': .; :: .--'\n");
		printf("\t\t			:  _.'.--.  .--.   .-. .--. `. .'  : `;  .-.,-.,-.  `. `. :    :`. `. \n");
		printf("\t\t			: :   : ..'' .; :  : :' '_.' : :   : :   : :: ,. :   _`, :: :: : _`, :\n");
		printf("\t\t			:_;   :_;  `.__.'  : :`.__.' :_;   :_;   :_;:_;:_;  `.__.':_;:_;`.__.'\n");
		printf("\t\t			                 .-. :                                                     \n");
		printf("\t\t			                 `._.'                                                          \n");
		printf("\n\n\n");
		}

/*+++++++++++++++++++++++++++++ FONCTION AJOUTER ++++++++++++++++++++++++++++++*/
void Ajouter_reservation() {
    if (NbrReservation < Max_Reservation) {
        reservation patien;
        patien.reference = nouvelleReference;

        printf("entre le nom : ");
        scanf(" %[^\n]", patien.Nom);
        printf("entre le prenom : ");
        scanf(" %[^\n]", patien.Prenom);
        printf("entre le Telephone : ");
        scanf(" %[^\n]", patien.TeleNume);
        printf("entre l'age : ");
        scanf("%d", &patien.age);
        printf("entre la date au format YYYY-MM-JJ : ");
        scanf(" %[^\n]", patien.Date);
        printf("Statut : Valide\n");
        reservations[NbrReservation] = patien;
       NbrReservation++;
        nouvelleReference++;
    } else {
        printf("pas espace pour ajouter une  reservation.\n");
    }
}

/*++++++++++++++++++++++++++++++ FONCTION MODIFIER RESERVATION +++++++++++++++++++++++++++++++*/
void modifierReservation(int reference) {
    for (int i = 0; i < NbrReservation; i++) {
        if (reservations[i].reference == reference) {
            printf("Modification de la reservation:\n");
            printf("entre un nouveau nom : ");
            scanf(" %[^\n]", reservations[i].Nom);
            printf("entre un nouveau prenom : ");
            scanf(" %[^\n]", reservations[i].Prenom);
            printf("entre un nouveau numero de telephone : ");
            scanf(" %[^\n]", reservations[i].TeleNume);
            printf("entre un nouvel age : ");
            scanf("%d", &reservations[i].age);
            printf("entre un nouveau statut : ");
            scanf(" %[^\n]", reservations[i].statut);
             printf("entre un nouveau date : ");
            scanf(" %[^\n]", reservations[i].Date);

            printf("Reservation modifiee.\n");
            return;
        }
    }
    printf("Reference non trouvee.\n");
}

/*+++++++++++++++++++++++++ FONCTION SUPPRIMER RESERVATION ++++++++++++++++++++++++++*/
void supprimeReservation(int reference) {
    for (int i = 0; i < NbrReservation; i++) {
        if (reservations[i].reference == reference) {
            for (int j = i; j < NbrReservation - 1; j++) {
                reservations[j] = reservations[j + 1];
            }
            NbrReservation--;
            printf("Reservation supprimee.\n");
            return;
        }
    }
    printf("Reference non trouvee.\n");
}

/*+++++++++++++++++++++ AFFICHER ELEMENT ++++++++++++++++++++++++++++++++*/
void afficherElement(int i) {
    printf("Reservation %d:\n", reservations[i].reference);
    printf("Nom: %s\n", reservations[i].Nom);
    printf("Prenom: %s\n", reservations[i].Prenom);
    printf("Numero de telephone: %s\n", reservations[i].TeleNume);
    printf("Statut: %s\n", reservations[i].statut);
    printf("Age: %d\n", reservations[i].age);
     printf("Date: %s\n", reservations[i].Date);

    printf("--------------\n");
}

/* +++++++++++++++++++++++AFFICHER TOUTES LES RESERVATIONS++++++++++++++++++++++ */
void afficherReservations() {
    if (NbrReservation == 0) {
        printf("Aucune reservation a afficher.\n");
    } else {
        for (int i = 0; i < NbrReservation; i++) {
            afficherElement(i);
        }
    }
}

/* ++++++++++++++++++++++++++++++RECHERCHE PAR REFERENCE ++++++++++++++++++*/
int rechercheElement(int a) {
    for (int i = 0; i < NbrReservation; i++) {
        if (a == reservations[i].reference) {
            return i;
        }
    }
    return -1;
}

/* ++++++++++++++++++++++++++++RECHERCHE PAR NOM++++++++++++++++++++++++++ */
int rechercheElementNom(char nom[30]) {
    for (int i = 0; i < NbrReservation; i++) {
        if (strcasecmp(nom, reservations[i].Nom) == 0) {
            return i;
        }
    }
    return -1;
}

/* ++++++++++++++++++++++++RECHERCHE PAR DATE +++++++++++++++++++++++++*/
int rechercheElementDate(char date[20]) {
    for (int i = 0; i < NbrReservation; i++) {
        if (strcasecmp(date, reservations[i].Date) == 0) {
            return i;
        }
    }
    return -1;
}

/* +++++++++++++++++++FONCTION DE RECHERCHE AVEC SOUS-MENU ++++++++++++++++++++++++*/
void rechercheReservation() {
    int choix;
    printf("============ Sous-menu Recherche ==================\n");
    printf("1. Rechercher par reference\n");
    printf("2. Rechercher par nom\n");
    printf("3. Rechercher par date\n");
    printf("Entrez votre choix : ");
    scanf("%d", &choix);

    switch (choix) {
        case 1: {
            int reference;
            printf("Entrez la reference recherchee : ");
            scanf("%d", &reference);
            int index = rechercheElement(reference);
            if (index != -1) {
                afficherElement(index);
            } else {
                printf("Reservation non trouvee.\n");
            }
            break;
        }
        case 2: {
            char nom[30];
            printf("Entrez le nom recherche : ");
            scanf(" %[^\n]", nom);
            int index = rechercheElementNom(nom);
            if (index != -1) {
                afficherElement(index);
            } else {
                printf("Reservation non trouvee.\n");
            }
            break;
        }
        case 3: {
            char date[20];
            printf("Entrez la date recherchee (YYYY-MM-JJ) : ");
            scanf(" %[^\n]", date);
            int index = rechercheElementDate(date);
            if (index != -1) {
                afficherElement(index);
            } else {
                printf("Reservation non trouvee.\n");
            }
            break;
        }
        default:
            printf("Choix invalide.\n");
            break;
    }
}

/* ++++++++++++++++++++++TRI DES RESERVATIONS PAR NOM +++++++++++++++++++++++++++++*/
void TriAlphabitique() {
    for (int i = 0; i < NbrReservation - 1; i++) {
        for (int j = 0; j < NbrReservation - i - 1; j++) {
            if (strcasecmp(reservations[j].Nom, reservations[j + 1].Nom) > 0) {
                reservation T = reservations[j];
                reservations[j] = reservations[j + 1];
                reservations[j + 1] = T;
            }
        }
    }
}

/*+++++++++++++++++++++++ TRI DES RESERVATIONS PAR STATUT+++++++++++++++++++++ */
void TriStatut() {
    for (int i = 0; i < NbrReservation - 1; i++) {
        for (int j = 0; j < NbrReservation - i - 1; j++) {
            if (strcasecmp(reservations[j].statut, reservations[j + 1].statut) > 0) {
                reservation T = reservations[j];
                reservations[j] = reservations[j + 1];
                reservations[j + 1] = T;
            }
        }
    }
}

/* ++++++++++++++++++++TRI DES RESERVATIONS PAR DATE ++++++++++++++++++++*/
void TriDate() {
    for (int i = 0; i < NbrReservation - 1; i++) {
        for (int j = 0; j < NbrReservation - i - 1; j++) {
            if (strcasecmp(reservations[j].Date, reservations[j + 1].Date) > 0) {
                reservation T = reservations[j];
                reservations[j] = reservations[j + 1];
                reservations[j + 1] = T;
            }
        }
    }
}

/* ++++++++++++++++++++++++++++++SOUS-MENU POUR LES TRI+++++++++++++++++++++++++++++++++ */
void menuTri() {
    int choix;
    printf("\n========== Sous-menu de Tri ==========\n");
    printf("1. Trier par ordre alphabetique Nom\n");
    printf("2. Trier par statut\n");
    printf("3. Trier par date\n");
    printf("Entrez votre choix : ");
    scanf("%d", &choix);

    switch (choix) {
        case 1:
            TriAlphabitique();
            printf("Reservations  par ordre alphabetique Nom.\n");
            break;
        case 2:
            TriStatut();
            printf("Reservations  par statut.\n");
            break;
        case 3:
            TriDate();
            printf("Reservations  par date.\n");
            break;
        default:
            printf(" entrez un nombre valide.\n");
            break;
    }
}

/*++++++++++++++++ STATISTIQUE CALCULER MOYENNE D'AGE++++++++++++++++ */
void StatistiqueMoyenneAge() {
    int S = 0;
    for (int i = 0; i < NbrReservation; i++) {
        S += reservations[i].age;
    }
    float moyenne = S / NbrReservation;
    printf("La moyenne d'age est : %.2f\n", moyenne);
}

/*++++++++++++++ STATISTIQUE AFFICHER TRANCHE D'AGE++++++++++++++++ */
void StatistiqueTrancheAge() {
    int generation1 = 0, generation2 = 0, generation3 = 0;

    for (int i = 0; i < NbrReservation; i++) {
        if (reservations[i].age <= 18) {
            generation1++;
        } else if (reservations[i].age <= 35) {
            generation2++;
        } else {
            generation3++;
        }
    }
    
    printf(" 0 et 18 ans: %d\n", generation1);
    printf(" 19 et 35 ans: %d\n", generation2);
    printf(" plus de 35 ans: %d\n", generation3);
}

/* +++++++++++++++++++++++STATISTIQUE NOMBRE TOTALE PAR STATUT++++++++++++++ */
void StatistiqueStatut() {
    int valide = 0, annule = 0, reporte = 0, traite = 0;

    for (int i = 0; i < NbrReservation; i++) {
        if (strcasecmp(reservations[i].statut, "Valide") == 0) {
            valide++;
        } else if (strcasecmp(reservations[i].statut, "Annule") == 0) {
            annule++;
        } else if (strcasecmp(reservations[i].statut, "Rep porte") == 0) {
            reporte++;
        } else if (strcasecmp(reservations[i].statut, "Traite") == 0) {
            traite++;
        }
    }

    printf("validees: %d\n", valide);
    printf(" annulees: %d\n", annule);
    printf(" reporte: %d\n", reporte);
    printf(" traitees: %d\n", traite);
}

/* +++++++++++++++SOUS MENU DE STATISTIQUES ++++++++++++*/
void StatistiqueReservation() {
    int choix;

    printf("\n===== Menu Statistiques =====\n");
    printf("1. Calculer la moyenne d'age\n");
    printf("2. Afficher la repartition par tranche d'age\n");
    printf("3. Afficher le nombre de reservations par statut\n");
    printf("0. Retour au menu principal\n");
    printf("Entrez votre choix: ");
    scanf("%d", &choix);

    switch (choix) {
        case 1:
            StatistiqueMoyenneAge();
            break;
        case 2:
            StatistiqueTrancheAge();
            break;
        case 3:
            StatistiqueStatut();
            break;
        case 0:
            printf("Retour au menu principal.\n");
            break;
        default:
            printf("Choix invalide.\n");
            break;
    }
}

/* +++++++++++++++++++++++++++++++++++MENU PRINCIPAL++++++++++++++++++++ */
void menu() {
    int choix;
    int reference;

    do {
        printf("\n============== Menu Principal ==============\n");
        printf("1. Ajouter une reservation\n");
        printf("2. Modifier une reservation\n");
        printf("3. Supprimer une reservation\n");
        printf("4. Afficher toutes les reservations\n");
        printf("5. Trier les reservations\n");
        printf("6. Rechercher une reservation\n");
        printf("7. Calculer les statistiques\n");
        printf("0. Quitter\n");
        printf("===========================================\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                Ajouter_reservation();
                break;
            case 2:
                printf("Entrez la reference : ");
                scanf("%d", &reference);
                modifierReservation(reference);
                break;
            case 3:
                printf("Entrez la reference : ");
                scanf("%d", &reference);
                supprimeReservation(reference);
                break;
            case 4:
                afficherReservations();
                break;
            case 5:
                menuTri();
                break;
            case 6:
                rechercheReservation();
                break;
            case 7:
                StatistiqueReservation();
                break;
            case 0:
                printf("fin de program.\n");
                break;
            default:
                printf(" entrez un nombre valide.\n");
                break;
        }
    } while (choix != 0);
}

int main() {
    Sas();
    menu();
    return 0;
}
