#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Krawedz {
    int u, v, waga;
};

struct Subset {
    int parent, rank;
};

int find(vector<Subset>& subsets, int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(vector<Subset>& subsets, int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int kruskalMST(vector<Krawedz>& krawedzie, int N) {
    int mst_waga = 0;
    sort(krawedzie.begin(), krawedzie.end(), [](const Krawedz& a, const Krawedz& b) {
        return a.waga < b.waga;
    });

    vector<Subset> subsets(N);
    for (int v = 0; v < N; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    for (auto& k : krawedzie) {
        int x = find(subsets, k.u);
        int y = find(subsets, k.v);

        if (x != y) {
            mst_waga += k.waga;
            Union(subsets, x, y);
        }
    }
    return mst_waga;
}

int main() {
    int Z;
    cin >> Z;
    while (Z--) {
        int N, M;
        cin >> N >> M;
        vector<Krawedz> krawedzie(M);
        for (int i = 0; i < M; i++) {
            cin >> krawedzie[i].u >> krawedzie[i].v >> krawedzie[i].waga;
            krawedzie[i].u--; // Aby indeksowanie zaczynało się od 0
            krawedzie[i].v--;
        }
        cout << kruskalMST(krawedzie, N) << endl;
    }
    return 0;
}
