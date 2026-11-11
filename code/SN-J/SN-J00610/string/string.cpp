#include<bits/stdc++.h>
using namespace std ;
const long long N = 2e5 + 5 ;
long long s[N] , ans ; 
char ch[N] ;
int main()
{
	freopen("string.in" , "r" , stdin) ;
	freopen("string.out" , "w" , stdout) ;
	ios::sync_with_stdio(0) ;
	cin.tie(0) , cout.tie(0) ;
	long long n ; cin >> n ;
	for(long long i = 1 ; i <= n ; i++)
	{
		cin >> s[i] >> ch[i] ;
	}
	long long l = 1 , r = n ;
	while(l <= r)
	{
		if(s[l] <= s[r])
		{
			if(ch[l] != ch[r])
			{
				ans += s[l] ;
			}
			s[r] -= s[l] ;
			s[l] = 0 ;
		}
		else
		{
			if(ch[l] != ch[r])
			{
				ans += s[r] ;
			}
			s[l] -= s[r] ;
			s[r] = 0 ;
		}
		if(!s[r])
		{
			r-- ;
		}
		if(!s[l])
		{
			l++ ;
		}
	}
	cout << ans << "\n" ;
	return 0 ; 
}
/*
3
2 a
2 b
1 c



6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
