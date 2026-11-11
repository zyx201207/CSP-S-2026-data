#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 2e5 + 10;

ll n, m, a[N], ans;
vector <ll> c[50];

bool cmp(ll x, ll y) {
	return x > y;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	cin >> n >> m;
	for (ll i = 1; i <= n; i ++) {
		cin >> a[i];
		for (ll d = 32; d >= 0; d --) 
			if ((a[i] >> d) & 1) c[d].push_back(a[i]);
	}
	for (ll d = 32; d >= 0; d --) {
		if (c[d].size() < m) continue;
		sort(c[d].begin(), c[d].end(), cmp);	// 总共O(32nlogn) 
		ll res = c[d][0];
		for (ll i = 1; i < m; i ++) res = res & c[d][i];	// 总共O(32m) 
		ans = max(ans, res);
	}

	cout << ans << endl;
	return 0;
}

// 不要有压力，你去年已经拿过 J 1= 了
// 加油冲 AK
// 我相信你 Cute_zsz ！！！
// RP ++ ！！！！！

// 1h 我是【数据删除】 
// 对于可能 and=0 的情况，只需要按照每一位最优先的顺序处理
// 我想上迷惑行为大赏 上面的 Cute_zsz 是我的 luogu 用户名
// 我真的能 ak 吗，做到这里感觉有点抽象了 我也太菜了吧 

