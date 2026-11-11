#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[1000005];
int a[100005][100005];
int t[100005][100005];
int k[1000005];
int be=0;
int en=0;
int ans=0;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int j=1;j<=q;j++)
	{
		
		for(int i=1;i<=n;i++)
		{
			cin>>k[j];
			cin>>a[j][i]>>t[j][i];
		}
		cin>>be>>en;
		ans+=w[be]+w[en];
		for(int r=be;r<=en;r++)
		{
			ans+=t[j][r];
		}
		cout<<ans;
		ans=0;
	}
	return 0;
}
