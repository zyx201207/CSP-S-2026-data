#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[500005], ans[500005];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			ans[a[j]]++;
			if (ans[a[j]] > i) {
				bool flag = 0;
				for (int k = i; k <= j - 1; k++) {
					if (a[k] == a[j]) flag = 1;
					if (flag) ans[a[k]]--;
				}
			}
		}
	}
	for (int i = 1; i <= m; i++) cout << ans[i] << " ";
	return 0;
} 
