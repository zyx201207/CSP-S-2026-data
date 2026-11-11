#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5 * 1e5+9;
ll a[N];

inline int read() {
	ll f = 1, z = 0;
	char s;
	s = getchar();
	while (s < '0' || s > '9') {
		if (s == '-')
			f = -1;
		s = getchar();
	}
	while (s >= '0' && s <= '9') {
		z *= 10;
		z += s - '0';
		s = getchar();
	}
	return z * f;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n, m;
	n = read();
	m = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	sort(a + 1, a + n + 1);
	ll pos = 0;
	for (int i = 1; i <= n; i++) {
		ll p = upper_bound(a + 1, a + n + 1, a[i]) - a;
		p--;
		ll sum = 0;
		ll cnt = 0;
		for (int j = p; j >= 1; j--) {
			if (cnt + a[i] - a[j] <= m) {
				cnt += a[i] - a[j];
				sum++;
			}
		}
		pos = max(pos, sum);
	}
	cout << pos;
	/*ll id = a[1];
	ll ans = 1;
	ll i = 1;
	ll tot = 0;
	while (i <= n) {
		if (tot + i <= m) {
			tot += i;
			id++;
		} else {
			break;
		}
		if (id == a[i + 1]) {
			ans++;
			i++;
		}
	}
	ll pos = 0;
	for (int i = 1; a[i] <= id; i++) {
		pos ++;
	}
	cout << pos;*/
	return 0;
}
