#include <bits/stdc++.h>
using namespace std;
long long int a[1000010], b[1000010];
long long int n, m;
long long t = 0;

void check(int mid) {
	long long int cnt = m, sum = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] < mid) {
			cnt -= (mid - a[i]);
			sum++;
		}
		if (cnt <= 0) {
			break;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == mid) {
			sum++;
		}
	}
	t++;
	b[t] = sum;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	long long int maxn = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		maxn = max(maxn, a[i]);
	}
	sort(a + 1, a + n + 1);
	long long int l = 1, r = maxn, ans = 0;
	for (int i = 1; i <= maxn; i++) {
		check(i);
	}
	long long int maxn1 = 0;
	for (int i = 1; i <= t; i++) {
		maxn1 = max(maxn1, b[i]);
	}
	cout << maxn1;
	return 0;
}