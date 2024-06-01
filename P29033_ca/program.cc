#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> Graph;

bool dfs (int u, int color, VI& colorejat, const Graph& g) {
    colorejat[u] = color;
    for (int v : g[u]) {
        if (colorejat[v] == -1) {
            if (not dfs(v, (color+1)%2, colorejat, g)) return false; // alterno color entre 0 y 1
        }
        else if (colorejat[v] == color) return false; // el vecino tiene el mismo color
    }
    return true;
}

bool dos_colorable(const Graph& g) {
    int n = g.size();
    VI colorejat(n, -1); // sin colorear

    for (int i = 0; i < n; ++i) {
        if (colorejat[i] == -1) {
            if (not dfs(i, 0, colorejat, g)) return false;
        } 
    } 
    return true;
} 

int main() {
    int n, m;
    while (cin >> n >> m) {
        Graph g(n);
        int x, y;
        for (int i = 0; i < m; ++i) {
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        if (dos_colorable(g)) cout << "yes" << endl;
        else cout << "no" << endl;
    } 
}