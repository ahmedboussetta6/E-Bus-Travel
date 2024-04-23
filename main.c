/////////////////////////////////////////////////////////////////////////////////////////////////
///////////////Bienvenue sur notre application 'E-Bus-Travel'/////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
////'E-Bus-Travel' est une simple application cmd , ecrite en langage C, assure la reservation////
/////d'un bus pour faire un voyage. Elle permet de gerer : /////////////////////////////////////
/////les bus, les reservations, et les voyageurs.////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100
typedef struct
{
    char nom[max];
    char prenom[max];
    char num_tel[10]; //numero_de_telephone
    char cin[10];     //numero du carte d'identite nationale
} voyageur;

typedef struct
{
    char jour[5];
    char mois[5];
    char annee[5];
} datev;                        //structure date du voyage

typedef struct
{
    char depart[max];
    char fin[max];
    datev date;              //date de voyage
    int nombre_de_place;     //nombre de place à reserver
} reservation;

typedef struct
{
    char mail[max];
    char mdp[10];           //mot de passe du compte
    voyageur voy;
    reservation res;
} compte;                   //compte E-Bus-Travel

typedef struct
{
    char matricule[4];
    char marque_bus[max];
    char couleur[max];
    char depart_bus[max];
    char hd[10];            //heure de de
    char fin_bus[max];
    char hf[10];                          // heure de fin
    int nombre_de_place_disponible;     //nombre de place disponible dans le bus
    int montant_a_payer;
} bus_a_reserver;

bus_a_reserver bus[20]=
    {
        {"101", "Iveco", "bleu", "monastir", "8am", "tunis", "11am", 49, 25},
        {"101", "Iveco", "bleu", "tunis", "1pm", "monastir", "4pm", 49, 25},
        {"102", "MAN", "noir", "nabeul", "8am", "tunis", "10am", 49, 20},
        {"102", "MAN", "noir", "tunis", "11am", "nabeul", "1pm", 49, 20},
        {"103", "Neoplan", "bleu", "sfax", "10am", "tunis", "4pm", 49, 50},
        {"103", "Neoplan", "bleu", "tunis", "5pm", "sfax", "11pm", 49, 50},
        {"104", "Heuliez", "blanc", "tunis", "6am", "mahdia", "11am", 49, 30},
        {"104", "Heuliez", "blanc", "mahdia", "1pm", "tunis", "6pm", 49, 30},
        {"105", "Mercedes-Benz", "jaune", "gabes", "4am", "tunis", "10am", 49, 45},
        {"105", "Mercedes-Benz", "jaune", "tunis", "1pm", "gabes", "7pm", 49, 45},
        {"106", "Scania", "noir", "tunis", "7am", "jendouba", "11am", 49, 30},
        {"106", "Scania", "noir", "jendouba", "2pm", "tunis", "6pm", 49, 30},
        {"107", "Solaris", "bleu", "sousse", "8am", "tunis", "10am", 49, 20},
        {"107", "Solaris", "bleu", "tunis", "11am", "sousse", "1pm", 49, 20},
        {"108", "Iveco", "bleu", "tataouine", "1am", "tunis", "11am", 49, 80},
        {"108", "Iveco", "bleu", "tunis", "1pm", "tataouine", "11pm", 49, 80},
        {"109", "SETRA", "noir", "gafsa", "1am", "tunis", "10am", 49, 65},
        {"109", "SETRA", "noir", "tunis", "1pm", "gafsa", "10pm", 49, 65},
        {"110", "MAN", "noir", "Médenine", "8am", "tunis", "6pm", 49, 70},
        {"110", "MAN", "noir", "tunis", "8pm", "mednine", "6am", 49, 70}
    };
char place[5][12][4] =
    {
    {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12"},
    {"13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24"},
    {"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "49"},
    {"25", "26", "27", "28", "29", "30", "31", "32", "33", "34", "35", "36"},
    {"37", "38", "39", "40", "41", "42", "43", "44", "45", "46", "47", "48"}
    };
char place_mod[5][12][4] =
    {
    {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12"},
    {"13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24"},
    {"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "49"},
    {"25", "26", "27", "28", "29", "30", "31", "32", "33", "34", "35", "36"},
    {"37", "38", "39", "40", "41", "42", "43", "44", "45", "46", "47", "48"}
    };


void creer_nouveau_compte(compte *c)        //la fonction pour Creer un nouveau compte voyageur sur E-Bus-Travel
{
    printf("Reservez plus facilement que jamais. Inscrivez-vous sur E-Bus-Travel des maintenant\n");
    printf("tapez votre mail : ");
    scanf("%s", c->mail);
    printf("tapez votre mot de passe : ");
    scanf("%s", c->mdp);
    printf("Felicitations !Votre compte a ete cree avec succes.\n");
    printf("veuillez completer votre profil en ajoutant quelques informations : \n");
    printf("tapez votre nom : ");
    scanf("%s", c->voy.nom);
    printf("tapez votre prenom : ");
    scanf("%s", c->voy.prenom);
    printf("tapez votre numero de telephone : ");
    scanf("%s", c->voy.num_tel);
    printf("tapez le numero de votre carte d'identite nationale : ");
    scanf("%s", c->voy.cin);
    printf("Felicitations ! Vous etes maintenant membre de E-Bus-Travel.\n");
}

void detail_reservation(compte *c)    ////////////la fonction pour Creer une nouvelle reservation sur E-Bus-Travel
{
    printf("pour reserver veuillez ajouter quelques informations :\n");
    printf("donnez le point de depart : ");
    scanf("%s", c->res.depart);
    printf("donnez la destination : ");
    scanf("%s", c->res.fin);
    printf("donnez la date du voyage :\n");
    printf("tapez le jour : ");
    scanf("%s", c->res.date.jour);
    printf("tapez le mois : ");
    scanf("%s", c->res.date.mois);
    printf("tapez l'annee : ");
    scanf("%s", c->res.date.annee);
}

int reserver_dans_un_bus(compte *c)    ///////////la fonction pour reserver un bus sur E-Bus-Travel et Afficher les details de bus + reservation
{
    int somme=0;
    int test=1;
    for (int i = 0; i < 20; i++)
    {
        somme++;
        if (strcmp(c->res.depart, bus[i].depart_bus) == 0 && strcmp(c->res.fin, bus[i].fin_bus) == 0)
        {
            char ch1[max];
            char ch2[max];
            char ch3[max];
            char ch4[max];
            strcpy( ch1,bus[i].matricule);
            strcpy( ch2,c->res.date.jour);
            strcpy( ch3,c->res.date.mois);
            strcpy( ch4,c->res.date.annee);
            printf("Il existe un bus qui sera disponible pour votre trajet(de %s vers %s) \n.", c->res.depart, c->res.fin);
            printf("Il est programme pour partir le %3s/%3s/%5s a %5s et il arrivera a son dernier arret a %5s .\n", c->res.date.jour, c->res.date.mois, c->res.date.annee, bus[i].hd, bus[i].hf);
            printf("donnez le nombre de place a reserver : ");
            scanf("%d", &c->res.nombre_de_place);
            somme=0;
            if (bus[i].nombre_de_place_disponible >= c->res.nombre_de_place)
            {
                int x = c->res.nombre_de_place * bus[i].montant_a_payer;
                bus[i].nombre_de_place_disponible -= c->res.nombre_de_place;
                printf("Felicitations ! Votre reservation de bus a ete confirmee avec succes . voici les details de votre bus , le numero de votre ticket et le prix :\n");
                printf("matricule de bus : %s \n", bus[i].matricule);
                printf("marque de bus : %s \n", bus[i].marque_bus);
                printf("couleur de bus : %s \n", bus[i].couleur);
                printf("le numero de votre ticket: %s\n", strcat(strcat(ch1,ch2), strcat(ch3,ch4)));
                printf("le prix total du voyage : %d \n", x);
            }
            else if (bus[i].nombre_de_place_disponible == 0)
            {
                test=0;
                printf("Le bus a dejà commence son trajet.N'oubliez pas qu'il sera de retour demain pour de nouvelles reservations.\n");
            }
            else if (bus[i].nombre_de_place_disponible < c->res.nombre_de_place)
            {
                test=0;
                printf("Desole, il ne reste que %d place(s) disponible dans le bus. Veuillez ajuster le nombre de sieges souhaite.\n", bus[i].nombre_de_place_disponible);
            }
        }
        else if (somme==20)
        {
            test=2;
        }
    }
    return (test) ;
}

void choisir_numero_de_siege(compte *c)          //////la fonction pour choisir le numero_de_siege_dans le bus
{
    int nbp = c->res.nombre_de_place;
    printf("Veuillez choisir un siege parmi les numeros disponibles:\n");
    printf("'RR' signifie que le siege est reserve.\n");

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            printf("%s ", place[i][j]);
        }
        printf("\n");
    }

    for (int k = 0; k < nbp; k++)
    {
        int sum = 0;
        char p[3];
        printf("tapez le numero du siege du voyageur n°%d : ", k + 1);
        scanf("%2s", p);
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 12; j++)
            {
                sum++;
                if (strcmp(p, place[i][j]) == 0)
                {
                    place[i][j][0] = 'R';
                    place[i][j][1] = 'R';
                    sum = 0;
                }
                else if (sum == 60)
                {
                    printf("Malheureusement, le siege que vous avez choisi est pris ou faux. Veuillez en choisir un autre.\n");
                    k--;
                }
            }
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            printf("%s ", place[i][j]);
        }
        printf("\n");
    }
    printf("Bon voyage !\n");
}
void choisir_numero_de_siege_mod(compte *c)          //////la fonction pour choisir le numero_de_siege_dans le bus en cas d'une modification de reservation
{
    int nbp = c->res.nombre_de_place;
    printf("Veuillez choisir un siege parmi les numeros disponibles:\n");
    printf("'RR' signifie que le siege est reserve.\n");

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            printf("%s ", place_mod[i][j]);
        }
        printf("\n");
    }

    for (int k = 0; k < nbp; k++)
    {
        int sum = 0;
        char p[3];
        printf("tapez le numero du siege du voyageur n°%d : ", k + 1);
        scanf("%2s", p);
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 12; j++)
            {
                sum++;
                if (strcmp(p, place_mod[i][j]) == 0)
                {
                    place_mod[i][j][0] = 'R';
                    place_mod[i][j][1] = 'R';
                    sum = 0;
                }
                else if (sum == 60)
                {
                    printf("Malheureusement, le siege que vous avez choisi est pris ou faux. Veuillez en choisir un autre.\n");
                    k--;
                }
            }
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            printf("%s ", place_mod[i][j]);
        }
        printf("\n");
    }
    printf("Bon voyage !\n");
}

int modifier_reservation(compte *c)       /////la fonction pour modifier les details d'une réservation
{
    int s=0;
    char oui_non[5];
    printf("Si vous souhaitez apporter des modifications a votre reservation, veuillez taper 'oui' si oui ou 'non' sinon :\n");
    printf("Veuillez modifier votre point de depart ? : ");
    scanf("%s", oui_non);
    while ((strcmp(oui_non, "non") != 0) && (strcmp(oui_non, "oui") != 0))
    {
        printf("Veuillez modifier votre point de depart ? : ");
        scanf("%s", oui_non);

    }
    if (strcmp(oui_non, "oui") == 0)
    {
        printf(" tapez votre nouveau point de depart : ");
        scanf("%s", c->res.depart);
        s++;
    }
    printf("Veuillez modifier votre destination ? : ");
    scanf("%s", oui_non);
    while ((strcmp(oui_non, "non") != 0) && (strcmp(oui_non, "oui") != 0))
    {
        printf("Veuillez modifier votre destination ? : ");
        scanf("%s", oui_non);
    }
    if (strcmp(oui_non, "oui") == 0)
    {
        printf(" tapez votre nouvelle destination : ");
        scanf("%s", c->res.fin);
        s++;
    }
     printf("Veuillez modifier votre date du voyage ? : ");
    scanf("%s", oui_non);
    while ((strcmp(oui_non, "non") != 0) && (strcmp(oui_non, "oui") != 0))
    {
        printf("Veuillez modifier votre date du voyage ? : ");
        scanf("%s", oui_non);
    }
    if (strcmp(oui_non, "oui") == 0)
    {
        printf("tapez le jour : ");
        scanf("%s", c->res.date.jour);
        printf("tapez le mois : ");
        scanf("%s", c->res.date.mois);
        printf("tapez l'annee : ");
        scanf("%s", c->res.date.annee);
        s++;
    }
     return(s);
}

int main()
{
    int w;
    int z;
    int y;
    compte c;
    printf("Bienvenue sur notre application 'E-Bus-Travel' ! Nous sommes ravis de vous accueillir.\n");
    creer_nouveau_compte(&c);
    detail_reservation(&c);
    y=reserver_dans_un_bus(&c);
    if(y==2)
    {
        printf("Desole, la reservation n'est pas possible, car le bus demande n'est pas disponible dans notre système. Veuillez verifier votre choix.\n");
        printf("voici les bus disponibles dans notre système :\n");
        for(int i=0;i<20;i++)
        {
            printf("%s ----> ",bus[i].depart_bus);
            printf("%s\n",bus[i].fin_bus);
        }
    }
    else if(y==1)
    {
        choisir_numero_de_siege(&c);
    }
    z=modifier_reservation(&c);
    if(z>0)
    {
        w=reserver_dans_un_bus(&c);
        if(w==2)
        {
            printf("Desole, la reservation n'est pas possible, car le bus demande n'est pas disponible dans notre système. Veuillez verifier votre choix.\n");
            printf("voici les bus disponibles dans notre systeme :\n");
            for(int i=0;i<20;i++)
            {
                printf("%s ----> ",bus[i].depart_bus);
                printf("%s\n",bus[i].fin_bus);
            }
        }
        else if(w==1)
        {
            choisir_numero_de_siege_mod(&c);
        }
    }
    printf("Nous vous attendons pour votre prochaine reservation.A bientot!");
    return 0;
}
