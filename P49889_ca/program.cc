#include <iostream>
#include <vector>
#include <string> 
using namespace std;

typedef vector<int> VI;


void paraules(string paraula, string con, string voc, VI& con_b, VI& voc_b, int idx) {
    int n = paraula.size();
    if (idx == n) cout << paraula << endl;
    else {
        int m = con.size();
        if (idx%2 == 0) {
            for (int i = 0; i < m; ++i) {
                if (not con_b[i]) {
                    paraula[idx] = con[i];
                    con_b[i] = true;
                    paraules(paraula, con, voc, con_b, voc_b, idx+1);
                    con_b[i] = false;
                }
            }
        }
        else {
            for (int i = 0; i < m; ++i) {
                if (not voc_b[i]) {
                    paraula[idx] = voc[i];
                    voc_b[i] = true;
                    paraules(paraula, con, voc, con_b, voc_b, idx+1);
                    voc_b[i] = false;
                }
            } 
        } 
    } 
}

int main() {
    int n;
    cin >> n;
    string con, voc;
    cin >> con >> voc;
    string paraula(2*n, ' '); // los strings tambien se pueden inicializar con ua medida
    VI con_b(n, false);
    VI voc_b(n, false);
    paraules(paraula, con, voc, con_b, voc_b, 0);
}