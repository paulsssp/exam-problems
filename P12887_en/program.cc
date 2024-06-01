#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> P; // cost i vertex
typedef vector<P> VP;
typedef vector<VP> VVP;

int mst(const VVP& g) {
    int n = g.size();
    vector<bool> vis(n, false);
    vis[0] = true; 
    priority_queue<P, VP, greater<P> > pq; // arestes visitades
    for (P x : g[0]) pq.push(x);
    int sz = 1;
    int sum = 0;
    while (sz < n) { // escull la aresta de pes minim entre les que uneixen un vertex visitat i un que no
        int c = pq.top().first;
        int x = pq.top().second;
        pq.pop();
        if (not vis[x]) {
            vis[x] = true;
            for (P y : g[x]) pq.push(y);
            sum += c;
            ++sz;
        }
    }
    return sum;
}

int main() {
    int n, m, u, v, w; // n = nre de vertex   m = nro de aristas
    while (cin >> n >> m) {
        VVP graph(n);
        for (int i = 0; i < m; ++i) {
            cin >> u >> v >> w;
            --u;
            --v;
            graph[u].push_back({w,v});
            graph[v].push_back({w,u});
        }
        cout << mst(graph) << endl;
    }
}