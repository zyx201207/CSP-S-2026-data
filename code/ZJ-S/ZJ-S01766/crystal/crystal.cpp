#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 3;
int n;
long long m, a[N], srr[N];

bool check(int x) {
	long long sum;
	int len;
	for (int l = 1, r = x; r <= n; l++, r++) {
		len = r - l + 1;
		sum = len * a[r] - (srr[r] - srr[l - 1]);
		if (sum <= m) {
			return true;
		}
	}
	return false;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) 
		srr[i] = srr[i - 1] + a[i];
	int l = 1, r = n, mid;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (check(mid)) l = mid + 1;
		else r = mid - 1;
	}
	cout << l - 1;
	return 0;
}
