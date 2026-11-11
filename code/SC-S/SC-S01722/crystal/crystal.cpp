#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 5e5 + 5 ;
int n , a[N] , m , pre[N] ;

signed main() {
	ios_base::sync_with_stdio(0) ;
	cin.tie(0) , cout.tie(0) ;
	
	freopen("crystal.in" , "r" , stdin) ;
	freopen("crystal.out" , "w" , stdout) ;
	
	cin >> n >> m ;
	for(int i = 1 ; i <= n ; ++ i) {
		cin >> a[i] ; 
	}
	sort(a + 1 , a + n + 1) ;
	for(int i = 1 ; i <= n ; ++ i) {
		pre[i] = pre[i - 1] + a[i] ;
	}
	int ans = 0 ;
	for(int i = 1 ; i <= n ; ++ i) {
		int l = 1 , r = i , mid , pos = i ;
		while(l <= r) {
			mid = (l + r) >> 1 ;
			if(a[i] * (i - mid + 1) - (pre[i] - pre[mid - 1]) <= m) {
				r = mid - 1 ;
				pos = mid ;
			} else {
				l = mid + 1 ;
			}
		}
		ans = max(ans , i - pos + 1) ;
	}
	cout << ans ;
	return 0 ;
}