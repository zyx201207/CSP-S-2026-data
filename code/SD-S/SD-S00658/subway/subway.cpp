#include <iostream>
#include <vector>
#include <cstring>
#define int long long
using namespace std;
const int maxm = 5e5 + 5 , maxn = 505 , inf = 1e18 + 7; 
int w[maxm];
struct Node{
	int id , dis; 
}; vector < Node > st[maxm];
int f[maxn][maxn];
signed main() { 
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	memset(f , 0x3f , sizeof f);
	ios :: sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0);
	int c , n , m , d , q ; cin >> c >> n >> m >> d >> q;
	for(int i = 1 ; i <= m ; i ++) cin >> w[i];
	for(int i = 1 ; i <= n ; i ++) {
		int k ; cin >> k;
		for(int j = 1 ; j <= k ; j ++) {
			int x , y ; cin >> x >> y;
			st[x].push_back({i , y});
		} 
		f[i][i] = 0;
	} for(int i = 1 ; i <= m ; i ++) {
		for(int j = 0 ; j < st[i].size() ; j ++)
			for(int k = j + 1 ; k < st[i].size() ; k ++) {
				int u = st[i][j].id , v = st[i][k].id , dis = st[i][j].dis + st[i][k].dis;
				f[u][v] = min(f[u][v] , dis) ; f[v][u] = min(f[v][u] , dis);
			}
	} for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= n ; j ++)
			for(int k = 1 ; k <= n ; k ++)
				f[j][k] = min(f[j][k] , f[j][i] + f[i][k]);
	for(int i = 1 ; i <= q ; i ++) {
		int u , v ; cin >> u >> v;
		int ans = inf;
		for(int j = 0 ; j < st[u].size() ; j ++)
			for(int k = 0 ; k < st[v].size() ; k ++)
				ans = min(ans , f[st[u][j].id][st[v][k].id] + st[u][j].dis + st[v][k].dis);
		cout << ans + w[u] + w[v] << '\n';
	}
	return 0;
}
