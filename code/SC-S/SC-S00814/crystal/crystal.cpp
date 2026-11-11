#include <bits/stdc++.h>
#define max(a, b) a > b ? a : b
#define ll long long
using namespace std;

ll n, a[500005], m, s[500005], ans = -1;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	} sort(a+1, a+n+1);
	for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];
	for(int i = 1;i <= n; ++i) {
		int l = 1, r = i;
		while(l < r) {
			int mid = (l + r) >> 1;
			if (s[i] + m >= (i - mid + 1) * a[i] + s[mid - 1]) {
				r = mid;
			} else l = mid + 1;
		} ans = max(ans, i - l + 1);
	} cout << ans;
	
	return 0;
}