#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define int long long
const int MAXN = 2e5 + 10;
int a[MAXN];
bool vis[MAXN];
int n, m, ans;

bool cmp(int x, int y) {
	return x > y;
}
int cnt;

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	ans = a[1];
	for (int i = 1; i <= m; i++) {
		if (ans & a[i] != 0) {
			ans &= a[i];
			cnt++;
			vis[i] = 1;
		}
	}
	//cout << m << " " <<  cnt << endl;
	if (cnt < m) {
		for (int i = 1; i <= m; i++) {
			if (!vis[i]) {
				if (ans & a[i] != 0)
					ans &= a[i];
				cnt++;
			}
			if (cnt == m)
				break;
		}
	}
	cout << ans;

	return 0;
}