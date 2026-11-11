#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 5e5 + 5;
int n;
ll m, a[MAXN];
bool check(int x) {
	ll sum = 0;
	for (int i = 1; i <= n; i ++) {
		if (a[i] >= a[x]) break;
		sum += a[x] - a[i];
	}
	return sum <= m;
}
int main () {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	int l = 1, r = n, maxn = 0;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(mid)) {
			l = mid + 1;
			maxn = mid;
		} else {
			r = mid - 1;
		}
	}
	cout << maxn;
	return 0;
}

