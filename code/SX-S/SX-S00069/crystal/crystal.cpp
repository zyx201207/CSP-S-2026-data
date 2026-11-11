#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 5e5+5;
ll n, m, a[N], p[N], f[N], ans, asd, sh;
bool yy;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	stable_sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		p[i] = a[i] - a[i - 1];
	}
	for (ll i = 2; i <= n; i++) {
		if (ans + p[i] * (i - 1) > m) {
			yy = 1;
			asd = max(asd, i - 1 - sh);
			sh = i - 1;
			ans = 0;
		} else
			ans += p[i] * (i - 1);
	}
	if (yy == 0)
		asd = n;
	cout << asd;
	return 0;
}