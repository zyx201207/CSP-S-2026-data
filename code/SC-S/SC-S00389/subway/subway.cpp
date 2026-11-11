#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=5e3+10;
long long int w[N],a[M][M],t[M][M];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,k,ans=0,x,y;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		ans=0;
		cin>>x>>y;
		ans+=w[x];
		ans+=w[y];
		ans+=t[x][x];
		ans+=t[2][3];
		cout<<ans<<'\n';
	}
	return 0;
}