#include <bits/stdc++.h>
using namespace std;
long long n, m, ans = INT_MAX;

struct node {
	long long x;
	int sum;
} a[200010];

bool cmp(node a, node b) {
	if (a.sum > b.sum) {
		return 1;
	} else if (a.sum == b.sum) {
		return a.x > b.x;
	} else {
		return 0;
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int  i = 1; i <= n; i ++) {
		cin >> a[i].x;
		long long p = a[i].x;
		while (p) {
			if (p % 2 == 1) {
				a[i].sum ++;
			}
			p /= 2;
		}
	}
	sort(a + 1, a + 1 + n, cmp);
	for (int i = 1; i <= m; i ++) {
		ans &= a[i].x;
	}
	cout << ans;
	return 0;
}
