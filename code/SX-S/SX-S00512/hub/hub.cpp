#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL n, m;
LL a[500005];

int main() {
	//freopen("aaa.in","r",stdin);
	//freopen("aaa.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int p = 1;
	LL cnt = 0, ans = -1;
	for (int i = 1; i <= n; i++) {
		cnt = cnt + (i - p) * (a[i] - a[i - 1]);
		if (cnt > m) {
			while (cnt > m && p <= i) {
				cnt = cnt - a[i] - a[p];
				p++;
			}
		}
		if (i - p + 1 > ans)
			ans = i - p + 1;
	}
	cout << ans;
}