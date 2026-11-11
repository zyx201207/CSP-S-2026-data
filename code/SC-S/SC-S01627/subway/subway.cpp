#include<bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 505, M = 500050, D = 21;

struct node{
	int a, t;
};

int c, n, m, d, q, xr, yr;
int w[M], k, cnt[M];
node info[M][D];
ll e[N][N];

void init(){
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
			e[i][j] = 1e18;
	for(int i = 1; i <= n; i ++)
		e[i][i] = 0;
	for(int i = 1; i <= m; i ++){
		for(int j = 2; j <= cnt[i]; j ++){
			for(int k = 1; k < j; k ++){
				e[info[i][j].a][info[i][k].a] = min(e[info[i][j].a][info[i][k].a], (ll)info[i][j].t + info[i][k].t);
				e[info[i][k].a][info[i][j].a] = min(e[info[i][k].a][info[i][j].a], (ll)info[i][j].t + info[i][k].t);
			}
		}
	}
	for(int k = 1; k <= n; k ++)
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j ++)
				e[i][j] = min(e[i][j], e[i][k] + e[k][j]);
}

ll query(int a, int b){
	ll ans = 1e18;
	for(int i = 1; i <= cnt[a]; i ++)
		for(int j = 1; j <= cnt[b]; j ++)
			ans = min(ans, (ll)w[a] + w[b] + info[a][i].t + info[b][j].t + e[info[a][i].a][info[b][j].a]);
	return ans;
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for(int i = 1; i <= m; i ++)
		scanf("%d", &w[i]);
	for(int i = 1, k; i <= n; i ++){
		scanf("%d", &k);
		for(int j = 1, a, t; j <= k; j ++){
			scanf("%d%d", &a, &t);
			info[a][++ cnt[a]] = (node){i, t};
		}
	}
	init();
	while(q --){
		scanf("%d%d", &xr, &yr);
		printf("%lld\n", query(xr, yr));
	}
	return 0;
}