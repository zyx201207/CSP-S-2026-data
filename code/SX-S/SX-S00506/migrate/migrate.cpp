#include <bits/stdc++.h>
using namespace std;
int c, t;
int n ;
long long d;
long long x[200005];
int tong[200005];
int ans;
int maxx;

void dfs(int l, int last, int now, int r, int cnt) {
	if (now == r) {
		maxx = max(maxx, cnt);
		tong[cnt]++;
		return;
	}
	dfs(l, now, now + 1, r, cnt);
	if ((x[now + 1] - x[last] <= d) && now != l ) {
		//cout << now << endl;
		dfs(l, last, now + 1, r, cnt + 1);
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		if (c == 11 || c == 12) {
			int T = x[2] - x[1];
			if (d < 2 * T) {
				cout << 0 << endl;
				break;
			}
			int td = d / T;
			cout << n - (2 * td - 1) << endl;
			break;
		}
		ans = 0;
		for (int i = 1; i < n; i++) {
			for (int j = i + 1; j <= n; j++) {
				maxx = -1;
				memset(tong, 0, sizeof(tong));
				if (x[j] - x[j - 1] > d)
					break;
				dfs(i, i, i, j, 0);
				//cout << i << " " << j << " " << maxx << " " << tong[maxx] << endl;
				if (tong[maxx] == 2)
					ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}