#include<bits/stdc++.h>
using namespace std;
bool b[300005];
int n,m,a[500005],c[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		int s[500005],cnt=1;
		b[a[i]]=true;
		s[cnt]=a[i];
		for(int j=i+1;j<=n;j++)
		{
			if(!b[a[j]])
			{
				cnt++;
				s[cnt]=a[j];
				b[a[j]]=true;
			}
			else
			{
				while(s[cnt]!=a[j])
				{
					b[s[cnt]]=false;
					cnt--;
				}
			}
		}
		for(int i=1;i<=cnt;i++)
		{
			c[s[i]]++;
			b[s[i]]=false;
		}
	}
	for(int i=1;i<=m;i++)
	{
		printf("%d ",c[i]);
	}
	return 0;
}
