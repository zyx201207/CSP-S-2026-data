#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,qs,w[500005],k[500005],ans,s,vis[500005],dis[500005];
struct edge
{
    int v,w;
};
vector <edge> e[500005];
struct node
{
	int dis,pos;
	bool operator <(const node &x) const{
		return x.dis<dis;
	}
};
priority_queue <node> q;
void dij()
{
	q.push({0,s});
	memset(vis,0,sizeof vis);
	while(!q.empty())
	{
		auto i=q.top();
		q.pop();
		int x=i.pos;
		if(vis[x]!=0)
		{
			continue;
		}
		vis[x]=1;
		for(auto a:e[x])
		{
			int ny=a.v;
			if(dis[ny]>dis[x]+a.w)
			{
				dis[ny]=dis[x]+a.w;
			}
			if(!vis[ny])
			{
				q.push({dis[ny],ny});
			}
		}
	}
}
//vector <edge> e[500005];
int main()
{
 	ios::sync_with_stdio(false);
 	cin.tie(0);
 	freopen("subway.in","r",stdin);
 	freopen("subway.out","w",stdout);
 	cin>>c>>n>>m>>d>>qs;
 	for(int i=1;i<=m;i++)
 	{
 		cin>>w[i];
	 }
	
	if(c>=12&&c<=19)
	{
		
	}
	if(c>=7&&c<=11)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>k[i];
			if(k[i]==1)
			{
				continue;
			}
			int x,y,c1,c2;
			cin>>x>>c1>>y>>c2;
			e[x].push_back({y,c1+c2});
			e[y].push_back({x,c1+c2});
		}
		cin>>qs;
		while(qs--)
		{
			memset(dis,0x3f,sizeof dis);
			int x,y;
			cin>>x>>y;
			s=x;
			dij();
			cout<<dis[y]+w[x]+w[y];
		}
	}
 	return 0;
}
//洛谷id：tangjunzhe1020 2022~2026 懒得调T2了，大概率二等，没希望一等，中考去了，退役快乐，希望能上神人大赏（doge）
//一名初三牲oier