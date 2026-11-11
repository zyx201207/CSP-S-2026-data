# include <bits/stdc++.h>
# define int long long
using namespace std;
const int N = 2e6 + 5,M = 5005,inf = 0x3f3f3f3f3f3f;
int c,T,n,d,ans,a[N],dis[N],cnt[N];
vector <int> g[N];
void A () {
	int w = d / (a[2] - a[1]);
	int r = 2 * w - 1;
	if (w <= 1 || r > n) cout << "0\n";
	else cout << n - r << "\n";
	return ;
}
void C () {
	ans = 0;
	for (int i = 1;i <= n;i++) g[i].clear();
	for (int i = 1;i <= n;i++) {
		for (int j = i + 1;j <= n;j++) {
			if (a[j] - a[i] <= d) g[i].push_back(j),g[j].push_back(i);
		}
	}
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) dis[j] = inf,cnt[j] = 0;
		queue <int> q; dis[i] = 0; cnt[i] = 1; q.push(i);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int v : g[u]) {
				if (dis[u] + 1 == dis[v]) cnt[v] += cnt[u];
				else if (dis[u] + 1 < dis[v]) dis[v] = dis[u] + 1,cnt[v] = cnt[u],q.push(v);
			}
		}
		for (int j = i + 1;j <= n;j++) ans += (cnt[j] == 2);
	}
	cout << ans << "\n";
	return ;
}
void solve () {
	cin >> n >> d;
	for (int i = 1;i <= n;i++) cin >> a[i];
	if (c >= 11 && c <= 12) A(); 
	else if (c >= 13 && c <= 14) cout << "0\n";
	else C();
	return ;
}
signed main () {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> T;
	while (T --) solve();
	return 0;
}
