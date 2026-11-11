#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 5e5 + 5, M = 3e5 + 5;
ll n, m, a[N], ans[M], f[M], z[N];
bool bol[M];
void cnt(ll st) {
	memset(bol, 0, sizeof(bol)); f[a[st - 1]]--;
	for (ll k = st; k <= n; k++) {
		for (ll i = 1; i <= m; i++) z[i] = f[i];
		bool found = 1;	z[a[k]]--;
		if (bol[a[k]]) continue;
		for (ll i = n; i > k; i--) {
			z[a[i]]--;
			if (z[a[i]]) {
				found = 0;
				break;
			}
		}
		z[a[k]]++;
		if (found) { ans[a[k]]++; bol[a[k]] = 1; }
	}
	return ;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	bool flag = 1;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i]; f[a[i]]++;
		if (a[i] < a[i - 1]) flag = 0;
	}
	if (flag) {
		ll last = a[1];
		for (ll i = 2; i <= n; i++) {
			if (a[last] != a[i]) {
				ans[a[last]] = i - last - 1;
				last = i;
			}
		}
	}
	for (ll k = 1; k <= n; k++) cnt(k);
	for (ll i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}

