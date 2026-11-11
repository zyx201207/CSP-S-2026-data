#include<bits/stdc++.h>

const int MAXN = 2e5 + 5;

typedef long long LL;

int n, m; LL a[MAXN];

int b[MAXN], tot, c[MAXN], pos;

int main()
{
//	freopen("and5.in", "r", stdin);
//	freopen("LCR.out", "w", stdout);

	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%lld", &a[i]), b[++tot] = i;
		
	LL ans = 0;
	
	for(int j = 30; ~j; j--)
	{
		pos = 0;
		for(int i = 1; i <= tot; i++)
			if((a[b[i]] >> j) & 1)
				c[++pos] = b[i];
				
		if(pos < m) continue;
		
		ans |= (1ll << j), tot = pos;
		for(int i = 1; i <= pos; i++)
			b[i] = c[i];
	}
	
	printf("%lld\n", ans);
	
	return 0;
}
