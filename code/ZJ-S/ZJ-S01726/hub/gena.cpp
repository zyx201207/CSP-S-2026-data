#include <bits/stdc++.h>

int main() {
	freopen("hub.in", "wb", stdout);
	std::mt19937 rng(1248);
	printf("0 30\n");
	for(int m = 1; m <= 30; m++) {
		int n = 2 * m + 1;
		printf("%d %d\n", n, rng() % (n - 1) + 2);
		for(int i = 1; i <= m; i++)
			printf("%d %d\n", i, i + 1);
		for(int i = 1; i <= m; i++)
			printf("%d %d\n", i, i + m + 1);
	}
	return 0;
}

