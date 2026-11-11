#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long a[N], sum[N], f[N];
long long m, ans = 0;
int n;

void dfs(int x, long long mx, long long cnt, long long sum, long long mid) {
	if (x > n) {
		ans = max(ans, sum);
		return ;
	}
	if (sum == 0) {
		dfs(x + 1, a[x], cnt, sum + 1, a[x]);
		dfs(x + 1, mx, cnt, sum, mid);
		return ;
	}
	if (a[x] != mid) {
		if (a[x] < mid) {
			if (cnt + mid - a[x] <= m) {
				dfs(x + 1, mx, cnt + mid - a[x], sum + 1, mid);
			}
		} else {
			long long t = sum * (a[x] - mid);
			if (cnt + t <= m) {
				dfs(x + 1, max(mx, a[x]), cnt + t, sum + 1, a[x]);
			} 
			else {
				if (mid >= mx + 1 && a[x] <= mid - 1) {
					long long total = (mid - a[x]);
					dfs(x + 1, max(mx, a[x]), cnt - total + mid - a[x], sum + 1, a[x]);
				}
			}
		}
	} else {
		dfs(x + 1, mx, cnt, sum + 1, mid);
	}
	dfs(x + 1, mx, cnt, sum, mid);
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	if (n >= 5000) {
		long long off = abs(a[2] - a[1]);
		for (int i = 1; i <= n; i++) {
			sum[i] = sum[i - 1] + a[i];
			f[i] = f[i - 1] + i;
		}
		for (int i = 1; i <= n; i++) {
			long long res = f[i] * off;
			if (res > m) {
				cout << i - 1;
				return 0;
			}
		}
		cout << n;
	} else {
		dfs(1, 0, 0, 0, 0);
		cout << ans;
	}
	return 0;
}