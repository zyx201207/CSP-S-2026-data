#include<bits/stdc++.h>
using namespace std ;
#define int long long
#define FIO ios::sync_with_stdio(),cin.tie(0),cout.tie(0) ;
int n , m , a[100000 + 5] , maxn ;
void dfs (int x , int ans , int step)
{
	if(step == m)
	{
		maxn = max(maxn , ans) ;
		return ;
	}
	for(int i = x + 1 ; i <= n ; i ++)
		dfs(i , ans & a[i] , step + 1) ;
}
signed main()
{
	freopen("and.in" , "r" , stdin) ;
	freopen("and.out" , "w" , stdout) ;
	FIO
	cin >> n >> m ;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i] ;
	sort(a + 1 , a + n + 1) ;
	for(int i = 1 ; i <= n - m + 1 ; i ++)
		dfs(i , a[i] , 1) ;
	cout << maxn ;
	return 0 ;
}
