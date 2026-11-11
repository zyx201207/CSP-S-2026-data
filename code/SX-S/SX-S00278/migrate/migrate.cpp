#include <bits/stdc++.h>
using namespace std;
#define ll long long
int c, t;
ll x[3000000];
ll n, d;
queue<int>q;
ll ans;

int main() {
//	freopen("migrate.in", "r", stdin);
//	freopen("migrate.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; ++i) {
			cin >> x[i];
		}
		int cha = x[2] - x[1];
		if (d != cha) {
			if (d % cha != 0);
			d = d - (d % cha);
			int cnt = 1 + 2 * d - cha;
			int s = (cnt + 1) / 2;
			ans = n - s + 1;
			cout << ans << '\n';
		}
	}
	return 0;
}
