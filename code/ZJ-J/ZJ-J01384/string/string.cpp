#include <bits/stdc++.h>
using namespace std;
long long n, cnt, a[200005];
char c[200005];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	int l = 1, r = n;
	while(l <= r) {
		if(l==r) break;
		long long len = min(a[l], a[r]);
		a[l] -= len;
		a[r] -= len;
		if(c[l] != c[r]) cnt += len;
		if(a[l] == 0) l++;
		if(a[r] == 0) r--;
	}
	cout << cnt;
	return 0;
}
