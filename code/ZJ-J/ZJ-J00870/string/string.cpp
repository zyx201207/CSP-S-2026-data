#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, a[200005], ans;
char c[200005];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
		cin >> c[i];
	}
	ll j = n, i = 1;
	while (i < j) {
		if (a[i] > a[j] && c[i] != c[j]) {
			a[i] -= a[j];
			ans += a[j];
			j--;
		} else if (a[i] < a[j] && c[i] != c[j]) {
			a[j] -= a[i];
			ans += a[i];
			i++;
		} else {
			if (c[i] == c[j]) {
				if (a[i] > a[j]) {
					a[i] -= a[j];
					j--;
				} else if (a[i] < a[j]) {
					a[j] -= a[i];
					i++;
				} else {
					i++;
					j--;
				}
			} else {
				ans += a[i];
				i++;
				j--;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
