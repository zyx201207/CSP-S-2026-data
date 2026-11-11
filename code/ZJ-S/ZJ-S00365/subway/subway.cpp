#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int w[50005],k[50005];
int a[505][100005],t[505][100005];
ll ans;
int p=1,q=1;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,n,m,d,q;
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
	
	for(int r=1;r<=q;r++)
	{
		int x,y;
		cin>>x>>y;
		ans+=w[x];
		ans+=w[y];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int q=1;q<=n;q++)
				{
					for(int p=1;q<=n;p++)
					{
						if(a[i][j]==a[q][p]) 
						{
							ans+=t[i][j];
							ans+=t[q][p];
						}
					}
				}	
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
