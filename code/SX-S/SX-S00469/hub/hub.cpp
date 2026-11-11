#include <bits/stdc++.h>
using namespace std;
const int N =  1111;
int n, k;
vector<int> v[N];
int dp[N][N][3];

//inline bool check(int x) {
//	return 1;
//}

inline void solve() {
	cin >> n >> k;
	for (int i = 1, u, V; i < n; i ++) {
		cin >> u >> V;
		v[u].push_back(V);
		v[V].push_back(u);
	}
	int l = 0, r = n, mid, ans;
//	while (l <= r) {
//		mid = (l + r) >> 1;
//		if (check(mid)) {
//			r = mid - 1;
//			ans = r;
//		} else {
//			l = mid + 1;
//		}
//	}
	ans = n / (k + 1) - 1;
	ans = max(1, ans);
	cout << ans << '\n';


	for (int i = 1; i <= n; i ++) {
		v[i].clear();
	}
}

int main() {
//	freopen("hub.in", "r", stdin);
//	freopen("hub.out", "w", stdout);
	//jiushijiushihenkaixin wuwuwuwu wo ganjuewo keyiqifeil  wo de t1t2sihudouzuochulail erqieshijianfuzadumeiyouwenti  wozhendeaisinil OI cspjinianchudetizhende haokeai
	//xiaomaoerai xiaogoukeai shenmedongxidoukeai muamuamuaqingsinimen xixi
	int c, T;
	cin >> c >> T;
	while (T--) {
		solve();
	}
	return 0;
}
