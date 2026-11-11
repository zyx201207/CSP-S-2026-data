// 蒲逸尘 西安理工大学附属中学 SN-J00669
#include <bits/stdc++.h>
using namespace std ;
int n , m ;
long long a[200005] ;
int main()
{
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	cin >> n >> m ;
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i] ;
	if(m == 1)
	{
		long long maxn = -1e18 ;
		for(int i = 1 ; i <= n ; i++)
			maxn = max(maxn , a[i]) ;
		cout << maxn << endl ;
		exit(0) ;
	}
	if(m == 2)
	{
		long long maxn = -1e18 ;
		for(int i = 1 ; i <= n ; i++)
			for(int j = 1 ; j <= n && j != i ; j++)
				maxn = max(maxn , a[i] & a[j]) ;
		cout << maxn << endl ;
		exit(0) ;
	}
	if(m == n)
	{
		long long res = a[1] ;
		for(int i = 2 ; i <= n ; i++)
			res = res & a[i] ;
		cout << res << endl ;
		exit(0) ;
	}
	if(m == (n - 1))
	{
		long long res ;
		for(int i = 1 ; i <= n ; i++)
		{
			if(i == 1) res = a[2] ;
			else res = a[1] ;
			for(int j = 1 ; j <= n && j != i ; j++)
				res = res & a[j] ;
		}
		cout << res << endl ;
		exit(0) ;
	}
	return 0 ;
}
