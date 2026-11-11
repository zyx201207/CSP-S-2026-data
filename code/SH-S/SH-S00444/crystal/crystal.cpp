# include <iostream>
# include <algorithm>
# include <cstdio>
# include <queue>
# include <vector>
# include <map>
# include <cstring>
# include <cmath>

typedef long long LL;
const int NR = 5e5 + 10;
int N;
LL M;
LL a[NR], s[NR];
LL d[NR];

int solve(int id) {
	LL l = 1LL, r = (LL)id;
	LL ret = l;
	while (l <= r) {
		LL mid = (l + r) / 2LL;
		if (mid * a[id] - s[id] + s[id - mid] <= M) {
			ret = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	return (int)ret;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%lld", a + i);
	}
	std::sort(a + 1, a + 1 + N);
	for (int i = 1; i <= N; i++) {
		s[i] = s[i  - 1] + a[i];
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		ans = std::max(ans, solve(i));
	}
	printf("%d\n", ans);
	return 0;
}
