#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],b[300005],c[300005],d[500005],s[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=n;i>0;i--)
	{
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++)
		{
			d[j]=a[j];
			if(b[d[j]]==1)
			{
				for(int k=c[d[j]]+1;k<=j-1;k++)
				{
					b[d[k]]=0;
					s[d[k]]--;
					d[k]=0;
				}
				d[c[d[j]]]=0;
				c[d[j]]=j;
			}
			else
			{
				b[d[j]]=1;
				s[d[j]]++;
				c[d[j]]=j;
			}
		}
	}
	for(int i=1;i<=m;i++) printf("%d ",s[i]);
	return 0;
}
