#include <bits/stdc++.h>

using namespace std;

long long n, t, l, s = 1, ll, minn = 1e10, res, a[200005], x[200005];

char b[200005], y[200005];

int main () {
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
	}
	for (int i = 1; i <= n; i++) {
		ll += a[i];
	}
	if (ll % 2 == 1) ll++;
	ll /= 2;
	for (int i = 1; i <= n; i++) {
		if (t + a[i] > ll && t < ll) {
			if (b[i] != y[l]) {
				l++;
				x[l] = ll - t;
				y[l] = b[i];
			} else {
				x[l] += ll - t;
			}
			s = l;
			l++;
			x[l] = t + a[i] - ll;
			y[l] = b[i];
		} else {
			if (b[i] != y[l]) {
				l++;
				x[l] = a[i];
				y[l] = b[i];
			} else {
				x[l] += a[i];
			}
		}
		t += a[i];
	} 
	t = l;
	for (int i = 1; i <= s; i++) {
		ll = 0;
		while (ll < x[i]) {
			if (ll + x[t] > x[i]) {
				if (y[t] != y[i]) {
					res += x[i] - ll;
				}
				x[t] -= x[i] - ll;
				break;
			}
			if (y[t] != y[i]) res += x[t];
			ll += x[t];
			t--;
		}
	}
	cout << res;
	fclose (stdin);
	fclose (stdout);
	return 0;
} 

