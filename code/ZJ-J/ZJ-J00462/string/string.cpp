#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200010], c[200010], ans = 0ll;
char b[200010], d[200010];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i] >> b[i], c[n - i + 1] = a[i], d[n - i + 1] = b[i];
	int l = 1, r = 1;
	while(1) {
		if(l > n && r > n)
			break;
		if(a[l] < c[r]) {
			c[r] -= a[l];
			if(b[l] != d[r])
				ans += a[l];
			l++;
		} else if(a[l] == c[r]) {
			if(b[l] != d[r])
				ans += a[l];
			l++, r++;
		} else {
			a[l] -= c[r];
			if(b[l] != d[r])
				ans += a[l];
			r++;
		}
	}
	cout << ans / 2ll;
	return 0;
}
