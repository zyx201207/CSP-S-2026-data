#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5 + 10;
ll c, n, m, d, q;
ll w[maxn],k[maxn], mp[30][maxn], t[30][maxn];

ll ans = 2e18, tmp = 0;
ll vis[maxn];

void dfs(int s, int e, int now) {
	if (e == now) ans = min(ans, tmp);
	for (int i = 1; i <= d; i++) {
		if (mp[i][now] == 1) {
			for (int j = 1; j <= n; j++) {
					if(vis[j]) continue;
					vis[j] = 1;
					tmp = tmp + t[i][i] + t[i][j];
					dfs(s, e, j);
					vis[j] = 0;
					tmp = tmp + t[i][i] + t[i][j];
				}
			}
		}
	}	


void solve() {
	int x, y;
	cin >> x >> y;
	tmp = 0;
	ans = 2e18;
	for (int i = 1; i <= n; i++) vis[i] = 0;
	
	dfs(x, y, x);
	cout << ans + w[x] + w[y] << endl;
}
int main() { 
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	 
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
		
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			int ta, tt;
			cin >> ta >> tt;
			mp[ta][i] = 1;
			t[ta][i] = tt;
		}
	}
	
	for (int i = 1; i <= n; i++) solve();
	fclose(stdin);
	fclose(stdout);
} 
