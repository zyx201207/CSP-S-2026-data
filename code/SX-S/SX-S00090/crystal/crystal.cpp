#include <bits/stdc++.h>
using namespace std;
long long a[500005];
int f[500005];

int main () {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	for ( int i = 1 ; i <= n ; i ++ ) {
		cin >> a[i];
		f[i] = 1;
	}
	sort(a + 1, a + n + 1);
	int kk = 0;
	for ( int i = n ; i >= 2 ; i-- ) {
		long long mm = m;
		int j = i - 1;
		int ii = i;
		while ( a[i] == a[j] ) {
			i--;
			j--;
			f[ii]++;
		}
		while ( mm > 0 ) {
			if ( j == 0 )
				break;
			if ( mm >= a[i] - a[j] )
				f[ii]++;
			mm -= (a[i] - a[j]);
			j--;
		}
		if ( f[ii] > kk )
			kk = f[ii];
		if ( kk >= i )
			break;
	}
	cout << kk;
	return 0;
}