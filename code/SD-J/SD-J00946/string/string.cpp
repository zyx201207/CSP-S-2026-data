#include <bits/stdc++.h>
using namespace std;

int n;
long long ans;
long long l, a[200010];
char c[200010], b[100000010];


int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		cin >> a[i] >> c[i];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= a[i]; j++)
			b[++l] = c[i];
	for(int i = 1; i <= l / 2; i++)
		if(b[i] != b[l - i + 1])
			ans++;
	printf("%lld\n", ans);
	return 0;
}
/*
3
2 a
2 b
1 c
*/
