
# MP3-Modul
Nr. 68

Hersteller Bezeichnung:
> DFRobot Gravity UART Voice Module V1.0
> `DFR0534`

<img alt="DFRobot DFR0534" src="https://makeyourschool.de/wp-content/uploads/2018/10/68_mp3-modul_rz-1024x1024.jpg" style="max-height:30vh"/>

Bildquelle: *Wissenschaft im Dialog*


Das MP3-Modul ermöglicht das Abspielen von Musik oder Tönen.
Die Audio-Dateien können direkt auf dem Modul gespeichert werden.
Für die Ausgabe wird ein Lautsprecher angeschlossen.
Die Steuerung des Moduls erfolgt über einen Mikrocontroller.

## Benutzung / Erste Schritte

### Anschließen

> Achtung: 
> die Pin-Belegung des Steckers im Modul sind anders als im Grove System: Plus und Minus sind vertauscht!

#### Adapter Kabel

schnell zusammen gesteckt..

Bitte genau auf die Farb-Zuordnung Achten!!

##### Benötigtest Material
- beim Modul ist ein Kabel mitgeliefert. (Rot Schwarz Blau Grün)
- Kabel Grove auf Female-Pin-Header (Schwarz Rot Weiß Gelb)
- 10K Widerstand
- Draht-Stücke oder *Pin-Header* die gut in die Buchsen reinpassen..

##### Vorgehen
die Kabel einfach nach dieser Zuordnung (siehe auch das Foto) zusammen stecken:

##### Zuordnung

| Grove   | Verbindung     | MP3-Modul |
| ------- | -------------- | --------- |
| Rot     | Draht          | Rot       |
| Schwarz | Draht          | Schwarz   |
| Weiß    | 10K Widerstand | Blau      |
| Gelb    | Draht          | Grün      |

- Grove Rot mit Modul Rot
- Grove Schwarz mit Modul Schwarz
- Grove Weiß auf 10k Widerstand auf Modul Blau
    - 10k Widerstand in Leitung die zum Modul RX (Receive = Empfangen = Eingang) führt
    - nötig da das Modul nur 3.3V **Signale** _mag_
    - der Serien-Widerstand limitiert den möglichen Strom und schützt so das Modul
- Grove Gelb mit Modul Grün

![Adapterkabel - Lautsprecher1](./adapter/20240503_123257.jpg)



#### Adapter Kabel löten
alternative kannst du das Kabel auch *ordentlich* löten:

[AdapterLoeten.md](./AdapterLoeten.md)



### Musik aufspielen
Das Modul wird über eine Micro-USB Kabel mit dem Laptop verbunden.
Dann erscheint es als *Massenspeicher* (*USB-Stick*) im Datei-Explorer.
Über diesen können dann die Sounds im MP3 oder WAV Format auf das Modul kopiert werden.

Bei den Dateien bitte darauf achten das diese
- maximal 8 Zeichen 
- keine Sonderzeichen 
- mit einer Nummer beginnen

zum Beispiel:
- `01BELL.mp3`
- `02DOOR.wav`
- `03DOOR.mp3`

es stehen maximal 8MB Speicherplatz zu Verfügung.

![Datei Manager](<datei manager.png>)


du findest hier im Ordner DFR0534 ein paar Beispiel Sounds die auch im Beispiel-Code verwendet wurden.

eine große auswahl an frei verfügbaren Sound-Effekten findest du auf
[freesound.org](https://freesound.org)

z.B.
- [allgemeine suche nach *Tür-Glocke*](https://freesound.org/search/?q=door+bell&f=license%3A%22creative+commons+0%22)
- [Klassische Tür-Klingel](https://freesound.org/people/Lynx_5969/sounds/422668/) (beispiel bell.mp3)

### Programmieren

bitte die Library `DFR0534` via library manager installieren.



```c++
// Minimal Beispiel für das MP3 Modul DFR0534

#include <DFR0534.h>
#include <SoftwareSerial.h>

#define TX_PIN A1
#define RX_PIN A0
SoftwareSerial mp3_serial(RX_PIN, TX_PIN);
DFR0534 mp3_audio(mp3_serial);

void setup() {
    // Serial für Informationen am Laptop
    Serial.begin(115200);

    // Software serial für die Kommunikation mit dem MP3 Module (DFR0534)
    mp3_serial.begin(9600);

    // Setze Lautstärke (0..30)
    mp3_audio.setVolume(18);
}


void loop() {

    // für die Dateinamen dieses format Verwenden:
    // "/01BELL  MP3"
    // "/02DOOR*WAV"
    // "/03*MP3"
    // 
    // - falls der Dateiname weniger als 8 Zeichen hat die fehlenden Zeichen mit Leerzeichen füllen.
    // - oder zum füllen das * verwenden
    // - nur GROßBUCHSTABEN verwenden
    // - den Punkt weglassen
    // - der Datei-Typ (MP3 oder WAV) muss angegeben werden

    Serial.println("play /BELL*MP3");
    mp3_audio.playFileByName("/BELL*MP3");
    delay(4000);

    Serial.println("play /DOOR*WAV");
    mp3_audio.playFileByName("/DOOR*WAV");
    delay(4000);

    Serial.println("play /03*MP3");
    mp3_audio.playFileByName("/03*MP3");
    delay(4000);
}

```



## Weiterführende Hintergrundinformationen:
- [DFRobot Wiki](https://wiki.dfrobot.com/Voice_Module_SKU__DFR0534#target_0)
- [library repository](https://github.com/codingABI/DFR0534) 
    hier findest du die eine Dokumentation zur Library
    und auch viele weitere Informationen und Möglichkeiten...




<style>
img {
    max-height: 35vh;
    max-width: 50vw;
}
</style>