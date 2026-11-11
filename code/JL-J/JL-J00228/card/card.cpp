#include <bits/stdc++.h>
using namespace std;
int ans[505],sumans[505],a[500005];
int num[500005],flag[500005],anss[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int check = 0;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),check+=(i>=2&&a[i]>=a[i-1]);
	if(n<=500&&m<=200)
	{
		for(int i=1;i<=n;i++)
		{
			int cnt = 0;
			for(int j=i;j<=n;j++)
			{
				ans[++cnt] = a[j];
				for(int k=1;k<cnt;k++)
				{
					if(ans[k]==ans[cnt]) cnt = k;
				}
			}
			for(int j=1;j<=cnt;j++) sumans[ans[j]]++;
		}
		for(int i=1;i<=m;i++) printf("%d ",sumans[i]);
	}
	else if(check==n-1&&n<=5000)
	{
		for(int i=1;i<=n;i++) num[a[i]]++;
		for(int i=1;i<=m;i++)
		{
			if(num[i]==0) flag[i] = 0;
			else flag[i] = 1;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++) anss[j]+=flag[j];
			num[a[i]]--;
			if(num[a[i]]==0) flag[a[i]] = 0;
			else flag[a[i]] = 1;
		}
		for(int i=1;i<=m;i++) printf("%d ",anss[i]);
	}
	else
	{
		for(int i=2;i<=n;i++)
		{
			if(a[i]!=a[i-1]) anss[a[i-1]] = i-1;
		}
		anss[a[n]] = n;
		for(int i=1;i<=m;i++) printf("%d ",anss[i]);
	}
}//40