#include <bits/stdc++.h>
#define int long long
using namespace std ;

const int N = 5000 + 7 ;

int c , t , n , d , minn , cnt ;

int x[N] ;

vector<int> G[N] ;

bool vis[N] ;

void dfs(int pos , int len , int fns)
{
	if(pos == fns)
	{
		minn = min(minn , len) ;
		return ;
	}
	if(len >= minn) return ;
	for(auto v : G[pos])
	{
		if(!vis[v])
		{
			vis[v] = true ;
			dfs(v , len + 1 , fns) ;
			vis[v] = false ;
		}
	}
}

void dfs2(int pos , int len , int fns)
{
	if(pos == fns and len == minn)
	{
		cnt++ ;
		return ;
	}
	if(len > minn) return ;
	for(auto v : G[pos])
	{
		if(!vis[v])
		{
			vis[v] = true ;
			dfs(v , len + 1 , fns) ;
			vis[v] = false ;
		}
	}
}

signed main()
{
	freopen("migrate.in" , "r" , stdin) ;
	freopen("migrate.out" , "w" , stdout) ; 
	cin >> c >> t ;
	while(t--)
	{
		memset(G , 0 , sizeof(G)) ;
		int ans = 0 ;
		cin >> n >> d ;
		for(int i = 1 ; i <= n ; i++)
		{
			cin >> x[i] ;
		}
		for(int i = 1 ; i <= n ; i++)
		{
			for(int j = i + 1 ; j <= n ; j++)
			{
				if(x[j] - x[i] <= d)
				{
					G[i].push_back(j) ;
					G[j].push_back(i) ;
				}
			}
		}
		for(int i = 1 ; i <= n ; i++)
		{
			for(int j = i + 1 ; j <= n ; j++)
			{
				minn = 1e9 ;
				cnt = 0 ;
				memset(vis , 0 , sizeof(vis)) ;
				vis[i] = true ;
				dfs(i , 0 , j) ;
				memset(vis , 0 , sizeof(vis)) ;
				vis[i] = true ;
				dfs2(i , 0 , j) ;
				if(cnt == 2) ans++ ;
			}
		}
		cout << ans << endl ;
	}
} 
