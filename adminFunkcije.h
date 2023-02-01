#ifndef ADMINFUNKCIJE_H_INCLUDED
#define ADMINFUNKCIJE_H_INCLUDED

void nazad()
{
  int unos;
  do
  {
    printf("\nUnesite broj [1] za nazad: ");
    scanf("%d", &unos);
  } while (unos != 1);
  adminPanel();
}
void kreiranjeNovogKorisnika()
{
  struct Korisnik korisnik;
  printf("\nUnesite ime novog korisnika: ");
  scanf("%s", &korisnik.ime);
  printf("Unesite sifru novog korisnika: ");
  scanf("%s", &korisnik.sifra);

  FILE *fp;
  fp = fopen("korisnik.dat", "a");
  fprintf(fp, "%s\n", korisnik.ime);
  fprintf(fp, "%s\n", korisnik.sifra);
  fclose(fp);
  printf("\nKREIRALI STE NOVOG KORISNIKA.");
  nazad();
}

void kreiranjeNovogNosila()
{
  struct Nosilo nosilo;
  printf("\nUnesite naziv nosila: ");
  scanf("%s", nosilo.naziv);
  printf("Unesite broj spratova: ");
  scanf("%d", &nosilo.brojSpratova);
  printf("Unesite broj sprata gdje se nosilo trenutno nalazi: ");
  scanf("%d", &nosilo.trenutniSprat);
  printf("Unesite broj koristenja kada nosilo ide na servis: ");
  scanf("%d", &nosilo.servis);
  printf("Unesite broj spratova kada nosilo gubi funkciju: ");
  scanf("%d", &nosilo.blokiranjeNosila);
  nosilo.brojKoristenja = 0;
  nosilo.aktivacija = 0;

  FILE *datoteka = fopen("nosilo.dat", "ab");
  if (datoteka == NULL)
  {
    printf("Greska pri otvaranju datoteke!\n");
    return;
  }
  fwrite(&nosilo, sizeof(struct Nosilo), 1, datoteka);
  fclose(datoteka);
  printf("\nKREIRALI STE NOVO NOSILO.");

  nazad();
}

void brojKoristenjaNosila(char *naziv)
{

  FILE *datoteka = fopen("nosilo.dat", "rb");
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
      printf("\nNaziv nosila: %s\n", nosilo.naziv);
      printf("Broj spratova: %d\n", nosilo.brojSpratova);
      printf("Nosilo je do sad bilo iskoristeno %d puta\n", nosilo.brojKoristenja);
      printf("Servis nosila se izvrsana na %d koristenja\n", nosilo.servis);
      printf("Broj do blokiranja nosila: %d\n", (nosilo.blokiranjeNosila-nosilo.brojKoristenja));

      break;
    }
  }

  fclose(datoteka);
  nazad();
}

void nosilaZaServis()
{
  int broj;
  FILE *file = fopen("nosilo.dat", "r+b");
  if (file == NULL)
  {
    printf("Greska pri otvaranju datoteke!\n");
    return;
  }

  struct Nosilo nosilo;
pocetak:
  fseek(file, 0, SEEK_SET);
  while (fread(&nosilo, sizeof(struct Nosilo), 1, file) == 1)
  {
    if (nosilo.brojKoristenja >= nosilo.servis && nosilo.brojKoristenja < nosilo.blokiranjeNosila)
    {
      printf("\nNaziv nosila: %s", nosilo.naziv);
      printf("\nBroj kada lift ide na servis je: %d", nosilo.servis);
      printf("\nBroj koristenja: %d", nosilo.brojKoristenja);

      printf("\nAko zelite resetovati ovaj lift unesite broj [1]: ");
      scanf("%d", &broj);
      if (broj == 1)
      {
        nosilo.brojKoristenja = 0;
        fseek(file, -sizeof(struct Nosilo), SEEK_CUR);
        fwrite(&nosilo, sizeof(struct Nosilo), 1, file);
        printf("\nLift je resetovan\n");
        goto pocetak;
      }
    }
    else
    {
      printf("\nNema nosila za servisiranje\n");
      nazad();
    }
  }

  fclose(file);
}

void blokiranaNosila()
{
  FILE *datoteka = fopen("nosilo.dat", "rb");
  if (datoteka == NULL)
  {
    printf("Greska pri otvaranju datoteke!\n");
    return;
  }
  struct Nosilo nosilo;
  while (fread(&nosilo, sizeof(struct Nosilo), 1, datoteka) == 1)
  {
    if (nosilo.brojKoristenja >= nosilo.blokiranjeNosila)
    {
      printf("Naziv nosila: %s\n", nosilo.naziv);
      printf("Broj spratova: %d\n", nosilo.brojSpratova);
      printf("Maksimalni broj koristenja: %d\n", nosilo.blokiranjeNosila);
      printf("______________________________________________\n");
      break;
    }
    else {
        printf("\nNema blokiranih nosila.\n");
        break;
    }
  }

  fclose(datoteka);
  nazad();
}

void ispisSvihNosila()
{
  FILE *datoteka = fopen("nosilo.dat", "rb");
  if (datoteka == NULL)
  {
    printf("Greska pri otvaranju datoteke!\n");
    return;
  }

  struct Nosilo nosilo;
  while (fread(&nosilo, sizeof(struct Nosilo), 1, datoteka) == 1)
  {
    printf("\nNaziv nosila: %s", nosilo.naziv);
    printf("\nBroj spratova: %d", nosilo.brojSpratova);
    printf("\nOvo nosilo je iskoristeno %d puta.", nosilo.brojKoristenja);
    printf("\nBroj koristenja kada lift ide na servis je: %d", nosilo.servis);
    printf("\nBroj kada lift gubi funkcionalnost: %d", nosilo.blokiranjeNosila);
    printf("\nNosilo se sada nalazi na %d spratu.", nosilo.trenutniSprat);
    printf("\nOvo nosilo je %s ", nosilo.aktivacija? "aktivirano" : "neaktivirano");
    printf("\n_____________________________________________________\n");
  }
  fclose(datoteka);
  nazad();
}


#endif // ADMINFUNKCIJE_H_INCLUDED
