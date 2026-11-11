#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long vis[300010],vis2[300010],b[500010],a[500010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		if(vis[a[i]]!=0)
			b[vis[a[i]]]=i;
		vis[a[i]]=i;
	}
	for(long long i=1;i<=n;i++)
		vis[i]=0;
	for(long long i=1;i<=n;i++)
	{
		for(long long i=1;i<=m;i++)
			vis2[i]=0;
		long long j=i;
		while(j<=n)
		{
			if(vis2[a[j]]==0)
			{
				vis[a[j]]++;
				vis2[a[j]]++;
			}
			if(b[j]!=0)
				j=b[j];
			else
				j++;
		}
	}
	for(long long i=1;i<=m;i++)
		cout<<vis[i]<<" ";
	return 0;
}
