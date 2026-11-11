//梁伯温 西安辅轮中学 SN-S00349
#include <bits/stdc++.h>
#define inf 0x3f3f3f3ff3f3f3fLL
using namespace std;
const int maxn = 2e6 + 5;

long long n, k;
vector<int> t;

void solve() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> k;
	for (int j = 1; j <= n; j ++) {
		int u, v;
		t[u].push_back(v);
		t[v].push_back(u);
	}
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out ", "w", stdout);
	long long T;
	cin >> c >> T;
	while (T--) {
		solve();
	}
	return 0;
}

