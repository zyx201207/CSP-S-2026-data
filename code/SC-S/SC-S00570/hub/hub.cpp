#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c, t;
const int N = 2e6+5;
vector<int> G[N];
int k, n, u, v;
int lt[N], sh, vis[N],slt;
int dfs(int x, int sc, int mc) {
	if (G[x].size() == 1) {
		return 0;
	}
	int ds = 0;
	for (int i = 0; i < G[x].size(); i++) {
		if (!vis[G[x][i]]) {
			vis[G[x][i]] = 1;
			ds = max(ds,dfs(G[x][i], sc + 1, mc)) + 1;
		}
		vis[G[x][i]] = 0;
	}
	if(ds > mc){
		sh++;
		lt[x] = 1;
		ds = 0;
	}
	return ds;
}
void dfs1(int x, int fa) {
	if (G[x].size() == 1) {
		return ;
	}
	int ds = 0;
	for (int i = 0; i < G[x].size(); i++) {
		if (!vis[G[x][i]]) {
			vis[G[x][i]] = 1;
			dfs1(G[x][i], x);
		}
		vis[G[x][i]] = 0;
	}
	if(lt[x] && lt[fa]){
		slt--;
	}
}
bool check(int d, int x) {
	memset(vis,0,sizeof vis);
	memset(lt,0,sizeof lt);
	slt = 0;
	sh = 0;
	dfs(x, 0, d);
	if (sh > k) {
		return 0;
	} else {
		slt = sh;
		if (slt <= 2 || k >= (slt-2) * (d-1)) {
			return 1;
		}
	}
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout); //一定要删注释
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while (t--) {
		cin >> n >> k;
		for(int i=1;i<=n;i++){
			G[i].clear();
		}
		if (k == n) {
			cout << 0 << "\n";
			continue;
		}
		for (int i = 1; i < n; i++) {
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		int l = 1, r = n;
		int ans = 1e9;
		while (l <= r) {
			if (l == r) {
				ans = min(ans, l);
				break;
			}
			int mid = (l + r) >> 1;
			if (check(mid, 1)) {
				l = mid + 1;
				ans = min(ans, mid);
			} else {
				r = mid - 1;
			}
		}
		cout << ans << "\n";
	}

	return 0;
}