// 15:52 O(n^2) + A 48pts
// 16:05 (i,nxt[i]] dist = 1
// 16:51 md 假了
// 17:08 O(n) 做法
// 17:58 开调
// 怎么小熊猫有默认栈空间限制啊，虚空调试 20 min
// 18:19 通过所有大样例
#include <bits/stdc++.h>
#define nmf(i, s, e) for (int i = s; i <= e; i++)
#define ref(i, s, e) for (int i = s; i >= e; i--)
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
LL a[2000006];
int nxt[2000006];
int testid;
LL n, d;

const int g[7][3] = {
	{0, 0, 1},
	{0, 0, 2},
	{0, 0, 3},
	{0, 1, 1},
	{0, 2, 1},
	{0, 1, 2},
	{1, 1, 1},
};

bool check(int v[], int st) {
	if (st == 0)return v[0] == 0 && v[1] == 0 && v[2] == 1;
	if (st == 1)return v[0] == 0 && v[1] == 0 && v[2] == 2;
	if (st == 2)return v[2] > 2;
	if (st == 3)return v[0] == 0 && v[1] == 1 && v[2] == 1;
	if (st == 4)return v[1] > 1 && v[2] == 1;
	if (st == 5)return v[1] > 0 && v[2] == 2;
	if (st == 6)return v[0] > 0 && v[1] == 1 && v[2] == 1;
	cout << "miao" << endl;
	assert(0);
	return 0;

}
int id(int v[]) {
	nmf(i, 0, 6)if (check(v, i))return i;
	cout << "miao" << endl;
	assert(0);
	return -1;
}

int f[2000006][7];

int dfs(int i, int st) {
	if (nxt[i] == i) return 0;
	if (~f[i][st])return f[i][st];
	int ret = 0;
	int ng[3] = {};
	int now = 0;
	int las = nxt[i] + 1;
	nmf(t, 0, 2) {
		if (i - t <= 0 || !g[st][2 - t]) break;
		if (now == 2) {
			ret += las - nxt[i - t];
		}
		nmf(j, 0, 2) {
			if (nxt[i] - 2 + j > i && nxt[i] - 2 + j <= nxt[i - t]) {
				ng[j] += g[st][2 - t];
			}
		}
		now += g[st][2 - t];
		las = nxt[i - t];
	}
	if (now == 2) {
		ret += las - i;
	}
	int nst = id(ng);
	ret += dfs(nxt[i], nst);
	return f[i][st] = ret;
}

namespace sol_bf {
	LL ans;
	int g[2000006];
	LL calc(int s) {
		g[s] = 1;
		LL ret = 0;
		int pre = s;
		for (int i = s; i <= n; i = nxt[i]) {
			if (nxt[i] == i) {
				break;
			}
			int cnt = 0, sum = 0;
			int pos = i + 1;
			ref(j, nxt[i], i + 1) {
				while (pos > pre && a[j] - a[pos - 1] <= d) {
					sum += g[--pos];
				}
				g[j] = sum;
				if (sum > 2) {
					break;
				} else if (sum == 2) {
					cnt++;
				}
			}
			ret += cnt;
			pre = i + 1;
		}
		return ret;
	}
	bool solve() {
		if (n > 5000)return 0;
		ans = 0;
		nmf(i, 1, n) {
			ans += calc(i);
		}
		cout << ans << endl;
		return 1;
	}
}// namespace sol_bf


void solve() {
	cin >> n >> d;
	nmf(i, 1, n) cin >> a[i];
	nmf(i, 1, n) {
		nxt[i] = max(nxt[i - 1], i);
		while (nxt[i] < n && a[nxt[i] + 1] - a[i] <= d) {
			nxt[i]++;
		}
	}
	if (sol_bf::solve())
		return;
	nxt[0] = 0;
	nmf(i, 0, n) memset(f[i], -1, sizeof(f[i]));
	LL ans = 0;
	nmf(i, 1, n) {
		ans += dfs(i, 0);
	}
	cout << ans << endl;
}
signed main() {
#ifndef LOCAL
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> testid;
	int T = 1;
	cin >> T;
	while (T--)
		solve();
	cerr << "Time Used : " << clock() * (1000.0 / CLOCKS_PER_SEC) << " ms." << endl;
}