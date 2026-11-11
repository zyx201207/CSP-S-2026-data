#include<bits/stdc++.h> 
#define int long long
using namespace std;

const int N = 5e5 + 5;

int n, m, a[N], ans = 0;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout); 
	cin.tie(nullptr)->sync_with_stdio(false);
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	
	sort(a + 1, a + n + 1); 
	
	// 双指针秒了喵，8 min，空调好舒服，比年简单多了 qwq 
	for (int r = 1, l = 1, sum = 0; r <= n; ) {
		while (sum > m) {
			sum -= (a[r] - a[l]);
			++l;
		}
		int len = r - l + 1;
		ans = max(ans, len);
		sum += (a[r + 1] - a[r]) * len;
		++r;
	} 
	
	cout << ans << '\n';
	return 0;
}