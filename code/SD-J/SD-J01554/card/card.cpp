#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int n,m,a[N],b[N],L[N],d[N],ans[N];

int main()
{
//	freopen("card.in", "r", stdin);
//	freopen("card.out", "w", stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	for(int i=1;i<=n;i++)
	{
		int l=1,p=0;
		for(int j=1;i+j-1<=n;j++)
		{
			b[j]=a[i+j-1];
			if(L[a[j]]);
			{
				l=j;
				for(int k=L[a[j]];k<j;k++)
				{
					L[b[k]]=0;
					d[++p]=b[k];
				}
			}
			L[a[j]]=j;
		}
		for(int j=l;j<=n;j++)
		{
			d[++p]=b[j];
			ans[b[j]]++;
		}
		//for(int i=1;i<=n;i++)
		//	printf("%d ",a[i]);
//		printf("\n");
///		for(int i=1;i<=n;i++)
//			printf("%d ",b[i]);
///		printf("\n");
//		for(int i=1;i<=m;i++)
//			printf("%d ",ans[i]);
//		printf("\n");
	}
	
	for(int i=1;i<=m;i++)
		printf("%d ",ans[i]);
	return 0;
}
