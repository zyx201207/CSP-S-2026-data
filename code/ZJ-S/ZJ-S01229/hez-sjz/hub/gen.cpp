#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector < int >;
using pii = pair < int, int >;
#define fi first
#define se second
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define qio() cin.tie(0) -> sync_with_stdio(0)
#define L(i, l, r) for (int i = l; i <= (int)(r); i++)
#define R(i, r, l) for (int i = r; i >= (int)(l); i--)
#define rep(i, l, r) for (int i = l; i < (int)(r); i++)
#define per(i, r, l) for (int i = r - 1; i >= (int)(l); i--)
#define FileIO(name) \
    freopen(name ".in", "r", stdin); \
    freopen(name ".out", "w", stdout)

mt19937 seed(random_device{}());
int rand(int l, int r) {
	return uniform_int_distribution < int >(l, r)(seed);
}

int main() {
    int c = 0, T = 100; cout << c << ' ' << T << '\n';
    while (T--) {
        int n = rand(5, 15), k = rand(2, n); 
        cout << n << ' ' << k << '\n';
        L(i, 2, n) cout << rand(1, i - 1) << ' ' << i << '\n';
    }
    return 0;
}