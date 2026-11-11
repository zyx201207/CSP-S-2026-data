#include <bits/stdc++.h>
using namespace std;
int ans, a[100005], cnt[100005], dis[100005], vis[100005];
vector <int> v[100005];
struct node {
	int id, w;
	bool operator < (const node &a) const {
		return w > a.w;
	}
};
map <int, bool> mp;
void Dijk(int x) {
	memset(cnt, 0, sizeof cnt);
	memset(dis, 0x3f, sizeof dis);
	memset(vis, 0, sizeof vis);
	priority_queue <node> q;
	q.push({x, 0});
	dis[x] = 0;
	while(!q.empty()) {
		int t = q.top().id;
		q.pop();
		if(vis[t]) continue;
		vis[t] = 1;
		for(int j = 0; j < v[t].size(); j++) {
			int i = v[t][j];
			if(dis[i] > dis[t] + 1) {
				dis[i] = dis[t] + 1;
				q.push({i, dis[i]});
			} else if(dis[i] == dis[t] + 1) {
				cnt[i]++;
				if(cnt[i] == 1) ans++;
				if(cnt[i] == 2) ans--;
			}
		}
	}
	return ;
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int c, t;
	cin >> c >> t;
	while(t--) {
		int n, d;
		cin >> n >> d;
		mp.clear();
		int minn = 1000000000;
		for(int i = 1; i <= n; i++) cin >> a[i], minn = min(minn, a[i]);
		if(minn <= 0) for(int i = 1; i <= n; i++) a[i] -= minn - 1;
		for(int i = 1; i <= n; i++) mp[a[i]] = 1;
		for(int i = 1; i <= n; i++) {
			v[i].clear();
			for(int j = 1; j <= d; j++) if(mp.count(i + j)) v[i].push_back(i + j);
		}
		ans = 0;
		for(int i = 1; i <= n; i++) Dijk(i);
		cout << ans << "\n";
	}
	return 0;
}
