#include<bits/stdc++.h>
using namespace std;

int c, t, ans;

int main() {
	freopen("migreta.in", "r", stdin);
	freopen("migreta.out", "w", stdout);
	scanf("%d%d", &c, &t);
	for (int i = 1; i <= t; i++) {
		int n, d, a[1001];
		scanf("%d%d", &n, &t);
		for (int j = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for (int x = 1; x < n; i++) {
			for (int y = x + 1; y <= n; y++) {
				if (ans == 2) {
					ans++;
				}
			}
		}
	}
	printf("%d", &ans);
	return 0;
} 
