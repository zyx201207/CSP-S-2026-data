#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, ans, Max, Minn, a[N], dif[N];
bool pan, pann;

bool checkk(int x, int y) {
	int cnt = 0, sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += abs(x - a[i]);
		cnt++;
		if (cnt >= y)return sum <= m;
	}
	return 0;
}

bool check(int x) {
	int cnt = 0, sum = 0;
	int l = Minn, r = Max, Min = 0;
	for (; l <= r;) {
		int mid = (l + r) >> 1;
		if (checkk(mid, x)) {
			l = mid + 1;
			Min = mid;
		} else {
			r = mid - 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (Min < a[i])continue;
		sum += abs(Min - a[i]);
		cnt++;
		if (cnt >= x)return sum <= m;
	}
	return 0;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	pan = pann = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		Max = max(Max, a[i]), Minn = min(Minn, a[i]);
		if (a[i] != i)pan = 0;
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		if (i >= 2) {
			if (a[i] != a[i - 1] + a[2] - a[1]) pann = 0;
		}
	}
	if (pan == 1) {
		int Min = n, sum = 0, cnt = 0;
		for (int i = 1; i <= n; i++) {
			dif[i] = Min - a[i];
		}
		sort(dif + 1, dif + n + 1);
		for (int i = 1; i <= n; i++) {
			if (dif[i] > 0)sum += dif[i];
			if (sum <= m) cnt++;
			else break;
		}
		cout << cnt << "\n";
		exit(0);
	} else if (pann == 1) {
		int ne = 0, las = 1, cnt = 0;
		for (; ne <= m;) {
			las *= (a[2] - a[1]);
			ne += las;
			cnt++;
		}
		exit(0);
	} else if (n <= 5000) {
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int sum = 0, cnt = 0;
			for (int j = 1; j <= n; j++) {
				dif[j] = a[i] - a[j];
			}
			sort(dif + 1, dif + n + 1);
			for (int j = 1; j <= n; j++) {
				if (dif[j] < 0)continue;
				sum += dif[j];
				if (sum <= m) cnt++;
				else break;
			}
			ans = max(ans, cnt);
		}
		cout << ans;
		exit(0);
	}
	int l = 0, r = n;
	for (; l <= r;) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout << ans;
	return 0;
}