#include <bits/stdc++.h>
using namespace std ;

const int M = 2e4 + 1000 ;

int c , n , m , d , q , ans = 1e9 , s , e ;

int w[M] ;

bool vis[M] ;

vector<pair<int , int>> G[M] ;

void dfs(int pos , int ti)
{
	if(pos == e)
	{
		ans = min(ans , ti) ;
		return ;	
	}	
	if(ti >= ans) return ;
	for(auto v : G[pos])
	{
		int val = v.second ;
		int son = v.first ;
		if(!vis[son])
		{
			vis[son] = true ;
			dfs(son , ti + val) ;
			vis[son] = false ;
		}
	}
} 

int main()
{
	freopen("subway.in" , "r" , stdin) ;
	freopen("subway.out" , "w" , stdout) ;
	cin >> c >> n >> m >> d >> q ;
	for(int i = 1 ; i <= m ; i++)
	{
		cin >> w[i] ;
	}
	for(int i = 1 ; i <= n ; i++)
	{
		int k ;
		cin >> k ;
		while(k--)
		{
			int u , v ;
			cin >> u >> v ;
			G[u].push_back(make_pair(2e4 + i , v)) ;
			G[M - 1000 + i].push_back(make_pair(u , v)) ;
		}
	}
	while(q--)
	{
		cin >> s >> e ;
		memset(vis , 0 , sizeof(0)) ;
		ans = 1e9 ;
		dfs(s , 0) ;
		cout << ans + w[s] + w[e] << endl ;
	}
} 
