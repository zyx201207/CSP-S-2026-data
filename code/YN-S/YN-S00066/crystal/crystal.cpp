#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
int n, m, ans = 0;
long long a[MAXN];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int last = 1;
	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		while (last <= i - 1 && sum + (i - last) * (a[i] - a[i - 1]) > m && i - last + 1 >= ans)
			sum -= a[i - 1] - a[last], last++;
		sum += (i - last) * (a[i] - a[i - 1]);
		ans = max(ans, i - last + 1);
	}
	cout << ans << "\n";
	return 0;
}