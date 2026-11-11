#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,p,ans=0;
void solve(int x,int y)
{
	ans=0;
	ans+=w[x];
	ans+=w[y];
	cout<<ans<<endl;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>p;
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
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=q;i++)
	{
		solve(x[i],y[i]);
	}
	return 0;
}
