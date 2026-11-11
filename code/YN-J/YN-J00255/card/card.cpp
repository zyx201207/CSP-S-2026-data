#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, ans[300005], a[500005];
bool vis[300005];

void F(ll s, ll f) {
	deque<ll>q;
	for (int i = s; i <= f; i++) {
		if (!vis[a[i]])
			q.push_back(a[i]), vis[a[i]] = 1;
		else {
			while (q.back() != a[i]) {
				vis[q.back()] = 0;
				q.pop_back();
			}
		}
	}
	while (!q.empty()) {
		ans[q.front()]++;
		q.pop_front();
	}
	memset(vis, 0, sizeof vis);
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		F(i, n);
	for (int i = 1; i <= m; i++)
		cout << ans[i] << ' ';
	return 0;
}