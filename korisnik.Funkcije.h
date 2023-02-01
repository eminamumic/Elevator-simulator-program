#ifndef KORISNIK_FUNKCIJE_H_INCLUDED
#define KORISNIK_FUNKCIJE_H_INCLUDED
#include "strukture.h"

void nazadKorisnik()
{
  int unos;
  do
  {
    printf("\nUnesite broj [1] za nazad: ");
    scanf("%d", &unos);
  } while (unos != 1);
  korisnikPanel();
}

void aktivacijaNosila(char *naziv)
{

  FILE *datoteka = fopen("nosilo.dat", "rb+");
  if (datoteka == NULL)
  {
    printf("Greska pri otvaranju datoteke!\n");
    return;
  }
  struct Nosilo nosilo;
  while (fread(&nosilo, sizeof(struct Nosilo), 1, datoteka) == 1)
  {
    if (strcmp(nosilo.naziv, naziv) == 0)
    {
      if (nosilo.aktivacija == 1)
      {
        printf("\nNosilo je vec aktivirano!\n");
      }
      else if (nosilo.aktivacija == 0)
      {
        nosilo.aktivacija = 1;
        printf("\nNosilo je aktivirano!\n");
        fseek(datoteka, -sizeof(struct Nosilo), SEEK_CUR); /* Postavljanje pozicije*/
        fwrite(&nosilo, sizeof(struct Nosilo), 1, datoteka);
      }
      break;
    }
    else if (strcmp(nosilo.naziv, naziv) == 1)
    {
      printf("\nNosilo koje ste odabrali ne postoji.");
    }
  }
  fclose(datoteka);
  nazadKorisnik();
}

void koristenjeNosila(char *n)
{
  int trenutni;
  int zeljeni;
  FILE *datoteka = fopen("nosilo.dat", "rb+");
  if (datoteka == NULL)
  {
    printf("Greska pri otvaranju datoteke!\n");
    return;
  }
  struct Nosilo nosilo;
  while (fread(&nosilo, sizeof(struct Nosilo), 1, datoteka) == 1)
  {
    if (strcmp(nosilo.naziv, n) == 0)
    {
      if (nosilo.aktivacija == 0)
      {
        printf("\nNosilo nije aktivirano!\n");
        nazadKorisnik();
      }
      else if (nosilo.brojKoristenja >= nosilo.blokiranjeNosila)
      {
        printf("\nNosilo nije u funkciji\n");
        nazadKorisnik();
      }

      printf("\nNosilo je aktivno. Trenutno se nalazi na %d spratu.\n", nosilo.trenutniSprat);
      nosilo.brojKoristenja++;
      fseek(datoteka, -sizeof(struct Nosilo), SEEK_CUR);
      fwrite(&nosilo, sizeof(struct Nosilo), 1, datoteka);

    opet:
      printf("Sprat na kojem se vi nalazite je: ");
      scanf("%d", &trenutni);
      printf("Sprat na koji zelite da idete je: ");
      scanf("%d", &zeljeni);
      if (zeljeni > nosilo.brojSpratova)
      {
        printf("Ovo nosilo ima samo %d spratova. Pokisajte ponovo.!\n", nosilo.brojSpratova);
        goto opet;
      }

      if (nosilo.trenutniSprat > trenutni)
      {
        for (nosilo.trenutniSprat; nosilo.trenutniSprat >= trenutni; nosilo.trenutniSprat--)
        {
          system("cls");
          printf(" __________________\n");
          printf("|                  |\n");
          printf("|                  |\n");
          printf("|                  |\n");
          printf("|             [%d]  |\n", nosilo.trenutniSprat);
          printf("|                  |\n");
          printf("|                  |\n");
          printf("|                  |\n");
          printf("|                  |\n");
          printf("|                  |\n");
          printf("|__________________|\n");
          sleep(2);
          nosilo.brojKoristenja + 1;
        } printf("\a");
      }
      else if (nosilo.trenutniSprat < trenutni){

        for (nosilo.trenutniSprat; nosilo.trenutniSprat <= trenutni; nosilo.trenutniSprat++)
        {
           system("cls");
          printf(" __________________\n");
          printf("|                  |\n");
          printf("|                  |\n");
          printf("|                  |\n");
          printf("|             [%d] |\n", nosilo.trenutniSprat);
          printf("|                  |\n");
          printf("|                  |\n");
          printf("|                  |\n");
          printf("|                  |\n");
          printf("|                  |\n");
          printf("|__________________|\n");
          sleep(2);
          nosilo.brojKoristenja + 1;
        }printf("\a");
      }
      printf("\nVas lift je stigao!");
      sleep(2);

      if (trenutni < zeljeni)
      {
        for (trenutni; trenutni <= zeljeni; trenutni++)
        {
          nosilo.brojKoristenja + 1;
           system("cls");
          printf(" __________________\n");
          printf("|                  |\n");
          printf("|                  |\n");
          printf("|                  |\n");
          printf("|             [%d]  |\n", trenutni);
          printf("|    (*.*)         |\n");
          printf("|      |           |\n");
          printf("|     |||          |\n");
          printf("|      |           |\n");
          printf("|     |||          |\n");
          printf("|__________________|\n");
          sleep(2);
        }printf("\a");
        nosilo.trenutniSprat = trenutni--;
        fseek(datoteka, -sizeof(struct Nosilo), SEEK_CUR);
        fwrite(&nosilo, sizeof(struct Nosilo), 1, datoteka);
        fclose(datoteka);

        fclose(datoteka);
        nazadKorisnik();
      }



      for (trenutni; trenutni >= zeljeni; trenutni--)
      {
        nosilo.brojKoristenja + 1;
       system("cls");
          printf(" __________________\n");
          printf("|                  |\n");
          printf("|                  |\n");
          printf("|                  |\n");
          printf("|             [%d]  |\n", trenutni);
          printf("|    (*.*)         |\n");
          printf("|      |           |\n");
          printf("|     |||          |\n");
          printf("|      |           |\n");
          printf("|     |||          |\n");
          printf("|__________________|\n");
        sleep(2);
      }printf("\a");
      nosilo.trenutniSprat = trenutni--;
      fseek(datoteka, -sizeof(struct Nosilo), SEEK_CUR);
      fwrite(&nosilo, sizeof(struct Nosilo), 1, datoteka);
      fclose(datoteka);
      fclose(datoteka);
      nazadKorisnik();
    }
  }
}

#endif // KORISNIK_FUNKCIJE_H_INCLUDED
