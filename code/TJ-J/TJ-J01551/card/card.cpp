#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, M = 3e5 + 5;
int a[N], ans[M], t[M];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	bool fl = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] < a[i - 1])
			fl = 1;
	}
	if (fl == 0) {
		for (int i = 1; i <= n; i++) {
			t[a[i]]++;
		}
		for (int i = 0; i < n; i++) {
			t[a[i]]--;
			for (int j = 1; j <= m; j++) {
				if (t[j] % 2 == 1) {
					ans[j]++;
				}
			}
		}
		for (int i = 1; i <= m; i++)
			cout << ans[i] << ' ';
		return 0;
	}
	for (int st = 0; st < n; st++) {
		for (int i = 1; i <= m; i++)
			t[i] = 0;
		for (int i = st + 1; i <= n; i++) {
			if (t[a[i]] == 0) {
				t[a[i]] = i;
				ans[a[i]]++;
			} else {
				for (int k = t[a[i]] + 1; k < i; k++) {
					ans[a[k]]--;
					t[a[k]] = 0;
				}
				t[a[i]] = i;
				//ans[a[i]]++;
			}
		}
	}
	for (int i = 1; i <= m; i++)
		cout << ans[i] << ' ';
	//xym
	return 0;
}