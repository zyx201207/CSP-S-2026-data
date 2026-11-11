#include<bits/stdc++.h>
using namespace std;
long long c, n, m, d, q, ans;
long long w[500010], k[510], t[510][500010], a[510][500010];
bool vis[500010], b[500010][30];
void dfs(long long s, long long e, long long now, long long time){
	if(vis[now]) return;
	if(now == e){
		ans = min(ans, time);
		return;
	}
	vis[now] = 1;
	for(int i = 1; i <= d; i++){
		if(b[now][d]){
			for(int j = 1; j <= k[b[now][d]]; j++){
				dfs(s, e, a[b[now][d]][j], time + t[b[now][d]][j]);
			}
		}
	}
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
	for(int i = 1; i <= m; i++){
		scanf("%lld", &w[i]);
	}
	for(int i = 1; i <= n; i++){
		scanf("%lld", &k[i]);
		for(int j = 1; j <= k[i]; j++){
			scanf("%lld%lld", &a[i][j], &t[i][j]);
			a[t[i][j]][i] = 1;
		}
	}
	for(int i = 1; i <= q; i++){
		int s, e;
		ans = INT_MAX;
		scanf("%lld%lld", &s, &e);
		dfs(s, e, s, w[s] + w[e]);
		printf("%lld\n", ans);
	}
	return 0;
}
