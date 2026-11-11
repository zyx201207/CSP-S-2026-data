#include <bits/stdc++.h>
using namespace std;
int n, ans = 1;
long long m, cnt = 0;
long long a[500010], s[500010];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	scanf("%d %lld", &n, &m);
	for(int i = 1;i <= n;i ++)
		scanf("%lld", &a[i]);
	
	sort(a + 1, a + 1 + n);
	
	for(int i = 1;i <= n;i ++)
		s[i] = a[i] - a[i - 1];
	s[1] = 0;
	
	for(int r = 1, l = 1;r <= n;r ++)
	{
		if(cnt + (r - l) * s[r] <= m)
			cnt += (r - l) * s[r];
		else
		{
			while(cnt + (r - l) * s[r] > m)
			{
				cnt -= (a[r - 1] - a[l]);
				l ++;
			}
			cnt += (r - l) * s[r];
		}
		ans = max(ans, r - l + 1);
	}
	
	printf("%d\n", ans);
	return 0;
}
