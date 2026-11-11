#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m;
long long a[N];
long long shxia[N],zp[N],x=0;
bool vis[N];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		zp[i]=-1;
	}
	for (int i=1;i<=n;i++)
	{
		x=0;
		for (int j=i;j<=n;j++)
		{
			if (!vis[a[j]])
			{
				vis[a[j]]=1;
				x++;
				zp[x]=a[j];
			}
			else
			{
				while (zp[x]!=a[j])
				{
					vis[zp[x]]=0;
					x--;
				}
			}
		}
		for (int i=1;i<=x;i++)
		{
			shxia[zp[i]]++;
			vis[zp[i]]=0;
			zp[i]=-1;
		}
	}
	for (int i=1;i<=m;i++)
	{
		cout<<shxia[i]<<" ";
	}
	return 0;
}
