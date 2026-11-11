#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int n, ans;
long long m;
long long a[N];
long long cost[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + 1 + n);
	for (int i = 2; i <= n; i++)
		cost[i] = cost[i - 1] + (i - 1) * (a[i] - a[i - 1]);
	for (int i = 1; i <= n; i++) {
		if (cost[i] <= m)
			ans = i; //够用
		else {
			//不够用的话剪掉前面的大开销到够用，ans=max(ans,i-mid);
			long long ask = cost[i] - m;
			int l = 1, r = i - 1, pos = 0;
			while (l <= r) {
				int mid = (l + r) >> 1;
				long long have = cost[mid] + (mid) * (a[i] - a[mid]);
				if (have >= ask) {
					r = mid - 1;
					pos = mid;
				} else
					l = mid + 1;
			}
			ans = max(ans, i - pos);
		}
	}
	printf("%d\n", ans);
	return 0;
}