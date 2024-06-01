#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> Fila;
typedef vector<Fila> Matriu;

const Matriu X({{1, 1}, {1, 0}});
/*  X = | 1  1 |
        | 1  0 |

Entonces, podemos expresar la relación de recurrencia como una multiplicación de matrices:

    | F(n)   |   | 1  1 |   | F(n-1) |
    | F(n-1) | = | 1  0 | * | F(n-2) |

Por lo tanto, multiplicar la matriz X por un vector de dos términos de la sucesión de Fibonacci nos da el siguiente término de la secuencia.
*/


// Pre: a i b són matrius quadrades n×n amb n ≥ 0
// Post: retorna la matriu resultant de multiplicar a i b
Matriu producte(const Matriu& a, const Matriu& b, int m) {
    int n = a.size();
    Matriu prod(n, vector<int>(n, 0));  // inicialitzo a zero per poder anar sumant valors a mesura que multiplico
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) prod[i][j] = (prod[i][j] + a[i][k]*b[k][j])%m;
        }
    }
    return prod;
}
 
//Retorna la potencia de n^k mod m
Matriu potencia(const Matriu& mat, int k, int m, const Matriu& X) {
    if (k == 1) return X;
    Matriu resultat = potencia(mat, k/2, m, X);
    resultat = producte(resultat, resultat, m);
    if (k%2 != 0) resultat = producte(resultat, X, m);
    return resultat;
}

int fibonacci(int n, int m) {
    if (n < 2) return n;
    Matriu mat(2, Fila(2));
    mat = potencia(mat, n, m, X);
    return mat[0][1];
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        cout << fibonacci(n, m) << endl;
    }
}
