#include "gametree.h"

#include <iostream>

#include "test/test.h"

// Privater Namensraum mit Hilfsfunktionen, die nur hier gebraucht werden.
namespace {
Game* get_left_child(std::vector<Game*>& games, size_t n) {
  if (2 * n + 1 < games.size()) {
    return games[2 * n + 1];
  }
  return nullptr;
}
Game* get_right_child(std::vector<Game*>& games, size_t n) {
  if (2 * n + 2 < games.size()) {
    return games[2 * n + 2];
  }
  return nullptr;
}

bool is_power_of_two(int n) {
  if (n <= 0) {
    return false;
  }
  if (n == 1) {
    return true;
  }
  return n % 2 == 0 && is_power_of_two(n / 2);
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
}  // namespace

// Implementierung der Gametree-Klasse.

Gametree::Gametree(){};

void Gametree::add_game(Game* g) { games.push_back(g); }

void Gametree::update_teams() {
  build_gametree();
  games[0]->update_teams();
}

void Gametree::set_result(size_t pos, int home, int away) {
  games[pos]->set_result(home, away);
}

void Gametree::build_gametree() {
  if (!is_power_of_two(games.size() + 1)) {
    return;
  }

  for (int n = 0; n < games.size(); n++) {
    games[n]->child_game_1 = get_left_child(games, n);
    games[n]->child_game_2 = get_right_child(games, n);
  }
}

void Gametree::print() { print_games(games); }
