#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int v,w;
};
int op,n,m,d,q,used[5005],b[5005],dis[5005][5005],vis[5005],s[5005],p[5005][5005],t[5005][5005];
vector<node> a[5005];
int spfa(int s,int e)
{

	memset(used,0,sizeof(used));
	queue<int> q;
	used[s]=1;
	dis[s][s]=0;
	q.push(s);
	while(q.size())
	{
		int u=q.front();
		q.pop();
		used[u]=0;
		for(int i=0;i<a[u].size();i++)
		{
			int v=a[u][i].v;
			int w=a[u][i].w;
			if(dis[s][v]>dis[s][u]+w)
			{
				dis[s][v]=dis[s][u]+w;
				if(!used[v])
				{
					used[v]=1;
					q.push(v);
				}
			}
		}
	}
	return dis[s][e];
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>op>>m>>n>>d>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>s[i];
		for(int j=1;j<=s[i];j++)
			cin>>p[i][j]>>t[i][j];
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=s[i];j++)
		{
			for(int k=j+1;k<=s[i];k++)
			{
				a[p[i][j]].push_back({p[i][k],t[i][j]+t[i][k]});
				a[p[i][k]].push_back({p[i][j],t[i][j]+t[i][k]});
			}
		}
	}
	memset(dis,63,sizeof(dis));
	while(q--)
	{
		int s,e;
		cin>>s>>e;
		if(!vis[s])
		{
			cout<<(spfa(s,e)+b[s]+b[e])<<"\n";
			vis[s]=1;
		}
		else
		{
			cout<<(dis[s][e]+b[s]+b[e])<<"\n";
		}
	}
}