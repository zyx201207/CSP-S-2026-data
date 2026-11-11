#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
ll c,n,m,d,q,tot,w[500005],k[505],a,t[105][105];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a>>t[i][j];	
		}
	}
	for(int i=1;i<=q;i++)
	{
		ll x,y;
		cin>>x>>y;
		tot=0;
		tot+=w[x]+w[y]+t[1][x]+t[1][y];
		cout<<tot<<"\n";
	}
	cout<<endl;
	return 0;
}
