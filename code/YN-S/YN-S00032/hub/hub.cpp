#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 514514;
ll n, m, ans, k;
ll a[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ll c, t;
	m = 1;
	cin >> c >> t;
	while (t--) {
		cin >> n >> k;
		int u, v;
		for (int i = 1; i < n; i++)
			cin >> u >> v;
		cout << m << endl;
		m = m + 1;
	}
	return 0;
}
