#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int M = 3e5 + 10;
int n, m;
int a[N];
int cnt[M];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int k = 1; k <= n; ++k) {
		int x[N];
		int size = 0;
		for (int i = k; i <= n; ++i) {
			bool v = 0;
			for (int j = 1; j <= size; ++j) {
				if (a[i] == x[j]) {
					v = 1;
					break;
				}
			}
			if (v) {
				while (x[size] != a[i]) {
					size--;
				}
				size--;
			}
			x[++size] = a[i];
		}
		for (int i = 1; i <= size; ++i) {
			cnt[x[i]]++;
		}
	}
	for (int i = 1; i <= m; ++i) {
		printf("%d ", cnt[i]);
	}
	return 0;
}