#include <bits/stdc++.h>
#define File(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout)
#define int long long
#define endl '\n'
using namespace std;
const int N = 2e5 + 10;
const int M = 40;
int bs[N][M], g[N][M];
int num[N];
inline void turn(int x, int id) {
	int t = 0;
	while (x) {
		t ++;
		if (x & 1) bs[id][t] = 1;
		x >>= 1;
	}
}
signed main() {
	File("and");
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		int x;
		cin >> x;
		turn(x, i);
	}
	for (int i = M; i >= 1; i --) {
		int res = 0;
		for (int j = 1; j <= n; j ++)
			if (bs[j][i]) {
				res ++;
				for (int k = 1; k <= M; k ++) g[res][k] = bs[j][k];
			}
		if (res >= m) {
			memset(bs, 0, sizeof(bs));
			for (int j = 1; j <= res; j ++)
				for (int k = 1; k <= M; k ++) bs[j][k] = g[j][k];
			num[i] = 1;
		}
	}
	int t = 1, ans = 0;
	for (int i = 1; i <= M; i ++) {
		ans += num[i] * t;
		t <<= 1;
	}
	cout << ans;
	return 0;
}
