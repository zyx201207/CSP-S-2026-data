#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 5e5 + 10000;
int n;
ll m;
ll a[N];
ll pre[N];


bool check (ll len) {
	for (int L = 1; L + len - 1 <= n; ++ L) {
		int R = L + len - 1;
		if (a[R] * len - (pre[R] - pre[L - 1]) <= m) return true;
	}
	return false;
}

int main () {
    freopen ("crystal.in", "r", stdin);
    freopen ("crystal.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; ++ i) {
		cin >> a[i];
	}
	sort (a + 1, a + n + 1);

	pre[0] = 0;
	for (int i = 1; i <= n; ++ i) {
		pre[i] = pre[i - 1] + a[i];
	}

	int l = 1, r = n;
	while (l < r) {
        //cout << l << ' ' << r << endl;
		int mid = (l + r + 1) >> 1;
		if (check (mid)) {
			l = mid;
		}
		else {
			r = mid - 1;
		}
	}
	cout << l << endl;
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
