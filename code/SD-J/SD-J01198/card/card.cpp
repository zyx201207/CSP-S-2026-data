#include <bits/stdc++.h>
using namespace std;

long long n, m, a[500005], cnt[500005], ans[500005], sum[500005];

int main() {
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n <= 500) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) cnt[j] = 0;
			stack<long long>v;
			for (int j = i; j <= n; j++) {
				if (cnt[a[j]] == 1) {
					while (cnt[a[j]] == 1) {
						cnt[v.top ()]--;
						v.pop ();
					}
				}
				v.push (a[j]);
				cnt[a[j]]++;
			}
			while (!v.empty ()) {
				ans[v.top ()]++;
				v.pop ();
			}
		}
		for (int i = 1; i <= m; i++) cout << ans[i] << " ";
		cout << "\n";
	}
	else {
		for (int i = 1; i <= n; i++) {
			sum[a[i]] ++;
		}
		long long cas = 0;
		for (int i = 1; i <= m; i++) {
			cas += sum[i];
			cout << cas << " ";
		}
		cout << "\n";
	}
	return 0;
}
