#ifndef GAME_H
#define GAME_H

#include <string>

struct Game {
  std::string home_team;
  std::string away_team;
  int home_score;
  int away_score;
  Game* child_game_1;
  Game* child_game_2;

  /// Erzeugt ein leeres Game-Objekt.
  Game();

  /// Erzeugt ein Game-Objekt mit leeren Teams, aber mit Kind-Spielen.
  /// Ein Kindspiel ist ein Spiel, von dem dieses Spiel abhängt.
  /// Beispielsweise hängt ein Halbfinale von den zwei Viertelfinalspielen ab.
  Game(Game* child_game_1, Game* child_game_2);

  /// Erzeugt ein Game-Objekt mit den gegebenen Teams.
  /// Das Spiel ist noch nicht gespielt worden.
  Game(std::string const& home_team, std::string const& away_team);

  /// Liefert den Namen des Gewinners des Spiels.
  /// Liefert den leeren String, falls das Spiel noch nicht gespielt wurde.
  /// Liefert "Unentschieden", falls das Spiel unentschieden ausgegangen ist.
  std::string result();

  /// Legt das Ergebnis des Spiels fest.
  void set_result(int home_score, int away_score);

  /// Liefert true, wenn das Spiel bereits gespielt wurde;
  bool has_result();

  /// Aktualisiert die Mannschaften des aktuellen Spiels auf Basis der
  /// Ergebnisse der Kindspiele.
  void update_teams();
};

#endif
