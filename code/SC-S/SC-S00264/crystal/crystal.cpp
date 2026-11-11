#include <bits/stdc++.h>
using namespace std ;

long long n ,m ,a[500005] ,d[500005];

long long check(long long u)
{
	long long cnt = 0 ,sum = 0;
	for (int i = 1 ;i <= n ;i ++)
	{
		if (a[i] > u) return cnt ; 
		if (sum + (u - a[i]) <= m)
		{
			cnt ++ ;
			sum += (u - a[i]) ;
		}
		else 
		{
			return cnt ;
		}
	}
	if (sum == 0) return -1 ;
}

int main()
{
	freopen("crystal.in","r",stdin) ;
	freopen("crystal.out","w",stdout) ;
	cin >> n >> m ;
	for (int i = 1 ;i <= n ;i ++)
	{
		cin >> a[i] ;
	}
	sort(a + 1 ,a + n + 1) ;
	long long sum = 0 ;
	for (int i = 1 ;i <= n ;i ++)
		d[i] = d[i - 1] + (a[i] - a[i - 1]) ,sum += d[i];
	long long ans = 0;
	for (int i = 0 ; i <= min(sum ,m) ; i ++)
	{
		ans = max(ans ,check(i)) ;
	}
	cout << ans << endl ;
	return 0 ;
 }
/*
找一个数，使它减去比他小的较大的若干个数的值 之和小于或等于m ; 二分？ 
*/ 