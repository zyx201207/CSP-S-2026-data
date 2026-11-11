#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <map>

#define int long long

struct Node{
	int v, w;
};

int c, n, m, d, qq, dis[2000006], cnt = 0;
std::vector<Node> mp[2000006];
std::map<std::pair<int, int>, int> vis;

int dij(int s, int t){
	for(int i = 1;i <= cnt;i++)
		dis[i] = (int)2e18;
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
	q.push({0, s});
	dis[s] = 0;
	while(!q.empty()){
		int u = q.top().second, dd = q.top().first;
		q.pop();
		if(dd != dis[u])
			continue;
		for(Node it : mp[u]){
			int v = it.v, w = it.w;
			if(dis[v] > dd + w){
				dis[v] = dd + w;
				q.push({dis[v], v});
				if(v == t)
					return dis[t];
			}
		} 
	}
	return -1;
}

signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &qq);
	for(int i = 1;i <= m;i++){
		int w;
		scanf("%lld", &w);
		mp[i].push_back({m + i, w});
		mp[m + i].push_back({i, w});
	}
	cnt = m * 2;
	for(int i = 1;i <= n;i++){
		int k, vir = ++cnt;
		scanf("%lld", &k);
		for(int j = 1;j <= k;j++){
			int a, t;
			scanf("%lld%lld", &a, &t);
			int zhantai = ++cnt;
			mp[zhantai].push_back({vir, 0});
			mp[vir].push_back({zhantai, 0});
			mp[zhantai].push_back({a + m, t});
			mp[a + m].push_back({zhantai, t});
		}
	}
//	for(int i = 1;i <= cnt;i++){
//		printf("%lld : ", i);
//		for(Node it : mp[i])
//			printf("%lld ", it.v);
//		printf("\n");
//	}
	while(qq--){
		int u, v;
		scanf("%lld%lld", &u, &v);
		if(vis.count({std::min(u, v), std::max(u, v)})){
			printf("%lld\n", vis[{std::min(u, v), std::max(u, v)}]);
			continue;
		}
		int ans = dij(u, v);
		vis[{std::min(u, v), std::max(u, v)}] = ans;
		printf("%lld\n", ans);
	}
	return 0;
}