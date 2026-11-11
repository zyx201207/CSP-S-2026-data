#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 5;
int n, m;
int a[N], b[N];
int ans;
int timer = 0, g[N];

signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i ++) {
		b[i] = a[i] - a[i - 1];
		if (b[i] != 0) {
			timer ++;
			g[timer] = i;
		}
	}
	for (int i = timer + 1; i >= 2; i --) g[i] = g[i - 1];
	g[1] = 1;
	g[timer + 2] = n + 1;
	for (int i = timer + 1; i >= 1; i --) {
		int t = i - 1, cnt = 0;
		int sum = 0;
		while (t >= 1) {
			if (sum + (g[t + 1] - g[t]) * (a[g[i]] - a[g[t]]) <= m) {
				sum += (g[t + 1] - g[t]) * (a[g[i]] - a[g[t]]);
				cnt = g[i + 1] - g[t];
			}
			else {
				cnt += (m - sum) / (a[g[i]] - a[g[t]]);
				sum += (m - sum) / (a[g[i]] - a[g[t]]) * (a[g[i]] - a[g[t]]);
				break;
			}
			t--;
		}
		if (cnt == 0) cnt = 1;
		if (ans < cnt) {
			ans = max(ans, cnt);
		}
	}
	cout << ans << "\n";
	return 0;
}
