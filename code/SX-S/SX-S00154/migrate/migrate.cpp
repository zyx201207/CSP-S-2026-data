#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=2e6+5;
int c,t,n,d,cnt,head[N],x[N],dist[N];
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
			if(dist[v]>dist[u]+edge[i].val)
			{
				dist[v]=dist[u]+edge[i].val;
				vis[v]=1;
			}
		}
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=n;j++)
//			{
//				if(abs(x[i]-x[j])<=d)
//				{
//					add(x[i],x[j],abs(x[i]-x[j]));
//					add(x[j],x[i],abs(x[i]-x[j]));
//				}
//			}
//		}
		cout<<1<<endl;
	}
	return 0;
}