#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
const int M = 40;
const int E[] = {0, 536870912, 268435456, 134217728, 67108864, 33554432, 16777216, 8388608, 4194304, 2097152, 1048576,
				524288, 262144, 131072, 65536, 32768, 16384, 8192, 4096, 2048, 1024, 512, 256, 128, 64, 32, 16, 8, 4,
				2, 1};

int n, m, x, d, ans, RP;
int cnt[M];
bool e[N][M];
vector<int> g[N], rp, sum;

signed main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		for (int j = 1; j <= 30; j++)
			if (x >= E[j])
				e[i][j] = true, cnt[j]++, g[j].push_back (i), x -= E[j];
	}
	d = -1;
	for (int i = 1; i <= 30; i++)
		if (cnt[i] >= m) {
			d = i, ans += E[i], sum = g[i];
			break;
		}
	if (d == -1) {
		cout << 0;
		return 0;
	}
	for (int i = d + 1; i <= 30; i++) {
		RP = 0, rp.clear ();
		for (auto it : sum) {
			if (e[it][i])
				RP++, rp.push_back (it);
		}
		if (RP >= m)
			ans += E[i], sum = rp;
	}
	cout << ans;
	return 0;
}