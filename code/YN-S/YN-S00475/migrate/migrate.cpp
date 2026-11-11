#include <bits/stdc++.h>
using namespace std;
int MAXN = 500086;
long long c, n, m, d, q, x, y;
int w[500086], a[510][500086], b[500086];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c, m, ans = 0;
	cin >> c >> m;
	while (m) {
		int n, d;
		cin >> n >> d;
		int a[n], b[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i < n; i++) {
			b[i] = a[i] - a[i - 1];
		}


	}
	return 0;
}
