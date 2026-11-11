#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef long long ll;
typedef int itn;
typedef  __int128 i128;
int test = 1;
const int N = 505 , M = 5e5 + 5;
int n , m , d , q , c , k[N];
ll dis[N][N] , w[M];
vector < pair < int , ll > > e[N + M];
int read() {
	int x = 0;
	char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - '0' , c = getchar();
	return x;
}
void write(ll x , bool f) {
	if (x == 0 && f) putchar('0');
	else if (x == 0) return ;
	write(x / 10 , 0);
	putchar('0' + x % 10);
}
inline void solve() {
	c = read();
	n = read();
	m = read();
	d = read();
	q = read();
	for (int i = 1 ; i <= m ; i++) {
		w[i] = read();
	}
	for (int i = 1 ; i <= n ; i++)
		for (int j = 1 ; j <= n ; j++) {
			if (i == j) continue ;
			dis[i][j] = 9e18;
		}
	for (int i = 1 ; i <= n ; i++) {
		k[i] = read();
		for (int j = 1 ; j <= k[i] ; j++) {
			int a = read() , t = read();
			e[a + n].push_back({i , t});
			e[i].push_back({a + n , t});
		}
	}
	for (int i = n + 1 ; i <= n + m ; i++) {
		int l = e[i].size();
		for (int j = 0 ; j < l ; j++) {
			for (int k = 0 ; k < l ; k++) {
				dis[e[i][j].fi][e[i][k].fi] = min(dis[e[i][j].fi][e[i][k].fi] , e[i][j].se + e[i][k].se);
			}
		}
	}
	for (int k = 1 ; k <= n ; k++)
		for (int i = 1 ; i <= n ; i++)
			for (int j = 1 ; j <= n ; j++)
				if (dis[i][k] != 9e18 && dis[k][j] != 9e18)
					dis[i][j] = min(dis[i][j] , dis[i][k] + dis[k][j]);
	while (q--) {
		int x = read() , y = read();
		ll ans = 9e18;
		for (auto i : e[n + x])
			for (auto j : e[n + y]) {
				ans = min(ans , dis[i.fi][j.fi] + i.se + j.se);
			}
		write(ans + w[x] + w[y] , 1);
		puts("");
	}
}

signed main() {
	
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
//	scanf("%d" , &test);
	while (test--)
		solve();
	
	return 0;
}
