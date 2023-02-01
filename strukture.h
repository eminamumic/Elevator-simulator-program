#ifndef STRUKTURE_H_INCLUDED
#define STRUKTURE_H_INCLUDED

struct Korisnik
{
  char ime[100];
  char sifra[100];
};

struct Nosilo {
   char naziv[100];
   int brojSpratova;
   int blokiranjeNosila;
   int servis;
   int brojKoristenja;
   int aktivacija;
   int trenutniSprat;
};

#endif // STRUKTURE_H_INCLUDED
