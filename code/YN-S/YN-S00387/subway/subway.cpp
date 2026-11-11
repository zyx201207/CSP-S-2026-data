#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int c, n, m, d, q, t[100000], t2[1001][1001], k, x, y;
int arr[1000000], cnt, ans, now;
bool huan = false;

void dfs(int x) {
	if (x == y) {
		cnt += t2[x][now] + t[x];
		ans = max(cnt, ans);
	}
	for (int i = 1; i <= 2; i++) {
		if (i == 1) {
			for (int j = x; j <= m; j++) {
				if (t2[j][now] != 0 && arr[j] == 0) {
					arr[j] = 1;
					dfs(j);
				}
			}
		}
		if (i == 2) {
			for (int i = 1; i <= n; i++) {
				if (t2[x][i] != 0) {
					cnt += t2[x][now] + t2[x][i];
					now = i;
					huan = true;
					dfs(x);
				}
			}
		}
	}
	if (huan == true) {
		for (int i = now; i >= 1; i--) {
			if (t2[x][i] != 0) {
				cnt -= t2[x][now] + t2[x][i];
				now = i;
				huan = false;
			}
		}
	}
	return;
}

signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> t[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int g;
			cin >> g;
			cin >> t2[i][g];
		}
	}
	while (q--) {
		cin >> x >> y;
		ans = 0;
		huan = false;
		cnt = t[x];
		for (int i = 1; i <= m; i++) {
			if (t2[x][i] != 0) {
				now = i;
				break;
			}
		}
		dfs(x);
		cout << ans << endl;
	}
	return 0;
}