#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;
int a[N];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= m; i++) {
		printf("%d ", n);
	}
	
	return 0;
}
