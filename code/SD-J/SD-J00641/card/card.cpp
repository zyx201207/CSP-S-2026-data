#include <bits/stdc++.h>
using namespace std;
int n, m, a[500050], ans[500050];
void Game(int x) {
	int cnt[m + 1] = {0};
	for (int i = x; i <= n; i++) {
		cnt[a[i]]++;
		if (cnt[a[i]] > 1) {
			cnt[a[i]]--;
			int j = i - 1;
			while (a[j] != a[i]) {
				cnt[a[j]]--;
				j--;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		if (cnt[i] != 0) ans[i]++;
	}
}
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		Game(i);	
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << " "; 
	}
	return 0;
}
