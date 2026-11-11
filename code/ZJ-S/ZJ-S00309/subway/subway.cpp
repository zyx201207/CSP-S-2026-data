#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FRE freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
int read()
{
	int f=1;
	int k=0,c=getchar();
	for(;!isdigit(c);c=getchar())
		if(c=='-')
			f=-1;
	for(;isdigit(c);c=getchar())
		k=k*10+(c-'0');
	return k*f;
}
//rp++;
const LL N=505,M=5e5+505,LOWM=1005,INS=1e18;
struct node{
	int v;
	LL w;
	bool operator <(const node&others) const{return others.w<w;};
};
int c,n,m,d,q;
vector<node> a[M];
int k[N],w[M];
LL dis[LOWM][LOWM];
LL dis_b[M];
bool vis[M];
void dijktra1(int start)
{
	memset(vis,false,sizeof(vis));
	priority_queue<node> q;
	q.push((node){start,0LL});
	dis[start][start]=0LL;
	vis[start]=1;
	while(!q.empty())
	{
		int u=q.top().v;
		LL use=q.top().w;
		q.pop();
		vis[u]=1;
		for(int j=0;j<a[u].size();j++)
		{
			int v=a[u][j].v,w=a[u][j].w;
			if(vis[v]) continue;
			int less=w+use;
			if(less<dis[start][v])
			{
				dis[start][v]=less;
				q.push((node){v,less});
			}
		}
	}
}
void solve1_11()
{
	for(int i=1;i<=m+n;i++)
		for(int j=1;j<=m+n;j++)
			dis[i][j]=INS;
	for(int i=1;i<=m;i++)
		dijktra1(i);
	while(q--)
	{
		int u,v;
		cin>>u>>v;
		cout<<dis[u][v]+w[u]+w[v]<<endl;
	}
}

void dijktra2(int start)
{
	memset(vis,false,sizeof(vis));
	queue<node> q;
	q.push((node){start,0});
	dis_b[start]=0LL;
	vis[start]=1;
	while(!q.empty())
	{
		int u=q.front().v;
		LL use=q.front().w;
		q.pop();
		vis[u]=1;
		for(int j=0;j<a[u].size();j++)
		{
			int v=a[u][j].v,w=a[u][j].w;
			if(vis[v]) continue;
			int less=w+use;
			if(less<dis_b[v])
			{
				dis_b[v]=less;
				q.push((node){v,less});
			}
		}
	}
}

void solveB()
{
	while(q--)
	{
		for(int i=1;i<=m+n;i++)
			dis_b[i]=INS;
		int u,v;
		u=read();
		v=read();
		dijktra2(u);
		cout<<dis_b[v]+w[u]+w[v]<<endl;
	}
}

LL sum[3][M],sx=INS;
void solve20_21()
{
	for(int i=0;i<M;i++)
		sum[1][i]=sum[2][i]=INS;
	for(int i=1;i<=m;i++)
	{
		if(a[i].size()==2)
		{
			sx=min(sx,a[i][0].w+a[i][1].w);	
		}	
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<a[i].size();j++)
		{
			sum[a[i][j].v-m][i]=a[i][j].w;
		}
	}
	for(int i=1;i<=m;i++)
	{
		sum[1][i]=min(sum[1][i],sum[2][i]+sx);
		sum[2][i]=min(sum[2][i],sum[1][i]+sx);
	}
	while(q--)
	{
		int u,v;
		cin>>u>>v;
		cout<<w[u]+w[v]+min(sum[1][u]+sum[1][v],sum[2][u]+sum[2][v])<<endl;
	}
}

int main()
{
	FRE 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		w[i]=read();
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int v,w;
			v=read();
			w=read();
			a[i+m].push_back((node){v,w});
			a[v].push_back((node){i+m,w});
		}
	}
	if(m<=1000)
		solve1_11();
	else 
	if(q<=2000)
	    solveB();
	else
	if(n<=2)
		solve20_21(); 
	return 0;
} 
