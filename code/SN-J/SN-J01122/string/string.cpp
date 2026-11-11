#include <bits/stdc++.h>
#define int long long
using namespace std ;
const int MAXN = 1e5 + 5 ;
std :: string s ;
int ans ;
signed main() {
	freopen("string.in" , "r" , stdin) ;
	freopen("string.out" , "w" , stdout) ;
	int n ;
	cin >> n ;
	int cnt = 0 ;
	for (int i = 1 ; i <= n ; i++) {
		int x ;
		char c ;
		cin >> x >> c ;
		for (int j = 1 ; j <= x ; j++) {
			s += c ;
		}
	}
	for (int i = 0 , j = s.size() - 1 ; i < j ; i++ , j--) {
		if (s[i] != s[j]) {
			ans++ ;
		}
	}
	cout << ans ;
	return 0 ;
}
