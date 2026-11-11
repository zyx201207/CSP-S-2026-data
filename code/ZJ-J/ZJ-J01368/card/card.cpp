#include<bits/stdc++.h>
using namespace std ;
#define int long long
#define FIO ios::sync_with_stdio(),cin.tie(0),cout.tie(0) ;
int n , m , a[500000 + 5] , b[500000 + 5] , c[300000 + 5] ;
signed main()
{
	freopen("card.in" , "r" , stdin) ;
	freopen("card.out" , "w" , stdout) ;
	FIO
	cin >> n >> m ;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i] ;
	for(int i = 1 ; i <= n ; i ++)
	{
		map<int , int> p ;
		b[500000 + 5] = {0} ;
		int k = 1 ;
		for(int j = i ; j <= n ; j ++)
		{
			b[k] = a[j] ;
			if(p[b[k]] != 0)
			{
				for(int t = p[b[k]] + 1 ; t <= k ; t ++)
					b[t] = 0 , p[b[t]] = 0 ;
				k = p[b[k]] + 1 ;
			}else{
				p[b[k]] = k ;
			}
			k ++ ;
		}
		for(int i = 1 ; i < k ; i ++)
			c[b[i]] ++ ;
	}
	for(int i = 1 ; i <= m ; i ++)
		cout << c[i] << ' ' ;
	return 0 ;
}
