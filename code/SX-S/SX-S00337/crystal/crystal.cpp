#include <bits/stdc++.h>
using namespace std;
int n, ans;
long long m;
long long a[500005];

bool cnp(int x1, int x2) {
	return x1 < x2;
}

int check(int x) {
	int h = m, cnt = 0;
	for (int i = x; i >= 0; i--) {
		if (h >= 0) {
			h = h - (a[x] - a[i]);
			cnt++;
		} else
			return cnt;
	}
	return cnt;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n, cnp);
	for (int i = 0; i < n; i++) {
		ans = max(ans, check(i));
	}
	cout << ans;
	return 0;
}
