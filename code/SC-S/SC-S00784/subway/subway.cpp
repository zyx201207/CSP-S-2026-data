#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
using namespace std;
const int maxn=500,maxm=500010;
struct edge
{
	int from,to,next,dis;
}e[2*maxm];
int c,n,m,d,q,w[maxm],k[maxn],a[maxm],t[maxm],head[maxm],cnt;
il void add(int u,int v,int w)
{
	e[++cnt].from=u;
	e[cnt].to=v;
	e[cnt].dis=w;
	e[cnt].next=head[u];
	head[u]=cnt;
	return;
}
il ull bfs(int x,int y)
{
	int minstp[maxm];
	memset(minstp,0,sizeof(minstp));
	queue<int>qe;
	qe.push(x);
	while(!qe.empty())
	{
		int u=qe.front();
		qe.pop();
		for(int i=head[u];i;i=e[i].next)
		{
			int v=e[i].to;
			if(minstp[v]==0||minstp[v]>minstp[u]+e[i].dis)
			{
				minstp[v]=minstp[u]+e[i].dis;
				if(v!=y)qe.push(v);
			}
		}
	}
	return minstp[y]+w[x]+w[y];
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)cin>>a[j]>>t[j];
		for(int j=1;j<k[i];j++)
		{
			add(a[j],a[j+1],t[j]+t[j+1]);
			add(a[j+1],a[j],t[j]+t[j+1]);
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<bfs(x,y)<<'\n';
	}
	return 0;
}
//0pts，我还以为是最短路啥的，敲半天题意理解错了T.T 