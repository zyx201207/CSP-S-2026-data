#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005],b[500005],c[500005],d[500005];
vector<int>G[500005];
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<3000)
	{
		for(int i=1;i<=n;i++)
		{
			fill(b,b+500003,0);
			fill(c,c+500003,0);
			for(int j=i;j<=n;j++)
			{
				if(b[a[j]])for(int k=b[a[j]];k<=j;k++)b[c[k]]=0,c[k]=0;
				b[a[j]]=j,c[j]=a[j];
			}
			for(int j=1;j<=m;j++)d[j]+=(1&&b[j]);
		}
		for(int j=1;j<=m;j++)cout<<d[j]<<' ';
		return 0;
	}
	for(int i=1;i<=n;i++)b[a[i]]=i;
	for(int i=1;i<=m;i++)cout<<b[i]<<' ';
	return 0;
}