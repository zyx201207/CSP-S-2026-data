#include <bits/stdc++.h>
using namespace std;
long long n, m, diff[500005], a[500005], ma = 0;
void work();

void dfs(int this_number) {
	if (this_number == m) {
		work();
		return;
	}
	for (int i = 1; i <= n; i++) {
		diff[i]++;
		dfs(this_number + 1);
		diff[i]--;
	}
}

void work() {
	long long now_number = 100000000000000, ans = 0;
	for (int i = 1; i <= n; i++) {
		if (now_number != diff[i] + a[i]) {
			now_number = diff[i] + a[i];
			ma = max(ma, ans);
			ans = 0;
			ans++;
		} else {
			ans++;
		}
	}
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	dfs(0);
	printf("%d", ma);
}