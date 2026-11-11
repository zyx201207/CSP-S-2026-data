#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[500005], Next[500005], Front[500005];
long long ans;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		Next[i] = i + 1;
		Front[i] = i - 1;
	}
	Next[0] = 1;
	int cnt = n, Last = n, First = 1;
	int cnt = 1, i = 1, j = 1;
	for (int k = 1; k <= m; k++) {
		while (cnt <= n) {
			while (i <= n) {
				if (a[i] == a[j]) {
					Next[i - 1] = Front[j];
					break;
				}
				j++;
			}
			for (int r = 0; r < n; r++) {
				if (a[Next[r]] == i) {
					ans++;
				}
			}
			cout << ans << " ";
			i++;
			Next[Last] = 0;
			cnt++;
		}
	}
	return 0;
}