#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int n, m;
int f[N];
int ans[N];

struct abc {
	int id;
	bool vis;
};

deque<int> get(int f[], int l) {
	map<int, int>mp, p, vis;
	deque<int>res;

	for (int i = l; i <= n; i++) {
		if (vis[f[i]]) {
			for (int j = mp[f[i]]; j < i; j++)
				p[j] = 1, vis[f[j]] = 0;
			mp[f[i]] = i;
			vis[f[i]] = 1;
		} else {
			vis[f[i]] = 1;
			mp[f[i]] = i;
		}
	}
	for (int i = l; i <= n; i++)
		if (!p[i])
			res.push_back(f[i]);
	return res;
}

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> f[i];
	for (int t = 1; t <= n; t++) {
		deque<int>tmp = get(f, t);
		for (auto i : tmp)
			ans[i]++;
	}
	for (int i = 1; i <= m; i++)
		cout << ans[i] << " ";
	return 0;
}
