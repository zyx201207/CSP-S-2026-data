#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, ma = INT_MIN, manum = 0, pos = 0, a[500005];
map<int, int> median;

bool check(int x) {
	if (x <= ma) {
		return 1;
	}

	int mm = m, les = x - ma, cnt = 0;
	for (int i = pos - 1; i >= 1; i--) {
		if (a[i] == manum)
			cnt++;
		if (a[i] + mm >= manum) {
			cnt++;
			mm -= manum - a[i];
		}
	}


	cout << cnt << " " << les << endl;
	return cnt >= les;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}


	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		median[a[i]]++;
		if (ma < median[a[i]]) {
			ma = median[a[i]];
			manum = a[i];
			pos = i;
		}

		else if (ma == median[a[i]]) {
			if (manum < a[i]) {
				manum = a[i];
				pos = i;
			}
		}
	}

	int l = 1, r = n, mid = 0;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (check(mid))
			l = mid + 1;
		else
			r = mid - 1;
	}

	cout << r << endl;
	return 0;
}
