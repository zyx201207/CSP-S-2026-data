#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a, x = 0;
char s;
string ss = "";

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (ll i = 1; i <= n; i++) {
		cin >> a >> s;
		for (ll j = 1; j <= a; j++) {
			ss += s;
		}
	}
	ll l = 0, r = ss.size() - 1;
	while (l <= r) {

		if (ss[l] == ss[r]) {
			l++;
			r--;
			continue;
		} else {
			x++;
		}
		l++;
		r--;
	}
	cout << x;
}