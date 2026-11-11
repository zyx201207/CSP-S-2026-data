#include<bits/stdc++.h>
#define int long long
using namespace std ;
const int MAXN = 2e6 + 7 ;
int c , t ;

int x[MAXN] ;
int lst[MAXN] ;
int nxt[MAXN] ;

int dep[MAXN] , mx[MAXN] ;

int dp[MAXN] ;
int sum[MAXN] ;

void solve() {
	int n , d ;
	cin >> n >> d ;

	for (int i = 1 ; i <= n ; i ++) {
		cin >> x[i] ;
	}
	if (c <= 10) {
		for (int i = 1 , j = 1 ; i <= n ; i ++) {
			while (x[j] < x[i] - d)	j ++ ;
			lst[i] = j ;
		}

		int ans = 0 ;
		for (int i = 1 ; i <= n ; i ++) {
			//u

			for (int j = 1 ; j <= n ; j ++) {
				dp[j] = 0 ;
				mx[j] = 0 ;
				dep[j] = 0 ;
				sum[j] = 0 ;
			}

			dp[i] = 1 ;
			dep[i] = 0 ;
			mx[0] = i ;
			sum[i] = 1 ;

			for (int j = i + 1 ; j <= n ; j ++) {
				dep[j] = dep[lst[j]] + 1 ;

				dp[j] = sum[mx[dep[lst[j]]]] - sum[lst[j] - 1] ;

				if (dp[j] == 2)	ans ++ ;

				sum[j] = sum[j - 1] + min(dp[j] , 3ll) ;

				mx[dep[j]] = j ;
			}
		}

		cout << ans << "\n" ;
		return ;
	}

	if (c == 11 or c == 12) {
		if (n == 1) {
			cout << 0 << "\n" ;
			return ;
		}

		int z = x[2] - x[1] ;
		int p = d / z ;	//一次最多跳p段

		if (p == 0 or p == 1) {
			cout << 0 << "\n" ;
			return ;
		}

		int h = 2 * p - 1 ;	//只有长度为h可以

		cout << max(n - h , 0ll) << "\n" ;
	}
	if (c == 13 or c == 14) {
		for (int i = 1 , j = 1 ; i <= n ; i ++) {
			while (x[j] < x[i] - d)	j ++ ;
			lst[i] = j ;
		}
		
		for (int i = 1 , j = 1 ; i <= n ; i ++) {
			while (j + 1 <= n and x[j + 1] <= x[i] + d)	j ++ ;
			nxt[i] = j ;
		}
		
		for (int i = 1 ; i <= n ; i ++) {
			sum[i] = 0 ;
		}
		
		nxt[n + 1] = n + 1 ;
		int ans = 0 ;
		for (int i = n ; i >= 1 ; i --) {
			for (int j = nxt[i + 1] - 1 ; j >= nxt[i] ; j --) {
				sum[lst[j]] ++ ;
			}
			
			if (nxt[i] <= i + 1)	continue ;
			
			ans += sum[nxt[i] - 1] ;
		}
		
		cout << ans << "\n" ;
	}
}

signed main() {
	freopen("migrate.in" , "r" , stdin) ;
	freopen("migrate.out" , "w" , stdout) ;

	ios::sync_with_stdio(0) ;
	cin.tie(0) ;
	cout.tie(0) ;

	cin >> c >> t ;

	while (t--) {
		solve() ;
	}

	return 0 ;
}
