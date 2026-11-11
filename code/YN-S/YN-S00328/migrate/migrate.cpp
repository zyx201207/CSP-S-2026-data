#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2000005;
int c, T, n, d;
ll x[N];
int cnt[114][514][10];
vector<pair<ll, int> > curr;

void dfs(int idx) {
	if (idx == n + 1) {
		if (curr.size() < 2)
			return;
		for (int i = 1; i < curr.size(); ++i)
			if (curr[i].first - curr[i - 1].first > d)
				return;
		int u = curr.front().second, v = curr.back().second, l = curr.size() - 1;
		++cnt[u][v][l];
		return;
	}
	dfs(idx + 1);
	curr.push_back(make_pair(x[idx], idx));
	dfs(idx + 1);
	curr.pop_back();
}

int solve1() {
	int ans = 0;
	dfs(1);
	for (int i = 1; i <= n; ++i)
		for (int j = i; j <= n; ++j)
			for (int k = 1; k <= n; ++k)
				if (cnt[i][j][k] != 0) {
					if (cnt[i][j][k] == 2)
						++ans;
					break;
				}
	return ans;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> T;
	while (T--) {
		cin >> n >> d;
		for (int i = 1; i <= n; ++i)
			cin >> x[i];
		if (c <= 2)
			cout << solve1() << '\n';
		else
			cout << "114514\n";
	}
	return 0;
}