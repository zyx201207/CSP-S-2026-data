#include <bits/stdc++.h>
#define ll long long
const int N = 2e6 + 10;
const int M = 5010;
using namespace std;

int c, n;
ll d, x[N], dp[M], cnt[M], a[M];

int lowbit(int x) {
	return x & (-x);
}

void add(int x, ll y) {
	while(x <= n) {
		a[x] += y;
		x += lowbit(x);
	}
}

ll query(int x) {
	ll res = 0;
	
	while(x) {
		res += a[x];
		x -= lowbit(x);
	}

	return res;
}

void solve1() {
	ll ans = 0;

	for(int i = 1; i <= n; i++) {
		int l = i;
		for(int j = 1; j <= n; j++) dp[j] = cnt[j] = 1e7, a[j] = 0;
		dp[i] = 0, cnt[i] = 1;
		add(i, 1);

		for(int j = i + 1; j <= n; j++) {
			while(x[j] - x[l] > d) l++;
			if(j == l) continue;

			dp[j] = min(dp[j], dp[l] + 1);
			int nxt = upper_bound(dp + l, dp + j + 1, dp[l]) - dp - 1;
			cnt[j] = query(nxt) - query(l - 1);
			if(cnt[j] == 2) ans++;
			add(j, cnt[j]);
		}
	}

	printf("%lld\n", ans);
}

void solve2() {	int i = 1;
	while(i < n && x[i + 1] - x[1] <= d) i++;
	
	if(i <= 2) {
		printf("0\n");
		return;
	}

	i--;
	int num1 = i * 2 - 1;
	printf("%d\n", max(0, n - num1));
}

void solve() {
	scanf("%d %lld", &n, &d);
	for(int i = 1; i <= n; i++) scanf("%lld", &x[i]);

	if(n <= M) solve1();
	else if(x[2] - x[1] == x[3] - x[2] && x[2] - x[1] == x[n] - x[n - 1]) solve2();
	else printf("0\n");
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int T;
	scanf("%d %d", &c, &T);

	while(T--) solve();

	return 0;
}
