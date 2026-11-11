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

int main() {
	for (int t = 1; t <= 100000; t++) {
		system("gen > migrate.in");
		system("a");
		system("bf < migrate.in > 1.ans");
		if (system("fc migrate.out 1.ans")) {
			cout << "WA " << t << '\n';
			return 0;
		}
		cout << "AC " << t << '\n';
	}
    return 0;
}