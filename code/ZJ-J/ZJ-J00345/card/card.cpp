#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans[N],p=1;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]<a[i-1])
		p=0;
	}
	if(p)
	{
		for(int i=2;i<=n;i++)
		{
			if(a[i]!=a[i-1])
			ans[a[i-1]]=i-1;
		}
		ans[a[n]]=n;
		for(int i=1;i<=m;i++)
		printf("%d ",ans[i]);
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int u[N],len=0;
		memset(u,0,sizeof(u));
		for(int j=i;j<=n;j++)
		{
			for(int k=len;k>=1;k--)
			{
				if(u[k]==a[j])
				{
					len=max(0,k-1);
					break;
				}
			}
			u[++len]=a[j];
		}
		for(int j=1;j<=len;j++)
		ans[u[j]]+=1;
	}
	for(int i=1;i<=m;i++)
	printf("%d ",ans[i]);
	return 0;
}
