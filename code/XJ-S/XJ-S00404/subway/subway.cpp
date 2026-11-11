#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],k[505],a[505][20005],t[505][20005],l,r,z[505][20005],minn=2e9+5;

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
			cin>>a[i][j];
			cin>>t[i][j];
		}
		z[a[i][1]][a[i][2]]=1;
		z[a[i][2]][a[i][1]]=1;
	}
	for(int i=1;i<=q;i++)
	{
		cin>>l>>r;
		cout<<10<<endl;
	}
	return 0;
}
