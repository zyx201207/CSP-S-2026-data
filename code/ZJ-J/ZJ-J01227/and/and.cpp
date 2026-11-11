#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 7;
int n, k, ans;
int a[N], mi[N], vis[N];
map<int, bool> ma;
bool cmp(int a, int b) {
	return a > b;
}
int f(int x, int k) {
	return (x >> (k - 1)) & 1;
}
void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n, cmp);
	ans = 0;
	int t = k;
	for (int i = 30; i >= 0; i--) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (f(a[j], i + 1) == 0) continue;
			if (vis[j] == 1) cnt++;
		}
		if (cnt >= k) ans += (1 << i);
		else {
			if (t <= 0) continue;
			int sheng = k - cnt;
			bool flag = 0;
			int tot = 0;
			for (int j = 1; j <= n; j++) {
				if (f(a[j], i + 1) == 0) continue;
				if (tot == sheng) {
					flag = 1;
					break;
				}
				tot++;
				vis[j] = 1;
			}
			if (flag == 1) ans += (1 << i), t -= sheng;
		}
	}
	cout << ans;
}
signed main() {
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int T = 1;
//	cin >> T;
	while (T--) solve();
	return 0;
}
