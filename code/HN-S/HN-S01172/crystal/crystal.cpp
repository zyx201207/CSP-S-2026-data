#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5e5 + 10;

int n, m, a[N], sum[N];

bool Check(int len) {
	for (int i = 1; i + len - 1 <= n; i++) {
		int j = i + len - 1;
		int val = a[j];
		if (val * (len - 1) - (sum[j - 1] - sum[i - 1]) <= m)
			return 1;
	}
	return 0;
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (n == 1) {
		cout << 1;
		return 0; 
	}
	sort (a + 1, a + 1 + n);
//	if (m == 0) {
//		int cnt 
//	}
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	int l = 0, r = n + 1;
	while (l + 1 < r) {
		int Mid = l + r >> 1;
		if (Check(Mid))
			l = Mid;
		else
			r = Mid;
	}
	cout << l;
	return 0;
}

/* 

5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

历经千辛万苦于 16:53 写完 

*/
