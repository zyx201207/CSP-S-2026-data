#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void FileIO(const char * inf, const char * ouf) {
	freopen(inf, "r", stdin);
	freopen(ouf, "w", stdout);
}

constexpr int MAXN = 1000010;

int n, k;
ll ans;
ll dis[1010][1010];
ll d2[1010];
vector<int> edges[MAXN];
bool vis[MAXN];

void dfs(int u, int S) {
	vis[u] = true;
	for (auto v: edges[u]) {
		if (S & (1<<(v-1))) {
			if (!vis[v])
				dfs(v, S);
		}
	}
}

void solve() {
	cin>>n>>k; 
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) dis[i][j] = 1<<30;
	for (int i=1;i<=n;i++) dis[i][i] = 0;
	for (int i=1;i<n;i++) {
		int u, v;
		cin>>u>>v;
		edges[u].push_back(v);
		edges[v].push_back(u);
		dis[u][v] = 1;
		dis[v][u] = 1;
	}
	for (int k=1;k<=n;k++) {
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++) {
				dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
			}
		}
	}
	
	ans = 1ll<<60;
	for (int S=0;S<(1<<n);S++) {
		if (__builtin_popcount(S) != k) continue;
		for (int i=1;i<=n;i++) vis[i] = false;
		int block_cnt=0;
		for (int i=1;block_cnt<=2&&i<=n;i++) {
			if (S & (1<<(i-1))) {
				if (!vis[i]) {
					dfs(i, S);
					block_cnt++;
				}
			}
		}
		if (block_cnt <= 2) {
			for (int i=1;i<=n;i++) d2[i] = 1ll<<60;
			for (int i=1;i<=n;i++) {
				if (!(S & (1<<(i-1)))) continue;
				for (int j=1;j<=n;j++) {
					d2[j] = min(d2[j], dis[i][j]);
					// cout<<dis[i][j]<<" \n"[j==n];
				}
			}
			ll pans = 0;
			for (int i=1;i<=n;i++) pans = max(pans, d2[i]);
			// cout<<S<<" "<<pans<<endl;
			// for (int i=1;i<=n;i++) cout<<d2[i]<<" \n"[i==n];
			ans = min(ans, pans);
		}
	}
	cout<<ans<<endl;
	for (int i=1;i<=n;i++) edges[i].clear(); // 多测不清空，爆零两行泪。 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	FileIO("hub.in", "hub.out");
	int c, T;
	cin>>c>>T;
	while (T--) solve(); 
	return 0;
}
