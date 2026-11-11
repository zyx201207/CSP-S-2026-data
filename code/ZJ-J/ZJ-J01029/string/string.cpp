#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
char c[N];
ll n, a[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(ll i = 1;i <= n;i ++) {
		cin >> a[i] >> c[i];
		a[i] = a[i - 1] + a[i];
	}
	ll l, r, mid = a[n] >> 1;
	if(a[n] % 2 == 0) {
		l = a[n] / 2;
		r = l + 1;
	}
	else l = (a[n] + 1) / 2 - 1, r = (a[n] + 1) / 2 + 1;
	ll lp, rp, ans = 0;
	for(int i = 1;i <= n;i ++) {
		if(l > a[i-1] && l <= a[i])lp = i - 1;
		if(r > a[i-1] && r <= a[i])rp = i;
	}
	while(l >= 1 && r <= a[n]) {
		ll lo = l - a[lp], ro = a[rp] - r + 1;
		l -= (lo < ro ? lo : ro), r += (lo < ro ? lo : ro);
		if(c[lp + 1] == c[rp]) {
			continue ;
		}
		ans += min(lo, ro);
		if(lo <= ro)lp --;
		if(lo >= ro)rp ++;
	}
	cout << ans;
	return 0;
}
