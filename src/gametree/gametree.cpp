#include "gametree.h"

#include "test/test.h"

void build_gametree(std::vector<Game*>& games) {
  // TODO
}

TEST_CASE("build_gametree") {
  std::vector<Game*> games;
  for (int i = 0; i < 15; i++) {
    games.push_back(new Game());
  }

  build_gametree(games);

  CHECK(games[0]->child_game_1 == games[1]);  // Halbfinale 1
  CHECK(games[0]->child_game_2 == games[2]);  // Halbfinale 2

  CHECK(games[1]->child_game_1 == games[3]);  // Viertelfinale 1
  CHECK(games[1]->child_game_2 == games[4]);  // Viertelfinale 2
  CHECK(games[2]->child_game_1 == games[5]);  // Viertelfinale 3
  CHECK(games[2]->child_game_2 == games[6]);  // Viertelfinale 4

  CHECK(games[3]->child_game_1 == games[7]);   // Achtelfinale 1
  CHECK(games[3]->child_game_2 == games[8]);   // Achtelfinale 2
  CHECK(games[4]->child_game_1 == games[9]);   // Achtelfinale 3
  CHECK(games[4]->child_game_2 == games[10]);  // Achtelfinale 4
  CHECK(games[5]->child_game_1 == games[11]);  // Achtelfinale 5
  CHECK(games[5]->child_game_2 == games[12]);  // Achtelfinale 6
  CHECK(games[6]->child_game_1 == games[13]);  // Achtelfinale 7
  CHECK(games[6]->child_game_2 == games[14]);  // Achtelfinale 8
}

bool is_power_of_two(int n) {
  // TODO
  return false;
}

TEST_CASE("is_powwer_of_two") {
  CHECK(is_power_of_two(1));
  CHECK(is_power_of_two(2));
  CHECK(is_power_of_two(4));
  CHECK(is_power_of_two(8));
  CHECK(is_power_of_two(16));
  CHECK(is_power_of_two(32));
  CHECK(is_power_of_two(64));
  CHECK(is_power_of_two(128));
  CHECK(is_power_of_two(256));
  CHECK(is_power_of_two(512));
  CHECK(is_power_of_two(1024));
  CHECK(is_power_of_two(2048));
  CHECK(is_power_of_two(4096));
  CHECK(is_power_of_two(8192));
  CHECK(is_power_of_two(16384));
  CHECK(!is_power_of_two(3));
  CHECK(!is_power_of_two(5));
  CHECK(!is_power_of_two(6));
  CHECK(!is_power_of_two(7));
  CHECK(!is_power_of_two(9));
  CHECK(!is_power_of_two(10));
  CHECK(!is_power_of_two(11));
  CHECK(!is_power_of_two(12));
  CHECK(!is_power_of_two(13));
  CHECK(!is_power_of_two(14));
  CHECK(!is_power_of_two(15));
}
