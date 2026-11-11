#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m, a[10010], f[10010] = {0}, ans[10010] = {0}, c[10010] = {0}, e = 0;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
//	for (int h = 1; h <= 10000; h++) {
//		for (int i = 1; i <= n; i++) {
//			if (f[1] == 0) {
//				f[1] = a[i];
//			} else {
//				for (int j = 1; j < i; j++) {
//					if (f[j] == a[i]) {
//						for (int k = 1; k <= i; k++) {
//							f[k] == 0;
//						}
//						break;
//					}
//				}
//				if (c == 0) {
//					f[i] = a[i];
//				}
//			}
//		}
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= n; j++) {
//				if (f[j] == a[i]) {
//					ans[a[i]] = h;
//				}
//			}
//		}
//		for (int i = 1; i <= n; i++) {
//			if (ans[a[i]] == 0 && c[a[i]] != 1) {
//				c[a[i]] = 1;
//				ans[a[i]] = h;
//				e++;
//			}
//		}
//		if (e == n) {
//			break;
//		}
//	}
//	for (int i = 1; i <= m; i++) {
//		printf("%d ", ans[i]);
//	}
	printf("%d %d %d", n, m, m);
	fclose(stdin);
	fclose(stdout);
	return 0;
}