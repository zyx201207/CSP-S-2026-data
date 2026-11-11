#include<bits/stdc++.h>
using namespace std ; 
const int M = 2e5 + 5 ; 
int a[M] , k[M] , ans[M] , b[M] ;
stack<int> s ;
map<int , int> ma ;
int main()
{
	freopen("card.in" , "r" , stdin) ;
	freopen("card.out" , "w" , stdout) ;
	ios::sync_with_stdio(false) ; 
	cin.tie(0) ; 
	int n , m ;
	cin >> n >> m ; 
	bool y = 1 ;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> a[i] ; 
		if(a[i] != a[i - 1]) 
		{
			b[a[i - 1]] = i - 1 ;
		}
	}
	b[m] = n ;
	for(int i = 2 ; i <= n ; i ++)
	{
		if(a[i - 1] > a[i]) y = 0 ;
	}
	if(y)
	{
		for(int i = 1 ; i <= m ; i ++)
		{
			cout << b[i] ;
			if(i != m) cout << " " ;
		}
		return 0 ;
	}
	for(int i = 1 ; i <= n ; i ++)
	{
		int cnt = 0 ;
		ma.clear() ;  
		for(int j = i ; j <= n ; j ++)
		{
			if(ma[a[j]] != 0)
			{
				int t = cnt ; 
				for(int b = ma[a[j]] ; b <= t ; b ++)
				{
					ma[s.top()] = 0 ;
					s.pop() ;
					cnt -- ;
				}
			}
			cnt ++ ;
			s.push(a[j]) ; 
			ma[a[j]] = cnt ;
		}
		for(int j = 1 ; j <= m ; j ++)
		{
			if(ma[j] != 0) ans[j] ++ ; 
		}
	}
	for(int i = 1 ; i <= m ; i ++)
	{
		cout << ans[i] ; 
		if(i != m) cout << " " ; 
	}
	return 0 ;
}
