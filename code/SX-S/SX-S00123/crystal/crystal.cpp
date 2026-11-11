#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+5, M = 1e18;
int n, m, ans = INT_MIN, a[N], s[N];

bool check(int x, int o) {
	return (a[o] * (o - x) - (s[o - 1] - s[x - 1])) <= m;
	//attention
}

int half_find(int x) {
	int l = 1, r = x, mid, answer;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid, x)) {
			answer = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	return answer;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", a + i);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
	}
//	for (int i = 1; i <= n; i++) {
//		if (a[i] == a[i + 1])
//			continue;
//		int mm = m, mans = 0;
//		for (int j = i; j >= 1; j--) {
//			mans++;
//			int hal = a[i] - a[j];
////			if (hal < 0)
////				hal *= -1;
//			mm -= hal;
//			if (mm <= 0)
//				break;
////			printf("%lld:%lld,%lld\n", mans, i, j);
//		}
//
//		if (mm < 0)
//			mans--;
//		ans = max(mans, ans);
//	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == a[i + 1])
			continue;
		int pla = half_find(i);
		ans = max(ans, i - pla + 1);
	}
	printf("%lld", ans);
	return 0;
}