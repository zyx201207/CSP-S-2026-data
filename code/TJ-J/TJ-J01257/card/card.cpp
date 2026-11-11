#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010],b[500010],c[500010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.ans","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(b[a[j]])
			{
				for(int k=b[a[j]];k<=j;k++)
				{
					b[k]=0;
				}
			}
			b[a[j]]=j;
		}
		for(int j=1;j<=n;j++)
		{
			if(b[j])
			{
				c[j]++;
				b[j]=0;
			}
		}
	}
	cout<<c[1];
	for(int i=2;i<=m;i++)
	{
		cout<<' '<<c[i];
	}
	return 0;
}
