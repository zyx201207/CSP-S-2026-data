#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int qwq = 0;
	for(int i=30;i>=0;i--)
	{
		int now = (1<<i);
		bool flag = 1;
		for(int j=n;j>=n-m+1;j--)
		{
			if(a[j]<now) flag = 0;
			else a[j]-=now;
		}
		if(flag)
		{
			qwq = now;
			break;
		}
		sort(a+1,a+n+1);
	}
	int ans = a[n];
	for(int i=n-1;i>=n-m+1;i--) ans&=a[i];
	printf("%d\n",ans+qwq);
}//100