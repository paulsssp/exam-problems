#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef vector<char> VC;
const int lletres = 4;
const VC v = {'A', 'C', 'G', 'T'};

void busca_combinacions(string& s, int n) {
    if (int(s.size()) == n) {
        cout << s << endl;
        return;
    }
    for (int i = 0; i < lletres; ++i) {
        s.push_back(v[i]);
        busca_combinacions(s, n);
        s.pop_back();
    }
}

int main() {
    int n;
    cin >> n;
    string s;
    busca_combinacions(s, n);
}
