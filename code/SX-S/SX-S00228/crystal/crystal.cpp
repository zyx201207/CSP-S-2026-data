#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+5;
int n, m, a[N], sum[N], cnt[N];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
		cnt[a[i]]++;
	}
	int ans = 0, fi = 1; //fi表示当前数字第一次出现的位置
	for (int i = 1; i < n; i++) {
		int bns = 0;
		if (a[i] == a[i + 1])
			continue;
		fi = i;
		for (int j = 1; j < fi; j++) {
			if (a[i] * (i - j + 1) - (sum[i] - sum[j - 1]) <= m) {
				bns += i - j + 1;
				break;
			}
		}
		ans = max(ans, bns);
	}
	cout << ans;
	return 0;
}