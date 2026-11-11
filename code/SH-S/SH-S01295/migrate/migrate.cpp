#include<bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
using namespace std;
long long nxt[2000010], c, t;
long long x[2000010], mem[2000010][2], n, d;
vector<long long> f[2000010];
long long lastPoint(long long pos) {
	long long l = 1, r = n, ans = -1;
	while (l <= r) {
		long long mid = (l + r) / 2;
		if (x[mid] <= pos) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	return ans;
}
bool jump(int px, int py) {
	return x[py] - x[px] <= d;
}
// 计算出 假设 cur 为路径上第二个点，则 初始点为 u，有多少 (u, v) 至多有两条路线（且至少有一条路线） 的答案
long long dfs(long long cur, int hasChanged = 0) {
	if (mem[cur][hasChanged]) return mem[cur][hasChanged];
	long long ans = 1; // 原地不动直接结算
	if (nxt[cur] != cur && nxt[cur] != nxt[cur - 1])
		ans += dfs(nxt[cur], hasChanged); // 不动，继续跳
	if (!hasChanged) {
		// -1，看看合不合法
		bool flag1 = jump(cur - 1, nxt[cur]); // 能否跳到
		// cur - 2 是否跳不到 / cur - 2 不存在
		bool flag2 = (cur - 2 < 1 || !jump(cur - 2, nxt[cur]));
		if (flag1 && flag2) {
			ans += dfs(nxt[cur], 1);
		}
	}
	mem[cur][hasChanged] = ans;
	return ans;
}
// 计算出 假设 cur 为路径上第二个点，则 初始点为 u，有多少 (u, v) 只有一条路线 的答案
long long dfs2(long long cur) {
}
// 给定一条路径，这条路径是否是 “唯一的”
bool check(vector<int>& v) {
	for (int i = 1; i < v.size() - 1; i++) {
		if (v[i] - 1 >= 1 && jump(v[i] - 1, v[i + 1])) return false;
	}
	return true;
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		rep (i, 1, n) {
			f[i].clear();
		}
		rep (i, 1, n) {
			cin >> x[i];
		}
		rep (i, 1, n) {
			nxt[i] = lastPoint(x[i] + d);
			// cout << i << ": " << nxt[i] << "\n";
		}
		rep (i, 1, n) {
			int cur = nxt[i];
			while (cur <= n) {
				f[i].push_back(cur);
				if (nxt[cur] == cur) break;
				if (nxt[cur] == nxt[cur - 1]) break;
				cur = nxt[cur];
			}
		}
		// for (auto i: f[1]) {
			// cout << i << " ";
		// }
		// cout << "\n";
		long long ans = 0;
		rep (i, 1, n) {
			vector<int> v; v.push_back(i);
			for (int j = 0; j < f[i].size() - 1; j++) {
				// 在 f[i][j] 使用 -1
				// 两条子路径：i -> (f[i][j] - 1) && (f[i][j] - 1) -> ...
				// 后一条反正一定合法，只要能跳到
				// cout << "Try to change at: " << f[i][j] << "\n";
				if (f[i][j] - 1 >= 1 && jump(f[i][j] - 1, f[i][j + 1])) {
					v.push_back(f[i][j] - 1);
					// cout << "changed at: " << f[i][j] - 1 << "\n";
					bool flag = (f[i][j] - 2 < 1 || !jump(f[i][j] - 2, f[i][j + 1]));
					if (check(v) && flag) {
						ans += (f[i].size() - j - 1);
					}
					v.pop_back();
				}
				v.push_back(f[i][j]);
			}
			// 在末端使用 -1，有概率能再跳
			int j = f[i].size() - 1, nx = nxt[f[i][j]];
			if (f[i][j] - 1 >= 1 && jump(f[i][j] - 1, nx)) {
				v.push_back(f[i][j] - 1);
				// cout << i << " changed at: " << f[i][j] - 1 << "\n";
				bool flag = (f[i][j] - 2 < 1 || !jump(f[i][j] - 2, nx));
				if (check(v) && flag) {
					ans += (f[i].size() - j);
				}
				v.pop_back();
			}
		}
		cout << ans << "\n";
	}
}