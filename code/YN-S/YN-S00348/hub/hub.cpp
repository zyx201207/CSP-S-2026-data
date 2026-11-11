#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll c, t;
ll n, m, ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> m;
		ans = n - m * m;
		cout << ans;
	}
	return 0;
}