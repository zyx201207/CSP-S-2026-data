#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 500005;

int n, m, ans = 0, cnt = 1;
int a[N], b[N], g[N];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) {
		b[i] = a[i] - a[i-1];
		g[i] = g[i-1] + b[i];
	}
	int k = 0, sum = 0;
	for(int i = 1; i <= n; i++) {
		sum += b[i] * (i - k);
		cnt++;
		while(sum > m) {
			k++;
			sum -= g[i] - g[k+1];
			cnt--;
		}
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
}
