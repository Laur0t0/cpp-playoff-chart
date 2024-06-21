#include <iostream>

#include "game/game.h"
#include "gametree/gametree.h"

int main() {
  // Spiele erzeugen. Das erste Spiel ist das Finale, die beiden folgenden
  // Spiele sind die Halbfinals, die vier folgenden Spiele sind die
  // Viertelfinals, usw.
  // Am Anfang sind nur die Paarungen der Achtelfinals bekannt.

  // Spielbaum aufbauen.
  // Bisher waren die Spiele noch nicht miteinander verknüpft.
  // Die Funktion `build_gametree` verknüpft die Spiele zu einem Baum.
  Gametree gt;
  gt.add_game(new Game());
  gt.add_game(new Game());
  gt.add_game(new Game());
  gt.add_game(new Game());
  gt.add_game(new Game());
  gt.add_game(new Game());
  gt.add_game(new Game());
  gt.add_game(new Game("Borussia Bremen", "Bayern Berlin"));
  gt.add_game(new Game("Dynamo Dortmund", "RB Rostock"));
  gt.add_game(new Game("Hansa Heidenheim", "Union Ulm"));
  gt.add_game(new Game("TSV Tübingen", "Arminia Aalen"));
  gt.add_game(new Game("Bavaria Bochum", "Werder Würzburg"));
  gt.add_game(new Game("Eintracht Emden", "Fortuna Frankfurt"));
  gt.add_game(new Game("Hannover Hundertdrei", "Hertha Halle"));
  gt.add_game(new Game("Alemannia Augsburg", "FC Freiburg"));

  // Beispielhaft einige Ergebnisse eintragen.
  gt.set_result(14, 2, 1);
  gt.set_result(13, 1, 3);
  gt.set_result(12, 7, 1);
  gt.set_result(11, 1, 5);

  // Die Teams der Spiele aktualisieren.
  // Die Funktion `update_teams` aktualisiert die Teams der Spiele.
  // D.h. falls die Kindspiele gespielt wurden, werden die Teams des
  // aktuellen Spiels auf die Gewinner der Kindspiele gesetzt.
  gt.update_teams();

  // Die Spiele ausgeben.
  gt.print();

  return 0;
}
