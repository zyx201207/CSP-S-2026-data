#include <bits/stdc++.h>
using namespace std;

typedef int ll;

ll INF = 0x3f3f3f3f;
ll n, m;
ll re[200005], mem[24000][20000];

ll dfs(ll x, ll y) {
	if (mem[x][y] != 0) {
		return mem[x][y];
	}

	if (y == 0) {
		return re[x + 1];
	}

	if (x == 0 && y != 0) {
		return 0;
	}

	ll ans = dfs(x - 1, y);

	if (y - 1 >= 0) {
		ans = max((dfs(x - 1, y - 1) & re[x]), ans);
	}

	mem[x][y] = ans;
	return ans;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	cin >> n >> m;

	for (ll i = 1; i <= n; i++) {
		cin >> re[i];
	}
	cout << dfs(n, m);

	return 0;
}