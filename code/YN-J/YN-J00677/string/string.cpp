#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5;
ll a[N];
string b[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin.tie(0);
	ll n;
	cin >> n;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
	}
	string s = "";
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= a[i]; j++) {
			s += b[i];
		}
	}
	ll cnt = 0;
	for (ll i = 1; i <= n; i++) {
		if (b[i] == b[i + 1])
			cnt = 0;
		else
			cnt++;
	}
	if (cnt == 0) {
		cout << 0;
		return 0;
	}
	cnt = 0;
	return 0;
}