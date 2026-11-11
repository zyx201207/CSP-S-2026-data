#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 2e5 + 5;
string s;
ll n;
ll a[N];
char c[N];
ll sumi[N], sumj[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		sumi[i] += sumi[i - 1] + a[i];
	}
	for (ll i = n; i >= 1; i--) {
		sumj[i] += sumj[i + 1] + a[i];
	}
	ll i = 1, j = n;
	ll ans = 0;
	ll len = 0;
	while (i <= j) {
		if (c[i] != c[j]) {
			ans += min(sumi[i] - len, sumj[j] - len);
		}
		if (sumi[i] >= sumj[j]) {
			len = sumj[j];
			j--;
		} else {
			len = sumi[i];
			i++;
		}
	}
	cout << ans;
	return 0;
}