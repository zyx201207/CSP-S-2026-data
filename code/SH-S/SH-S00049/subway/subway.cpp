#include <bits/stdc++.h>
using namespace std;
#define int long long
int c, n, m, d, q, w[514514], kk, dis[514][514], u, v, ans, lin[514514][25], cnt[514514];
map <pair <int, int>, int> mp, t;
void pre(){
	for(int i = 1; i <= 513; i++){
		for(int j = 1; j <= 513; j++){
			if(i == j) continue;
			dis[i][j] = 1145141919810114514;
		}
	}
}
void input(){
	scanf("%lld %lld %lld %lld %lld", &c, &n, &m, &d, &q);
	for(int i = 1; i <= m; i++){
		scanf("%lld", &w[i]);
	}
	for(int i = 1; i <= n; i++){
		scanf("%lld", &kk);
		for(int j = 1; j <= kk; j++){
			scanf("%lld", &u);
			lin[u][++cnt[u]] = i;
			scanf("%lld", &t[{i, u}]);
			mp[{i, u}] = 1145141919810;
		}
	}
}
void getdis(){
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= cnt[i]; j++){
			for(int k = j + 1; k <= cnt[i]; k++){
				dis[lin[i][j]][lin[i][k]] = min(dis[lin[i][j]][lin[i][k]], t[{lin[i][j], i}] + t[{lin[i][k], i}]);
				dis[lin[i][k]][lin[i][j]] = min(dis[lin[i][k]][lin[i][j]], dis[lin[i][j]][lin[i][k]]);
			}
		}
	}
}
void floyd(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			for(int k = n; k; k--){
				dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);
			}
		}
	}
}
void output(){
	while(q--){
		scanf("%lld %lld", &u, &v);
		ans = 1145141919810114514;
		for(int i = 1; i <= cnt[u]; i++){
			for(int j = 1; j <= cnt[v]; j++){
				ans = min(ans, dis[lin[u][i]][lin[v][j]] + t[{lin[u][i], u}] + t[{lin[v][j], v}]);
			}
		}
		ans += w[u] + w[v];
		printf("%lld\n", ans);
	}
}
signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	pre();
	input(); 
	getdis();
	floyd();
	output();
	return 0;
}
