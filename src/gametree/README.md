# Funktionen für Spielbäume

## Überblick

In diesem Verzeichnis werden zwei Funktionen implementiert, die mit Spielbäumen arbeiten.
Die Idee ist dabei, dass man zuerst eine Liste von Spielen erzeugt, die zusammen ein Turnier ergeben.
Aus diesen Spielen wird ein Spielbaum aufgebaut, der die Beziehungen zwischen den Spielen abbildet.
D.h. Sie sollten zuerst die Aufgaben im Verzeichnis `game` bearbeiten bzw. verstehen.

## Details zur Idee

Um ein Turnier zu beschreiben, erzeugt man eine Liste von `Game`-Objekten (genauer Pointern), die die einzelnen Spiele repräsentieren.
In dieser Liste können Spiele bereits Mannschaften haben, müssen aber nicht.
Auf keinen Fall haben die Spiele bereits Ergebnisse und auch keine Kindspiele.

Die Funktion `build_gametree` erzeugt aus dieser Liste einen Spielbaum, der die Beziehungen zwischen den Spielen abbildet.
Dazu trägt sie in jedem Spiel die beiden Kindspiele ein, die zu diesem Spiel geführt haben.

*Beispiel*: Angenommen, es gibt sieben Spiele `A`, `B`, `C`, `D`, `E`, `F` und `G`.
In dieser Liste wären `A` das Finale, `B` und `C` die Halbfinalspiele, sowie `D`, `E`, `F` und `G` die Viertelfinalspiele.
Daher muss `build_gametree` als Kindspiele für `A` die Spiele `B` und `C` eintragen, für `B` die Spiele `D` und `E`, usw.

Es gibt in den Dateien `gametree.h` und `gametree.cpp` zwei Funktionen:

* `build_gametree`: Erzeugt einen Spielbaum aus einer Liste von Spielen.
* `is_power_of_two`: Überprüft, ob eine Zahl eine Zweierpotenz ist.

Die Funktion `build_gametree` ist die Hauptfunktion, die Sie implementieren müssen.
Die Funktion `is_power_of_two` ist eine Hilfsfunktion, die die Aufgabe stark vereinfacht.

## Aufgaben

**Implementieren Sie die Funktionen `build_gametree()` und `is_power_of_two()`.**

In der Datei `gametree.h` finden Sie die Deklaration der Funktionen
sowie Dokumentations-Kommentare, die die Funktionen genauer beschreiben.

In der Datei `gametree.cpp` werden die Funktionen implementiert.
Dort finden Sie auch Unit-Tests, mit denen Sie Ihre Implementierung überprüfen können.
