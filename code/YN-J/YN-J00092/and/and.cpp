#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long n, m, a[N], f[N];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;

	for (long long i = 1; i <= n; i++) {

		cin >> a[i];

	}

	for (long long i = 1; i <= n; i++)

		for (long long j = m; j >= 1; j--) {

			if (j == m)
				f[j] = a[i];
			else
				f[j] = max(f[j], f[j - 1] + (a[j] & a[i]));
		}

	cout << f[m] << "\n";

	return 0;
}
