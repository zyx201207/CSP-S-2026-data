#include<bits/stdc++.h>
using namespace std;
int c, t;
int x[500];
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("nigrate.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while(t--) {
		int n, d;
		scanf("%d%d", &n, &d);
		for (int i = 1;i <= n;i++){
			scanf("%d", &x[i]);
		}
		int ans = 0;
		for (int i = 1;i <= n;i++) {
			for (int j = i + 3;j <= n;j++){
				int k = abs(x[j]) - abs(x[i]);
				
				if (k <= d && k % d != 0 && (k - 1) <= 2)
					ans++;
			} 
		}
		printf("%d\n", ans);
	}
	return 0;
} 
