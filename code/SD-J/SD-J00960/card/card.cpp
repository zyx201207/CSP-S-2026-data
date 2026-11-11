#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],c[300005],vis[300005],h[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	++h[a[n]];
	for(int k=1;k<n;k++)
	{
		for(int i=1;i<=m;i++)
			c[i]=0;
		for(int i=k;i<=n;i++) 
		{
			++c[a[i]];
			if(c[a[i]]>1)
				for(int j=vis[a[i]];j<i;j++)
					c[a[j]]--;	
			vis[a[i]]=i;
		}
		for(int i=1;i<=m;i++)
			if(c[i]>0)
				++h[i];
	}
	for(int i=1;i<=m;i++)
		printf("%d ",h[i]);
	return 0;
} 
