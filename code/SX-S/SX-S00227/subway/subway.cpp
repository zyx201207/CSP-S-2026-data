#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
const int N=5e2+5,M=5e4+5,Q=1e5;
int c,n,m,d,q,w[M],x[Q],y[Q],a[N][M],t[N][M],k[N];
bool vis[N][M],s[M];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	rep(i,1,m)
	{
		cin>>w[i];
	}
	rep(i,1,n)
	{
		cin>>k[i];
		rep(j,1,k[i])
		{
			cin>>a[i][j]>>t[i][a[i][j]];
			vis[i][a[i][j]]=1;
		}
	}
	rep(i,1,q)
	{
		ll mmin=1e10;
		cin>>x[i]>>y[i];
		if((vis[1][x[i]]==1&&vis[1][y[i]]==1))
		{
			cout<<w[x[i]]+w[y[i]]+t[1][x[i]]+t[1][y[i]]<<"\n";
			continue;
		}
		if((vis[2][x[i]]==1&&vis[2][y[i]]==1))
		{
			cout<<w[x[i]]+w[y[i]]+t[2][x[i]]+t[2][y[i]]<<"\n";
			continue;
		}
		rep(j,1,m)
		{
			if(vis[1][j]==1&&vis[2][j]==1)
			{
				if(vis[1][x[i]]==1)
				{
					mmin=min(mmin,1LL*t[1][x[i]]+t[2][y[i]]+t[2][j]+t[1][j]);
				}
				else
				{
					mmin=min(mmin,1LL*t[2][x[i]]+t[1][y[i]]+t[2][j]+t[1][j]);
				}
			}
		}
		cout<<mmin+w[x[i]]+w[y[i]]<<"\n";
	}
	return 0;
}
