#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,i,w[500005],x,y,sum=0,t[500005],j,k;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=m;i++)cin>>w[i];
	for(i=1;i<=n;i++)
	{
		cin>>k;
		for(j=1;j<=k;j++)
		{
		cin>>x>>t[x];
	    }
	}
	for(i=1;i<=q;i++)
	{
		sum=0;
		cin>>x>>y;
		for(i=x;i<=y;i++)sum+=t[x]+t[y]+w[x]+w[y];
		cout<<sum;
	}
	return 0;
}
