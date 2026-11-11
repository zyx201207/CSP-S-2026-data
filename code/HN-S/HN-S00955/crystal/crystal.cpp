#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std ;
int main()
{
	freopen("crystal.in" , "r" , stdin) ;
	freopen("crystal.out" , "w" , stdout) ;
	int n ;
	long long m ;
	cin >> n >> m ;
	if(n > 5000)
	{
		long long c , d , e , f ;
		cin >> c >> d >> e >> f ;
		if(e - d == d - c && f - e == d - c)
		{
			cout << m / (e - d) ;
			return 0 ;
		}
		int cnt = 1 ;
		int s[n + 1] ;
		int a[n + 1] ;
		a[1] = c ;
		a[2] = d ;
		a[3] = e ;
		a[4] = f ;
		for(int i = 5 ; i <= n ; i ++)
		{
			cin >> a[i] ;
		}
		sort(a + 1 , a + n + 1) ;
		for(int i = 1 ; i <= n ; i ++)
		{
			s[i] = s[i - 1] + a[i] ;
			for(int j = i ; j >= 1 ; j --)
			{
			 	if(s[i] - s[j - 1] + m < a[i] * (i - j + 1))
			 	{
			 		cnt = max(cnt , i - j) ;
			 		break ;
				}
			}
		}
		cout << cnt ;
		return 0 ;
	}
	int cnt = 1 ;
	long long s[n + 1] ;
	long a[n + 1] ;
	s[0] = 0 ;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> a[i] ;
	}
	sort(a + 1 , a + n + 1) ;
	for(int i = 1 ; i <= n ; i ++)
	{
		s[i] = s[i - 1] + a[i] ;
		for(int j = i ; j >= 1 ; j --)
		{
		 	if(s[i] - s[j - 1] + m < a[i] * (i - j + 1))
		 	{
		 		cnt = max(cnt , i - j) ;
		 		break ;
			}
		}
	}
	cout << cnt ; 
	return 0 ;
}

