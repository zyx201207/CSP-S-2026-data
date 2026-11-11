#include <bits/stdc++.h>
using namespace std;
const int N = 1e7+5;
long long c, T;
long long n, m, a[N];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> c >> T;
	while (T--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		if (n >= 4)
			cout << n - 3 << "\n";
		else
			cout << 0 << "\n";
	}

	return 0;
}