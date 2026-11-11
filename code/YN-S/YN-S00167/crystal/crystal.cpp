#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long m, a[N];
int n;

bool check(int x) {
	int cnt = 1, maxx = 0;
	long long sum = m;
	for (int i = 1; i < n; i++) {
		if (a[i] == a[i + 1])
			cnt++;
		else if (a[i] < a[i + 1]) {
			if (sum < (a[i + 1] - a[i]) * cnt)
				maxx = max(maxx, cnt), cnt = 1, sum = m;
			else
				sum -= (a[i + 1] - a[i]) * cnt, cnt++;
		}
	}
	maxx = max(maxx, cnt);
	return maxx >= x;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	int l = 0, r = 5e5, ans = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			ans = mid, l = mid + 1;
		} else
			r = mid - 1;
	}
	cout << ans << endl;
	return 0;
}