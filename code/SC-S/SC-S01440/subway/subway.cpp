#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define PII pair<int , int>
#define fir first
#define se second

using namespace std ;

inline int read()
{
	int x = 0 , f = 1 ; char ch = 0 ;
	while(!isdigit(ch)){if(ch == '-') f = -1 ; ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + (ch ^ 48) ; ch = getchar() ;}
	return x * f ;
}

const int N = 5e5 + 10 , INF = 1e18 ;

vector<int> a[N] , t[N] ;
vector<PII> s[N] ;
int c , n , m , d , q , w[N] , dis[510][510] ;

inline int cmin(int xx , int yy)
{
	return (xx > yy) ? yy : xx ;
}

signed main()
{
	freopen("subway.in" , "r" , stdin) ;
	freopen("subway.out" , "w" , stdout) ;
	c = read() , n = read() , m = read() , d = read() , q = read() ;
	for(int i = 1 ; i <= m ; i ++ ) w[i] = read() ;
	for(int i = 1 ; i <= n ; i ++ )
	{
		int kk = read() ;
		for(int j = 1 ; j <= kk ; j ++ )
		{
			int aa = read() , tt = read() ;
			a[i].pb(aa) , t[i].pb(tt) ;
			s[aa].pb({i , tt}) ;
		}
	}
	for(int i = 1 ; i <= n ; i ++ ) for(int j = 1 ; j <= n ; j ++ ) if(i != j) dis[i][j] = INF ;
	for(int i = 1 ; i <= m ; i ++ )
	{
		int len = (int)s[i].size() ;
		for(int j = 0 ; j < len ; j ++ )
		{
			PII t1 = s[i][j] ;
			int u = t1.fir , valu = t1.se ;
			for(int k = j + 1 ; k < len ; k ++ )
			{
				PII t2 = s[i][k] ;
				int v = t2.fir , valv = t2.se ;
				if(u > v) swap(u , v) ;
				dis[u][v] = cmin(dis[u][v] , valu + valv) ;
//				dis[v][u] = dis[u][v] ;
			}
		}
	}
//	cout << dis[1][2] << endl ;	
	for(int i = 1 ; i <= n ; i ++ )
	{
		for(int j = i + 1 ; j <= n ; j ++ )
		{
			for(int k = 1 ; k <= n ; k ++ )
			{
				if(k == i || k == j) continue ;
				dis[i][j] = cmin(dis[i][j] , dis[i][k] + dis[k][j]) ;
//				dis[j][i] = dis[i][j] ;
			}
		}
	}
//	cout << dis[1][3] << endl ;
	while(q -- )
	{
		int x = read() , y = read() ;
		int ans = INF ;
		for(int i = 0 ; i < (int)s[x].size() ; i ++ )
		{
			for(int j = 0 ; j < (int)s[y].size() ; j ++ )
			{
				PII t1 = s[x][i] ;
				int u = t1.fir , valu = t1.se ;
				PII t2 = s[y][j] ;
				int v = t2.fir , valv = t2.se ;
				if(u > v) swap(u , v) ;
				ans = cmin(ans , valu + valv + dis[u][v]) ;
			}
		}
		ans += w[x] + w[y] ;
		printf("%lld\n" , ans) ;
	}
	return 0 ;
}
