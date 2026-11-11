#include <bits/stdc++.h>

using namespace std;

int n, m, a[500010], s[500010], top = 0, ans[200010];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		memset(s, 0, sizeof(s));
		top = 0;
		for (int j = i; j <= n; j++) {
			bool ok = 1;		
			for (int k = 1; k <= top && ok; k++)
				if (a[j] == s[k])
					ok = 0,
					top = k - 1;
			s[++top] = a[j];
		}
		for (int j = 1; j <= top; j++)
			ans[s[j]]++;
	}
	for (int i = 1; i <= m; i++)
		cout << ans[i] << ' ';
	puts("");
}
