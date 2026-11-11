#include <stdio.h>
int n,m,a[5001],p[5001],Q[50001],ans[5001],R;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		R=0;
		for(int i=0;i<5001;i++)
			p[i]=0;
		for(int j=i;j<=n;j++)
		{
			if(p[a[j]]==0)
				Q[++R]=a[j],p[a[j]]=R;
			else
				Q[p[a[j]]]=a[j],R=p[a[j]];
		}
		for(int j=1;j<=R;j++)
		{
			//printf("%d ",Q[j]);
			ans[Q[j]]++;
		}
		//printf("\n");
	}
	for(int i=1;i<=m;i++)
		printf("%d ",ans[i]);
	return 0;
}
