#include <bits/stdc++.h>
using namespace std;

typedef int ll;

ll INF = 0x3f3f3f3f;

ll cnt, n, ans;

string s, s1, s2;

void dfs(ll x, ll y) {
	ll a = y + x;

	if (a <= 0 || x == y) {
		return ;
	}
	int mind = a / 2;

	if (a == 2) {
		ll num = 0;
		ll anum = 0;
		for (ll i = x + 1; i <= mind; i++) {
			s1[i] = s[i];
		}
		for (ll i = mind + 1; i <= a; i++) {
			num++;
			s2[num] = s[i];
		}

		for (ll i = 1; i <= anum; i++) {
			if (s2[i] != s1[i]) {
				ans++;
				s2[i] = s1[i];
			}
		}
	}

	else if (a % 2 == 0) {
		ll num = 0;
		ll anum = 0;
		for (ll i = x + 1; i < mind; i++) {
			anum++;
			s1[i] = s[i];
		}
		for (ll i = mind + 1; i < a; i++) {

			s2[num] = s[i];
		}

		for (ll i = 1; i <= anum; i++) {
			if (s2[i] != s1[i]) {
				ans++;
				s2[i] = s1[i];
			}
		}
	} else {
		ll num = 0;
		ll anum = 0;
		for (ll i = x + 1; i <= mind; i++) {
			s1[i] = s[i];
		}
		for (ll i = mind + 1; i <= a; i++) {
			num++;
			s2[num] = s[i];
		}

		for (ll i = 1; i <= num; i++) {
			if (s2[i] != s1[i]) {
				ans++;
				s2[i] = s1[i];
			}
		}
	}


	dfs(x, mind - 1);

	dfs(mind + 1, y);

	return;
}



int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	cin >> n;

	for (ll i = 1; i <= n; i++) {
		ll a;
		char b;

		cin >> a >> b;

		while (a--) {
			cnt++;
			s[cnt] = b;
		}
	}

	dfs(0, cnt + 1);

	cout << ans / 2;

	return 0;
}