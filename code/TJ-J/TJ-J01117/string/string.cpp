#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, ans = 0;
long long a[N];
char c[N], str[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	scanf("%d", &n);
	for (int i = 1;i <= n;i++) {
		scanf("%lld ", &a[i]);
		scanf("%c", &c[i]);
	}
	
	bool t = 1;
	for (int i = 2;i <= n;i++)
		if (c[i] != c[i - 1])
			t = 0;
	if (t) {printf("0\n");return 0;}
	
	int l = 0;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= a[i];j++)
			str[++l] = c[i];
	
	for (int i = 1;i <= l / 2;i++)
		if (str[i] != str[l - i + 1])
			ans++;
	
	printf("%d\n", ans);
	return 0;
}
