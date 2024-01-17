#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Arystokrata {
    long long prestiz;
    string nazwisko;

    Arystokrata(long long p, string n) : prestiz(p), nazwisko(n) {}
};

vector<Arystokrata> scalaj(const vector<Arystokrata>& a, const vector<Arystokrata>& b) {
    vector<Arystokrata> wynik;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i].prestiz < b[j].prestiz) {
            wynik.push_back(a[i++]);
        } else if (a[i].prestiz > b[j].prestiz) {
            wynik.push_back(b[j++]);
        } else {
            // W przypadku równego prestiżu
            if (a.size() - i > b.size() - j) {
                wynik.push_back(a[i++]);
            } else {
                wynik.push_back(b[j++]);
            }
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
        vector<Arystokrata> korytarz;
        for (int j = 0; j < Ni; ++j) {
            long long p;
            string n;
            cin >> p >> n;
            korytarz.push_back(Arystokrata(p, n));
        }
        finalny = scalaj(finalny, korytarz);
    }

    for (const auto& arystokrata : finalny) {
        cout << arystokrata.nazwisko << endl;
    }

    return 0;
}

/*
Uwagi

    Kod zakłada, że dane wejściowe są zawsze poprawne.
    Funkcja scalaj bierze dwa posortowane wektory i scala je w jeden posortowany wektor, biorąc pod uwagę specjalne reguły dotyczące porównywania prestiżu.
    Funkcja main wczytuje dane wejściowe, tworzy wektory dla każdego korytarza i scali je wszystkie, tworząc ostateczną kolejność arystokratów.
*/