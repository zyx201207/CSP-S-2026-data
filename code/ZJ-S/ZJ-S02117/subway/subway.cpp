#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+3;
int n,m,p[N],ans,l,r,used[N],dis[N],d,q,v[N],w[N];
struct node{
	int v,w;
};
vector<node>a[N-1];
void spfa(int s)
{
	queue<int>q;
	q.push(s);
	while(q.size())
	{
		int u=q.front();q.pop();
		used[u]=0;
		for(int i=0;i<a[u].size();i++)
		{
			int v=a[u][i].v;
			int w=a[u][i].w;
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				if(!used[v])
				{
					used[v]=1;
					q.push(v);
				}
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,d;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>p[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>v[j]>>w[j];
		}
		for(int j=1;j<k;j++)
		{
			for(int l=j+1;l<=k;l++)
			{
				a[v[j]].push_back({v[l],w[l]+w[j]});
				a[v[l]].push_back({v[j],w[j]+w[l]});
			}
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		memset(dis,32,sizeof(dis));
		memset(used,0,sizeof(used));
		dis[x]=0;
		spfa(x);
		cout<<dis[y]+p[x]+p[y]<<"\n";
	}
}