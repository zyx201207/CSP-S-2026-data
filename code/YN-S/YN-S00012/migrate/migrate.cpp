#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll c, t;
	cin >> c >> t;
	while (t--) {
		ll n, d;
		vector<ll>x(2000005);
		cin >> n >> d;
		ll zh = 0, zsh = 0, fuh = 0;
		for (int i = 0; i < n; i++) {
			cin >> x[i];
			if (x[i] < 0)
				fuh++;
			else if (x[i] > 0)
				zsh++;
			zh += x[i];
		}
		cout << max(fuh, zsh) / 2 - 1 + max(fuh, zsh) % 2 << "\n";
	}
	return 0;
}