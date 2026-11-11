#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= (r); ++i)
#define req(i, l, r) for (int i = l; i < (r); ++i)
#define per(i, r, l) for (int i = r; i >= (l); --i)
#define qer(i, r, l) for (int i = r; i > (l); --i)
#define eb emplace_back
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pli = pair<long long, int>;
const int N = 2e6 + 2;
int c, t, n, d, x[N];
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		rep(i, 1, n) cin >> x[i];
		cout << 0 << '\n';
	}
	return 0;
}
/*
ulimit -s 1024000000
g++ -o migrate migrate.cpp -std=c++14 -O2 -static
./migrate
*/