#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 2e6 + 5 , INF = 1e9 ; 
int n , d , x[N] , cnt[N] , dp[N] , f[N] ;

void solve() {
	cin >> n >> d ;
	for(int i = 1 ; i <= n ; ++ i) {
		cin >> x[i] ;
		cnt[i] = 0 ;
		f[i] = i ;
		int l = 1 , r = i - 1 , mid ;
		while(l <= r) {
			mid = (l + r) >> 1 ;
			if(abs(x[i] - x[mid]) <= d) {
				r = mid - 1 ;
				f[i] = mid ;
			} else {
				l = mid + 1 ;
			}
		}
	}
	int ans = 0 ;
	for(int i = 1 ; i <= n ; ++ i) {
		cnt[i] = 1 ;
		dp[i] = 0 ;
		for(int j = i + 1 ; j <= n ; ++ j) {
			dp[j] = INF ;
			int k = max(i , f[j]) , sum = 0 ;
			for(int l = k ; l < j ; ++ l) {
				if(dp[l] == INF) break ;
				if(dp[l] != dp[k]) break ;
				sum += cnt[l] ;
				if(sum > 2) break ;
			}
			if(sum == 0) break ;
			if(sum == 1) {
				cnt[j] = 1 ;
			} else if(sum == 2) {
				cnt[j] = 2 ;
				ans ++ ;
			} else {
				cnt[j] = INF ;
			}
			dp[j] = dp[k] + 1 ;
		}
	}
	cout << ans <<'\n' ;
}

signed main() {
	ios_base::sync_with_stdio(0) ;
	cin.tie(0) , cout.tie(0) ;
	
	freopen("migrate.in" , "r" , stdin) ;
	freopen("migrate.out" , "w" , stdout) ;
	
	int T , c ;
	cin >> c >> T ;
	while(T --) {
		solve() ;
	}
	return 0 ;
}