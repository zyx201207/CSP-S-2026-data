#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
#define N 5005
#define M 2000005
using namespace std;
int c, t, n, brk;
ll d, a[M], f[N], g[N], ans;

void solve0() {
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++)
				f[j] = INF, g[j] = 0;
			f[i] = 0, g[i] = 1;
			for (int j = i; j <= n; j++) {
				for (int k = j + 1; k <= n; k++) {
					if (a[k] - a[j] > d)
						break;
					if (f[k] > f[j] + 1)
						f[k] = f[j] + 1, g[k] = g[j];
					else if (f[k] == f[j] + 1)
						g[k] += g[j];
				}
				if (g[j] == 2)
					ans++;
			}
		}
		cout << ans << endl;
	}
}

void solve1() {
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		if (n == 1) {
			cout << 0 << endl;
			continue;
		}
		ll d0 = a[2] - a[1];
		if (d < d0 * 2) {
			cout << 0 << endl;
			continue;
		}
		ll m = d / d0;
		if (n >= m * 2)
			cout << (n - m * 2 + 1) << endl;
		else
			cout << 0 << endl;
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	if (c == 11 || c == 12)
		solve1();
	else
		solve0();
	return 0;
}