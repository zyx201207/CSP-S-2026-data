#include<bits/stdc++.h>
using namespace std;
const int maxn = 500 + 5;
const int maxm = 5e5 + 5;
const long long INF = 1e18 + 5;
const int maxk = 20 + 3;
long long e[maxn][maxn];
int w[maxm];
vector<int> din[maxm];
vector<int> dis[maxm];
int len[maxn];
int cnt[maxm];
void init(){
	for(int i = 0; i < maxn; i++){
		for(int j = 0; j < maxn; j++){
			e[i][j] = INF;
			if(i == j) e[i][j] = 0; 
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	init();
	int c, m, n, d, q;
	scanf("%d %d %d %d %d",&c, &n, &m, &d,&q);
	for(int i = 1; i <= m; i++){
		scanf("%d",&w[i]);
	}
	for(int i = 1; i <= n; i++){
		scanf("%d", &len[i]);
		int a, t;
		for(int j = 1; j <= len[i];j++){
			scanf("%d %d", &a, &t);
			if(cnt[a] == 0){
				din[a].push_back(0);
				dis[a].push_back(0);
			}
			++cnt[a];
			din[a].push_back(i);
			dis[a].push_back(t);
		}
	}
	for(int i = 1; i <= m; i++){
		for(int u = 1; u <= cnt[i]; u++){
			for(int v = u + 1; v <= cnt[i]; v++){
				int x = din[i][u], y = din[i][v];
				long long val = 1ll * dis[i][u] + dis[i][v];
				e[x][y] = e[y][x] = min(e[x][y], val);
			}
		}
		
	}
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				e[i][j] = min(e[i][k] + e[k][j],e[i][j]);
			}
		}
	}
	int x, y;
	for(int i = 1; i <= q; i++){
		scanf("%d %d", &x, &y);
		long long ans = INF;
		for(int u = 1; u <= cnt[x]; u++){
			for(int v = 1; v <= cnt[y]; v++){
				int l = din[x][u], r = din[y][v];
				long long val = dis[x][u] + dis[y][v];
				ans = min(ans,  e[l][r] + val);
			}
		}
		ans += 1ll * w[x] + w[y];
		printf("%lld\n",ans);
		
	}
	return 0;
}
