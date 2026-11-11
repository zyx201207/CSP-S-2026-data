#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 20;
int c, t, n, k, dis[N], now, ans, top[N];
bool ck[N], tag[N];
vector<int> e[N];

void dfs1(int u, int fa){
	if(!ck[fa] && ck[u]) top[u] = u;
	if(ck[fa] && ck[u]) top[u] = top[fa];
	for(int v : e[u]){
		if(v == fa) continue;
		dfs1(v, u);
	}
	return ;
}

void dfs2(int u, int fa){
	dis[u] = dis[fa] + 1;
	if(ck[u]) dis[u] = 0;
	for(int v : e[u]){
		if(v == fa) continue;
		dfs2(v, u);
		dis[u] = min(dis[u], dis[v] + 1);
	}
	now = max(now, dis[u]);
	return ;
}

signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while(t --){
		ans = 1e18;
		cin >> n >> k;
		for(int i = 1; i <= n; i++) e[i].clear();
		for(int i = 1, u, v; i < n; i++){
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dis[0] = 1e18;
		for(int i = 0, cnt; i < (1 << n); i++){
			cnt = 0;
			for(int j = 1; j <= n; j++) ck[j] = false;
			for(int j = 1; j <= n; j++){
				if((i >> (j - 1)) & 1){
					ck[j] = true;
					cnt ++;
				}
			}
			if(cnt != k) continue;
			dfs1(1, 0);
			for(int j = 1; j <= n; j++) tag[j] = false;
			for(int j = 1; j <= n; j++){
				if((i >> (j - 1)) & 1) tag[top[j]] = true;
			}
			cnt = 0;
			for(int j = 1; j <= n; j++){
				if(tag[j]) cnt ++;
			}
			if(cnt != 2) continue;
			now = 0;
			dfs2(1, 0);
			ans = min(ans, now);
		}
		cout << ans << endl;
	}
	return 0;
}