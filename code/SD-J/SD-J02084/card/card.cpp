#include <bits/stdc++.h>
using namespace std;
int ans[300005];
int a[500005];
int s[500005];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i ++) cin >> a[i];
	for (int i = 1;i <= n;i ++) {
		int x = 1;
		for (int j = i;j <= n;j ++) {
			bool l = 1;
			for (int k = 1;k < x;k ++) {
				if (s[k] == a[j]) {
					l = 0;
					x = k;
					break;
				}
				if (!l) break;
			} 
			s[x++] = a[j];
		}
		for (int j = 1;j < x;j ++) {
			ans[s[j]] ++;
		}
	}
	for (int i = 1;i <= m;i ++) cout << ans[i] << ' ';
	return 0;
}

