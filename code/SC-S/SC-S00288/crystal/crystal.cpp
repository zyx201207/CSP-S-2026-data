#include <bits/stdc++.h>
#define int long long 

using namespace std;

int n, m, a[500001], maxn = -1e18;
int b[500001];

int check(int x) {
	int l = 1, r = x; 
	int cnt = 1e18;
	while(l < r) {
		int mid = (l + r) / 2;
		int sum = (a[x] * (x - mid + 1) - (b[x] - b[mid - 1]));
		if(sum == m) {
			cnt = min(cnt, mid);
		}
		if (sum < m) {
			cnt = min(cnt, mid);
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	if (l == r) {
		int sum = (a[x] * (x - l + 1) - (b[x] - b[l - 1]));
		if (sum <= m) cnt = min(cnt, l);
	}
//	int sum = 0, cnt = 1;
//	for(int i = x - 1; i >= 1; i--) {
//		if (a[x] - a[i] <= m - sum) {
//			sum += a[x] - a[i];
//			cnt++;
//		} else break;
//	}
	return x - cnt + 1;
}

void t(int l, int r) {
	if (l > r) return;
	if (l == r) {
		maxn = max(maxn, check(l));
	}
	int mid = (l + r) / 2, flag = check(mid);
	maxn = max(maxn, flag);
	if (flag == mid) {
		t(mid + 1, r);
	} else {
		t(max(l, flag), mid - 1);
		t(mid + 1, r);
	}
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	stable_sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) b[i] = b[i - 1] + a[i];
	t(1, n);
	cout << maxn;
	return 0;	
}