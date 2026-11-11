//蒲逸尘 西安理工大学附属中学 SN-S00392
#include <bits/stdc++.h>
using namespace std ;
const int N = 5e5 + 10 ;
int n ;
long long m , res , a[N] , b[N];
int main()
{
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	cin >> n >> m ;
	for(int i = 1 ; i <= n ; i++) b[i] = -1e18 ;
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i] ;
	for(int i = 1 ; i <= n ; i++)
	{
		long long sum = 0 , ans = 1 ;
		for(int j = 1 ; j <= n && j != i ; j++)
			b[j] = abs(a[i] - a[j]) ;
		sort(b + 1 , b + n + 1) ;
		for(int k = 1 ; k <= n && sum <= m ; k++)
		{
			if(b[k] != -1e18)
			{
				sum += b[k] ;
				ans++ ;
				if(sum > m)
				{
					sum -= b[k] ;
					ans-- ;
					break ;
				}
			}
		}
		res = max(res , ans) ;
		ans = 0 ;
	}
	cout << res << endl ;
	return 0 ;
}
/*
ぃぅくねぬすせすこんめのふは
*/