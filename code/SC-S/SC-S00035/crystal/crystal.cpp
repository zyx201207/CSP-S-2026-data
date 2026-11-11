#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 5e5+3;
int n, res = 0;
LL a[N], m;
LL pre[N];
bool check(LL l, LL r) {
	return (r-l+1)*a[r]-(pre[r]-pre[l-1]) <= m;
} 
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i-1] + a[i];
	}
	int l = 1;
	for (int i = 1; i <= n; i++) {
		int j = i, ans = -1, r = i;
		while (a[j+1] == a[i]) j++;
		
		
		while (l <= r) {
			int mid = l + r >> 1;
			if (check(mid, i)) {
				r = mid-1;
				ans = mid;
			} else {
				l = mid+1;
			}
		}
		l = ans;
//		cout << ans << endl;
		res = max(res, j-ans+1);
		i = j;
	}
	cout << res;
	return 0;
} 