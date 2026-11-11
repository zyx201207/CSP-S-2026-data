//梁伯温 西安辅轮中学 SN-J00635
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 2e5 + 5;

int n, m;
long long a[maxn];

void solve() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m;
	for (int j = 1; j <= n; j++) cin >> a[j];
	sort(a + 1, a + 1 + n);
	cout << a[n] << endl;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int T = 1;
	while (T--) {
		solve();
	}

	return 0;
}
