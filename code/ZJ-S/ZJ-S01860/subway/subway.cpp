#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 505;
const int MAXM = 500005;
const long long INF = 1e18;
int c, n, m, d, q;
int s[MAXN], w[MAXN], t[MAXN][MAXM];
ll dist[MAXN][MAXN];
vector<int> l[MAXM];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i != j){
				dist[i][j] = INF;
			}
		}
	}
	for(int i = 1; i <= m; i++){
		scanf("%lld", &w[i]);
	}
	for(int i = 1; i <= n; i++){
		scanf("%d", &s[i]);
		for(int j = 1, sta; j <= s[i]; j++){
			scanf("%d", &sta);
			scanf("%lld", &t[i][sta]);	
			for(auto it : l[sta]){
				if(i == it) continue;
				if(t[it][sta] == 0) continue;
				dist[i][it] = min(dist[i][it], 1ll*(t[i][sta] + t[it][sta]));
				dist[it][i] = min(dist[it][i], 1ll*(t[it][sta] + t[i][sta]));		
			}
			l[sta].push_back(i);
		}
	}
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(dist[i][j] > dist[i][k] + dist[k][j]){
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	while(q--){
		int x, y;
		ll ans = INF;
		scanf("%d%d", &x, &y);
		for(auto lx : l[x]){
			for(auto ly : l[y]){
				if((ll)t[lx][x] + dist[lx][ly] + (ll)t[ly][y] < ans){
					ans = (ll)t[lx][x] + dist[lx][ly] + (ll)t[ly][y];
				}
			}
		}
		printf("%lld\n", (ans + (ll)w[x] + (ll)w[y]));
	}
	return 0;	
}
