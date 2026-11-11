#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500100],b[300100],c[300100],d;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			c[a[j]]++;
		}
		d=i;
		for(int j=n;j>=i;j--)
		{
			b[a[j]]++;
			if(c[a[j]]>=2)
			{
				d=j;
				break;
			}
		}
		for(int j=1;j<=n;j++)
		{
			c[j]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<' ';
	}
	return 0;
}
