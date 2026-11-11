#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 507, M = 5e5 + 7, K = 205 + 7;
int n, m, c, d, q, ans = 1e9 + 7;
int w[N], a[M], t[M], b[M];
struct Stu{
	int num, to[K], t[K];
}f[M];
void dfs(int x, int y, int cost){
	if(x == y){
		ans = min(ans, cost + w[y]);
		return ;
	}
	for(int i = 1;i <= f[x].num; i++)
		if(f[x].to[i] > 0 && b[f[x].to[i]] == 0){
			int go = f[x].to[i];
			b[go] = -1;
			dfs(go, y, cost + f[x].t[i]);
			b[go] = 0;
		}
	return ;
}
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
	for(int i = 1;i <= m; i++)
		scanf("%lld", &w[i]);
	for(int i = 1;i <= n; i++){
		int ct = 0, ra, rt;
		scanf("%lld", &ct);
		for(int j = 1;j <= ct; j++)
			scanf("%lld%lld", &a[j], &t[j]);
		for(int i = 1;i <= ct; i++)
			for(int j = 1;j <= ct; j++)
				if(i != j){
					int ra = a[i], rt = t[i], a2 = a[j], t2 = t[j];
					int p = f[ra].num + 1;
					f[ra].num ++;
					f[ra].to[p] = a2;
					f[ra].t[p] = t2 + rt;
				}
	}
	while(q --){
		int x, y;
		scanf("%lld%lld", &x, &y);
		b[x] = -1;
		dfs(x, y, w[x]);
		printf("%lld\n", ans);
		b[x] = 0;
	}
	return 0;
}
