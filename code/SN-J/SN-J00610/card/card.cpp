#include<bits/stdc++.h>
using namespace std ;
const long long N = 5e5 + 5 , M = 3e5 + 5 ;
long long s[N] , ans[M] , pos[N] ;
bool f[M] ;
int main()
{
	freopen("card.in" , "r" , stdin) ;
	freopen("card.out" , "w" , stdout) ;
	ios::sync_with_stdio(0) ;
	cin.tie(0) , cout.tie(0) ;
	long long n , m ; cin >> n >> m ;
	for(long long i = 1 ; i <= n ; i++)
	{
		cin >> s[i] ;
	}
	for(long long i = 1 ; i <= n ; i++)
	{
		memset(pos , 0 , sizeof(pos)) ;
		memset(f , false , sizeof(f)) ;
		for(long long j = i ; j <= n ; j++)
		{
			if(f[s[j]])
			{
				for(long long k = pos[s[j]] ; k < j ; k++)
				{
					f[s[k]] = false ;
					pos[s[k]] = 0 ;
				}
			}
			f[s[j]] = true ;
			pos[s[j]] = j ;
		}
		for(long long j = 1 ; j <= m ; j++)
		{
			if(f[j])
			{
				ans[j]++ ;
			}
		}
	}
	for(long long i = 1 ; i < m ; i++)
	{
		cout << ans[i] << " " ;
	}
	cout << ans[m] << "\n" ;
	return 0 ;
}
/*
4 3
1 2 1 3



10 3
3 1 2 1 3 2 3 1 2 1
*/

