//2
#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[510000],k[110000],a[5500][5500],t[5500][5500],s[110000],e[110000],dis[510000];
struct node
{
	int x,w;
};
vector<node>G[510000];
priority_queue<node> p;
void f(int x)
{
	for(int i=1;i<=k[x];i++)
	{
		G[a[x][i]].push_back({i+m,t[x][i]});
		G[i+m].push_back({a[x][i],t[x][i]});
	}
	memset(dis,-0x3f,sizeof(dis));
	dis[s[x]]=0;
	p.push({s[x],0});
	while(p.size())
	{
		node a=p.top();
		int t=a.x,h=a.w;
		p.pop();
		if(h>dis[t]) continue;
		for(auto to:G[t])
		{
			int y=to.x,u=to.w;
			if(dis[y]>dis[t]+u)
			{
				dis[y]=dis[t]+u;
				p.push({y,dis[y]});
			}
		}
	}
	cout<<dis[e[x]]<<"\n";
	return ;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=q;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
			cin>>a[i][j]>>t[i][j];
	}
	for(int i=1;i<=q;i++)
		cin>>s[i]>>e[i];
	for(int i=1;i<=q;i++)
		f(i);
	return 0;
}