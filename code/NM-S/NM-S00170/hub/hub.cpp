#include <bits/stdc++.h>
using namespace std;
int c, t, n, k, u[1000100], v[1000100];
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while(t--){
		scanf("%d%d", &n, &k);
		for ( int i = 1; i < n; i++ )
			scanf("%d%d", &u[i], &v[i]);
		printf("%d\n", (n - k) / 4 + 1);
	}
	return 0;
}
