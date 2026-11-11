#include<bits/stdc++.h>
using namespace std ;
const long long N = 2e5 + 5 ;
long long n , m , s[N] , ans ;
void dfs(long long st , long long tot , long long cnt)
{
	if(cnt == m)
	{
		ans = max(ans , tot) ;
		return ;
	}
	for(long long i = st + 1 ; i <= n ; i++)
	{
		if(!st)
		{
			tot = s[i] ;
		}
		dfs(i , tot & s[i] , cnt + 1) ;
	}
}
int main()
{
	freopen("and.in" , "r" , stdin) ;
	freopen("and.out" , "w" , stdout) ;
	ios::sync_with_stdio(0) ;
	cin.tie(0) , cout.tie(0) ;
	cin >> n >> m ;
	for(long long i = 1 ; i <= n ; i++)
	{
		cin >> s[i] ;
	}
	dfs(0 , 0 , 0) ;
	cout << ans << "\n" ;
	return 0 ;
}
/*
4 2
3 15 12 12



5 3
31 3 1 15 7
*/
