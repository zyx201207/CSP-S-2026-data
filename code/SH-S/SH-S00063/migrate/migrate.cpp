#include <bits/stdc++.h>
using namespace std ;

const int N = 2e6 + 10 ;
int c , t ;
int n ;
long long d ;
long long x[N] ;
long long dp[N] ;
long long dp2[N] ;

void solve ()
{
	cin >> n >> d ;
	int l = 1 ;
	for (int i = 1 ; i <= n ; i++ )
	{
		cin >> x[i] ;
		while (x[i] - x[l] > d) l++ ;
		dp[i] = l ;
		dp2[l] = i ;
	}
	dp[1] = 0 ;
	dp2[0] = 1 ;
	long long ans = 0 ;
	for (int i = 1 ; i <= n ; i++ )
	{
		int t = dp[i] + 1 ;
		if (dp2[dp[t]] != t || dp[t] > i - 2) continue ;
		t = dp[t] ;
		long long left = 0 ;
		while (dp[t] >= 1 && dp2[dp[t]] == t) t = dp[t] , left++ ;
		long long right = 0 ;
		int j = i ;
		while (dp2[j] <= n && dp[dp2[j]] == j) j = dp2[j] , right++ ;
		ans += (left + 1) * (right + 1) ;
	}
	cout << ans << '\n' ;
}

int main ()
{
	freopen ("migrate3.in" , "r" , stdin) ;
//	freopen ("migrate.out" , "w" , stdout) ;
	ios::sync_with_stdio (false) ;
	cin.tie (0) ;
	cout.tie(0) ;
	cin >> c >> t ;
	while (t--) solve() ;
	return 0 ; 
}
