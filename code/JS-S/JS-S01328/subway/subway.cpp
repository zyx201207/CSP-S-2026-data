#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int c,n,m,d,q;
int w[500050];
int k[550];
vector<int> a[550];
vector<ll> t[550];
//at most 500 subway lines & 500000 stations & 500000 edges
//violent is bad
//what's the usage of 'd'?
//Oh i can have the minium transport time between lines quite fast!
//Then...PROBLEM SOLVED!!!
vector<pair<int,ll> > stat_lines[500050];//station i's subway lines
ll trans_time[550][550];//time to transport between line i & j
ll dis[550],vis[550];
ll trans_time_new[550][550];
struct node
{
	int x,dis;
	node()
	{
		x=0,dis=0;
	}
	node(int x1,int dis1)
	{
		x=x1;
		dis=dis1;
	}
	bool operator <(node another) const
	{
		return dis>another.dis;
	}
};
void dijkstra_trans_time()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dis[j]=1e18;
		}
		dis[i]=0;
		priority_queue<node> q;
		q.push(node(i,0));
		while(!q.empty())
		{
//			cout<<"node"<<q.top().x<<" & dis="<<q.top().dis<<endl;
			int top=q.top().x;
			q.pop();
			if(vis[top]==i)
			{
				continue;
			}
			vis[top]=i;
			for(int j=1;j<=n;j++)
			{
				if(j==top)
				{
					continue;//I think self-ring is bad
				}
				if(dis[top]+trans_time[top][j]<dis[j])
				{
					dis[j]=dis[top]+trans_time[top][j];
					q.push(node(j,dis[j]));
				}
			}
		}
		for(int j=1;j<=n;j++)
		{
			trans_time_new[i][j]=dis[j];
//			cout<<"trans_time["<<i<<"]["<<j<<"]="<<dis[j]<<endl;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		a[i].resize(k[i]);
		t[i].resize(k[i]);
		for(int j=0;j<k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			stat_lines[a[i][j]].push_back(make_pair(i,t[i][j]));
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j)
			{
				trans_time[i][j]=1e18;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<(int)stat_lines[i].size();j++)
		{
			for(int k=0;k<(int)stat_lines[i].size();k++)
			{
				trans_time[stat_lines[i][j].first][stat_lines[i][k].first]=
					min(trans_time[stat_lines[i][j].first][stat_lines[i][k].first],
					stat_lines[i][j].second+stat_lines[i][k].second);
			}
		}
	}
	//oh no i have forget floyd! i now need dijkstra!
	dijkstra_trans_time();//O(n^2 * logn);
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		ll ans=1e18;
		int size1=stat_lines[x].size();
		for(int j=0;j<size1;j++)
		{
			int size2=stat_lines[y].size();
			for(int k=0;k<size2;k++)
			{
				ans=min(ans,trans_time_new[stat_lines[x][j].first][stat_lines[y][k].first]
						+stat_lines[x][j].second+stat_lines[y][k].second);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
// a bit too slow...maybe judge machine will be faster...
// task7=0.5s
