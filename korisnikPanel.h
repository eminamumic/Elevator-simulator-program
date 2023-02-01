#ifndef KORISNIKPANEL_H_INCLUDED
#define KORISNIKPANEL_H_INCLUDED
#include "korisnik.Funkcije.h"

char aktiviranjeNosila[100];
char pozivanjeNosila[100];

//Sve funkcije iz korisnik.Funkcije.h
void korisnikPanel () {
  int odabir;
  system("cls");
  printf("\n\t KORISNIK PANEL \n");
  printf("\n[1] Aktivacija nosila \n");
  printf("[2] Pozivanje i koristenje nosila \n");
  printf("[3] Izlaz\n");
  printf("\nUnesite zeljenu opciju: ");
  scanf("%d", &odabir);

  switch(odabir) {
  case 1:
    system("cls");

    printf(" _________________________________\n");
    printf("|                                 |\n");
    printf("|       AKTIVACIJA NOSILA         |\n");
    printf("|_________________________________|\n");

    printf("\nUnesite ime nosila koje zelite da aktivirate: ");
    scanf("%s", aktiviranjeNosila);
    aktivacijaNosila(aktiviranjeNosila);
    break;
  case 2:
    system("cls");

    printf(" _________________________________\n");
    printf("|                                 |\n");
    printf("|  POZIVANJE I KORISTENJE NOSILA  |\n");
    printf("|_________________________________|\n");
    printf("\nUnesite ime nosila koje zelite da koristite: ");
    scanf("%s", &pozivanjeNosila);
    koristenjeNosila(pozivanjeNosila);
    break;
  case 3:
   system("cls");
    main();
  default:
    printf("Pogrešan unos");
  }
}

#endif // KORISNIKPANEL_H_INCLUDED
