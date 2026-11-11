#include <bits/stdc++.h>
using namespace std;
int c, t, n, d, a[1000005], p[500005], step[5000005], ans;
vector<int> vt[1000005];

void dfs(int x, int st) {//x-об╠Й
	if (st < step[x]) {
		p[x] = 1;
		step[x] = st;
	} else if (st == step[x])
		p[x]++;
	for (int i = 0; i < vt[x].size(); i++) {
		dfs(vt[x][i], st + 1);
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		memset(a, 0, sizeof p);
		ans = 0;
		for (int i = 1; i <= 1005; i++)
			vt[i].clear();
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = 1; i < n; i++)
			for (int j = i + 1; j <= n; j++)
				if (a[j] - a[i] <= d)
					vt[i].push_back(a[j]);
		for (int i = 1; i < n; i++) {
			memset(p, 0x3f, sizeof p);
			memset(step, 0x3f, sizeof step);
			dfs(a[i], 0);
			for (int j = i + 1; j <= n; j++)
				if (p[a[j]] == 2)
					ans++;
		}
		cout << ans << endl;
	}

	return 0;
}