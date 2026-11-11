#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
const int N = 5e5 + 5;
int sum;
int a[N];
int ans = -1;
int sum2[N];
int b;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = n; i >= 1; i--) {
		int cnt = 0;
		int j = i;
		int isum = a[j];
		j--;
		int b = 1;
		int sum2 = 0;
		while (cnt <= m) {
			sum = isum - a[j] + sum2;
			sum2 = sum;
			cnt += abs(sum);
			b++;
			isum = a[j];
			j--;
			if (j < 1) {
				ans = max(b, ans);
				break;
			}
			if (cnt > m) {
				b--;
				ans = max(b, ans);
				break;
			}
			sum = 0;
			if (b == n) {
				cout << ans;
				return 0;
			}
		}
		ans = max(b, ans);
	}
	cout << ans << "\n";
	return 0;
}
