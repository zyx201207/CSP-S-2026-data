#include <bits/stdc++.h>
using namespace std;

int n, m, kk;
long long ans[500010];
long long a[500010];
long long b[500010];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
		int x = 0;
			for(int k = 1; k <= kk; k++)
				if(b[k] == a[j])
					x = k;
			if(x > 0)
				kk = x;
			else
				b[++kk] = a[j];
	}
	for(int j = 1; j <= kk; j++)
		ans[b[j]]++;
	}
	for(int i = 1; i <= m; i++)
		printf("%lld\n", ans[i]);
	return 0;
}
/*
3
2 a
2 b
1 c
*/
