#include <queue>
#include <cstdio>
#define N 510
#define M (int(5e5 + 10))
#define INF (0x3f3f3f3f3f3f3f3f)
#define min(a, b) (((a) < (b)) ? (a) : (b))

using std::queue;
using std::vector;

struct pii{
	int id;
	long long val;
};
vector<pii> point[M];
long long dis[N][N], w[M], tmp2, ans;
int cnt[N], c, n, m, d, Q, k, tmp1, size, i, j;

//long long min(long long a, long long b){
//	return a < b ? a : b;
//}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &Q);
	for(i = 1; i <= m; i ++)
		scanf("%lld", w + i);
	for(i = 1; i <= n; i ++){
		scanf("%d", &k);
		for(j = 1; j <= k; j ++)
			scanf("%d%lld", &tmp1, &tmp2), 
			point[tmp1].push_back(pii{i, tmp2});
		for(j = 1; j <= n; j ++)
			if(i != j)
				dis[i][j] = INF;
	}
	for(i = 1; i <= m; i ++){
		size = point[i].size();
		for(j = 0; j < size; j ++)
			for(k = j + 1; k < size; k ++)
				tmp1 = point[i][j].id, tmp2 = point[i][k].id,
				dis[tmp1][tmp2] = dis[tmp2][tmp1]
				 = point[i][j].val + point[i][k].val;
	}
//	for(i = 1; i <= n; i ++)
//		for(j = 1; j <= n; j ++)
//			if(i != j && dis[i][j] != INF)
//				e[i].push_back(j);
//	for(i = 1; i <= n; i ++){
//		for(j = 1; j <= n; j ++)
//			in[j] = false, cnt[j] = 0;
//		q.push(i);
//		while(q.size()){
//			int u = q.front(); q.pop(), in[u] = false, cnt[u] ++;
//			if(cnt[u] > n)
//				continue;
//			for(auto v : e[u])
//				if(dis[i][v] > dis[i][u] + dis[u][v] && not in[v]){
//					dis[i][v] = dis[i][u] + dis[u][v];
//					if(cnt[v] <= n)
//						q.push(v), in[v] = true;
//				}
//		}
//	}
	for(k = 1; k <= n; k ++)
		for(i = 1; i <= n; i ++)
			if(k != i && dis[i][k] != INF)
				for(j = 1; j <= n; j ++)
					if(k != j && i != j)
						dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	while(Q --){
		scanf("%d%lld", &tmp1, &tmp2), ans = INF;
		for(auto i : point[tmp1])
			for(auto j : point[tmp2])
				ans = min(ans, dis[i.id][j.id] + i.val +j.val);
		printf("%lld\n", ans + w[tmp1] + w[tmp2]);
	}
	return 0;
}
/*
##################################
######## more slowly code ########
##################################

#include <queue>
#include <cstdio>
#define D 23
#define N 510
#define M (int(5e5 + 10))
#define INF (0x3f3f3f3f3f3f3f3f)
//#define min(a, b) (((a) < (b)) ? (a) : (b))

using std::queue;
using std::vector;

struct pii{
	int id;
	long long val;
}point[M][D], _, __;
long long dis[N][N], w[M], tmp2, ans;
int cnt[N], top[M], c, n, m, d, Q, k, tmp1, size, i, j;

long long min(long long a, long long b){
	return a < b ? a : b;
}

int main(){
	freopen("subway7.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &Q);
	for(i = 1; i <= m; i ++)
		scanf("%lld", w + i);
	for(i = 1; i <= n; i ++){
		scanf("%d", &k);
		for(j = 1; j <= k; j ++)
			scanf("%d%lld", &tmp1, &tmp2), 
			point[tmp1][++ top[tmp1]] = pii{i, tmp2};
		for(j = i + 1; j <= n; j ++)
			dis[i][j] = dis[j][i] = INF;
	}
	for(i = 1; i <= m; i ++)
		for(j = 1; j <= top[i]; j ++)
			for(k = j + 1; k <= top[i]; k ++)
				tmp1 = point[i][j].id, tmp2 = point[i][k].id,
				dis[tmp1][tmp2] = dis[tmp2][tmp1]
				 = point[i][j].val + point[i][k].val;
//	for(i = 1; i <= n; i ++)
//		for(j = 1; j <= n; j ++)
//			if(i != j && dis[i][j] != INF)
//				e[i].push_back(j);
//	for(i = 1; i <= n; i ++){
//		for(j = 1; j <= n; j ++)
//			in[j] = false, cnt[j] = 0;
//		q.push(i);
//		while(q.size()){
//			int u = q.front(); q.pop(), in[u] = false, cnt[u] ++;
//			if(cnt[u] > n)
//				continue;
//			for(auto v : e[u])
//				if(dis[i][v] > dis[i][u] + dis[u][v] && not in[v]){
//					dis[i][v] = dis[i][u] + dis[u][v];
//					if(cnt[v] <= n)
//						q.push(v), in[v] = true;
//				}
//		}
//	}
	for(k = 1; k <= n; k ++)
		for(i = 1; i <= n; i ++)
			if(k != i && dis[i][k] != INF)
				for(j = 1; j <= n; j ++)
					if(k != j && i != j)
						dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	while(Q --){
		scanf("%d%lld", &tmp1, &tmp2), ans = INF;
		for(i = 1; i <= top[tmp1]; i ++)
			for(j = 1; j <= top[tmp2]; j ++)
				_ = point[tmp1][i], __ = point[tmp2][j],
				ans = min(ans, dis[_.id][__.id] + _.val + __.val);
		printf("%lld\n", ans + w[tmp1] + w[tmp2]);
	}
	return 0;
}
*/