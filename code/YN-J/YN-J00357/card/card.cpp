#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = 2e5 + 10;
int a[N], sum[N], ans[N];
bool flag[N];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		memset(sum, 0, sizeof(sum));
		memset(flag, 0, sizeof(flag));
		for (int j = i; j <= n; j++) {
			if (sum[a[j]] == 0) {
				sum[a[j]]++;
			} 
			else {
				int w = 0;
				for (int k = i; k < j; k++) {
					if (a[k] == a[j] && !flag[k]) {
						w = k;
						break;
					}
				}
				for (int k = w; k < j; k++) {
					if (!flag[k]) {
						flag[k] = true;
						sum[a[k]]--;
					}
				}
				sum[a[j]]++;
			}
		}
		for (int j = 1; j <= m; j++) {
			if (sum[j] > 0)
				ans[j]++;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << ' ';
	}
	return 0;
}
