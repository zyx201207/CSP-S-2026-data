#include<iostream>
#include<cstdio>
#include<vector>
#include<queue> 
#include<cstring>
using namespace std;
typedef long long ll;
int n,m,c,d,q,w[500005],x,y;
vector<pair<int,int> >v[500005],g[505];
ll dis[505],ans;
bool vis[505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)scanf("%d",w+i); 
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			int a,t;
			scanf("%d %d",&a,&t);
			v[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(auto j:v[i])
		{
			for(auto k:v[i])
			{
				if(j.first!=k.first)
				{
					g[j.first].push_back({k.first,j.second+k.second});
				}
			}
		}
	}
	while(q--)
	{
		scanf("%d %d",&x,&y);
		priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>q;
		memset(dis,0x3f,sizeof(dis));
		memset(vis,0,sizeof(vis));
		ans=1e18;
		for(auto z:v[x])
		{
			dis[z.first]=z.second;
			q.push({z.second,z.first});
		}
		while(!q.empty())
		{
			int id=q.top().second;
			q.pop();
			if(vis[id])continue;
			vis[id]=1;
			for(auto y:g[id])
			{
				if(dis[id]+y.second<dis[y.first])
				{
					dis[y.first]=dis[id]+y.second; 
					q.push({dis[y.first],y.first});
				}
			}
		}
		for(auto z:v[y])
		{
			ans=min(ans,dis[z.first]+z.second);
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
 } 
 /*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

 */
