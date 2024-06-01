#include <iostream>
#include <vector>
using namespace std;

// DFS

typedef vector<char> Fila;
typedef vector<Fila> Graf;
typedef vector<bool> VB;
typedef vector<VB> MatriuB;

const int dir = 4; // arriba, abajo, izq, der
const int df[dir] = {1, -1, 0, 0};
const int dc[dir] = {0, 0, -1, 1};

void llegir_matriu(Graf& mat) {
    int n = mat.size();
    int m = mat[0].size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> mat[i][j];
        }
    }
}

bool pos_valida(const Graf& mat, MatriuB& visitat, int f, int c) {
    if (f >= 0 and f < mat.size() and c >= 0 and c < mat[0].size() and mat[f][c] != 'X' and not visitat[f][c]) return true;
    return false;
}

int buscar_tresor(const Graf& mat, MatriuB& visitat, int f, int c, int& tresors) {
    visitat[f][c] = true;
    if (mat[f][c] == 't') ++tresors;
    for (int i = 0; i < dir; ++i) {
        int nf = f + df[i];
        int nc = c + dc[i];
        if (pos_valida(mat, visitat, nf, nc)) {
           tresors = buscar_tresor(mat, visitat, nf, nc, tresors);
        }
    }
    return tresors;
}

int main() {
    int n, m;
    cin >> n >> m;
    Graf mat(n, Fila(m));
    llegir_matriu(mat);
    MatriuB visitat(n, VB(m, false));
    int f, c;
    cin >> f >> c;
    int tresors = 0;
    cout << buscar_tresor(mat, visitat, f-1, c-1, tresors) << endl;
}