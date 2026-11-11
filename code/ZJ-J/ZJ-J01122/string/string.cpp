#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int a[N];
char c[N];
signed main () {
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	int n;
	cin >> n;
	long long sum = 0;
	for (int i = 1; i <= n; i ++ ) {
		cin >> a[i];
		cin >> c[i];
		sum += a[i];
	}
	int cnt = 0;
	int id = 0;
	for (int i = 1; i <= n; i ++ ) {
		if (cnt + a[i] > sum / 2) {
			id = i;
		}
		else {
			cnt += a[i];
		}
	}
	int ans = 0;
	int l = 1;
	int r = n;
	while (l <= r) {
		if (c[l] != c[r]) {
			ans += min (a[l], a[r]);	
		}
		if (a[l] < a[r]) {
			a[r] -= a[l];
			l ++;
		}
		else if (a[l] == a[r]) {
			a[l] = a[r] = 0;
			l ++;
			r --;
		}
		else {
			a[l] -= a[r];
			r --;
		}
	}
	cout << ans;
	return 0;
} 
/*
6
 1000000000 a
 10000006
 1000000000 a
 1000000000 a
 1000000000 a
 1000000000 b
 1000000000 b
 1000000000 b000 a
 1000000000 a
 1000000000 b
 1000000000 b
 1000000000 b
*/
