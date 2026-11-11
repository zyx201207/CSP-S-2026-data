#include <bits/stdc++.h>
using namespace std;

long long n, m;
long long a[500100] ;
long long b[500100] ;
long long c[500100] ;
long long l ;
long long ans = 0;
long long h;

int main() {
	freopen("crystal.in", "r", stdin) ;
	freopen("crystal.out", "w", stdout) ;
	cin >> n >> m;
	for (long long i = 1 ; i <= n ; i ++) {
		cin >> a[i] ;
	}
	sort(a + 1, a + 1 + n) ;
	l = 2 ;
	while (m >= (a[l] - a[l - 1]) * (l - 1) && l <= n) {
		m = m - (a[l] - a[l - 1]) * (l - 1) ;
		l ++ ;
	}
	cout << l - 1 ;
	return 0 ;
}