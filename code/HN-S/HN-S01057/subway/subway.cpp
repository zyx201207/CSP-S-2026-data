#include<bits/stdc++.h>
using namespace std;
using a2 = array<int, 2>;
int c, n, m, d, q, w[500001], k, a, t, x, y;
long long dis[501][501], ans;
vector<a2> s[500001];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(dis, 0x3f, sizeof(dis));
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for(int i = 1; i <= m; i++)scanf("%d", &w[i]);
	for(int i = 1; i <= n; i++){
		dis[i][i] = 0;
		scanf("%d", &k);
		for(int j = 1; j <= k; j++){
			scanf("%d%d", &a, &t);
			s[a].push_back({i, t});
		}
	}
	for(int i = 1; i <= m; i++){
		for(a2 a : s[i]){
			for(a2 b : s[i]){
				if(a[0] == b[0])continue;
				dis[a[0]][b[0]] = min(dis[a[0]][b[0]], (long long)a[1] + b[1]);
			}
		}
	}
	for(int k = 1; k <= n; k++)for(int i = 1; i <= n; i++)for(int j = 1; j <= n; j++)dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	while(q--){
		ans = 0x3f3f3f3f3f3f3f3fll;
		scanf("%d%d", &x, &y);
		for(a2 a : s[x]){
			for(a2 b : s[y]){
				ans = min(ans, dis[a[0]][b[0]] + a[1] + b[1]);
			}
		}
		printf("%lld\n", ans + w[x] + w[y]);
	}
	return 0;
}
