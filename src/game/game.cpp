#include "game.h"

#include "test/test.h"

Game::Game()
    : home_team(""),
      away_team(""),
      home_score(-1),
      away_score(-1),
      child_game_1(nullptr),
      child_game_2(nullptr) {}

Game::Game(Game* child_game_1, Game* child_game_2)
    : home_team(""),
      away_team(""),
      home_score(-1),
      away_score(-1),
      child_game_1(child_game_1),
      child_game_2(child_game_2) {}

Game::Game(std::string const& home_team, std::string const& away_team)
    : home_team(home_team),
      away_team(away_team),
      home_score(-1),
      away_score(-1),
      child_game_1(nullptr),
      child_game_2(nullptr) {}

std::string Game::result() {
  if (!has_result()) {
    return "";
  } else if (home_score == away_score) {
    return "Unentschieden";
  } else if (home_score > away_score) {
    return home_team;
  } else {
    return away_team;
  }
}

void Game::set_result(int home_score, int away_score) {
  this->home_score = home_score;
  this->away_score = away_score;
}

bool Game::has_result() {
  // TODO
  return false;
}

void Game::update_teams() {
  // TODO
}

TEST_CASE("Game States for new games") {
  SUBCASE("empty game") {
    Game game;
    CHECK(!game.has_result());
    CHECK(game.result() == "");
  }

  SUBCASE("unplayed game with child games") {
    Game child_game_1("Team C", "Team D");
    Game child_game_2("Team E", "Team F");
    Game game(&child_game_1, &child_game_2);
    CHECK(!game.has_result());
    CHECK(game.result() == "");
  }

  SUBCASE("unplayed game") {
    Game game("Team A", "Team B");
    CHECK(!game.has_result());
    CHECK(game.result() == "");
  }

  SUBCASE("home team wins") {
    Game game("Team A", "Team B");
    game.set_result(1, 0);
    CHECK(game.has_result());
    CHECK(game.result() == "Team A");
  }

  SUBCASE("away team wins") {
    Game game("Team A", "Team B");
    game.set_result(0, 1);
    CHECK(game.has_result());
    CHECK(game.result() == "Team B");
  }

  SUBCASE("draw") {
    Game game("Team A", "Team B");
    game.set_result(0, 0);
    CHECK(game.has_result());
    CHECK(game.result() == "Unentschieden");
  }
}

TEST_CASE("Game::update_teams") {
  SUBCASE("simple") {
    Game semi_final_1("Team C", "Team D");
    Game semi_final_2("Team E", "Team F");
    semi_final_1.set_result(1, 0);
    semi_final_2.set_result(0, 1);
    Game game(&semi_final_1, &semi_final_2);

    game.update_teams();
    CHECK(!game.has_result());
    CHECK(game.home_team == "Team C");
    CHECK(game.away_team == "Team F");
  }
  SUBCASE("recursive_quarterfinals") {
    Game quarter_final_1("Team G", "Team H");
    quarter_final_1.set_result(1, 0);
    Game quarter_final_2("Team I", "Team J");
    quarter_final_2.set_result(0, 1);
    Game quarter_final_3("Team K", "Team L");
    quarter_final_3.set_result(1, 0);
    Game quarter_final_4("Team M", "Team N");
    quarter_final_4.set_result(0, 1);
    Game semi_final_1(&quarter_final_1, &quarter_final_2);
    Game semi_final_2(&quarter_final_3, &quarter_final_4);
    Game final(&semi_final_1, &semi_final_2);
    final.update_teams();
    CHECK(semi_final_1.home_team == "Team G");
    CHECK(semi_final_1.away_team == "Team J");
    CHECK(semi_final_2.home_team == "Team K");
    CHECK(semi_final_2.away_team == "Team N");
    CHECK(final.home_team == "");
    CHECK(final.away_team == "");
  }
  SUBCASE("recursive_semifinals") {
    Game quarter_final_1("Team G", "Team H");
    quarter_final_1.set_result(1, 0);
    Game quarter_final_2("Team I", "Team J");
    quarter_final_2.set_result(0, 1);
    Game quarter_final_3("Team K", "Team L");
    quarter_final_3.set_result(1, 0);
    Game quarter_final_4("Team M", "Team N");
    quarter_final_4.set_result(0, 1);
    Game semi_final_1(&quarter_final_1, &quarter_final_2);
    Game semi_final_2(&quarter_final_3, &quarter_final_4);
    Game final(&semi_final_1, &semi_final_2);

    semi_final_1.set_result(1, 0);
    semi_final_2.set_result(0, 1);

    final.update_teams();
    CHECK(final.home_team == "Team G");
    CHECK(final.away_team == "Team N");
  }
}
