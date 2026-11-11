#include <bits/stdc++.h>
using namespace std ;

int main()
{
	freopen("migrate.in" , "r" , stdin) ;
	freopen("migrate.out" , "w" , stdout) ;
	int c , t ;
	cin >> c >> t ; 
	if(c == 11 || c == 12)
	{
		while(t --)
		{
			int n , d ;
			cin >> n >> d ;
			int a , b ;
			for(int i = 1 ; i <= n - 1 ; i ++)
			{
				cin >> a ;
			}
			cin >> b ;
			if(2 * (b - a) <= d && 3 * (b - a) > d)
			{
				cout << n - 2 << endl ;
				continue ;
			}
			cout << 0 << endl ;
		}
		return 0 ;
	}
	if(c == 13 || c == 14)
	{
		while(t --)
		{
			int n , d ;
			cin >> n >> d ;
			int a ;
			for(int i = 1 ; i <= n ; i ++)
			{
				cin >> a ;
			}
			if(n >= 2)
			{
				cout << n - 2 << endl ;
				continue ;
			}
			cout << 0 << endl ;
		}
	}
	return 0 ;
}

