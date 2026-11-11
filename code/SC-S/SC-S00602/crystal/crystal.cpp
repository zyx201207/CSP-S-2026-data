#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
int n, ans;
long long m;
int a[N];
int l, r;
long long sum;


int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) cin >> a[i];

	sort(a + 1, a + n + 1);

	l = 1, r = 1;

	for (l = 1; l <= n;) {
		while (r < n) {
			long long cost = (a[r + 1] - a[r]) * (r - l + 1);
			if (sum + cost > m) break;
			sum = sum + cost;
			r++;
		}

		if (r - l + 1 > ans) ans = r - l + 1;

		long long sub = a[r] - a[l];
		sum = sum - sub;

		l++;
	}

	cout << ans;
	return 0;
}