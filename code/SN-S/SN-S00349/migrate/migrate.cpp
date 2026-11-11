//梁伯温 西安辅轮中学 SN-S00349
#include <bits/stdc++.h>
#define inf 0x3f3f3f3ff3f3f3fLL
using namespace std;
const int maxn = 2e6 + 5;

long long n, d;
vector<long long> x;

void solve() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> d;
	for (int j = 1; j <= n; j ++) cin >> x[j];
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out ", "w", stdout);
	long long c, T;
	cin >> c >> T;
	while (T--) {
		solve();
	}
	return 0;
}

