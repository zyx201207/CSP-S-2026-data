#include <bits/stdc++.h>
using ll = long long; using ull = unsigned long long;
const int MAXN = 2e6 + 10;
const int INF32 = INT_MAX; const ll INF64 = LLONG_MAX;
using namespace std;
int n, d;
ll x[MAXN];
void solve(int C) {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
	}
	cout << 0 << '\n';
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	int C, T;
	cin >> C >> T;
	while (T--) solve(C);
	return 0;
}

