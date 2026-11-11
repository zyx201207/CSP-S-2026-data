#include<bits/stdc++.h>
using namespace std;
const int M=3e5+5,N=5e5+5;
int sum[M],a[N],r[M],x[M],n,m;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		r[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		int bo=0;
		for(int j=i-1;j>0;j--)
		{
			if(r[a[j]]>i)
			{
				sum[a[i]]=sum[a[i]]+i-j;
				if(x[a[i]]>j) sum[a[i]]-=j-x[a[i]];
				bo=1;
				break;
			}
		}
		if(bo==0) sum[a[i]]=i;
		x[a[i]]=i;
	}
	for(int i=1;i<=m;i++)
	{
		printf("%d ",sum[i]);
	}
	printf("\n");
	return 0;
}
