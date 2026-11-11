#include<bits/stdc++.h>
using namespace std ;
#define int long long
#define FIO ios::sync_with_stdio(),cin.tie(0),cout.tie(0) ;
int n , ans ;
string s ;
signed main()
{
	freopen("string.in" , "r" , stdin) ;
	freopen("string.out" , "w" , stdout) ;
	FIO
	cin >> n ;
	for(int i = 1 ; i <= n ; i ++)
	{
		int t ;
		char ch ;
		cin >> t >> ch ;
		for(int j = 1 ; j <= t ; j ++)
			s += ch ;
	}
	n = s.size() ;
	s = " " + s ;
	for(int i = 1 ; i <= n / 2 ; i ++)
		if(s[i] != s[n + 1 - i]) ans ++ ;
	cout << ans ;
	return 0 ;
}