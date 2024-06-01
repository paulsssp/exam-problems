#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> graph;

list<int> ordenacio_topologica(graph& G) {
    int n = G.size();
    VI ge(n, 0); // emmagatzema grau d'entrada de cada vertex
    for (int u = 0; u < n; ++u) { // u es un vertex
        int m = G[u].size();
        for (int i = 0; i < m; ++i) ++ge[G[u][i]];
    }

    //priority_queue<int> Q;  en lloc de queue fem servir priority_queue per garantitzar l'ordre lexicografic (per defecte l'ordena de gran a petit) per revertir l'ordre fem:
    priority_queue<int, vector<int>, greater<int>> Q; // min heap
    for (int u = 0; u < n; ++u) {
        if (ge[u] == 0) Q.push(u); // cua amb vertex de grau zero
    } 

    list<int> L;
    while(not Q.empty()) {
        int u = Q.top(); // treiem un vertex de la cua, l'escrivim i reajustem els graus
        Q.pop();
        L.push_back(u);
        int m = G[u].size();
        for(int i = 0; i < m; ++i) {
            int v = G[u][i];
            if (--ge[v] == 0) Q.push(v);
        }
    }
    return L;
} 


int main() {
    int n, m;
    while (cin >> n >> m) {
        graph G(n);
        int x, y;
        for(int i = 0; i < m; ++i) {
            cin >> x >> y;
            G[x].push_back(y);
        }
        list<int> L = ordenacio_topologica(G);
        auto it = L.begin();
        cout << *it;
        ++it;
        while(it != L.end()) {
            cout << ' ' << *it;
            ++it;
        }
        cout << endl;
    }
} 
