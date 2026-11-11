#include<bits/stdc++.h>
using namespace std ;
int main()
{
	freopen("migrate.in" , "r" , stdin) ;
	freopen("migrate.out" , "w" , stdout) ;
	int c , t ;
	cin >> c >> t ;
	for (int i = 0 ; i <= t ; i++)
	{
		int n , d ;
		cin  >> n >> d ;
		int way[n + 5] ;
		for (int j = 1 ; j <= n ; j++)
		{
			cin >> way[i] ;
		}
		int way1[n + 5] ;
		for (int j = 1 ; j <= n ; j++)
		{
			way1[i] = way[i + 1] - way[i] ;
		}
		int cnt = 0 ;
		for (int j = 1 ; j <= n ; j++)
		{
			if(way1[i] == way1[i + 1])
				cnt++ ;
		}
		cout << cnt ;
	}
	return 0 ;
}
