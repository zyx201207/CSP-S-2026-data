#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500005;

int n;
long long a[MAXN], m;

long long pa[MAXN];
bool check(int l, int r) {
	return (r - l + 1) * a[r] <= m + pa[r] - pa[l - 1];
}
int binary(int r) {
	int lp = 1, rp = r, mid, ans = r;
	while (lp < rp) {
		mid = (lp + rp) >> 1;
		if (check(mid, r)) rp = ans = mid;
		else lp = mid + 1;
	}
	return r - ans + 1;
} 

int ans;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) pa[i] = pa[i - 1] + a[i];
	for (int i = 1; i <= n; i++) {
		ans = max(ans, binary(i));
	}
	cout << ans;
	
	return 0;
} 
