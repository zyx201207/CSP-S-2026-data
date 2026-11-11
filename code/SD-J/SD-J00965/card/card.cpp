#include<bits/stdc++.h>
using namespace std;
int n,m,a[100000],f[100000];
bool b[10000000];
int h[100000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int i=1;i<=n;i++)
	{
		int r=0;
		for (int j=i;j<=n;j++)
		{
			if (b[a[j]]==0)
			{
				f[++r]=a[j];
				b[a[j]]=1;
			}
			else
			{
				memset (f,0,sizeof (f));
				memset (b,0,sizeof (b));
				r=0;
				f[++r]=a[j];
				b[a[j]]=1;
			}
		}
		for (int j=1;j<=m;j++)
		{
			if (b[j]==1)
			{
				cout<<j;
				h[j]++;
			}
		}
		memset (f,0,sizeof (f));
		memset (b,0,sizeof (b));
	}
	for (int i=1;i<=m;i++)
	{
		cout<<h[i]<<" ";
	}
}
