#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005];
int t[505][500005];
int sta,en;
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
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a;
			cin>>a>>t[i][j];

		}
	}

	while(q--)
	{
		cin>>sta>>en;
		long long ans=0;
		ans+=w[sta]+w[en];

		for(int i=sta;i<=en;i++)
		{
			ans+=t[i][i]+t[i][i+1];
		}
	}
	return 0;
}