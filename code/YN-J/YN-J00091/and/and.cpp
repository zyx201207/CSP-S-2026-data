#include <bits/stdc++.h>
#define N 200001
using namespace std;
int n, m, a[N], f[N], v[N], now;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	memset(f, -1, sizeof(f));

	for (int i = 1; i <= n; i++)

		cin >> a[i];
	sort(a + 1, a + n + 1);
	f[2] = a[n] & a[n - 1];
	v[n] = 1;
	v[n - 1] = 1;

	for (int i = 1; i <= m; i++) {

		now = 0;

		for (int j = i; j <= n; j++) {

			if (v[j] == 1)
				continue;

			if (f[i] >= f[i - 1]&a[j])
				continue;
			else {
				f[i] = f[i - 1] & a[j];
				now = j;
			}
		}

		v[now] = 1;
	}

	cout << f[m] << "\n";
	return 0;
}
