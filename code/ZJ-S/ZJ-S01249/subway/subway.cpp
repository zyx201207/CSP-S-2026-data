#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5,N=505;
int c,n,m,d,q;
int from,tow;
int temp;
int w[M],st[N];
int vis[M],ans=0x3f3f3f3f;
struct Node{
	int station,time;
};
struct edge{
	int line,time;
};
vector<Node> g[N];
vector<edge> u[M];
void search(int now,int dis,int pre)
{
	vis[now]=1;
	if(now==tow&&dis<ans)
	{
		ans=dis;
		return;
	}
	for(int i=0;i<u[now].size();i++)
	{
		int l=u[now][i].line;
		if(l==pre) continue;
		for(int j=0;j<g[l].size();j++)
		{
			if(!vis[g[l][j].station])
			{
				vis[g[l][j].station]=1;
				search(g[l][j].station,dis+u[now][i].time+g[l][j].time,l);
				vis[g[l][j].station]=0;
			}
		}
	}
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>st[i];
		for(int j=1;j<=st[i];j++)
		{
			int temp1,temp2;
			cin>>temp1>>temp2;
			g[i].push_back({temp1,temp2});
			u[temp1].push_back({i,temp2});
		}
	}
	while(q--)
	{
		memset(vis,0,sizeof(vis));
		ans=0x3f3f3f3f;
		cin>>from>>tow;
		search(from,w[from],-1);
		cout<<ans+w[tow]<<endl;
	}
	return 0;
}