#include<bits/stdc++.h>
using namespace std;

const int N = 200010;

int n;
char c[N];
long long a[N];
bool flag = false;

void solve() {
	long long ans = 0;
	int l = 1, r = n;
	long long tmp = a[l];
	bool isl = true;
	while ( l < r ) {
		while ( isl && l < r ) {
			if ( tmp > a[r] ) {
				if ( c[l] != c[r] ) ans += a[r];
				tmp -= a[r];
				r--;
			} else if ( tmp < a[r] ) {
				if ( c[l] != c[r] ) ans += tmp;
				tmp = a[r] - tmp;
				isl = false;
				l++;
				break;
			} else {
				if ( c[l] != c[r] ) ans += tmp;
				tmp = a[l];
				l++,r--;
			}
		}
		while ( ( !isl ) && l < r ) {
			if ( tmp > a[l] ) {
				if ( c[l] != c[r] ) ans += a[l];
				tmp -= a[l];
				l++;
			} else if ( tmp < a[l] ) {
				if ( c[l] != c[r] ) ans += tmp;
				tmp = a[l] - tmp;
				isl = true;
				r--;
				break;
			} else {
				if ( c[l] != c[r] ) ans += tmp;
				tmp = a[r];
				l++,r--;
			}
		}
	}
	cout << ans;
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for ( int i = 1; i <= n; i++ ) {
		cin >> a[i] >> c[i];
		flag ^= a[i] & 1;
	}
	solve();
	
}
