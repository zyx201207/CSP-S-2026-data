#include <bits/stdc++.h>
#define int long long
void gtmx(int& r, int p) { r = std::max(r, p); }

const int MAXN = 5e5 + 20;

int n, m;
int a[MAXN];
int ans = 0;

// 我不会写双指针, 怎么办!!
void solve() {
	int lp = 1ll, rp = 1ll;
	int rem = m, num = 1ll;
	while (lp <= rp && lp <= n && rp <= n) {
		while (rp < n && a[lp] - a[rp + 1] <= rem) {
			rp++; rem -= a[lp] - a[rp];
			gtmx(ans, ++num);
		}
		
		/*调整 lp*/
		if (lp == n) break;
		int delta = a[lp] - a[lp + 1]; num--;
		rem += delta * num;
		lp++;
	}
	
	printf("%lld", ans);
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	
	std::sort(a + 1, a + n + 1);
	std::reverse(a + 1, a + n + 1);
	
	solve();
	
	return 0;
}

// 说好带你流浪, 而我却半路返航, 坠入自责的海洋