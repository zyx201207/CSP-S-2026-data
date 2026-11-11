#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,b[500005],a[500005],t[500005],x,y,k[505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i]>>t[i];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		cout<<t[x]*2+t[y]*2;
	}
	return 0;
}
