#include <bits/stdc++.h>
using namespace std ;
#define int long long
const int N = 5e5 + 5 ;
int n , m , a[N] , cnt , ans ;
signed main()
{
	queue <int> q ;
	ios::sync_with_stdio(0) ;
	cin.tie(0) ;
	cout.tie(0) ;
	freopen("crystal.in" , "r" , stdin) ;
	freopen("crystal.out" , "w" , stdout) ;
	cin >> n >> m ;
	for(int i = 1 ; i <= n ; i ++) cin >> a[i] ;
	sort(a + 1 , a + n + 1) ;
	for(int i = 1 ; i <= n ; i ++)
	{
		int x = a[i] - a[i - 1] ;
		q.push(a[i]) ;
		m -= x * cnt ;
		cnt ++ ;
		while(m < 0 && !q.empty())
		{
			m += (a[i] - q.front()) ;
			q.pop() ;
			cnt -- ; 
		}
		ans = max(ans , cnt) ;
	}
	cout << ans ;
	return 0 ;
}

