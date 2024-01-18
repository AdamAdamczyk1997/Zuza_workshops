//Zuzanna Poznanska
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Arystokrata {
    long long prestiz;
    string nazwisko;
    int korytarzId;

    Arystokrata(){}

    Arystokrata(long long p, string n, int id) : prestiz(p), nazwisko(n), korytarzId(id) {}
};

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void heapify(vector<Arystokrata>& ary, int n, int i, const vector<int>& korytarzSize) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && (ary[left].prestiz > ary[largest].prestiz || 
        (ary[left].prestiz == ary[largest].prestiz && korytarzSize[ary[left].korytarzId] > korytarzSize[ary[largest].korytarzId]))) {
        largest = left;
    }

    if (right < n && (ary[right].prestiz > ary[largest].prestiz || 
        (ary[right].prestiz == ary[largest].prestiz && korytarzSize[ary[right].korytarzId] > korytarzSize[ary[largest].korytarzId]))) {
        largest = right;
    }

    if (largest != i) {
        swap(ary[i], ary[largest]);
        heapify(ary, n, largest, korytarzSize);
    }
}

void heapSort(vector<Arystokrata>& ary, const vector<int>& korytarzSize) {
    int n = ary.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(ary, n, i, korytarzSize);
    }
    for (int i = n - 1; i >= 0; i--) {
        swap(ary[0], ary[i]);
        heapify(ary, i, 0, korytarzSize);
    }
}

int main() {
    int M;
    cin >> M;

    vector<Arystokrata> A;
    vector<int> korytarzSize(M, 0);
    for (int i = 0; i < M; ++i) {
        int Ni;
        cin >> Ni;
        korytarzSize[i] = Ni;
        for (int j = 0; j < Ni; ++j) {
            long long p;
            string n;
            cin >> p >> n;
            A.emplace_back(p, n, i);
        }
    }

    heapSort(A, korytarzSize);

    for (const auto& arystokrata : A) {
        cout << arystokrata.nazwisko << endl;
    }

    return 0;
}