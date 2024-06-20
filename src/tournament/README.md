# Umsetzung eines Turnier-Rechners

## Überblick

In diesem Verzeichnis gibt es eine `main´-Funktion sowie mehrere Hilfsfunktionen,
mit denen ein Turnierbaum aufgebaut und ausgewertet wird.
Dabei werden die Klasse`Game` und die Funktionen aus dem Verzeichnis `gametree` verwendet.
Diese sollten Sie also zuerst bearbeiten bzw. verstehen.

In der `main`-Funktion wird zunächst eine Liste von Spielen erzeugt, die ein Turnier repräsentieren.
Wie in den Aufgaben zu `gametree` beschrieben, wird aus dieser Liste ein Spielbaum aufgebaut.

Anschließend wird der Spielbaum ausgewertet, d.h. es werden Ergebnisse der Spiele festgelegt.
Danach wird der Spielbaum aktualisiert und die Spiele ausgegeben.
Damit das richtig funktioniert, müssen Sie noch einige Funktionen implementieren,
die Eigenschaften von Spielen auf die Konsole ausgeben.

* `print_gametype()`:
    Erwartet eine Zahl und gibt einen Spieltyp aus, z.B. "Finale" oder "Halbfinale 1".
    Diese Funktion wird verwendet, um aufgrund der Position eines Spiels in der Liste den Spieltyp zu bestimmen.
* `print_game()`:
    Erwartet ein Spiel und gibt die beiden Mannschaften und das Ergebnis aus.
    Diese Funktion wird verwendet, um die Spiele des Turniers auszugeben.
    Die Funktion muss auch damit umgehen können, dass ein Spiel noch nicht gespielt wurde.
* `print_games()`:
    Erwartet eine Liste von Spielen und gibt alle Spiele aus.

## Aufgaben

**Implementieren Sie die Funktionen `print_gametype()`, `print_game()` und `print_games()`.**

Für diese Funktionen gibt es keine Tests, da sie Dinge auf die Konsole ausgeben.
Dies ist schwer automatich zu testen.
Die `main`-Funktion ist jedoch bereits implementiert.

Hier gibt es keine exakte Vorgabe, wie die Ausgabe aussehen soll.
Sie können also selbst entscheiden, wie Sie die Spiele auf der Konsole darstellen.
Ggf. müssen Sie auch nicht alle Funktionen nutzen, wenn Sie die Ausgabe anders gestalten.
