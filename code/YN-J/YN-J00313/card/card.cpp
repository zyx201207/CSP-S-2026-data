#include <bits/stdc++.h>
using namespace std;
int n, m;
int s[500005], a[300005], b[500005], ans[300005];

int main() {
	freopen("card.in", "w", stdin);
	freopen("card.out", "r", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	for (int i = n; i >= 1; i--) {
		a[s[i]]++;
		if (a[s[i]] <= 1) {
			b[s[i]] = i;
			for (int j = i; j <= n; j++) {
				ans[s[j]]++;
			}
		} else {
			for (int j = i + 1; j < b[s[i]]; j++) {
				ans[s[i]]--;
				a[s[j]]--;
			}
			for (int j = b[s[i]]; j <= n; j++)
				ans[s[j]]++;
			b[s[i]] = i;
			ans[s[i]]++;
		}
	}
	for (int i = 1; i <= m; i++)
		cout << ans[i] << ' ';

	return 0;
}