#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5 + 5;
#define LL long long

int n;
LL m, a[maxn];
LL pre_sum[maxn];

bool check(int L) {
	for (int i = 1; i + L - 1 <= n; i ++) {
		LL sum = pre_sum[i + L - 1] - pre_sum[i - 1];
		LL ned = a[i + L - 1] * L - sum;
		if (ned <= m) return 1;
	}
	return 0;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i ++) {
		pre_sum[i] = pre_sum[i - 1] + a[i];
	}
	
	int l = 1, r = n, mid, ans;
	for (; l <= r; ) {
		mid = (l + r) >> 1;
		check(mid) ?  l = (ans = mid) + 1 : r = mid - 1;
	}
	
	return cout << ans, 0;
}
