# Egzamino (Išankstinė) užduotis


## Aprašymas

Ši programa naudotojui suteikia galimybę automatiškai rasti tekste žodžius, kurie pasikartoja daugiau nei 1 kartą (programa suskaičiuoja kiek kartų jie kartojasi), bei suteikia galimybę iš teksto išrinkti URL nuorodas

## Įdiegimo instrukcija

Norint sėkmingai paleisti šią programą, reikalinga CMake įrankio versija 3.14 ar naujesnė. Taip pat reikalingas C++ kompiliatorius, palaikantis C++17 standartą.

### Programos paruošimas

1. Atsisiųskite projekto kodą iš GitHub ar kitos saugyklos.
2. Įsitikinkite, kad jūsų sistemoje įdiegtas CMake ir tinkamas C++ kompiliatorius.
3. Išskleiskite programos ZIP aplanką savo darbalaukyje.

### Programos kompiliavimas

Atidarykite terminalą ir vykdykite šias komandas:

```bash
cd kelias_iki_projekto
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
cmake --build .
.\Egzamino_Uzduotis
```
Šios komandos sukurs build katalogą, kuriame bus generuojami visi kompiliavimo failai, ir iškompiliuos programą.

## Naudojimosi instrukcija

Programa gali būti naudojama keliais būdais, priklausomai nuo to, kaip norite įvesti tekstą:

1. Rankinis teksto įvedimas: paleidus programą, pasirinkite duomenų įvedimo būdą ir įveskite norimą tekstą.
2. Teksto skaitymas iš failo: tekstas gali būti nuskaitomas iš iš anksto paruošto tekstinio failo.
3. Pasirinkite kokią užduotį norite atlikti (1. Rasti pasikartojančius žodžius. 2. Istraukti URL. 3. ABI)
4. Programą galite išbandyti su mano paruoštu testfile.txt failu

## Rezultatų išvedimas

Gauti rezultatai pateikiami konsolėje, taip pat yra galimybė pasirinkti, kad jie būtų išsaugoti tekstiniame faile, programos aplanke.
