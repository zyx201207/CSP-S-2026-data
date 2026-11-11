#include <bits/stdc++.h>
using namespace std;
int c, t, n, d, a[2000005], jl = 0, maxx = 0, b[20005];

int ck(int x) {
	for (int i = 1; i < d; i++) {
		for (int j = i + 1; j <= d; j++) {
			for (int l = 0; l < n; l++) {
				if (x + i + j == a[l] ) {
					return 0;
				}
			}
		}
	}
	return 1;
}

int main() {
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdin);
	scanf("%d%d", &c, &t);
	for (int i = 0; i < t; i++) {
		scanf("%d%d", &n, &d);
		int maxx = n;
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[j]);
		}

		for (int j = 0; j < n; j++) {
			if (ck(a[j]) == 0) {
				jl++;
			}
		}

		b[i] = jl;
		jl = 0;
	}
	for (int i = 0; i < t; i++) {
		printf("%d\n", b[i]);
	}

	return 0;
}