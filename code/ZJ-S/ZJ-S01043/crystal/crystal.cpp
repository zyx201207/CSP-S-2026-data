/*
rp++
只能加，不能减
所以肯定都到一个数
双指针
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;
int n;
long long m, a[N];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	long long sum = 0;
	int ans = 0;
	for (int i = 1, j = 0;i <= n;i++) {
		sum -= (a[j] - a[i - 1]);
		while (j < n && sum + (a[j + 1] - a[j]) * (j - i + 1) <= m)
			sum += (a[j + 1] - a[j]) * (j - i + 1), j++;
		ans = max(ans, j - i + 1);
	}
	cout << ans << "\n";

	return 0;
}