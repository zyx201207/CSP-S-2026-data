#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std ;

#define ll long long
#define MAX 2147483647
#define endl '\n'
#define N 500000 + 13

ll n, ans ;
ll m, a[N] ;

int main() {
	freopen("crystal.in", "r", stdin) ;
	freopen("crystal.out", "w", stdout) ;
	ios::sync_with_stdio(0) ;
	cin.tie(0) ; cout.tie(0) ;
	
	cin >> n >> m ;
	for(int i = 1 ; i <= n ; i ++ ) cin >> a[i] ;
	
	sort(a + 1, a + n + 1) ;
	
	ll t, w ;
	ll cnt = 0 ;
	for(t = 1, w = 2 ; t <= n && w <= n ; w ++ ) {
		cnt = (w - t) * (a[w] - a[w - 1]) + cnt ;
		while(cnt > m && t < w) {
			cnt -= (a[w] - a[t]) ;
			t ++ ;
		}
		ans = max(ans, w - t + 1) ;
//		cout << t << ' ' << w << ' ' << cnt << ' ' << ans << endl ;
	}
	cout << ans ;
	return 0 ;
}

