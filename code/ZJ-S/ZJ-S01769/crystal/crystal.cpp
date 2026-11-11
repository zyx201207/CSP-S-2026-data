# include <bits/stdc++.h>
# define int long long 

using namespace std ;

const int N = 5e5 ;

int a[N + 5] ;

signed main()
{	
	freopen("crystal.in", "r", stdin) ;
	freopen("crystal.out", "w", stdout) ;
	
	ios::sync_with_stdio(false) ;
	cin.tie(0) ; cout.tie(0) ;

	int n, m ;
	cin >> n >> m ;
	
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> a[i] ;
	}
	
	sort(a + 1, a + n + 1) ;
	
	int pos = 1, sum = 0, ans = 0 ;
	
	for(int i = 1 ; i <= n ; i ++)
	{
		if(i != 1) sum = sum + (i - pos) * (a[i] - a[i - 1]) ;
		
		while(sum > m)
		{
			if(pos + 1 <= i)
			{
				sum = sum - (a[i] - a[pos]) ;
				pos = pos + 1 ;
			}
			else break ;
		}
				
		while(sum <= m)
		{
			if(pos - 1 >= 1)
			{
				if(sum + (a[i] - a[pos - 1]) <= m)
				{
					sum = sum + (a[i] - a[pos - 1]) ;
					pos = pos - 1 ;
				}
				else break ;
			}
			else break ;
		}
		
		ans = max(ans, i - pos + 1) ;
	}
	
	cout << ans << '\n' ;
	
	return 0 ;
}
