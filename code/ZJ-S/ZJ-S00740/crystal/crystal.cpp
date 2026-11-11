#include <bits/stdc++.h>
#define FL(i, a, b) for (int i = (a); i <= (b); ++i) 
#define FR(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
typedef long long ll; // check ll
const int N = 5e5 + 10;
int n, ans;
ll m, a[N], s[N];
bool Check(int l, int r) {
	return (ll)a[r] * (r - l + 1) - (s[r] - s[l - 1]) <= m;
}
int main() {
//	freopen("crystal.in", "r", stdin);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d %lld", &n, &m);
	FL(i, 1, n) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	FR(i, n, 1) a[i] -= a[1];
	FL(i, 1, n) s[i] = s[i - 1] + a[i];
	FL(i, 1, n) {
		int l = 1, r = i, x = 1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (Check(i - mid + 1, i)) {
				x = mid;
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		ans = max(ans, x);
	}
	printf("%d\n", ans);
	return 0;
}
