#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[500005],e[505][505];
const int inf=0x3f3f3f3f3f3f3f3f;
vector<pair<int,int>> t[500005];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			e[i][j]=(i!=j)*inf;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		for(int j=1;j<=x;j++)
		{
			int p,v;
			cin>>p>>v;
			t[p].push_back({i,v});
		}
	}
	for(int i=1;i<=m;i++)
		for(pair<int,int> p1:t[i])
			for(pair<int,int> p2:t[i])
				e[p1.first][p2.first]=min(e[p1.first][p2.first],p1.second+p2.second);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				e[i][j]=min(e[i][k]+e[k][j],e[i][j]);
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		int ans=inf;
		for(pair<int,int> p1:t[x])
			for(pair<int,int> p2:t[y])
				ans=min(ans,p1.second+p2.second+e[p1.first][p2.first]);
		ans+=w[x]+w[y];
		cout<<ans<<"\n";
	}
}