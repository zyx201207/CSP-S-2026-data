#include <bits/stdc++.h>
using namespace std ;

typedef long long ll ;

const int N = 5e5 + 10 ;
int n ;
ll m , a[N] ;
ll ans = 0 ;

int main ()
{
	freopen ("crystal.in" , "r" , stdin) ;
	freopen ("crystal.out" , "w" , stdout) ;
	cin >> n >> m ;
	for (int i = 1 ; i <= n ; i++ ) cin >> a[i] ;
	sort (a + 1 , a + n + 1) ;
	ll len = 0 ;
	ll num = 0 ;
	for (int i = 1 ; i <= n ; i++ )
	{
		if (len == 0) len++ ;
		else
		{
			num += len * (a[i] - a[i - 1]) ;
			while (len > 0 && num > m ) 
			{
				num = num - a[i] + a[i - len] ;
				len-- ;
			}
			len++ ;
			ans = max (ans , len) ;
		}
	}
	cout << ans << '\n' ;
	return 0 ;
}
