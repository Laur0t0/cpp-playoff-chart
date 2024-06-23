#include <iostream>

#include "game/game.h"
#include "gametree/gametree.h"

/// Erwartet eine Zahl i und gibt die Art des Spiels aus.
/// Dabei gilt folgende Zuordnung:
///
/// i == 0: Finale
/// i == 1: Halbfinale 1
/// i == 2: Halbfinale 2
/// i == 3: Viertelfinale 1
/// i == 4: Viertelfinale 2
/// ... und so weiter.
void print_gametype(int i);

/// Erwartet ein Game-Objekt und gibt die Namen der Teams und das Ergebnis aus.
void print_game(Game* game);

/// Erwartet einen Vektor von Game-Pointern und gibt die Namen der Teams
/// und die Ergebnisse der Spiele in der Reihenfolge des Vektors aus.
void print_games(std::vector<Game*> games);

int main() {
  std::vector<Game*> games;

  // Spiele erzeugen. Das erste Spiel ist das Finale, die beiden folgenden
  // Spiele sind die Halbfinals, die vier folgenden Spiele sind die
  // Viertelfinals, usw.
  // Am Anfang sind nur die Paarungen der Achtelfinals bekannt.
  games.push_back(new Game());
  games.push_back(new Game());
  games.push_back(new Game());
  games.push_back(new Game());
  games.push_back(new Game());
  games.push_back(new Game());
  games.push_back(new Game());
  games.push_back(new Game("Borussia Bremen", "Bayern Berlin"));
  games.push_back(new Game("Dynamo Dortmund", "RB Rostock"));
  games.push_back(new Game("Hansa Heidenheim", "Union Ulm"));
  games.push_back(new Game("TSV Tübingen", "Arminia Aalen"));
  games.push_back(new Game("Bavaria Bochum", "Werder Würzburg"));
  games.push_back(new Game("Eintracht Emden", "Fortuna Frankfurt"));
  games.push_back(new Game("Hannover Hundertdrei", "Hertha Halle"));
  games.push_back(new Game("Alemannia Augsburg", "FC Freiburg"));

  // Spielbaum aufbauen.
  // Bisher waren die Spiele noch nicht miteinander verknüpft.
  // Die Funktion `build_gametree` verknüpft die Spiele zu einem Baum.
  build_gametree(games);

  // Beispielhaft einige Ergebnisse eintragen.
  games[14]->set_result(2, 1);
  games[13]->set_result(1, 3);
  games[12]->set_result(7, 1);
  games[11]->set_result(1, 5);

  // Die Teams der Spiele aktualisieren.
  // Die Funktion `update_teams` aktualisiert die Teams der Spiele.
  // D.h. falls die Kindspiele gespielt wurden, werden die Teams des
  // aktuellen Spiels auf die Gewinner der Kindspiele gesetzt.
  games[0]->update_teams();

  // Die Spiele ausgeben.
  print_games(games);

  return 0;
}

void print_gametype(int i) {
  if (i <= 0) {
    std::cout << "Finale: ";
    return;
  }
  if (i <= 2) {
    std::cout << "Halbfinale " << i << ": ";
    return;
  }
  if (i <= 6) {
    std::cout << "Viertelfinale " << i - 2 << ": ";
    return;
  }
  std::cout << "Achtelfinale " << i - 6 << ": ";
}

void print_game(Game* game) {
  if (game == nullptr) {
    return;
  }
  if (game->home_team == "" || game->away_team == "") {
    std::cout << "Spielpaarung noch nicht bekannt" << std::endl;
    return;
  }
  std::cout << game->home_team << " - " << game->away_team << ": ";
  if (!game->has_result()) {
    std::cout << "noch nicht gespielt" << std::endl;
    return;
  }
  std::cout << game->home_score << " - " << game->away_score << std::endl;
}

void print_games(std::vector<Game*> games) {
  for (int i = 0; i < games.size(); i++) {
    print_gametype(i);
    print_game(games[i]);
  }
}