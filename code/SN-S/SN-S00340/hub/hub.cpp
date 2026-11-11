/*
Author: fortyqin
*/
#include <bits/stdc++.h>
//#define int long long
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
using namespace std;
using ui = unsigned int;
using ll = long long;
using ull = unsigned long long;
using LLL = __int128;
using uLLL = unsigned __int128;
bool MBE;

namespace sub1 {

//  我们先尝试 n^2 做法
const int N = 4005;
//int f[N][N][2][3]; // 看了子树 x，使得深度答案 <= k 的最小花费，点 x 是否点亮，子树现在存在多少联通块了
//int f[N]
vector<int> e[N]; 
int n, K;
//int lim

void dfs(int x, int fa) {
//	bool is_leaf = 1;
	if (x != 0) e[x].erase(find(all(e[x]), fa));
	for (int y : e[x]) {
		if (y == fa) continue;
//		is_leaf = 0;
		dfs(y, x);
	}
//	if (is_leaf) {
//		for (int k=0; k<=n; ++k)
//	} 
}

int dis(int x, int y) {
	if (x == y) return 0;
	int res = 1e9;
	for (int t : e[x]) {
		res = min(res, dis(t, y) + 1);
	}
	return res;
}

void solve() {
	cin >> n >> K;
	for (int i=1; i<n; ++i) {
		int u, v; cin >> u >> v;
		--u; --v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(0, -1);
//	dfs(1, 0);
	int ans = n;
	for (int s=1; s<(1<<n); ++s) {
		if (__builtin_popcount(s) > K) continue;
		int tmp = 0;
		for (int i=0; i<n; ++i) {
			int ma = n;
			for (int j=0; j<n; ++j) if ((s >> j) &1) {
				ma = min(ma, min(dis(i, j), dis(j, i)));
			}
			tmp = max(tmp, ma);
		}
		ans = min(ans, tmp);
	}
	cout << ans << '\n';
	
//	int now = 0;
//	for (int k=)
//	
////	int ans = 0;
//	for (int k=0; k<=n; ++k) {
//		for (int c : {0, 1}) {
//			for (int t : {0, 1, 2}) {
//				if (f[1][k][c][t] <= K) {
//					cout << k << '\n';
//					return;
//				}
//			}
//		}
//	}
//	assert(0); 
	for (int i=0; i<n; ++i) e[i].clear();
}

}

void start() {
	sub1::solve();
}

bool MED;
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string name = "hub";
	freopen((name+".in").c_str(), "r", stdin);
	freopen((name+".out").c_str(), "w", stdout);
	cerr << "-- " << (&MBE - &MED) / 1048576 << " Mib\n";
	int c; cin >> c;
	int test_cnt = 1;
	cin >> test_cnt;
	while (test_cnt--) start();
	cerr << 1000 * clock() / CLOCKS_PER_SEC << " ms\n";
	return 0;
}

