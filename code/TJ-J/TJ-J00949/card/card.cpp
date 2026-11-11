#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500050];
int ans[300050];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for (int i=1;i<=n;i++)
	{
		int b[300050];
		memset(b,0,sizeof(b));
		for (int j=i;j<=n;j++)
		{
			if(b[a[j]]!=0)
			{
				for (int k=b[a[j]];k<j;k++)
				{
					b[a[k]]=0;
				}
			}
			b[a[j]]=j;
		}
		for (int j=1;j<=m;j++) {
			if(b[j]!=0) ans[j]++;
			//printf("!%d\n",b[j]);
		}
		//printf("\n");
	}
	for (int i=1;i<=m;i++) printf("%d ",ans[i]);
	return 0;
}
