#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,int> PII;
const int N=1010,M=1e6+10;
int id[210][N],cnt=0,ww[N],a[N];
ll dis[60010];
bool v[60010];
int e[M],ne[M],h[60010],w[M],idx;
void add(int a,int b,int c)
{
	e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
void dij(int root)
{
	memset(v,0,sizeof v);
	for(int i=1;i<=cnt;i++) dis[i]=1e18;
	priority_queue<PII,vector<PII>,greater<PII> > q;
	dis[root]=0;
	q.push({0,root});
	while(q.size())
	{
		PII o=q.top();
		q.pop();
		ll dist=o.fi;
		int k=o.se;
		if(v[k]) continue;
		v[k]=1;
		for(int i=h[k];~i;i=ne[i])
		{
			int j=e[i];
			if(dis[j]>dist+w[i])
			{
				dis[j]=dist+w[i];
				q.push({dis[j],j});
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	memset(h,-1,sizeof h);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	cnt=m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			id[i][j]=++cnt;
	for(int i=1;i<=m;i++)
		cin>>ww[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int t;
			cin>>a[j]>>t;
			if(j!=1)
			{
				add(id[i][a[j-1]],id[i][a[j]],0);
				add(id[i][a[j]],id[i][a[j-1]],0);
			}
			add(id[i][a[j]],a[j],t),add(a[j],id[i][a[j]],t);
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		dij(x);
		cout<<dis[y]+ww[x]+ww[y]<<"\n";
	}
	return 0;
}