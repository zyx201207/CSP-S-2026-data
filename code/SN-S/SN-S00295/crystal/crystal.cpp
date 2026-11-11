#include<bits/stdc++.h>

const int MAXN = 5e5 + 5;

typedef long long LL;

int n; LL a[MAXN], m;

std::map<LL, int> M; LL suf[MAXN];

int main()
{
//	freopen("crystal4.in", "r", stdin);
//	freopen("LCR.out", "w", stdout);

	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	scanf("%d%lld", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%lld", &a[i]), M[a[i]]++;
		
	std::sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
		suf[i] = suf[i - 1] + a[i];
	
	int ans = M[a[1]];
	
	for(int i = 2, j = 1; i <= n; i++)
	{
		if(a[i] == a[i - 1])
			continue;
			
		while(j <= i && a[i] * (i - j + 1) - (suf[i] - suf[j - 1]) > m)
			j++;
			
		if(j <= i && a[i] * (i - j + 1) - (suf[i] - suf[j - 1]) <= m)
			ans = std::max(ans, M[a[i]] + i - j);
	}
	
	printf("%d\n", ans);
	
	return 0;
}
