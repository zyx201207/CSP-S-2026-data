#include<bits/stdc++.h>
using namespace std;
long long t[300010];
long long a[500010];
long long b[500010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,i,j;
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(i=1;i<=n;i++)
	{
		memset(b,0,sizeof(b));
		int l=1,r=1;
		for(j=i;j<=n;j++)
		{
			b[r]=a[j];
			r++;
			int k;
			for(k=l;k<r;k++)
			{
				if(b[k]==b[r])
				{
					l=r;
					break;
				}
			}
		}
		for(j=l;j<=r;j++)
		{
			t[b[j]]++;
		}
	}
	for(i=1;i<=m;i++)
	{
		printf("%lld ",t[m]);
	}
	return 0;
}