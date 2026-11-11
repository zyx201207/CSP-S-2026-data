#include <bits/stdc++.h>
using namespace std;

#define MAXN 500010

int n;
long long m, a[MAXN];
long long sum_delta[MAXN], delta[MAXN];

void init() {
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++) {
		delta[i] = a[i] - a[i - 1];
	}
	for (int i = 2; i <= n; i++) {
		sum_delta[i] = sum_delta[i - 1] + (a[i] - a[i - 1]) * (i - 1);
	}
	/*	for (int i = 1; i <= n; i++) {
			printf("%d ", sum_delta[i]);
		}
	*/
//	printf("Init_ok\n");
}

int chk1() {
//	printf("Into_chk\n");
	int index = (upper_bound(sum_delta + 1, sum_delta + n + 1, m + 1) - sum_delta);
//	printf("%d %lld %lld %lld\n", index, m, sum_delta[index], sum_delta[315275]);
	while (sum_delta[index] > m && index >= 1)
		index--;
//	printf("%d %lld %lld %lld\n", index, m, sum_delta[index], sum_delta[315275]);
	if (sum_delta[index] == m)
		return index;
	int cnt1 = index;
	index++;
	//printf("%lld %lld %lld", sum_delta[index], sum_delta[index - 1], m);
	int cnt2 = (sum_delta[index - 1] - m) / (a[index] - a[index - 1]) + 1;
	return max(cnt1, cnt2);

}

long long make_value(int l, int r) {
	if (r > n || l > r)
		return 0x7fffffffffffffff;
	return (sum_delta[r] - sum_delta[l] - (a[r] - a[l]) * (l - 1));
}

int chk2() {
	int h = 1, t = 1;
	int res = 0;
	while (h <= t && t <= n) {
		while (make_value(h, t + 1) <= m && t + 1 <= n)
			t++;
//		printf("%d %d\n", h, t);
		res = max(res, t - h + 1);
		h++;
	}
	return res;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	init();
	int ans = chk2();
//	printf("%d", make_value(1, 1))500000 1000000000000000000
//1000000000000;
	printf("%d", ans);
	return 0;
}
