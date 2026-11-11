#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

#define int long long

int n, m, a[500005], dis[5005][5005], num[5005][5005];
std::vector<int> mp[500005];

signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	scanf("%lld%lld", &c, &t);
	while(t--){
		scanf("%lld%lld", &n, &m);
		for(int i = 1;i <= n;i++)
			scanf("%lld", &a[i]);
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++)
				dis[i][j] = (int)2e18, num[i][j] = 0;
			mp[i].clear();
			num[i][i] = 1;
		}
		for(int i = 1;i <= n;i++)
			for(int j = i + 1;j <= n;j++)
				if((int)std::abs(a[i] - a[j]) <= m){
					mp[i].push_back(j);
//					printf("%lld %lld\n", i, j);
				}
					
		std::priority_queue<std::pair<int, std::pair<int, int>>, std::vector<std::pair<int, std::pair<int, int>>>, std::greater<std::pair<int, std::pair<int, int>>>> q;
		for(int i = 1;i <= n;i++)
			q.push({0, {i, i}});
		int cnt = 0;
		while(!q.empty()){
			int d = q.top().first, u = q.top().second.first, p = q.top().second.second;
			q.pop();
			if(dis[p][u] != d)
				continue;
			for(int v : mp[u]){
				if(dis[p][v] > d + 1){
					dis[p][v] = d + 1;
					num[p][v] = num[p][u];
					q.push({dis[p][v], {v, p}});
//					if(p == 1)
//						printf("%lld %lld\n", u, v);
				}
				else if(dis[p][v] == d + 1){
					num[p][v] += num[p][u];
//					if(p == 1)
//						printf("%lld %lld\n", cnt, v);
				}
			}
		}
		int ans = 0;
		for(int i = 1;i <= n;i++)
			for(int j = i + 1;j <= n;j++){
				ans += (num[i][j] == 2);
//				if(num[i][j] == 2)
//					printf("%lld %lld %lld\n", i, j, dis[i][j]);
			}
		printf("%lld\n", ans);
	}
	return 0;
}