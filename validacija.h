#ifndef VALIDACIJA_H_INCLUDED
#define VALIDACIJA_H_INCLUDED

char admin_email[100];
char admin_password[100];
char user_email[100];
char user_password[100];

void podaci()
{

  // PODACI ADMINA
  FILE *f = fopen("admin.dat", "r");
  if (f == NULL)
  {
    printf("Greska pri otvaranju datoteke!\n");
  }
  fscanf(f, "%s\n", admin_email);
  fscanf(f, "%s\n", admin_password);

  fclose(f);

  // PODACI KORISNIK
  FILE *fi = fopen("korisnik.dat", "r");
  if (fi == NULL)
  {
    printf("Greska pri otvaranju datoteke!\n");
  }
  fscanf(fi, "%s\n", user_email);
  fscanf(fi, "%s\n", user_password);

  fclose(fi);
}

int validacija(char email[100], char password[100])
{
  //validacija.h
  podaci();
  if (strcmp(email, admin_email) == 0 && strcmp(password, admin_password) == 0)
  {
    return 1;
  }

  else if (strcmp(email, user_email) == 0 && strcmp(password, user_password) == 0)
  {
    return 2;
  }
  else
  {
    return 3;
  }
}

#endif // VALIDACIJA_H_INCLUDED
