#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in" , "w" , stdin) ;
	freopen("string.out" , "r" , stdout) ;
	int n , a[100] , xb = 1 , ans = 0 ;
	char c[100] ;
	char s[1000] ;
	cin >> n ;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> a[i] >> c[i] ;
	}
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 1 ; j <= a[i] ; j++)
		{
			s[xb] = c[i];
			xb++;
		}
	}
	for(int i = 1 ; i * 2 <= xb; i++)
	{
		if(s[i] != s[xb - i])
		{
			ans++;
		}
	}
	
	cout << ans ;
	return 0;
}
