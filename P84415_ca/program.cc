#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string,int> m; // {paraula, freq}
    string token;
    while (cin >> token) {
        if (token == "store") {
            string p;
            cin >> p;
            if (m.find(p) == m.end()) m[p] = 1;
            else ++m[p];
        }
        else if (token == "delete") {
            string p;
            cin >> p;
            if (m.find(p) != m.end()) {
                --m[p];
                if (m[p] == 0) m.erase(p);
            }
        }
        else if (token == "maximum?") {
            if (m.size() == 0) cout << "indefinite maximum" << endl;
            else {
                auto it = m.end();
                --it;
                cout << "maximum: " << it->first << ", " << it->second << " time(s)" << endl;
            }
        }
        else { // token == "minimum?"
            if (m.size() == 0) cout << "indefinite minimum" << endl;
            else cout << "minimum: " << m.begin()->first << ", " << m.begin()->second << " time(s)" << endl;
        }
    }
}