#include <bits/stdc++.h>
#include <vector>
using namespace std;
const int maxn1 = 3e5 + 10, maxn2 = 5e5 + 10;
int n, m, a[maxn];

int main() {


	freopen("card.in", "r", srdin);
	freopen("card.out", "w", stdout);
	scanf("%d %d", &n, &m);
	int cnt[maxn2];
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		cnt[a[i]]++;
	}

	for (int i = 1; i <= m; i++) {
		printf("%d ", (cnt / 2 + cnt % 2));
	}

	return 0;
}