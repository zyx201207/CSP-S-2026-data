#include <bits/stdc++.h> 
using namespace std;
int c,n,m,d,q;
long long ans;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int w[m+5];
	int k[n+5];
	int a[n+5][m+5],t[n+5][m+5]; 
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++) 
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		ans=w[x]+w[y]+t[x][x]+t[x][y]+t[x][y];
		cout<<ans<<endl;
	}
	return 0;
}
