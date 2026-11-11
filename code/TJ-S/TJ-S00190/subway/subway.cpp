#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q,w[50005],k[505],a[505][2],t[505][2],x,y,sum=0;
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
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--)
	{
		cin>>x>>y;
		sum+=w[x];
		x+=2;
		if(x==y)
		{
			cout<<sum<<endl;
			continue;
		}
		else
		{
			sum+=t[x-2][2]+t[x][1];
		}
	}
	return 0;
} 
