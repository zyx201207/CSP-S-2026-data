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
    int c = 0, T = 100; cout << c << ' ' << T << '\n'; while (T--) {
	    int n = rand(5, 100), v = 100000, d = rand(1, v / 500);;
	    vi pos(v); iota(all(pos), -v / 2);
	    shuffle(all(pos), seed); pos = vi(pos.begin(), pos.begin() + n);
    	sort(all(pos)); cout << n << ' ' << d << '\n'; L(i, 0, n - 1) cout << pos[i] << " \n"[i == n - 1];
    }
    return 0;
}