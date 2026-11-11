#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int maxn = 5e5 + 10;
int n, m;
int a[maxn], tiao[maxn], vis[maxn];
vector <int> ans[maxn];
int tong[maxn], cnt[maxn];
signed main () {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	for (int i = n; i >= 1; i --) {
		if (!vis[a[i]]) {
			vis[a[i]] = i;
			tiao[i] = i;
		} else {
			tiao[i] = vis[a[i]];
		}
		cnt[i] = 1;
	}
	for (int i = n; i >= 1; i --) {
		int k = tiao[i] + 1;
		while (k <= n) {
			cnt[k] ++;
			k = tiao[k] + 1;
		}
		ans[i].push_back(a[i]);
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = 0; j < ans[i].size(); j ++) {
			tong[ans[i][j]] += cnt[i];
		}
	}
	for (int i = 1; i <= m; i ++) {
		cout << tong[i] << " ";
	}
	return 0;
}

