#include <bits/stdc++.h>
#define int long long 

using namespace std;

int c, t, n, d;
int dis[10001][10001];
bool mp[10001][10001];
int a[2000001];
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> c >> t;
	while(t--) {
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> a[i];
		map<pair<int, int>, bool> vis;
		memset(mp, 0, sizeof(mp));
		memset(dis, 0x3f, sizeof(dis));
		for(int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				if (abs(a[j] - a[i]) <= d) {
					mp[i][j] = 1;
					dis[i][j] = 1;
				}
			}
		}
		for(int k = 1; k <= n; k++) {
			for(int i = 1; i <= n; i++) {
				for(int j = 1; j <= n; j++) {
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
				}
			} 
		}
		int cnt = 0;
		for(int i = 1; i <= n; i++) {
			int j = i + 3;
			int s1 = -1, s2 = -1, s3 = -1, s4 = -1;
			if (mp[i][i + 1] && mp[i + 1][i + 2] && mp[i + 2][i + 3]) {
				s1 = 3;
			}
			if (mp[i][i + 1] && mp[i + 1][j]) s2 = 2;
			if (mp[i][i + 2] && mp[i + 2][i + 3]) s3 = 2;
			if (mp[i][j]) s4 = 1;
			if (s2 != -1 && s3 != -1 && dis[i][j] == 2) {
				vis[{i, j}] = 1;
				cnt++;
//				cout << i << " " << j << "\n";
			}
			
		}
		for(int j = n; j > 1; j--) {
			for(int i = n - 1; i >= 1; i--) {
				if (abs(i - j) == 1) {
					vis[{i, j}] = 0;
					continue;
				}
				if (vis[{i, j}]) continue;
				int book = 0;
				for(int k = i + 1; k < j; k++) {
					if (mp[i][k] && vis[{k, j}] && dis[i][k] + dis[k][j] == dis[i][j] || (vis[{i, k}] && mp[k][j] && dis[i][k] + dis[k][j] == dis[i][j])) {
						book += 1;
//						cout << i << " " << k << " " << j << "\n";
					}
				}
				if (book == 1) {
					cnt++;
					vis[{i, j}] = 1;
				}
			}
		}
		cout << cnt << "\n";
	}
	return 0;	
}