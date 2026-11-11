#include<bits/stdc++.h>
using namespace std;

const int maxn = 500005;
const int maxm = 300005;

int n, m, a[maxn], t_num[maxm], ans[maxm], vis[maxm];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		t_num[a[i]]++;
	}
	for (int i = 1; i <= n; i++) {
		if (i >= 2) {
			t_num[a[i - 1]]--;
		}
		int num[maxn];
		for (int j = 1; j <= m; j++) {
			num[j] = t_num[j];
		}
		for (int j = i; j <= n; j++) {
			ans[a[j]]++;
			if (num[a[j]] >= 2) {
				int t = a[j], cnt = num[a[j]] - 1;
				while (cnt) {
					num[a[++j]]--;
					if (a[j] == t) {
						cnt--;
					}
				}
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}