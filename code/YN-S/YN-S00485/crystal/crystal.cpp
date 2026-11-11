#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int a[N];
long long sum[N];
long long n, m;

bool cheak(int mimi) {
	for (int i = mimi - 1; i < n; i++) {
		if (m >= sum[i] - sum[i - mimi + 1] - (a[i] - a[i - mimi + 1]) * (i - mimi + 2)) {
			return true;
		}
	}
	return false;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 1; i < n; i++) {
		sum[i] = (sum[i - 1]) + (a[i] - a[i - 1]) * i;
	}
	int l = 1, r = n + 1;
	while (l < r) {
		int mid = r + l;
		mid /= 2;
		if (cheak(mid)) {
			l = mid ;
		} else {
			r = mid - 1;
		}
	}
	cout << l;
	return 0;
}
