#include<iostream>
#include<vector>
using namespace std;
#define int long long
int c,n,m,d,q,w[500001],a[501][501];
vector<pair<int,int>>g[500001];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int t;
		cin>>t;
		while(t--)
		{
			int t1,t2;
			cin>>t1>>t2;
			g[t1].push_back({i,t2});
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j)a[i][j]=1e18;
	for(int i=1;i<=m;i++)for(int j=0;j<g[i].size();j++)for(int k=0;k<g[i].size();k++)a[g[i][j].first][g[i][k].first]=min(a[g[i][j].first][g[i][k].first],g[i][j].second+g[i][k].second);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)for(int k=1;k<=n;k++)a[j][k]=min(a[j][k],a[j][i]+a[i][k]);
	while(q--)
	{
		int t1,t2,ans=1e18;
		cin>>t1>>t2;
		for(int i=0;i<g[t1].size();i++)for(int j=0;j<g[t2].size();j++)ans=min(ans,g[t1][i].second+a[g[t1][i].first][g[t2][j].first]+g[t2][j].second);
		cout<<w[t1]+ans+w[t2]<<'\n';
	}
}