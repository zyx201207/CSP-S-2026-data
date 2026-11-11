#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[500005];
int ans[300005];
int t[500005];
int w[500005];

void clear () {
	for (int i = 1; i <= m; i++) {
		t[i] = 0;
		w[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int cnt = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];

	}
	for (int k = 1; k <= n; k++) {
		for (int i = k; i <= n; i++) {
			t[a[i]]++;
			if (t[a[i]] == 2) {
				for (int j = w[a[i]] + 1; j < i; j++) {
					t[a[j]] = 0;

				}
				t[a[i]]--;
			}
			w[a[i]] = i;

		}
		for (int i = 1; i <= m; i++) {
			ans[i] += t[i];
		}
		clear();
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}

	return 0;
}
