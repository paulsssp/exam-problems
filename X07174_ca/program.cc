#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;

void printar_nombre(const VI& result) {
    int n = result.size();
    for (int i = 0; i < n; ++i) cout << result[i];
    cout << endl;
}

bool es_divisible(const VI& divisors, VI& result, int idx) {
    int prefix = 0;
    for (int i = 0; i <= idx; ++i) {
        prefix = prefix*10 + result[i];
        for (int d : divisors) {
            if (prefix%d == 0) return true;
        }
    } 
    return false;
}

void buscar_nombres(const VI& divisors, VI& result, int idx) {
    if (idx == int(result.size())) printar_nombre(result);
    else {
        for (int i = 0; i <= 9; ++i) {
            result[idx] = i;
            if (not es_divisible(divisors, result, idx)) buscar_nombres(divisors, result, idx+1);
        } 
    }
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        VI divisors(m);
        for (int i = 0; i < m; ++i) cin >> divisors[i];
        VI result(n);
        buscar_nombres(divisors, result, 0);
        cout << "----------" << endl;
    }
}