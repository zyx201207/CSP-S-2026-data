#include<bits/stdc++.h>
using namespace std;
int n, m, a[500010], c[300010], ans[300010];
bool vis[500010];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i], c[a[i]] = i;
	for(int i = 1; i <= n; i++) {
		int l = i;
		while(1) {
			if(l > n)
				break;
			l = c[a[l]];
			ans[a[l]]++;
			l++;
		}
	}
	for(int i = 1; i <= m; i++)
		cout << ans[i] << " ";
	return 0;
}
