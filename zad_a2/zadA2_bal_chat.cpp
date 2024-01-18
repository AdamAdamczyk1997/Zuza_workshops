// #include <iostream>
// #include <vector>
// #include <string>
// #include <algorithm>
// #include <list>

// using namespace std;

// struct Arystokrata {
//     long long prestiz;
//     string nazwisko;

//     Arystokrata(long long p, string n) : prestiz(p), nazwisko(n) {}
// };

// bool komparator(const Arystokrata& a, const Arystokrata& b) {
//     if (a.prestiz != b.prestiz) return a.prestiz < b.prestiz;
//     // Dodaj logikę dla równego prestiżu, jeśli jest potrzebna
//     return false; // przykładowa logika
// }

// int main() {
//     int M;
//     cin >> M;

//     list<Arystokrata> finalny;
//     for (int i = 0; i < M; ++i) {
//         int Ni;
//         cin >> Ni;
//         list<Arystokrata> korytarz;
//         for (int j = 0; j < Ni; ++j) {
//             long long p;
//             string n;
//             cin >> p >> n;
//             korytarz.emplace_back(p, n);
//         }

//         // Scalanie wektorów
//         list<Arystokrata> scalony;
//         merge(finalny.begin(), finalny.end(), korytarz.begin(), korytarz.end(), back_inserter(scalony), komparator);
//         finalny.swap(scalony);
//     }

//     for (const auto& arystokrata : finalny) {
//         cout << arystokrata.nazwisko << endl;
//     }

//     return 0;
// }

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Arystokrata {
    long long prestiz;
    string nazwisko;

    Arystokrata(){}
    Arystokrata(long long p, string n) : prestiz(p), nazwisko(n) {}
};

void insertionSort(vector<Arystokrata>& ary) {
    for (size_t i = 1; i < ary.size(); i++) {
        Arystokrata key = ary[i];
        int j = i - 1;

        // Porównanie najpierw prestiżu, potem nazwiska
        while (j >= 0 && (ary[j].prestiz > key.prestiz ||
                          (ary[j].prestiz == key.prestiz && ary[j].nazwisko > key.nazwisko))) {
            ary[j + 1] = ary[j];
            j--;
        }
        ary[j + 1] = key;
    }
}

vector<Arystokrata> scalaj(const vector<Arystokrata>& a, const vector<Arystokrata>& b) {
    vector<Arystokrata> wynik;
    size_t i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i].prestiz < b[j].prestiz || 
            (a[i].prestiz == b[j].prestiz && a[i].nazwisko < b[j].nazwisko)) {
            wynik.push_back(a[i++]);
        } else {
            wynik.push_back(b[j++]);
        }
    }
    while (i < a.size()) wynik.push_back(a[i++]);
    while (j < b.size()) wynik.push_back(b[j++]);

    return wynik;
}

int main() {
    int M;
    cin >> M;

    vector<Arystokrata> finalny;
    for (int i = 0; i < M; ++i) {
        int Ni;
        cin >> Ni;
        vector<Arystokrata> korytarz(Ni);
        for (int j = 0; j < Ni; ++j) {
            long long p;
            string n;
            cin >> p >> n;
            korytarz[j] = Arystokrata(p, n);
        }

        insertionSort(korytarz);
        finalny = scalaj(finalny, korytarz);
    }

    for (const auto& arystokrata : finalny) {
        cout << arystokrata.nazwisko << endl;
    }

    return 0;
}

