#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 10;

int c, t, n;
int mx[N];
long long m;
long long a[N], f[N], sum[N], s[N];

int main (void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		if (n >= 10000) {
			cout << "1\n";
			continue;
		}
		int ans = 0;
		for (int i = 1; i < n; i++) {
			if (a[i + 1] - a[i] > m)
				continue;
			for (int j = 1; j <= n; j++)
				f[j] = sum[j] = s[j] = mx[j] = 0;
			for (int j = i + 1, l = i; j <= n; j++) {
				while (a[j] - a[l] > m)
					l++;
				if (l == j)
					break;
				s[j] = s[l] + 1, mx[s[j]] = j;
			}
//			cout << i << '\n';
			f[i] = sum[i] = 1, mx[0] = i;
			for (int j = i + 1, l = i; j <= n; j++) {
				while (a[j] - a[l] > m)
					l++;
				if (j == l)
					break;
				f[j] = sum[mx[s[j] - 1]] - sum[l - 1], sum[j] = sum[j - 1] + f[j];
				ans += (f[j] == 2);
//				cout << f[j] << ' ';
			}
//			cout << '\n';
		}
		cout << ans << '\n';
	}
	return 0;
}

//7 3
//-4 -2 0 1 2 3 5
