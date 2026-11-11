# include <bits/stdc++.h>
# define int long long 

using namespace std ;

const int N = 5e5 ;
const int M = 500 ;

int w[N + 5] ;
vector<pair<int, int>> p[N + 5] ; 

int F[M + 5][M + 5] ;

signed main()
{
	freopen("subway.in", "r", stdin) ;
	freopen("subway.out", "w", stdout) ;
	
	ios::sync_with_stdio(false) ;
	cin.tie(0) ; cout.tie(0) ;	
	
	int c, n, m, d, q ;
	cin >> c >> n >> m >> d >> q ;
	
	for(int i = 1 ; i <= m ; i ++) cin >> w[i] ;
	
	for(int i = 1 ; i <= n ; i ++)
	{
		int k ;
		cin >> k ;
		
		for(int j = 1 ; j <= k ; j ++)
		{
			int a, t ; cin >> a >> t ;
			p[a].push_back({i, t}) ;
		}
	}
	
	memset(F, 0x3f, sizeof(F)) ;	
	
	for(int i = 1 ; i <= n ; i ++) F[i][i] = 0 ;
	
	for(int i = 1 ; i <= m ; i ++)
	{
		for(pair<int, int> p1 : p[i])
		{
			int u = p1.first, t1 = p1.second ;

			for(pair<int, int> p2 : p[i])
			{
				int v = p2.first, t2 = p2.second ;
				
				F[u][v] = min(F[u][v], t1 + t2) ;
			}
		}
	}
	
	for(int k = 1 ; k <= n ; k ++)
	{
		for(int i = 1 ; i <= n ; i ++)
		{
			for(int j = 1 ; j <= n ; j ++)
			{
				F[i][j] = min(F[i][j], F[i][k] + F[k][j]) ;
			}
		}
	}
	
	for(int i = 1 ; i <= q ; i ++)
	{
		int x, y ; cin >> x >> y ;
		
		int ans = 1e18 ;
		
		for(pair<int, int> p1 : p[x])
		{
			int u = p1.first, t1 = p1.second ;
			
			for(pair<int, int> p2 : p[y])
			{
				int v = p2.first, t2 = p2.second ;
				ans = min(ans, w[x] + w[y] + t1 + t2 + F[u][v]) ;
			}
		}
		
		cout << ans << '\n' ;
	}
	
	return 0 ;
}
