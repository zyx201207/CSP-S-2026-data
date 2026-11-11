#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5 , inf = 0x3f3f3f3f;
#define in(a) a = read()
inline int read() { 
	int ch = getchar() , x = 0;
	bool f = 0;
	while('9' < ch || ch < '0') f |= ch == '-' , ch = getchar();
	while('0' <= ch && ch <= '9') x = x * 10 + ch - '0' , ch = getchar();
	return f ? -x : x;
}
int c , n , m , d , q , a[N];
ll dis[505][505];
vector<pair<int , int>>g[N];
int main() {
	freopen("subway.in" , "r" , stdin) , freopen("subway.out" , "w" , stdout);
	in(c) , in(n) , in(m) , in(d) , in(q);
	for(int i = 1 ; i <= m ; i ++) in(a[i]);
	for(int i = 1 ; i <= n ; i ++) {
		int k;
		in(k);
		for(int j = 1 ; j <= k ; j ++) {
			int u , w;
			in(u) , in(w);
			g[u].push_back({i , w});
		}
	}
	memset(dis , 0x3f , sizeof(dis));
	for(int i = 1 ; i <= m ; i ++) { // md^2 
		int l = g[i].size();
		for(int j = 0 ; j < l ; j ++) {
			for(int k = j + 1 ; k < l ; k ++) {
				dis[g[i][k].first][g[i][j].first] = dis[g[i][j].first][g[i][k].first] = g[i][j].second + g[i][k].second;
			}
		}
	}
	for(int i = 1 ; i <= n ; i ++) dis[i][i] = 0;
	for(int i = 1 ; i <= n ; i ++) {
		for(int j = 1 ; j <= n ; j ++) {
			for(int k = 1 ; k <= n ; k ++) {
				dis[i][j] = min(dis[i][j] , dis[i][k] + dis[k][j]);
			}
		}
	}
	while(q --) {
		int x , y;
		in(x) , in(y);
		int l = g[x].size() , r = g[y].size();
		ll ans = 1e18;
		for(int i = 0 ; i < l ; i ++) {
			int u = g[x][i].first , w = g[x][i].second;
			for(int j = 0 ; j < r ; j ++) {
				int v = g[y][j].first , W = g[y][j].second;
				ans = min(ans , dis[u][v] + w + W);
			}
		}
		printf("%lld\n" , ans + a[x] + a[y]);
	}
	return 0;
}

