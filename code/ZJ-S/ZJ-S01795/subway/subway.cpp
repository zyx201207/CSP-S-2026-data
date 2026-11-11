#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int , int> pr;
const int M = 5e5 + 5 , N = 505;
const ll INF = 1e18L;
int c , n , m , d , q , w[M] , tot , deg[M];
struct Edge{int u , v , w;}edge[M]; pr e[M];
ll g[N][N];
int main()
{
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) , cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1 ; i <= m ; i++)
		cin >> w[i];
	for(int i = 1 ; i <= n ; i++)
	{
		int k; cin >> k;
		for(int j = 1 ; j <= k ; j++)
		{
			int a , t; cin >> a >> t;
			edge[++tot] = {a , i , t};
			deg[a]++;
		}
	}
	for(int i = 1 ; i <= m ; i++)
		deg[i] += deg[i - 1];
	for(int i = tot ; i >= 1 ; i--)
	{
		auto [u , v , w] = edge[i];
		e[deg[u]--] = {v , w};
	}
	for(int i = 1 ; i <= m ; i++)
		deg[i]++;
	deg[m + 1] = tot + 1;
	memset(g , 0x3f , sizeof g);
	for(int i = 1 ; i <= n ; i++)
		g[i][i] = 0;
	for(int i = 1 ; i <= m ; i++)
	{
		int l = deg[i] , r = deg[i + 1] - 1;
		for(int j = l ; j <= r ; j++)
		{
			auto [u , ut] = e[j];
			for(int k = l ; k <= r ; k++)
			{
				auto [v , vt] = e[k];
				g[u][v] = min(g[u][v] , (ll)ut + vt);
			}
		}
	}
	// for(int i = 1 ; i <= n ; i++)
	// 	for(int j = 1 ; j <= n ; j++)
	// 		cerr << g[i][j] << " \n"[j == n];
	for(int k = 1 ; k <= n ; k++)
		for(int i = 1 ; i <= n ; i++)
			for(int j = 1 ; j <= n ; j++)
				g[i][j] = min(g[i][j] , g[i][k] + g[k][j]);
	// for(int i = 1 ; i <= n ; i++)
	// 	for(int j = 1 ; j <= n ; j++)
	// 		cerr << g[i][j] << " \n"[j == n];
	for(int i = 1 ; i <= q ; i++)
	{
		int x , y; ll res = INF;
		cin >> x >> y;
		for(int j = deg[x] ; j < deg[x + 1] ; j++)
			for(int k = deg[y] ; k < deg[y + 1] ; k++)
				res = min(res , g[e[j].fi][e[k].fi] + e[j].se + e[k].se);
		cout << res + w[x] + w[y] << "\n";
	}
	return 0;
}