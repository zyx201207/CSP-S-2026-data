#include <bits/stdc++.h>
using namespace std;
int c, t, n, m, a[2000100], ans;
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for ( int i = 1; i <= n; i++ )
			scanf("%d", &a[i]);
		for ( int i = 1; i < n - 2; i++ )
			if ( a[i + 3] - a[i] > m && a[i + 1] - a[i] <= m && a[i + 3] - a[i + 1] <= m && a[i + 1] - a[i] <= m && a[i + 3] - a[i + 2] <= m )
				ans++;
		printf("%d\n", ans);
		ans = 0;
	}
	return 0;
}
