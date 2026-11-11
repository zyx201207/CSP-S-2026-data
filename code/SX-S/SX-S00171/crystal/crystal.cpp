#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5+15;
int n;
long long m;
long long sum[N];
long long a[N];

bool check(int x) {
	for (int i = x; i <= n; i++) {
		if ((ll)a[i]*x - sum[i] + sum[i - x] <= m) {
			return 1;
		}
	}
	return 0;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		sum[i] = a[i] + sum[i - 1];
	}
	int l = 1;
	int r = n;
	int ans;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			l = mid + 1;
			ans = mid;
		} else
			r = mid - 1;
	}
	cout << ans;
	return 0;
}
