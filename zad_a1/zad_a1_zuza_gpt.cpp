#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct para {
    int num;
    string word;

    para(int n, string w) : num(n), word(w) {}

void print() const {
    cout << num << " " << word << " ";
}

};

int partition(vector<para>& p, int low, int high, bool ascending) {
    para pivot = p[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (ascending ? (p[j].num < pivot.num || (p[j].num == pivot.num && p[j].word < pivot.word)) 
                      : (p[j].num > pivot.num || (p[j].num == pivot.num && p[j].word > pivot.word))) {
            i++;
            swap(p[i], p[j]);
        }
    }
    swap(p[i + 1], p[high]);
    return (i + 1);
}

void quickSort(vector<para>& p, int low, int high, bool ascending) {
    if (low < high) {
        int pi = partition(p, low, high, ascending);

        quickSort(p, low, pi - 1, ascending);
        quickSort(p, pi + 1, high, ascending);
    }
}


int main() {
    int M;
    cin >> M;
    cin.ignore();

    for (int i = 0; i < M; i++) {
        char order;
        int N;
        cin >> order >> N;

        vector<para> pairs;
        for (int j = 0; j < N; j++) {
            int n;
            string w;
            cin >> n >> w;
            pairs.emplace_back(n, w);
        }

        quickSort(pairs, 0, pairs.size() - 1, true); // Dla sortowania rosnącego

        for (auto& p : pairs) {
            p.print();
        }
        cout << endl;
    }

    return 0;
}
