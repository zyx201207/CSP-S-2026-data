#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 500005;
int n, ans = 1;
ll m, a[N];
int main () {
//	freopen ("crystal4.in", "r", stdin);
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	ios::sync_with_stdio (0);
	cin.tie (0);
	cout.tie (0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 1) {
		cout << "1\n";
		return 0;
	}
	sort (a + 1, a + 1 + n);
	int ptr = 1;
	ll now = 0ll;
	for (int i = 2; i <= n; i++) {
		now += (a[i] - a[i - 1]) * (ll) (i - ptr);
		while (now > m) {
			now -= a[i] - a[ptr];
			ptr++;
		}
		ans = max (ans, i - ptr + 1);
	}
	cout << ans << "\n";
	return 0;
}
/*
给定了一个数列 
我们要使得出现次数最多的数字尽可能大 

*/
