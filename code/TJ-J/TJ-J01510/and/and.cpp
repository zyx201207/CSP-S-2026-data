#include<bits/stdc++.h>
using namespace std;

int n, m, a[200001], k;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	k = a[n];
	for (int i = n; i >= n - m + 1; i--)
		k &= a[i];
	printf("%d", k);
	return 0;
}
