#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 10;
int n, ans;
ll m, a[N], s[N];
int main() {
	freopen("crystal.in" , "w", stdin);
	freopen("crystal.out" , "a", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a+n+1);
	for (int i = 2; i <= n; i++)
		s[i] = s[i - 1] + (a[i] - a[i - 1]) * (i - 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			if (s[i] - s[j] <= m)
				ans = max(ans, i - j + 1);
	printf("%d\n", ans);
	return 0;
}