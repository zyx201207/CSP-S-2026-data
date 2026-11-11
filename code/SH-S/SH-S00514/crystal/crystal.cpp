#include <bits/stdc++.h>
#define int long long
using namespace std ;

const int N = 5e5 + 7 ;

int n , m , a[N] , s[N] , s2[N] ;

bool check(int x)
{
	int sum = 1e18 ;
	for(int i = 1 ; i <= n - x + 1 ; i++)
	{
		sum = min(sum , s[i + x - 1] - (i - 1) * a[i + x - 1] + s2[i - 1]) ;
	}
	return sum <= m ;
}

signed main()
{
	freopen("crystal.in" , "r" , stdin) ;
	freopen("crystal.out" , "w" , stdout) ;
	cin >> n >> m ;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> a[i] ;
	}
	sort(a + 1 , a + n + 1) ;
	for(int i = 1 ; i <= n ; i++)
	{
		s[i] = s[i - 1] + (a[i] - a[i - 1]) * (i - 1) ;
		s2[i] = s2[i - 1] + a[i] ; 
	}
	int l = 0 , r = n , ans ;
	while(l <= r)
	{
		int mid = (l + r) / 2 ;
		if(check(mid))
		{
			l = mid + 1 ;
			ans = mid ;
		}	
		else
		{
			r = mid - 1 ;
		}
	} 
	cout << ans ;
}
