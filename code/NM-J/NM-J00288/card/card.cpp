#include <bits/stdc++.h>
using namespace std;
int n, m, a[500100], b[500100], c[300100], s[300100];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for ( int i = 1; i <= n; i++ )
		scanf("%d", &a[i]);
	for ( int t = 1; t <= n; t++ ){
		int cnt = 0;
		memset(c, 0, sizeof(c));
		for ( int i = t; i <= n; i++ ){
			if ( c[a[i]] ){
				int x = c[a[i]];
				for ( int j = c[a[i]]; j <= cnt; j++ )
					c[b[j]] = 0;
				cnt = x - 1;
			}
			b[++cnt] = a[i];
			c[a[i]] = cnt;
		}
		for ( int i = 1; i <= cnt; i++ )
			s[b[i]]++;
	}
	for ( int i = 1; i <= m; i++ )
		printf("%d ", s[i]);
	return 0;
}
