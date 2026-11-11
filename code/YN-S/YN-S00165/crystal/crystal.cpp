#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int n, m;
int f[N], p[N];
int ans;
map<int, int>mp;

bool ch(int x) {
	deque<int>pre, g;
	int cnt = 0, cur = 0;
	for (int i = 1; i <= x; i++)
		pre.push_back(f[i]), cnt += p[i];
	cur = cnt;
	for (int i = x + 1; i <= n; i++) {
		int tmp = p[i - x + 1];
		int num = cur + p[i] - tmp;
		if (num < cnt) {
			pre.push_back(f[i]);
			pre.pop_front();
			cnt = num;
		}
		cur = num;
	}
	for (int i = mp[pre.back()] - x + 1; i <= mp[pre.back()]; i++)
		g.push_back(f[i]);
	int res = 0;
	for (int i = 0; i < g.size(); i++)
		res = res + g.back() - g[i];
	return res <= m;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> f[i];
	sort(f + 1, f + n + 1);
	p[1] = 1;
	for (int i = 2; i <= n; i++)
		p[i] = f[i] - f[i - 1];
	for (int i = 1; i <= n; i++)
		mp[f[i]] = i;
	int l = 0, r = n;
	while (l <= r) {
		int mid = l + ((r - l) >> 1);
		if (ch(mid)) {
			ans = mid;
			l = mid + 1;
		} else
			r = mid - 1;
	}
	cout << ans;
	return 0;
}
