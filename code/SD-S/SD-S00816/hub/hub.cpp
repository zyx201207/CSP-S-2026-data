#include<bits/stdc++.h>
#define int long long
using namespace std;
int c, t, n, k, a[2000005], ans, vis[2000005];
vector<int> mp[2000005];
int cnt;
void bfs(int x) {
	queue<int> q;
	q.push(x);
	vis[x] = 1;
	while (q.size()) {
		int u = q.front();
		q.pop();
		if (cnt == k) {
			return ;
		}
		for (int v : mp[u]) {
			if (!vis[v]) {
				q.push(v);
				vis[v] = 1;
				cnt++;
			}
		}
	}
}
void solve() {
	int flag = 0;
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		mp[u].push_back(v);
		mp[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			cnt = 0;
			bfs(i);
			ans++;
		}
	}
	cout << ans / 2 << '\n'; 
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> c >> t;
	while (t--) {
		solve();
	}
	return 0;
}
