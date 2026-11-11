#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
int a[10000005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == a[i + 1])
			for (int j = m; j <= m; j--)
				a[i] == a[i] + a[i + 1];
		ans++;
		a[i + 1] = a [i + 2];
		if (a[i] - a[i + 1] == 1)
			a[i + 1] = a[i + 1] + 1;
		if (a[i + 1] - a[i] == 1)
			a[i] = a[i] + 1;
	}
	cout << ans;

	return 0;
}

