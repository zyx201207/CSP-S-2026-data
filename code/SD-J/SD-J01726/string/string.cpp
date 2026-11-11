# include <bits/stdc++.h>
# define ll long long
# define inf 0x3f3f3f3f3f3f3f3f

using namespace std;

const ll N = 2e5 + 5;
ll n, ans, a[N];
char c[N];
string s;

int main () {
	
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	cin >> n;
	ll maxx = -inf;
	for (ll i = 1; i <= n; i ++) {
		cin >> a[i] >> c[i];
		maxx = max (maxx, a[i]);
	}
	if (maxx <= 500) {
		for (ll i = 1; i <= n; i ++)
			for (ll j = 1; j <= a[i]; j ++) s = s + c[i];
		for (ll i = 0; i < s.size (); i ++) {
			ll j = s.size () - 1 - i;
			if (j <= i) break;
			if (s[i] != s[j]) ans ++;
		}	
		cout << ans;
	} else {
		ll sum = 0;
		for (ll i = 1; i <= n; i ++) sum += a[i];
		ll tot = 0, i;
		for (i = 1; i <= n; i ++) {
			tot += a[i];
			if (tot > (sum + 1) / 2) break;
		}
		tot -= a[i];
		// a[i]±äÎª(sum+1)/2-totºÍa[i]-(sum+1)/2+tot 
		for (ll j = i + 1; j <= n; j ++) a[j + 1] = a[j];
		a[i + 1] = a[i] - (sum + 1) / 2 + tot;
		a[i] = (sum + 1) / 2 - tot;
		for (ll j = i; j <= n; j ++) c[j + 1] = c[j];
		n ++;
		for (ll i = 1, j = n; i <= n && i <= j; i ++) {
			if (a[i] < a[j]) {
				a[j] -= a[i];
				if (c[i] != c[j]) ans += a[i];
			} else {
				while (a[i] >= a[j] && j >= i) {
					a[i] -= a[j];
					if (c[i] != c[j]) ans += a[j];
					j --;
				}
				a[j] -= a[i];
				if (c[i] != c[j]) ans += a[i];
			}
		}
		cout << ans;
	}
	
	return 0;
}

