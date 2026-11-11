#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e6 + 10;

int c, t, n, vis[maxn];
ll d, x[maxn], cnt[maxn], dis[maxn], dist[300][300];

void dfs(int now, int s) {

	for (int nxt = 1; nxt <= n; nxt++) {
		if (vis[nxt]) continue;
		if (abs(x[nxt] - x[now]) <= d) {
			if (abs(x[now] - x[nxt]) && dis[now] < dis[nxt]) {
				dis[nxt] = dis[now] + 1;
				if (dis[nxt] == dist[s][nxt]) {
					cnt[nxt]++;
				}
				vis[nxt] = 1;
				dfs(nxt, s);
				vis[nxt] = 0;
			}
		}
	}
}


void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];	
	}	
	if (n <= 1e3) {
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = 2e18;
				if (i == j) dist[i][j] = 0;
				else if (abs(x[i] - x[j]) <= d) dist[i][j] = dist[j][i] = 1;
 			}
		}
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (dist[i][k] + dist[k][j] <= dist[i][j]) {
						dist[i][j] = dist[i][k] + dist[k][j];
					}
				}
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[j] = 2e18;
				vis[j] = 0;
				cnt[j] = 0;
			}
			vis[i] = 1;
			dis[i] = 0;
			dfs(i, i);
			for (int i =1; i <= n; i++) {
				if (cnt[i] == 2) ans++;
			}
		}

		cout << ans/2 << endl;
	} else {
		if (x[2]-x[1] > d) cout << 0 << endl;
		else if (n - (d/(x[2] - x[1])) * 2 + 1>0)cout << n - (d/(x[2] - x[1])) * 2 + 1 << endl;
		else cout << 0 << endl;	
	}

}
	
int main() { 
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	 
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> c >> t;
	for (int i = 1; i <= t; i++) solve();
	
	fclose(stdin);
	fclose(stdout);
	
	return 0; 
} 
