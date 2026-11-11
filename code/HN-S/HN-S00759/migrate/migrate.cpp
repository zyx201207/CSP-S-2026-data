#include <bits/stdc++.h>
using namespace std;
vector<int> v[2000005];
long long d, ans, a[2000005];
int c, t, n, fa[2000005], dis[2000005], pre[2000005];
void dfs(int x) {
	for(int i : v[x])
		dfs(i);
	if(v[x].size()) {
		dis[x] = dis[v[x][0]] + v[x].size();
		pre[x] = pre[v[x][0]];
		if(v[x].size() > 1)
			pre[x] += v[v[x][0]].size() ? v[v[x][1]].size() : dis[v[x][1]];
	}
	return;
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t--) {
		cin >> n >> d, ans = 0;
		for(int i = 1; i <= n; i++)
			cin >> a[i], v[i].clear(), dis[i] = pre[i] = 0;
		for(int i = n, j = n; i; i--) {
			while(a[j] - a[i] > d)
				j--;
			fa[i] = j;
			if(i ^ j)
				v[j].push_back(i);
		}
		for(int i = 1; i <= n; i++)
			sort(v[i].begin(), v[i].end());
		for(int i = 1, last = 0; i <= n; i++)
			if(fa[i] == i) {
				dfs(i);
				for(int p = i; p > last + 1; p--) {
					int l = last, r = p;
					while(l + 1 < r) {
						int mid = l + r >> 1;
						if(fa[mid] >= p)
							r = mid;
						else
							l = mid;
					}
					if(r + 1 < p) {
						// r,r+1
						if(v[r].size())
							ans += v[r + 1].size();
						else
							ans += dis[r + 1];
					}
					if(r < p)
						ans += pre[r];
				}
				last = i;
			}
		cout << ans << '\n';
	}
	return 0;
}