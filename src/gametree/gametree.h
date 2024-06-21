#ifndef GAMETREE_H
#define GAMETREE_H

#include <vector>

#include "game/game.h"

struct Gametree {
  std::vector<Game*> games;

  Gametree();
  void add_game(Game* g);
  void set_result(size_t pos, int home, int away);
  void update_teams();

  void build_gametree();
  void print();
};

#endif
