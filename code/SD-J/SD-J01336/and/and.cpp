#include<bits/stdc++.h>
using namespace std ; 
typedef long long ll ; 
const int M = 2e5 + 5 ;  
int n , m ;
ll a[M] , maxn = 0 ;
bool b[M] ; 
void f(int pos , int cnt) 
{
	if(pos > n)
	{
		if(cnt == m)
		{ 
			ll ans ; 
			int i = 1;
			for(; i <= n ; i ++)
			{
				if(b[i])
				{
					ans = a[i] ; 
					break ;
				} 
			}
			i ++ ;
			for(; i <= n ; i ++)
			{
				if(b[i])
				{
					ans &= a[i] ; 
				}
			}
			maxn = max(maxn , ans) ; 
			return ;
		}	
		else return ; 
	} 
	b[pos] = 1 ;
	f(pos + 1 , cnt + 1)  ;
	b[pos] = 0 ; 
	f(pos + 1 , cnt) ;
}
bool ts(ll x)
{
	ll l = x + 1 ;
	while(l != 1)
	{
		if(l % 2 == 1) return 0 ;
		l /= 2 ;
	}
	return 1 ;
}
int main()
{
	freopen("and.in" , "r" , stdin) ;
	freopen("and.out" , "w" , stdout) ;
	ios::sync_with_stdio(false) ; 
	cin.tie(0) ; 
	cin >> n >> m ; 
	bool y = 1 ; 
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> a[i] ;	
		if(ts(a[i]) == 0) y = 0 ; 
	} 
	if(y)
	{
		sort(a + 1 , a + n + 1 , greater<int>()) ; 
		int ans = a[1] ; 
		for(int i = 2 ; i <= m ; i ++)
		{
			ans &= a[i] ;
		}
		cout << ans ; 
		return 0 ; 
	}
	if(m == n)
	{
		ll ans = a[1] ;
		for(int i = 2 ; i <= n ; i ++)
		{
			ans &= a[i] ;
		}
		cout << ans ;
		return 0 ;  
	}
	else if(m == 1)
	{
		ll ans = 0 ; 
		for(int i = 1 ; i <= n ; i ++)
		{
			ans = max(ans , a[i]) ; 
		}
		cout << ans ; 
		return 0 ;
	}
	f(1 , 0) ; 
	cout << maxn ; 
	return 0 ;
}
