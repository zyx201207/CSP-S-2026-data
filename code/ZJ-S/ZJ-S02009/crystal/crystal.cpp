#include <bits/stdc++.h>
using namespace std;
int n, m, a[500010], c[500010], x, cnt, maxx=-99999;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a+1, a+1+n);
	for (int i = 1; i < n; i++)
	{
		c[i]=a[i+1]-a[i];
	}
	for (int i = 1; i < n; i++)
	{
		cnt=0, x=1;
		while (cnt+c[i+x-1]*x <= m && i+x-1 < n)
		{
			cnt += c[i+x-1]*x;
			cout << cnt << " " << x << "\n";
			x++;
			if(x > maxx) maxx=x;
		}
		if(maxx==n-i+1) break;
	}
	printf("%d", maxx);
	return 0;
}