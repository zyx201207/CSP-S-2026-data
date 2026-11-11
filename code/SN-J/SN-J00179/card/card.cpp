#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],b[500005],c[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=1;i<n;i++)
	{
		memset(b,0,sizeof(b));
		int p=0;
		for(int j=i;j<=n;j++)
		{
			int flag=1,x=0;
			for(int k=1;k<=p;k++)
			{
				if(a[j]==b[k])
				{
					flag=0;
					x=k;
					break;
				}
			}
			if(flag==0)
			{
				for(int k=x+1;k<=p;k++)
				{
					b[k]=0;
				}
			}
			else
			{
				p++;
				b[p]=a[j];
			}
		}
		for(int j=1;j<=p;j++)
		{
			c[b[j]]++;
		}
	}
	c[a[n]]++;
	for(int i=1;i<=m;i++)
	{
		cout << c[i] << " ";
	}
	return 0;
}
