#ifndef GAMETREE_H
#define GAMETREE_H

#include <vector>

#include "game/game.h"

/// Erwartet einen Vektor von Game-Pointern und verbindet sie zu einem
/// Spielbaum. Dabei wird das erste Spiel als Finale verwendet, die beiden
/// folgenden Spiele als Halbfinals, die vier folgenden Spiele als
/// Viertelfinals, usw.
///
/// Überschreibt die Kindspiele der gegebenen Spiele,
/// um die geforderte Struktur zu erzeugen.
void build_gametree(std::vector<Game*>& games);

/// Erwartet eine Zahl n und prüft, ob n eine Potenz von 2 ist.
bool is_power_of_two(int n);

#endif
