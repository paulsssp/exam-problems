#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// BFS

typedef vector<char> Fila;
typedef vector<Fila> Graf;
typedef vector<int> VI;
typedef vector<VI> Distancies;
typedef pair<int, int> PII;
typedef queue<PII> Posicions;

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

bool pos_valida(const Graf& mat, Distancies& dis, int f, int c) {
    if (f >= 0 and f < mat.size() and c >= 0 and c < mat[0].size() and mat[f][c] != 'X' and dis[f][c] == -1) return true;
    return false;
}

int minim_tresor(const Graf& mat, Distancies& dis, Posicions& pos, int f, int c) {
    while (not pos.empty()) {
        int dis_fila = pos.front().first; //distancias anteriores
        int dis_col = pos.front().second;
        pos.pop();
        for (int i = 0; i < dir; ++i) {
            int nf = dis_fila + df[i];
            int nc = dis_col + dc[i];
            if (pos_valida(mat, dis, nf, nc)) {
                pos.push(make_pair(nf, nc));
                dis[nf][nc] = dis[dis_fila][dis_col] + 1;
                if (mat[nf][nc] == 't') return dis[nf][nc];
            } 
        }
    } 
    return -1;
}

int main() {
    int n, m;
    cin >> n >> m;
    Graf mat(n, Fila(m)); // grafo
    llegir_matriu(mat);
    Distancies dis(n, VI(m, -1)); // grafo con distancias a la pos ini
    int f, c;
    cin >> f >> c;
    Posicions pos; // cola de posiciones
    pos.push(make_pair(f-1, c-1));
    dis[f-1][c-1] = 0;
    int dist_min = minim_tresor(mat, dis, pos, f-1, c-1);
    if (dist_min == -1) cout << "no es pot arribar a cap tresor" << endl;
    else cout << "distancia minima: " << dist_min << endl;
}