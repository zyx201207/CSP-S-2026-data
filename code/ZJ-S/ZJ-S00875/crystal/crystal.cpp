#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 500010;
int n, m, a[N], s[N], ans;
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
//		cout << s[i] << " ";
	}
//	cout << endl;
	int l = 1, r = 1;
	for(; r <= n; r++) {
		while(l < r && a[r] * (r - l) - s[r - 1] + s[l - 1] > m) l++;
//		cout << l << " " << r << " " << a[r] * (r - l) - s[r - 1] + s[l - 1] << endl;
		ans = max(ans, r - l + 1);
	}
	cout << ans;
	return 0;
}
