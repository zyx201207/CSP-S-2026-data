#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = 2e5 + 10;
long long a[N];
int f[N][35];
bool vis[N];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		long long x = a[i];
		for (int j = 31; j >= 1; j--) {
			f[i][j] = (x & 1);
			x >>= 1;
		}
	}
	long long ans = 0;
	for (int i = 1; i <= 31; i++) {
		ans <<= 1;
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (vis[j])
				continue;
			if (f[j][i] == 1)
				cnt++;
		}
		if (cnt >= m) {
			for (int j = 1; j <= n; j++) {
				if (f[j][i] == 0)
					vis[j] = 1;
			}
			ans++;
		}
	}
	cout << ans;

	return 0;
}
