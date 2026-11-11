#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 5e5 + 5;
int n, m, arr[MAXN], qzh[MAXN];
int dis(int p, int q) {
	if (p > q) swap (p, q);
	return (q - p + 1) * arr[q] - (qzh[q] - qzh[p - 1]);
}

int findp(int l, int r, int end, int maxval) {
//	printf("%d to %d\n", l, r);
	if (l >= r) return end - l + 1;
	int mid = (l + r) / 2;
	int here_dis = dis(mid, end);
//	printf("distance in middle %d is %d\n", mid, here_dis);
	if (here_dis > maxval) {
		findp(mid + 1, r, end, maxval);
	} else {
		findp(l, mid, end, maxval);
	}
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &arr[i]);
	}
	sort(arr + 1, arr + 1 + n);
	for (int i = 1; i <= n; i++) {
		qzh[i] = arr[i] + qzh[i - 1];
//		cout << qzh[i] << endl;
	}
	int ans = -1;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, findp(1, i, i, m));
//		printf("complete %d\n", i);
	}
	printf("%lld", ans);
	return 0;
} 
