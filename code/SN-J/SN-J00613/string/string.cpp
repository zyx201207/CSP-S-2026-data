#include<bits/stdc++.h>
using namespace std ;
int main()
{
	freopen("string.in" , "r" , stdin) ;
	freopen("string.out" , "w" , stdout) ;
	long long n , ans = 0 , cnt = 0 ;
	cin >> n ;
	int a[n + 5] ;
	string c[n + 5] ;
	for (int i = 1 ; i <= n ; i++) 
	{
		cin >> a[i] ;
		cin >> c[i] ;
	}
	for (int i = 1 ; i <= n ; i++)
	{
		cnt += a[i] ;
	}
	string total[cnt + 5] ;
	long long num = 0 ;
	for (int i = 1 ; i <= n ; i++)
	{
		for (int j = 1 ; j <= a[i] ; j++)
		{
			num += 1 ;
			total[num] = c[i] ;
		}
	}
	for (long long i = 1 ; i <= num / 2 ; i++)
	{
		if(total[i] != total[cnt + 1 - i])
			ans += 1 ; 
	}
	cout << ans ;
	return 0 ;
}
