#include <iostream>
#include <vector>
#include <string>
using namespace std;

class para {
    int num;
    string word;

public:
    para() : num(0), word("") {}
    para(int n, string w) : num(n), word(w) {}

    void print() const {
        cout << num << " " << word << " ";
    }

    void set_num(int x) {
        num = x;
    }

    void set_word(const string& w) {
        word = w;
    }

    int get_int() const {
        return num;
    }

    string get_string() const {
        return word;
    }

    void set_para(const para& y) {
        num = y.get_int();
        word = y.get_string();
    }

    char get_letter(size_t x) const {
        return (x < word.size()) ? word[x] : '\0';
    }
};

void swap(int& a, int& b, para& x, para& y) {
    int tmp = a;
    a = b;
    b = tmp;

    para t = x;
    x = y;
    y = t;
}

int partition(vector<para>& p, int start, int end, bool ascending) {
    int pivot = p[start].get_int();
    int i = start, j = end;

    while (i <= j) {
        if (ascending) {
            while (p[i].get_int() < pivot) i++;
            while (p[j].get_int() > pivot) j--;
        } else {
            while (p[i].get_int() > pivot) i++;
            while (p[j].get_int() < pivot) j--;
        }
        if (i <= j) {
            swap(p[i].get_int(), p[j].get_int(), p[i], p[j]);
            i++;
            j--;
        }
    }
    return i;
}

void quickSort(vector<para>& p, int start, int end, bool ascending) {
    if (start < end) {
        int pi = partition(p, start, end, ascending);
        quickSort(p, start, pi - 1, ascending);
        quickSort(p, pi, end, ascending);
    }
}

int main() {
    int M;
    cin >> M;

    for (int i = 0; i < M; i++) {
        char c;
        cin >> c;

        int N;
        cin >> N;

        vector<para> p(N);
        for (int j = 0; j < N; j++) {
            int n;
            string w;
            cin >> n >> w;
            p[j] = para(n, w);
        }

        quickSort(p, 0, N - 1, c == '<');

        for (int j = 0; j < N; j++) {
            p[j].print();
        }
        cout << endl;
    }

    return 0;
}
