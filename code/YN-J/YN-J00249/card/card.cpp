#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int a[N], k[N], top, ans[N], vis[N];
int n, m;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		top = 0;
		for (int j = 1; j <= m; j++)
			vis[j] = 0;
		for (int j = i; j <= n; j++) {
			if (vis[a[j]] != 0) {
				top = vis[a[j]];
				for (int c = 1; c <= m; c++)
					if (vis[c] > vis[a[j]])
						vis[c] = 0;
			} else
				k[++top] = a[j], vis[a[j]] = top;
		}
		for (int j = 1; j <= top; j++)
			ans[k[j]]++;
	}
	for (int i = 1; i <= m; i++)
		cout << ans[i] << ' ';
	return 0;
}