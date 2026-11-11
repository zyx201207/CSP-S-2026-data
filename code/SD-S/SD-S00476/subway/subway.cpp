// (1<=s<=n):A
// (1<=) 
#include <bits/stdc++.h>
#define ll long long

const int N = 550;
const int M = 600100;
int testid , n , m , d , q;
ll w[M];
ll dist[N][N];
std::vector<std::pair<int,ll>> edg[M];
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &testid , &n, &m, &d, &q);
	for(int i = 1;  i <= m ; ++ i){
		scanf("%lld", &w[i]);
	}
	for(int i = 1 ; i <= n ; ++ i){
		int k ; scanf("%d", &k);
		while(k --){
			// i + m
			int x ; scanf("%d" ,&x);
			ll v ; scanf("%lld", &v);
			edg[i + m].push_back({x , v});
			edg[x].push_back({i + m ,v});
		}
	}
	memset(dist , 0x7f , sizeof dist);
	for(int i = 1 ; i <= n ; ++ i)dist[i][i]=0ll;
	for(int st = m + 1 ; st <= m + n ; ++ st){
		for(auto it : edg[st]){
			for(auto ed : edg[it.first]){
				if(ed.first != st){
				//	printf("S:%d %d %lld\n",st - m , ed.first - m,it.second + ed.second);
					dist[st - m][ed.first - m] = std::min(dist[st - m][ed.first - m] , it.second + ed.second);
				}
			}
		}
	}
	for(int mid = 1 ; mid <= n ; ++ mid){
		for(int i = 1 ; i <= n ; ++ i){
			for(int j = 1 ; j <= n ; ++ j){
				if(dist[i][mid] != 0x7f7f7f7f7f7f7f7fll && dist[mid][j] != 0x7f7f7f7f7f7f7f7fll)
					dist[i][j] = std::min(dist[i][j] , dist[i][mid] + dist[mid][j]);
			}
		}
	}
	while( q-- ){
		int u , v;
		scanf("%d%d", &u ,&v);
		ll nwas = LLONG_MAX;
		for(auto x : edg[u]){
			for(auto y : edg[v]){
				nwas = std::min(nwas , x.second + y.second + dist[x.first - m][y.first - m]);
			}
		}
		printf("%lld\n" , nwas + w[u] + w[v]);
	}
	return 0;
}
