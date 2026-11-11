#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, ans = 0;
long long m;
long long a[N];
int main () {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	sort (a + 1, a + n + 1);
	int i = 1, j = 2;
	long long num = 0;
	while (i <= n) {
		if (num + (a[j] - a[j - 1]) * (j - i) > m || j - 1 == n) {
			ans = max(ans, j - i);
			num = num -  a[i] + a[i - 1];
			i ++;
		} else {
			num += (a[j] - a[j - 1]) * (j - i);
			j ++;
		}
	}
	cout << ans;
	return 0;
}
