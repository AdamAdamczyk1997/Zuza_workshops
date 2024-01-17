#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// Struktura do przechowywania par (liczba, napis)
struct Pair {
    int number;
    string word;
};

// Funkcja do scalania dwóch podtablic
void merge(vector<Pair>& array, int left, int mid, int right, bool ascending) {
    vector<Pair> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if ((ascending && array[i].number <= array[j].number) || (!ascending && array[i].number >= array[j].number)) {
            temp[k++] = array[i++];
        } else {
            temp[k++] = array[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = array[i++];
    }

    while (j <= right) {
        temp[k++] = array[j++];
    }

    for (i = left, k = 0; i <= right; i++, k++) {
        array[i] = temp[k];
    }
}

// Funkcja sortowania przez scalanie
void mergeSort(vector<Pair>& array, int left, int right, bool ascending) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(array, left, mid, ascending);
        mergeSort(array, mid + 1, right, ascending);
        merge(array, left, mid, right, ascending);
    }
}

int main() {
    int M;
    cin >> M;
    
    while (M--) {
        char order;
        int N;
        cin >> order >> N;
            vector<Pair> pairs(N);
    for (int i = 0; i < N; ++i) {
        cin >> pairs[i].number >> pairs[i].word;
    }

    bool ascending = (order == '<');
    mergeSort(pairs, 0, N - 1, ascending);

    for (const auto& p : pairs) {
        cout << p.number << " " << p.word << " ";
    }
    cout << endl;
}

return 0;

}

/*

**Jak to działa:**

1. Program najpierw wczytuje liczbę zestawów danych `M`.
2. Dla każdego zestawu danych wczytuje symbol porządku sortowania (`<` lub `>`), liczbę par `N` oraz same pary (liczba, słowo).
3. Następnie stosuje sortowanie przez scalanie do posortowania par w odpowiednim porządku.
4. Na końcu wypisuje posortowane pary na standardowe wyjście.

**Uwagi:**

- Sortowanie przez scalanie jest dobrym wyborem, ponieważ jest stabilne i ma złożoność czasową O(N log N).
- Program zakłada, że dane wejściowe są poprawne i nie wykonuje dodatkowej weryfikacji (np. sprawdzania, czy dane wejściowe są liczbami).
- Aby program działał, musisz mieć środowisko umożliwiające kompilację i uruchamianie programów w C++.

Uruchom ten program w środowisku, które obsługuje standard C++11 lub nowszy. Program wczytuje dane ze standardowego wejścia i wypisuje wyniki na standardowe wyjście, więc możesz przetestować go używając przekierowania wejścia/wyjścia w linii komend.

*/