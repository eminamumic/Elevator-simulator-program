#ifndef ADMINPANEL_H_INCLUDED
#define ADMINPANEL_H_INCLUDED
#include "adminFunkcije.h"

char imeNosila[100];

//Sve funkcije u adminFunkcije.h
void adminPanel()
{
  char imeNosila[100];
  int odabir;
  system("cls");
  printf("\n\tADMIN PANEL \n");
  printf("\n[1] Kreiranje novog korisnika\n");
  printf("[2] Kreiranje novog nosila\n");
  printf("[3] Trenutni broj koristenja nosila\n");
  printf("[4] Nosila spremna za servisiranje\n");
  printf("[5] Blokirana nosila\n");
  printf("[6] Ispis svih nosila\n");
  printf("[7] Izlaz\n");
  printf("\nUnesite zeljenu opciju: ");
  scanf("%d", &odabir);

  switch (odabir)
  {
  case 1:
    system("cls");

    printf(" _________________________________\n");
    printf("|                                 |\n");
    printf("|    KREIRANJE NOVOG KORISNIKA    |\n");
    printf("|_________________________________|\n");
    kreiranjeNovogKorisnika();
    break;
  case 2:
    system("cls");

    printf(" _________________________________\n");
    printf("|                                 |\n");
    printf("|      KREIRANJE NOVOG NOSILA     |\n");
    printf("|_________________________________|\n");
    kreiranjeNovogNosila();
    break;
  case 3:
    system("cls");

    printf(" _________________________________\n");
    printf("|                                 |\n");
    printf("| TRENUTNI BROJ KORISTENJA NOSILA |\n");
    printf("|_________________________________|\n");

    printf("\n Koje nosilo zelite da provjerite: ");
    scanf("%s", &imeNosila);
    brojKoristenjaNosila(imeNosila);
    break;
  case 4:
    system("cls");

    printf(" _________________________________\n");
    printf("|                                 |\n");
    printf("|   PROVJERA NOSILA ZA SERVIRS    |\n");
    printf("|_________________________________|\n");
    nosilaZaServis();
    break;
  case 5:
    system("cls");

    printf(" _________________________________\n");
    printf("|                                 |\n");
    printf("|   PROVJERA BLOKIRANIH NOSILA    |\n");
    printf("|_________________________________|\n");
    blokiranaNosila();
    break;
  case 6:
    system("cls");

    printf(" _________________________________\n");
    printf("|                                 |\n");
    printf("|        ISPIS SVIH NOSILA        |\n");
    printf("|_________________________________|\n");
    ispisSvihNosila();
    break;
  case 7:
    system("cls");
    main();
    break;
  default:
    printf("\nPogresan unos.");
  }
}

#endif // ADMINPANEL_H_INCLUDED
