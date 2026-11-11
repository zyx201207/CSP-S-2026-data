
#include  <bits/stdc++.h>
using namespace std;


int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	int n, m;
	long long a[10000005];
	long long res;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];

	}
	for (int i = 0; i < m; i++) {
		if (a[i] + 1 == a[i + 1]) {
			res++;
		}

	}

	cout << res << "\n";

	return 0;
}