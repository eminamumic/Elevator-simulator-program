#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int main();
#include "validacija.h"
#include "panel.h"

int main()
{
  system("color F3");
  char email[100];
  char password[100];
  printf(" _____________________________________\n");
  printf("|                                     |\n");
  printf("|   Dobro dosli na pocetnu stranicu   |\n");
  printf("|          lift simulatora            |\n");
  printf("|_____________________________________|\n");
  printf("\n");
  printf("\n");
  printf("Unesite svoje korisnicko ime: ");
  scanf("%s", &email);
  printf("\n");
  printf("Unesite svoju lozinku: " );
  scanf("%s", &password);
  printf("\n");
  //validacija.h
  system("cls");
  int panel = validacija(email, password);
  //panel.h
  ispisPanela(panel);
  return 0;
}




