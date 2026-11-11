#include <bits/stdc++.h>
#define int long long
const int N = 2e5 + 5;
using namespace std;
int n, m, a[N], maxx, ans, flag;
int dfs(int x, int cnt, int sum) {
	int ans1 = 0;
	if (x > n) {
		return -1;
	}
	if (cnt == m) {
		return sum;
	}
	for (int i = x + 1; i <= n; i++) {
		ans1 = max(ans1, dfs(i, cnt + 1, (sum & a[i])));
	}
	return ans1;
}
bool cmp(int a, int b) {
	return a > b;
}
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		double l1 = log2(a[i] + 1);
		int l2 = l1;
		if (l1 != l2) {
			flag = 1;
		}
		maxx = max(maxx, a[i]);
	}
	if (!flag) {
		sort(a + 1, a + n + 1, cmp);
		cout << a[m];
		return 0;
	}
	if (m == 1) {
		cout << maxx;
		return 0;
	}
	if (m == n) {
		for (int i = 1; i <= n; i++) {
			ans &= a[i];
		}
		cout << ans;
		return 0;
	}
	if (m == 2) {
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				ans = max(ans, (a[i] & a[j]));
			}
		}
		cout << ans;
		return 0;
	}
	if (maxx < 4) {
		int cnt1 = 0, cnt2 = 0, cnt3 = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] == 1) {
				cnt1++;
			} else if (a[i] == 2) {
				cnt2++;
			} else {
				cnt3++;
			}
		}
		if (cnt3 >= m) {
			cout << 3;
		} else if (cnt3 + cnt2 >= m) {
			cout << 2;
		} else if (cnt3 + cnt1 >= m) {
			cout << 1;
		} else {
			cout << 0;
		}
		return 0;
	}
	if (n <= 20) {
		for (int i = 1; i + m - 1 <= n; i++) {
			ans = max(ans, dfs(i, 1, a[i]));
		}
		cout << ans;
		return 0;
	}
	sort(a + 1, a + n + 1, cmp);
	cout << a[m];
	return 0;
}
