#include<bits/stdc++.h>
using namespace std;
const long long inf = LONG_LONG_MAX/3;
struct node{
	long long idx, tim;
} ;
long long c, n, m, q, w[1000010], d[510][510];
vector<node> g[1000010];
long long query(long long x, long long y){
	long long res = inf;
	for(long long i = 0; i < g[x].size(); i++){
		for(long long j = 0; j < g[y].size(); j++){
			res = min(res, g[x][i].tim + w[x] + d[g[x][i].idx][g[y][j].idx] + g[y][j].tim + w[y]);
			//printf("%lld %lld %lld\n", g[x][i].idx, d[g[x][i].idx][g[y][i].idx], g[y][j].idx);
		}
	}
	return res;
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
	for(long long i = 1; i <= m; i++){
		scanf("%lld", &w[i]);
	}
	for(long long i = 1; i <= n; i++){
		long long k;
		scanf("%lld", &k);
		for(long long j = 1; j <= k; j++){
			long long _, __;
			scanf("%lld%lld", &_, &__);
			g[_].push_back(node{i, __});
		}
	}
	for(long long i = 1; i <= n; i++){
		for(long long j = 1; j <= n; j++){
			d[i][j] = inf;
		}
		d[i][i] = 0;
	}
	for(long long i = 1; i <= m; i++){
		for(long long j = 0; j < g[i].size(); j++){
			for(long long k1 = 0; k1 <= j; k1++){
				d[g[i][k1].idx][g[i][j].idx] = d[g[i][j].idx][g[i][k1].idx] = min(d[g[i][j].idx][g[i][k1].idx], g[i][j].tim + g[i][k1].tim);
			}
		}
	}
	for(long long i = 1; i <= n; i++){
		for(long long k = 1; k <= n; k++){
			for(long long j = 1; j <= n; j++){
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}/*
	for(long long i = 1; i <= n; i++){
		for(long long j = 1; j <= n; j++){
			printf("%lld ", d[i][j]);
		}
		printf("\n");
	}
	printf("\n");*/
	while(q--){
		long long x, y;
		scanf("%lld%lld", &x, &y);
		printf("%lld\n", query(x, y));
	}
	return 0;
}
/*
在 17:55 打暴力时发现题目看错，看成要算坐地铁时间（不知道怎么看错的） 
在 18:16 通过全部大样例 
我们从地狱回来了！ 
*/
