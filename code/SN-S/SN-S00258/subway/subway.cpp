#include<bits/stdc++.h>
#define int long long
using namespace std ;
const int N = 1005 , M = 5e4 + 5 ;
int w[M] , s[N] , t[N] , ans , idx[N] , Idx[N] ;
int str[M][N / 2] , End[N / 2][M] ;
void dfs(int st , int ed , int tot)
{
	if(End[st][ed])
	{
		ans = min(ans , tot) ;
		return ;
	}
	for(auto i : str[st])
	{
		for(auto j : End[i])
		{
			dfs(j , ed , tot + w[st] * 2 + t[st]) ;
		}
	}
}
signed main()
{
	freopen("subway.in" , "r" , stdin) ;
	freopen("subway.out" , "w" , stdout) ;
	ios::sync_with_stdio(0) ;
	cin.tie(0) , cout.tie(0) ;
	int n , m , k , T ; cin >> n >> n >> m >> k >> T ;
	for(int i = 1 ; i <= m ; i++)
	{
		cin >> w[i] ;
	}
	for(int i = 1 ; i <= n ; i++)
	{
		int K ; cin >> K ;
		for(int j = 1 ; j <= K ; j++)
		{
			cin >> s[i] >> t[i] ;
			str[i][++idx[i]] = s[i] ;
			End[s[i]][++Idx[i]] = i ;
		} 
	}
	while(T--)
	{
		ans = 0 ;
		int x , y ; cin >> x >> y ;
		dfs(x , y , 0) ;
		cout << ans << "\n" ;
	}
	return 0 ;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
