//Oct31==Dec25?
//18minn miaosha T1
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long a[N];
long long sum[N];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	long long m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	int j = 1;
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		while(a[i] * (i - j) - (sum[i - 1] - sum[j - 1]) > m) j++;
		ans = max(ans, i - j + 1);
	}
	cout << ans << endl;
	return 0;
}
