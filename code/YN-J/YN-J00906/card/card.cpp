#include <bits/stdc++.h>
using namespace std;

int n, m;

void solve() {
	cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		cout << n << " ";
	}
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;
}