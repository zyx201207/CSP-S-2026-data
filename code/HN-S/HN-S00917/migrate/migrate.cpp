#include <bits/stdc++.h>
using namespace std ;
#define int long long
const int N = 2e6 + 5 ;
int n , d , x[N] , f[N] ;
map <pair <int , int> , int> mp ;
void dfs(int step , int lst)
{
	if(step > n)
	{
		int l = 0 , r = 0 ;
		for(int i = n ; i >= 1 ; i --)
		{
			if(f[i]) 
			{
				r = i ;
				break ;
			}
		}
		for(int i = 1 ; i <= n ; i ++)
		{
			if(f[i])
			{
				l = i ;
				break ;
			}
		}
		if(l < r) mp[{l , r}] ++ ;
		return ;
	}
	if(abs(lst - x[step]) <= d)
	{
		f[step] = 1 ;
		dfs(step + 1 , x[step]) ;
	}
	f[step] = 0 ;
	dfs(step + 1 , lst) ;
} 
void solve()
{
	mp.clear() ;
	cin >> n >> d ;
	for(int i = 1 ; i <= n ; i ++) cin >> x[i] ;
	if(n <= 9)
	{
		int ans = 0 ;
		dfs(1 , 1) ;
		for(auto i : mp) if(i.second == 2) ans ++ , cout << i.first.first << " " << i.first.second << "\n" ;
		cout << ans << "\n" ;
		return ;
	}
}
signed main()
{
	ios::sync_with_stdio(0) ;
	cin.tie(0) ;
	cout.tie(0) ;
	freopen("migrate.in" , "r" , stdin) ;
	freopen("migrate.out" , "w" , stdout) ;
	int c , t ;
	cin >> c >> t ;
	while(t --) solve() ;
	return 0 ;
}

