#include<bits/stdc++.h>//subway
using namespace std;
const int N=5e5+100;
int a,b,c,d,e,f[N],g;
vector<int>h1[N];
vector<int>h2[N];
struct node1
{
	int x;//节点编号 
	int y;//距离 
	bool operator>(const node1& u)const
	{
		return y>u.y;
	}
}ppppp;
int dis[N];
int vis[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>b>>c>>d>>e;
	for(int i=1;i<=c;i++)
	{
		cin>>f[i];
	}
	for(int i=1;i<=b;i++)
	{
		cin>>g;
		int u=-1;
		for(int j=1;j<=g;j++)
		{
			int x,y;
			cin>>x>>y;
			int xx=x+i*c;
			h1[xx].push_back(x);
			h2[xx].push_back(y);
			h1[x].push_back(xx);
			h2[x].push_back(y);
			if(j==1)
			{
				u=xx;
			}
			else
			{
				h1[xx].push_back(u);
				h2[xx].push_back(0);
				h1[u].push_back(xx);
				h2[u].push_back(0);
				u=xx;
			}
		}
	}
	for(int i=1;i<=e;i++)
	{
		int x,y;
		cin>>x>>y;
		//dij
		priority_queue<node1,vector<node1>,greater<node1>>r;
		r.push({x,0});
		for(int j=1;j<=c*(b+1);j++)
		{
			dis[j]=1e9+10;
			vis[j]=1;
		}
		dis[x]=0;
		while(r.size()>0)
		{
			auto u=r.top();
			r.pop();
			int u1=u.x;
			int u2=u.y;
			if(vis[u1]==0)
			{
				continue;
			}
			vis[u1]=0;
			for(int j=0;j<h1[u1].size();j++)
			{
				int u3=h1[u1][j];
				int u4=h2[u1][j];
				if(dis[u3]>dis[u1]+u4)
				{
					dis[u3]=dis[u1]+u4;
					r.push({u3,dis[u3]});
				}
			}
		}
		cout<<dis[y]+f[x]+f[y]<<"\n";
	}

	return 0;
}
