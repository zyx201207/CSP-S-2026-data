#include <bits/stdc++.h>
using namespace std;
long long a[200005], n, m, maxx, b[200005], ok, c[50];

int dfs(long long f) {
	long long k = 0, i = 1;
	long long c[50] = {0};
	while (f) {
		c[i] = f % 2;
		f /= 2;
		i++;
	}
	for (int j = i - 1; j > 0; j--) {
		k = k * 10 + c[j];
	}
	return k;
}

int das(long long iopp, long long iop) {
	long long z = 1;
	long long l[50] = {0}, fgh = 0;
	while (iopp || iop) {
		if (iopp % 10 + iop % 10 == 2)
			l[z] = 1;
		z++;
		iopp /= 10;
		iop /= 10;
	}
	for (int o = z - 1; o >= 1; o--) {
		fgh = fgh * 2 + l[o];
	}
	return fgh;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] > maxx)
			maxx = a[i];
		b[i] = dfs(a[i]);
	}
	if (m == 1) {
		cout << maxx;
		return 0;
	} else
		maxx = 0;
	if (m == n) {
		maxx = b[1];
		for (int i = 2; i <= n; i++) {
			maxx = dfs(das(maxx, b[i]));
		}
	}
	if (m == 2) {
		maxx = dfs(das(b[1], b[2]));
		for (int i = 2; i <= n - 1; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (maxx < das(b[i], b[j]))
					maxx = das(b[i], b[j]);
			}
		}
	}
	int i = 1;
	while (maxx) {
		c[i] = maxx % 10;
		maxx /= 10;
		i++;
	}
	for (int j = i - 1; j >= 1; j--) {
		ok = ok * 2 + c[j];
	}

	cout << ok;
	return 0;
}