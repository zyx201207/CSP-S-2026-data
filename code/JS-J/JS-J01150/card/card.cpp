#include<bits/stdc++.h>
using namespace std;
int a[500005], b[500005], c[500005];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==b[i])
		{
			c[a[i]]++;
			for(int j=i;j<=n;j++)
			{
				b[i]=-1;
			}
			for(int j=1;j<i;j++) c[b[j]]++;
			b[i]=a[i];
		}
		else
		{
			b[i+1]=a[i];
			c[a[i]]++;
			for(int j=1;j<=i;j++)
			{
				c[b[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}

