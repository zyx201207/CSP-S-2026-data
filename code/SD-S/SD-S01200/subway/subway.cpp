#include<bits/stdc++.h>
using namespace std;
const int N = 510;
const int M = 5e5+10;
#define int long long
int dis[N][N];
int c;
int n;
int m;
int d;
int q;
struct node
{
	int l,w;
};
int t[M];
vector<node> e[M];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>t[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int c,t;
			cin>>c>>t;
			e[c].push_back({i,t});
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=m;i++)
	{
		for(auto j:e[i])
		{
			for(auto k:e[i])
			{
				if(j.l==k.l) continue;
				dis[j.l][k.l]=min(dis[j.l][k.l],j.w+k.w);
				dis[k.l][j.l]=min(dis[k.l][j.l],j.w+k.w);
			}
		}
	}
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}			
		}		
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		long long ans=1e18;
		for(auto j:e[x])
		{
			for(auto k:e[y])
			{
				ans=min(ans,j.w+k.w+dis[j.l][k.l]);
			}
		}
		cout<<ans+t[x]+t[y]<<'\n';
	}
	return 0;
}
