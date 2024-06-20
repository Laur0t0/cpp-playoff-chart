# Datenstruktur `Game`

## Überblick

In diesem Verzeichnis wird ein Datentyp `Game` definiert, der eine Spielpaarung
repräsentiert. Ein `Game`-Objekt besteht aus sechs Attributen:

* `home_team`: `string`
* `away_team`: `string`
* `home_score` : `int`
* `away_score` : `int`
* `child_game_1`: `Game*`
* `child_game_2`: `Game*`

Die ersten vier Attribute repräsentieren die beiden Teams und deren Punktzahl.
Die letzten beiden Attribute sind Zeiger auf zwei weitere `Game`-Objekte, die
die beiden Vorläuferspiele repräsentieren, die zu diesem Spiel geführt haben.
D.h. bei einem Finale sind dies die beiden Halbfinalspiele, bei einem Halbfinale
sind dies die beiden Viertelfinalspiele, usw.

Die Klasse `Game` enthält folgende Methoden:

* `result()`: Liefert das Ergebnis des Spiels als String, d.h. entweder den Namen des Gewinners oder "Unentschieden".
* `set_result()`: Legt ein Ergebnis für das Spiel fest.
* `has_result()`: Liefert `true`, wenn das Spiel bereits gespielt wurde.
* `update_teams()`: Aktualisiert die Mannschaften des aktuellen Spiels auf Basis der Ergebnisse der Kindspiele.

Die Klasse `Game` enthält außerdem eine Reihe an Konstruktoren, die es erlauben,
ein `Game`-Objekt auf verschiedene Weisen zu initialisieren.

## Aufgaben

**Implementieren Sie die Methoden `result()`, `set_result()`, `has_result()` und `update_teams()`.**

In der Datei `game.h` finden Sie die Deklaration der Klasse `Game`.
Dort befinden sich auch Dokumentations-Kommentare, die die Funktionen genauer beschreiben.

In der Datei `game.cpp` werden die Methoden der Klasse `Game` implementiert.
Die Konstruktoren sind bereits implementiert und müssen nicht verändert werden.
Die Methoden sind wie üblich mit `TODO`-Kommentaren markiert.

Unten in der Datei `game.cpp` finden Sie Unit-Tests, mit denen Sie Ihre Implementierung überprüfen können.
