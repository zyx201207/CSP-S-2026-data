#include <bits/stdc++.h>
using namespace std;

int cnt[500005], ans[500005];
int m, n, s;


int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int j = 1; j <= m; j++) {
		for (int i = 0; i < n; i++) {
			cin >> s;
			cnt[s]++;
			if (cnt[s] != 1) {
				cnt[500005] = {};
				cnt[s]++;
			}
		}
		ans[j] += cnt[s];
	}

	for (int i = 1; i <= m; i++)
		cout << ans[i] << " ";
	return 0;
}