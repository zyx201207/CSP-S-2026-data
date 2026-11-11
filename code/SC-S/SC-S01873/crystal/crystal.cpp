#include<bits/stdc++.h>
#define int long long
using namespace std ;
const int MAXN = 5e5 + 7 ;
int a[MAXN] ;
signed main() {
	freopen("crystal.in" , "r" , stdin) ;
	freopen("crystal.out" , "w" , stdout) ;
	
	ios::sync_with_stdio(0) ;
	cin.tie(0) ;
	cout.tie(0) ;
	
	int n , m ;
	cin >> n >> m ;
	
	for (int i = 1 ; i <= n ; i ++) {
		cin >> a[i] ;
	}
	
	sort (a + 1 , a + 1 + n) ;
	
	int cnt = 0 ;
	int ans = 0 ;
	for (int i = 1 , j = 1 ; i <= n ; i ++) {
		while (j < n) {
			int del = (j - i + 1) * (a[j + 1] - a[j]) ;
			
			if (cnt + del <= m) {
				cnt += del ;
				j ++ ;
			}
			else {
				break ;
			}
		}
		
		ans = max(ans , j - i + 1) ;
		
		cnt -= a[j] - a[i] ;
	}
	
	cout << ans ;
	
	return 0 ;
}