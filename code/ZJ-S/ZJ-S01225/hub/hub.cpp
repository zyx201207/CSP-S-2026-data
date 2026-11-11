#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <map>

#define int long long

int n, k, vis[2000006], ans = (int)2e18, dis[2000006];
std::vector<int> mp[2000006];

void dij2(int s){
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
	q.push({0, s});
	dis[s] = 0;
	while(!q.empty()){
		int u = q.top().second, dd = q.top().first;
		q.pop();
		if(dd != dis[u])
			continue;
		for(int it : mp[u]){
			int v = it, w = 1;
			if(dis[v] > dd + w and vis[v]){
				dis[v] = dd + w;
				q.push({dis[v], v});
			}
		}
	}
}

void dij(int s){
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
	q.push({0, s});
	dis[s] = 0;
	while(!q.empty()){
		int u = q.top().second, dd = q.top().first;
		q.pop();
		if(dd != dis[u])
			continue;
		for(int it : mp[u]){
			int v = it, w = 1;
			if(dis[v] > dd + w){
				dis[v] = dd + w;
				q.push({dis[v], v});
			}
		}
	}
}

signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	scanf("%lld%lld", &c, &t);
	while(t--){
		scanf("%lld%lld", &n, &k);
		for(int i = 1;i <= n;i++)
			mp[i].clear();
		for(int i = 1;i < n;i++){
			int u, v;
			scanf("%lld%lld", &u, &v);
			mp[u].push_back(v);
			mp[v].push_back(u);
		}
		ans = (int)2e18;
		for(int s = 0;s < (1 << n);s++){
			int num = 0;
			for(int i = 0;i < n;i++)
				num += ((s >> i) & 1);
			if(num != k)
				continue;
			for(int i = 1;i <= n;i++)
				dis[i] = (int)2e18;
			for(int i = 0;i < n;i++)
				vis[i + 1] = ((s >> i) & 1);
			int cnt = 0;
			for(int i = 1;i <= n;i++){
				if(vis[i] and dis[i] >= (int)1e18){
					if(cnt == 2){
						cnt = 555;
						break;
					}
					dij2(i);
					cnt++;
				}
			}
			if(cnt > 2)
				continue;
			int tmp = 0;
			for(int i = 1;i <= n;i++){
				for(int j = 1;j <= n;j++)
					dis[j] = (int)2e18;
				dij(i);
				int tmpp = (int)2e18;
				for(int i = 1;i <= n;i++)
					if(vis[i])
						tmpp = std::min(tmpp, dis[i]);
				tmp = std::max(tmpp, tmp);
			}
			ans = std::min(ans, tmp);
//			printf("%lld %lld %lld\n", t, s, tmp);
		}
		printf("%lld\n", ans);
	}
	return 0;
}