#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> VC;
typedef vector<VC> Graph;

const int df[8] = {0, 0, 1, 1, 1, -1, -1, -1};
const int dc[8] = {1, -1, 0, 1, -1, 0, 1, -1};
const int veins = 8;

void dibuixa_tauler(const Graph& g) {
    int n = g.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) cout << g[i][j];
        cout << endl;
    } 
    cout << "----------" << endl;
}

bool pos_ok(Graph& g, int f, int c) {
    int n = g.size();
    return f < n and f >= 0 and c >= 0 and c < n;
} 

bool te_veins(Graph& g, int f, int c) {
    for (int i = 0; i < veins; ++i) {
        int nf = f + df[i];
        int nc = c + dc[i];
        if (pos_ok(g, nf, nc)) {
            if (g[nf][nc] == 'K') return true;
        } 
    }
    return false;
}

void posa_reis(Graph& g, int f, int c, int count, int reis) {
    int n = g.size();
    if (count == reis) {
        dibuixa_tauler(g);
        return;
    }
    if (f == n) return;

    for (int i = f; i < n; ++i) {
        for (int j = c; j < n; ++j) {
            if (!te_veins(g, i, j)) {
                g[i][j] = 'K';
                posa_reis(g, i, j + 1, count + 1, reis);
                g[i][j] = '.';
            }
        }
        if (i < n - 1) c = 0;
    }
}

int main() {
    int n, r;
    cin >> n >> r;
    Graph g(n, VC(n,'.'));
    posa_reis(g, 0, 0, 0, r);
}