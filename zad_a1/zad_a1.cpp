// Zuzanna Poznanska
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct para {
    int num;
    string word;

    para () {}

    para(int n, string w) : num(n), word(w) {}

void print() const {
    cout << num << " " << word << " ";
}

};

void merge(vector<para>& p, int low, int mid, int high, bool ascending) {
    vector<para> left(p.begin() + low, p.begin() + mid + 1);
    vector<para> right(p.begin() + mid + 1, p.begin() + high + 1);

    int i = 0, j = 0, k = low;

    while (i < left.size() && j < right.size()) {
        if (ascending) {
            if (left[i].num <= right[j].num) {
                p[k++] = left[i++];
            } else {
                p[k++] = right[j++];
            }
        } else {
            if (left[i].num >= right[j].num) {
                p[k++] = left[i++];
            } else {
                p[k++] = right[j++];
            }
        }
    }

    while (i < left.size()) {
        p[k++] = left[i++];
    }

    while (j < right.size()) {
        p[k++] = right[j++];
    }
}

void mergeSort(vector<para>& p, int low, int high, bool ascending) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(p, low, mid, ascending);
        mergeSort(p, mid + 1, high, ascending);
        merge(p, low, mid, high, ascending);
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
        pairs.reserve(N);
        for (int j = 0; j < N; j++) {
            int n;
            string w;
            cin >> n >> w;
            pairs.push_back(para(n, w));
        }

        mergeSort(pairs, 0, pairs.size() - 1, order == '<'); 

        for (int j = 0; j < N; j++) {
            pairs[j].print();
        }
        cout << endl;
    }

    return 0;
}