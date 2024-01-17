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

void insertionSort(vector<para>& p, bool ascending) {
    for (size_t i = 1; i < p.size(); i++) {
        para key = p[i];
        int j = i - 1;

        // Porównanie najpierw num, potem word
        while (j >= 0 && ((ascending && (p[j].num > key.num || (p[j].num == key.num && p[j].word > key.word))) || 
                          (!ascending && (p[j].num < key.num || (p[j].num == key.num && p[j].word < key.word))))) {
            p[j + 1] = p[j];
            j--;
        }
        p[j + 1] = key;
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

        insertionSort(pairs, order == '<');

        for (auto& p : pairs) {
            p.print();
        }
        cout << endl;
    }

    return 0;
}
