#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n,d,p,m,c,q;
const ll N = 5e5 + 5,INF = 1e18;
ll w[N]; // 表示地铁站的地铁口到站厅需要的时间
ll t[N]; // 站台走到站厅的时间
int a[N]; // 经过的站点
ll dp[2005][2005];
int f[2005][2005];
struct cyy{
	ll t;
	int e;
};
vector <cyy> v[N + 1000];


void solve(){
	if(n == 1){
		while(q --){
			int x,y;
			scanf("%d%d",&x,&y);
			printf("%lld\n",t[x] + t[y] + w[x] + w[y]);
		}
	}else{
		ll cnt = INF;
		for(int i = 1; i <= n; ++ i){
			if(v[i + m].size() == 2){
				cnt = min(cnt, dp[v[i + m][0].e][i + m] + dp[v[i + m][1].e][i + m]);
			}
		}
		while(q -- ){
			int x,y;
			scanf("%d%d",&x,&y);
			printf("%lld\n",cnt + w[x] + w[y]);
		}
	}
	return;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; ++ i){
		scanf("%lld",&w[i]);
	}
	for(int i = 1; i <= m + n; ++ i){
		for(int j = 1; j <= m + n; ++ j){
			dp[i][j] = INF;
			if(i == j){
				dp[i][j] = 0;
			}
		}
	}
	for(int i = 1; i <= n; ++ i){
		int k;
		scanf("%d",&k);
		for(int j = 1; j <= k; ++ j){
			scanf("%d",&a[i]);
			scanf("%lld",&t[i]);
			v[a[i]].push_back({t[i],i + m});
			dp[a[i]][i + m] = t[i];
			v[i + m].push_back({t[i],a[i]});
			dp[i + m][a[i]] = t[i];
			
		}
	}
//	for(int i = 0; i <= m + n; ++ i){
//		printf("%d ",i);
//	}
//	printf("\n");
//	for(int i = 1; i <= m + n; ++ i){
//		printf("%d ",i);
//		for(int j = 1; j <= m + n; ++ j){
//			printf("%lld ",dp[i][j] == INF ? 0 : dp[i][j]);
//		}printf("\n");
//	}
	// 单源最短路径
	if(n <= 1) {
		solve();
		return 0;
	}
	for(int k = 1; k <= m + n; ++ k){
		for(int j = 1; j <= n + m; ++ j){
			for(int i = 1; i <= n + m; ++ i){
				dp[i][j] = min(dp[i][k] + dp[k][j], dp[i][j]);
			}
		}
	}
//	for(int i = 0; i <= m + n; ++ i){
//		printf("%d ",i);
//	}
//	printf("\n");
//	for(int i = 1; i <= m + n; ++ i){
//		printf("%d ",i);
//		for(int j = 1; j <= m + n; ++ j){
//			printf("%lld ",dp[i][j] == INF ? 0 : dp[i][j]);
//		}printf("\n");
//	}
	while(q -- ){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%lld\n",dp[x][y] + w[x] + w[y]);
	}
	return 0;
}