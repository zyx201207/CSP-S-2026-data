#include<iostream>
#define int long long
using namespace std;
const int maxn = 2e5+100;
int a[maxn], ans[maxn], cntans;
char s[maxn];
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i] >> s[i];
	int l = 1, r = n;
	while (l < r) {
		if (s[l] != s[r]) {
			if (a[l] < a[r]) {
				int x = a[l], cnt = 0;
				while(x) {
					ans[++cnt] += x%10;
					x /= 10;
				}
				cntans = max(cnt, cntans);
				a[r] -= a[l];
				l++;
			}
			else {
				int x = a[r], cnt = 0;
				while(x) {
					ans[++cnt] += x%10;
					x /= 10;
				}
				cntans = max(cnt, cntans);
				a[l] -= a[r];
				r--;
			}
		}
		else {
			if (a[l] < a[r]) a[r] -= a[l], l++;
			else a[l] -= a[r], r--;
		}
	}
	int cnt = 1, f = 0;
	while (cnt <= cntans || ans[cnt]) {
		ans[cnt+1] += ans[cnt] / 10;
		ans[cnt] %= 10;
		cnt++;
	}
	for (int i = cnt-1; i >= 1; i--) {
		cout << ans[i];
		f = 1;
	}
	if (!f) cout << 0;
	return 0;
}
