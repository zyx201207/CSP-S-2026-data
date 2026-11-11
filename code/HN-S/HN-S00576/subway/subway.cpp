#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int N=1e6+5,INF=1e16;
vector<pii>v[N];
int c,n,m,d,q,b[N];
int f[505][505];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>n>>m;
	cin>>c;
	cin>>q;
	for(int i=1;i<=m;i++)
		cin>>b[i];
	for(int i=1;i<=n;i++)
	{
		int k;cin>>k;
		while(k--)
		{
			int a,t;
			cin>>a>>t;
			v[a].push_back(make_pair(i,t));
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			f[i][j]=INF;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<v[i].size();j++)
		{
			for(int k=j+1;k<v[i].size();k++)
			{
				int s=v[i][j].first,t=v[i][k].first;
				int w=v[i][j].second,w2=v[i][k].second;
				f[s][t]=f[t][s]=
				min(f[s][t],w+w2);
			}
		}
	}
	for(int i=1;i<=n;i++)
		f[i][i]=0;
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		}
	}
	while(q--)
	{
		int x,y,ans=INF;
		cin>>x>>y;
		for(auto j:v[x])
			for(auto k:v[y])
				ans=min(ans,f[j.first][k.first]+j.second+k.second);
		cout<<ans+b[x]+b[y]<<'\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/

