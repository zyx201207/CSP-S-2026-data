#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[100010],k[5010],t[10010][5010];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>t[i][j];
		}		
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		long long ans=0;
		for(int j=min(x,y);j<=max(x,y);j++)
		{
			ans+=t[i][j]+w[j];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
