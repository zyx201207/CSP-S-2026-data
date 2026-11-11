#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long ll;
int a[N];
char c[N];
ll s[N];
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		s[i] = s[i - 1] + a[i];
	}
	int l = 1, r = n;
	ll _l = 1, _r = s[n], ans = 0;
	while(_l <= _r) {
		if(c[l] == c[r]) {
			ll tmp = min(s[l] - _l + 1ll, _r - s[r - 1]);
			_l += tmp, _r -= tmp;
		}
		else {
			ll tmp = min(s[l] - _l + 1ll, _r - s[r - 1]);
			_l += tmp, _r -= tmp, ans += tmp;
		}
		if(_l > s[l]) l++;
		if(_r <= s[r - 1]) r--;
	}
	cout << ans;
	return 0;
}

