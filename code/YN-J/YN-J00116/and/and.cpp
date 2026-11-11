#include <bits/stdc++.h>
using namespace std;
map<long long, int> mp;
long long sum[200005], vis[200005];
int a[200005];
int maxn = -1;
int n, m;

void dfs(int dep, int now, int ans) {
	if (n - dep + now  < m)
		return ;
	if (dep == n || now == m) {
		if (now == m) {
//			cout << ans << '\n';
			maxn = max(maxn, ans);
		}
		return ;
	}
	for (int i = dep; i <= n; i++) {


		if (!vis[i]) {
			//cout << a[i] << " " << ans << " " << now << " " << (ans & a[i]) << "\n";
			vis[i] = 1;
			dfs(dep + 1, now + 1, (ans & a[i]));
			vis[i] = 0;
		}


		dfs(dep + 1, now, ans);

	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	int flag1 = 1, flag2 = 1, ff = 0;
	sum[1] = 1;
	sum[2] = 3;
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] * 2 + 1;
		mp[sum[i]] = 1;
	}
	mp[1] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (mp[a[i]] == 0) {
			flag1 = 0;

		}
		if (mp[a[i]] == 1) {
			ff = max(ff, a[i]);
		}
		if (a[i] != i - 1)
			flag2 = 0;
	}
	if (flag1 || (ff != 0 && m == 2) ) {

		sort(a + 1, a + 1 + n);
		if (flag1) {
			cout << a[n - m + 1];
			return 0;
		}

		else {
			for (int i = n; i >= 1; i--) {
				if (a[i] == ff) {
					cout << a[i - 1];
					return 0;
				}

			}
		}

	} else if (flag2) {
		cout << n - m;
	} else {
		dfs(1, 0, INT_MAX);
		cout << maxn;
	}
	return 0;
}


