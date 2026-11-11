#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], s[500005], ans;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout); 
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i]; 
	for (long long i = 1, j = 1; i <= n; i++) {
		while (j < i && (i - j + 1) * a[i] - s[i] + s[j - 1] > m) j++;
		ans = max(ans, i - j + 1);
//		cout << j << ' ' << i << '\n';
	}
	cout << ans << '\n';
	return 0;
}
/*
对于区间[j, i]，
设前缀和s[]，则
修改后s[j, i] = (i - j + 1) * a[i]
修改前s[j, i] = s[i] - s[j - 1]
这一段修改次数为 (i - j + 1) * a[i] - s[i] + s[j - 1]
*/
