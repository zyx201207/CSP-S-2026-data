#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500010];
map<int, int>mp;
int ans = -1;
int n, m;
int gap;

int check(int x) {
	int now = (n + 1 - x) * (n - x) / 2;
	return now <= m;
}

int check1(int x) {
	int now = (n - x) * (gap + (n - x) * gap) / 2;
	return now <= m;
}

void dfs(int step, int use) {
	if (use > m)
		return;
	int mmax = -1;
	mp.clear();
	for (int i = 1; i <= n; i++) {
		mp[a[i]]++;
		mmax = max(mmax, mp[a[i]]);
	}
	ans = max(mmax, ans);
	for (int i = 1; i <= n; i++) {
		a[i]++;
		dfs(step + 1, use + 1);
		a[i]--;
	}
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int tot = 1, flag = 1;
	for (int i = 1; i <= m; i++) {
		tot *= n;
		if (tot > 30000000) {
			flag = 0;
			break;
		}
	}
	if (flag) {
		dfs(1, 0);
		cout << ans;
		return 0;
	} else {
		if (a[2] - a[1] == 1) {
			int l = 0, r = n + 1;
			while (l + 1 < r) {
				int mid = ((l + r) >> 1);
				if (check(mid))
					r = mid;
				else
					l = mid;
			}
			cout << n - r + 1;
		} else {
			sort(a + 1, a + n + 1);
			gap = a[2] - a[1];
			int l = 0, r = n + 1;
			while (l + 1 < r) {
				int mid = ((l + r) >> 1);
				if (check1(mid))
					r = mid;
				else
					l = mid;
			}
			cout << n - r + 1;
		}
	}
	return 0;
}