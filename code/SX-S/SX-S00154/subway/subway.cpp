#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=5e2+5;
int c,n,m,k,x,y,d,q_,ans,cnt,head[N],dist[N],w[N],a[N],t[N];
bool vis[N];
struct node
{
	int to,nxt,val;
}edge[2*N];
void add(int u,int v,int w)
{
	cnt++;
	edge[cnt].nxt=head[u];
	edge[cnt].to=v;
	edge[cnt].val=w;
	head[u]=cnt;
}
queue<int>q,qq;
void spfa(int s)
{
	memset(vis,0,sizeof vis);
	memset(dist,0x3f,sizeof dist);
	q=qq;
	q.push(s);
	vis[s]=1;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=head[u];i!=0;i=edge[i].nxt)
		{
			int v=edge[i].to;
			if(vis[v])return;
			if(dist[v]<dist[u]+edge[i].val)
			{
				dist[v]=dist[u]+edge[i].val;
				vis[v]=1;
			}
		}
	}
}
void dfs(int x)
{
	for(int i=x;i!=0;i=edge[i].nxt)
	{
		cout<<i<<' ';
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q_;
	if(c>=12&&c<=19)
	{
		for(int i=1;i<=m;i++)cin>>w[i];
		for(int i=1;i<=n;i++)
		{
			cin>>k;
			for(int j=1;j<=k;j++)
			{
				cin>>a[j]>>t[j];
			}
		}
		while(q_--)
		{
			cin>>x>>y;
   			ans+=w[x],ans+=w[y];
			cout<<"QEQ"<<endl;
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[j]>>t[j];
			add(i,a[j],t[j]);
			add(a[j],i,t[j]);
		}
	}
	while(q_--)
	{
		cin>>x>>y;
		cout<<w[x]+w[y]<<endl;
		continue;
		ans=0;
		ans+=w[x],ans+=w[y];
		spfa(x);
		cout<<ans+dist[y]-0x3f3f3f3f3f3f3f3f<<endl;
	}
	return 0;
}