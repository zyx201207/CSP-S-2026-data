#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[500010], b[500010], s[500010];

signed main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		int top = 0;
		for (int j = i; j <= n; j++) {
			int k = -1;
			if (top != 0) {
				for (int l = top; l >= 1; l--) {
					if (s[l] == a[j]) {
						k = l;
						break;
					} 
				}
			}
			if (k == -1)
				s[++top] = a[j];
			else
				top = k;
		}
		for (int j = 1; j <= top; j++)
			b[s[j]]++;
	}
	for (int i = 1; i < m; i++)
		printf("%d ", b[i]);
	printf("%d", b[m]);
	return 0;
}
