#include<bits/stdc++.h>
using namespace std ; 
typedef long long ll ;
const int M = 2e5 + 5 ;
ll a[M] ; 
char c[M] ;
int n ;
int main()
{
	freopen("string.in" , "r" , stdin) ;
	freopen("string.out" , "w" , stdout) ;
	ios::sync_with_stdio(false) ; 
	cin.tie(0) ; 
	cin >> n ;
	string s = "" ; 
	ll cnt = 0 ;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> a[i] >> c[i] ;
		cnt += a[i] ;
		for(int j = 1 ; j <= a[i] ; j ++)
		{
			s += c[i] ;
		}
	}
	ll l ; 
	if(cnt % 2 == 0) l = cnt / 2 ;
	else l = (cnt - 1) / 2 ;
	ll ans = 0 ; 
	for(int i = 0 ; i < l ; i ++)
	{
		if(s[i] != s[cnt - i - 1]) 
		{
			ans ++ ; 
		}
	}
	cout << ans << endl ; 
	return 0 ;
}
