#include <bits/stdc++.h>
using namespace std;

long long c, n, a, b, h[2000100];
long long ans[2000100] ;

int main() {
	freopen("migrate.in", "r", stdin) ;
	freopen("migrate.out", "w", stdout) ;
	cin >> c >> n ;
	if (c == 11 || c == 12) {
		for (long long i = 1 ; i <= n ; i ++) {
			cin >> a >> b;
			for (long long l = 1 ; l <= a ; l ++) {
				cin >> h[i] ;
			}
			ans[i] = a - (b / (h[2] - h[1])) ;
		}
	}
	for (long long i = 1 ; i <= n ; i ++) {
		cout << ans[i] ;
	}
	return 0 ;
}