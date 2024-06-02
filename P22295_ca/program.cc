#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> VC;
typedef vector<VC> Graph;
typedef vector<int> VI;
typedef vector<VI> VII;

const int dir = 4;
const int df[dir] = {1, 0, 0, -1};
const int dc[dir] = {0, 1, -1, 0};

bool pos_ok(const Graph& g, int f, int c) {
    int n = g.size();
    int m = g[0].size();
    return f < n and f >= 0 and c >= 0 and c < m;
} 

void escriu_cami(const VC& cami) {
    int n = cami.size();
    for (int i = 0; i < n; ++i) cout << cami[i];
    cout << endl;
} 

// dfs + backtracking
void busca_camins(const Graph& g, VC& cami, VII& visitat, int f, int c, int x, int y) {
    if (f == x and c == y) {
        escriu_cami(cami);
        return;
    } 
    for (int i = 0; i < dir; ++i) {
        int nf = f + df[i];
        int nc = c + dc[i];
        if (pos_ok(g, nf, nc)) {
            if (not visitat[nf][nc]) {
                cami.push_back(g[nf][nc]);
                visitat[nf][nc] = true;
                busca_camins(g, cami, visitat, nf, nc, x, y);
                cami.pop_back();
                visitat[nf][nc] = false;
            } 
        } 
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    Graph g(n, VC(m));
    VII visitat(n, VI(m, false));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cin >> g[i][j];
    }
    int f_ini, c_ini, f_fi, c_fi;
    cin >> f_ini >> c_ini >> f_fi >> c_fi;
    VC cami;
    cami.push_back(g[f_ini][c_ini]);
    visitat[f_ini][c_ini] = true;
    busca_camins(g, cami, visitat, f_ini, c_ini, f_fi, c_fi);
} 