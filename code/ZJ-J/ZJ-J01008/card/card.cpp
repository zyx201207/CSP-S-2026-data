#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500009],flag[300009],sum[300009];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		flag[a[i]]=i;
	}
	int x=0;
	memset(sum,0,sizeof(sum));
	while(x<n)
	{
		x++;
		for(int i=x;i<=n;i++)
		{
			sum[a[i]]++;
			i=flag[a[i]];
		}
	}
	for(int i=1;i<=m;i++)
	{
		printf("%d ",sum[i]);
	}
	return 0;
}