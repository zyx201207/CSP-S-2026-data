#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
const ll N = 2e5 + 10;
ll a[N];
char c[N];
char s[N], s1[N], s2[N], s3[N];
ll top;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= a[i]; j++) {
			s[++top] = c[i];
		}
	}
	ll e = 0, d = 0;
	if (top % 2 == 0) {
		e = top / 2;
		d = top / 2 + 1;
	} else {
		e = int(top / 2);
		d = int(top / 2 + 2);
	}
	ll x = 0;
	for (ll i = 1; i <= e; i++) {
		s1[++x] = s[i];
	}
	ll y = 0;
	for (ll i = d; i <= top; i++) {
		s2[++y] = s[i];
	}
	ll z = 0;
	for (ll i = y; i >= 1; i--) {
		s3[++z] = s2[i];
	}
	ll sum = 0;
	for (ll i = 1; i <= x; i++) {
		if (s1[i] != s3[i]) {
			sum++;
		}
	}
	cout << sum;

	return 0;
}
//6
//1000000000 a
//1000000000 a
//1000000000 a
//1000000000 b
//1000000000 b
//1000000000 b
