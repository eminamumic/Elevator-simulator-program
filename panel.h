#ifndef PANEL_H_INCLUDED
#define PANEL_H_INCLUDED
#include "strukture.h"
#include <windows.h>
#include "adminPanel.h"
#include "korisnikPanel.h"


void ispisPanela(int panel)
{
  switch (panel)
  {
  case 1:
    //adminPanel.h
    adminPanel();
    break;
  case 2:
    //korisnikPanel.h
    korisnikPanel();
    break;
  default:
    printf("\n\n\n\n POGRESAN UNOS POKUSAJTE PONOVO.");
    printf("\n");
    // main.c
    main();
    break;
  }
}

#endif // PANEL_H_INCLUDED
