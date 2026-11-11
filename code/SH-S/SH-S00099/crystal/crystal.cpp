#include<iostream>
#include<algorithm>
#define int long long
#define gc getchar
#define pc putchar
using namespace std;
int rd() {
	int res = 0, c = gc();
	bool f = false;
	while (c < 48 || c > 57) {
		if (c == 45) f = true;
		c = gc();
	}
	while (48 <= c && c <= 57) res = (res << 3) + (res << 1) + (c ^ 48), c = gc();
	if (f) return -res;
	return res;
}
void wr(int x) {
	if (x > 9) wr(x / 10);
	pc(x % 10 + 48);
}
const int maxn = 5e5 + 5;
int n, m, ans;
int a[maxn];
int sum[maxn];
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = rd(), m = rd();
	for (int i = 1; i <= n; i ++) a[i] = rd();
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i ++) sum[i] = sum[i - 1] + a[i];
	for (int i = 1; i <= n; i ++) {
		int l = 1, r = i, x = i;
		while (l <= r) {
			int mid = (l + r) >> 1; 
			if ((i - mid + 1) * a[i] - (sum[i] - sum[mid - 1]) <= m) {
				r = mid - 1;
				x = mid;
			} 
			else l = mid + 1;
		}
		ans = max(ans, i - x + 1);
	}
	wr(ans);
}
