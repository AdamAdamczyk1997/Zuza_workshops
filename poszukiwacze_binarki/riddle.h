#ifndef RIDDLE_H
#define RIDDLE_H

#include <iostream>
#include <unordered_map>

// Struktura reprezentująca węzeł drzewa
struct Crux {
    int info;
    unsigned int left, right;

    Crux() : info(0), left(0), right(0) {}
};

// Klasa reprezentująca Zagadkową Maszynę
class Riddle {
private:
    std::unordered_map<unsigned int, Crux> storage;
    Riddle() {}

public:
    static Riddle& winarium() {
        static Riddle instance;
        return instance;
    }

    static void levioooza() {
        // Implementacja zakończenia pracy z maszyną
    }

    void akcio(unsigned int address) {
        // Rezerwacja pamięci dla Crux
        storage[address] = Crux();
    }

    void evanesko(unsigned int address) {
        // Zwolnienie pamięci dla Crux
        storage.erase(address);
    }

    Crux& operator()(unsigned int address) {
        // Zwracanie referencji do Crux
        return storage[address];
    }
};

void abra(Crux& crux) {
    // Implementacja inwokacji abra
}

void ka(Crux& crux) {
    // Implementacja inwokacji ka
}

void dabra(Crux& crux) {
    // Implementacja inwokacji dabra
}

#endif // RIDDLE_H
