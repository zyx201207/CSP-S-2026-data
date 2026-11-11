#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 2e5 + 5;
int n, m;
ll a[N];

bool cmp(ll x, ll y) {
	return x > y;
}
int ans = 0;

void dfs(int idx, int y, int z) {
	if (idx == m) {
		ans = max(y, ans);
		return;
	}

	for (int i = z + 1; i <= n; i++) {

		idx++;
		int w = y & a[i];
		dfs(idx, w, i);
		idx--;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	cin >> n >> m;

	if (n == m) {
		cin >> a[1];
		ll res = a[1];

		for (int i = 2; i <= n; i++) {

			cin >> a[i];
			res &= a[i];
		}

		cout << res;
	} else if (m == 1) {
		ll res = 0;

		for (int i = 1; i <= n; i++) {

			cin >> a[i];
			res = max(res, a[i]);
		}

		cout << res;
	} else if (n <= 20) {
		for (int i = 1; i <= n; i++) {

			cin >> a[i];
		}

		for (int i = 1; i <= n; i++) {

			dfs(1, a[i], i);
		}

		cout << ans;
	} else if (m == 2) {
		for (int i = 1; i <= n; i++) {

			cin >> a[i];
		}

		int res = 0;

		for (int i = 1; i <= n; i++) {

			for (int j = i + 1; j <= n; j++) {

				int d = a[i] & a[j];
				res = max(res, d);
			}
		}

		cout << res;
	} else {
		int f1 = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt0 = 0;

		for (int i = 1; i <= n; i++) {

			cin >> a[i];

			if (a[i] >= 4)
				f1 = 1;

			if (f1 == 0) {
				if (a[i] == 1)
					cnt1++;
				else if (a[i] == 2)
					cnt2++;
				else if (a[i] == 3)
					cnt3++;
				else
					cnt0++;
			}
		}

		if (f1 == 0) {
			if (cnt3 >= m) {
				cout << 3;
			} else if (m >= cnt2) {
				cout << 2;
			} else if (m >= cnt1) {
				cout << 1;
			} else {
				cout << 0;
			}
		} else {
			sort(a + 1, a + n + 1, cmp);
			cout << a[m];
		}
	}

	return 0;
}