#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[5000005];
int a[5][20005];
int t[505][20005];
int x[100005];
int y[100005];
long long ans;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
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
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		ans=w[x]+w[y]+t[1][x]+t[1][y];
		cout<<ans<<endl;
	}
	return 0;
}
