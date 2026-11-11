#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn], x[maxn];
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)scanf("%d", &a[i]);
	int ans = 0;
	for(int i = 29; i >= 0; i--)
	{
		int cnt = 0;
		for(int j = 1; j <= n; j++)
			if((a[j] >> i) & 1)x[++cnt] = a[j];
		if(cnt >= m)
		{
			ans = (((ans >> i) + 1) << i);
			for(int j = 1; j <= cnt; j++)a[j] = x[j];
			n = cnt;
		}
	}
	printf("%d\n", ans);
	return 0;
}
