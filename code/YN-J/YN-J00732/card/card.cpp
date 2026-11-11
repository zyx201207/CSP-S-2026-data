#include <bits/stdc++.h>
//#define int long long
using namespace std;
int a[500009];
int v[500009];
int t[500009];
int ans[500009];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.in", "w", stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			t[a[j]]++;
			ans[a[j]]++;
			if (t[a[j]] > 1) {
				for (int k = v[a[j]]; k <= j; k++) {
					if (ans[a[k]] > 0) {
						ans[a[k]]--;
					}
					t[a[k]] = 0;
				}
				ans[a[j]]++;
				t[a[j]]++;
			}
			v[a[j]] = j;
		}
		for (int j = 1; j <= m; j++) {
			t[j] = 0;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}