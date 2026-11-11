#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N = 2e5 + 10;
LL n, a[N], ans;
char c[N];
set<char> s;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (LL i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		s.insert(c[i]);
	}
	if (s.size() == 1) {
		cout << 0;
		return 0;
	}
	LL l = 1, r = n;
	while (l <= r){
		if (a[l] == a[r] && c[l] == c[r]) {
			l++, r--;
			continue;
		}
		if (a[l] == a[r] && c[l] != c[r]) {
			ans += a[l];
			l++, r--;
			continue;
		} if (a[l] > a[r]) {
			ans += a[l] - a[r];
			a[l] -= a[r];
			r--;
		} else {
			ans += a[r] - a[l];
			a[r] -= a[l];
			l++;
		}
	}
	cout << ans;
	return 0;
} 
