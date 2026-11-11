#include<bits/stdc++.h>
using namespace std;
const int N=5e5+12,M=572;
typedef long long ll;
ll cccccc,n,m,d,qq;
//别表示测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数
struct node
{
	ll x,z,y,sb;//z 是编号 
};
vector<node> adj[N];
ll w[N],k[N],anss=1e18;
bool flag[N];
void dfs(int u,ll z,int sum,int id)//当前在坐的列车，如果要转乘，要走多久<-sum，列车编号 id
{
	flag[u]=1;
	if(u==m+1)
	{
		anss=min(anss,z);
		flag[u]=0;
		return ;
	}
	for(int i=0;i<adj[u].size();i++)
	{
		node it=adj[u][i];
		if(flag[it.x])continue;
		if(id==it.z)
		{
			dfs(it.x,z,it.y,it.z);
		}
		else
		{
			int t2=sum+it.sb;
			dfs(it.x,z+t2,it.y,it.z);
		}
	}
	flag[u]=0;
}
void solve()
{
	int x,y;cin>>x>>y;anss=1e18;
	adj[y].push_back({m+1,0,0,0});
	dfs(x,0,0,0);
	adj[y].pop_back();
	cout<<anss+w[x]+w[y]<<'\n';
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>cccccc>>n>>m>>d>>qq;//m是点的个数！！ 
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++)
    {
    	cin>>k[i];
    	int last_x=0,last_y=0;
    	for(int j=1;j<=k[i];j++)
    	{
    		ll x,y;cin>>x>>y;
    		if(last_x!=0)
    		{
    			adj[last_x].push_back({x,i,y,last_y});
    			adj[x].push_back({last_x,i,last_y,y});
			}
			last_x=x,last_y=y;
		}
	}
	while(qq--)
	{
		solve();
	}
	return 0;
}
/*
15:37 start

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2


			if(t.id==it.z)
			{
				dis[it.x]=min(dis[it.x],dis[t.x]);
				q.push({it.x,dis[t.x],it.y,it.z});
			}
			else
			{
				int t2=t.sum+it.sb;
				dis[it.x]=min(dis[t.x]+t2,dis[it.x]);
				q.push({it.x,dis[t.x]+t2,it.y,it.z});
			}
*/ 
