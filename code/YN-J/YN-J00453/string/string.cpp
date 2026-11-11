#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::min;
using std::max;
using std::vector;
using std::string;

#define int long long

#define fst first
#define scd second
#define pr std::pair<int,int>
#define ep emplace
#define eb emplace_back

static constexpr int MAXN = (int)(2e5) + 10;

int n, il[MAXN], ans;
char a[MAXN];

signed main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> il[i] >> a[i];
	int reml = il[1], remr = il[n];
	for (int i = 1, j = n; i <= j;) {
		if (reml <= remr) {
			if (a[i] != a[j])
				ans += reml;
			remr -= reml, reml = il[++i];
		} else {
			if (a[i] != a[j])
				ans += remr;
			reml -= remr, remr = il[--j];
		}
	}
	cout << ans << '\n';

	return 0;
}