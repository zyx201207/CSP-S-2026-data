#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<pair<int,int> > g[510000];
int op,n,m,d,r,k;
int a[510000];
int b[510000];
int c[510000];
ll dist[510000];
ll read()
{
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
void dij(int s)
{
	memset(dist,0x3f,sizeof(dist));
	priority_queue<pair<int,int>,vector<pair<int,int> > ,greater<pair<int,int> > > pq;
	pq.push({0,s});
	dist[s]=0;
	while(!pq.empty())
	{
		pair<int,int> cur=pq.top();
		pq.pop();
		int u=cur.second;
		int w=cur.first;
		if(w>dist[u]) continue;
		for(int j=0;j<g[u].size();j++)
		{
			int v=g[u][j].first;
			w=g[u][j].second;
		//	cout<<"u"<<u<<"v"<<v<<"w"<<w<<"\n";
		//if(v==m+3) cout<<"u="<<u<<" "<<"v="<<v<<" "<<dist[u]<<endl;
			if(dist[v]>dist[u]+w)
			{
				dist[v]=dist[u]+w;
				pq.push({dist[v],v});
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	op=read();
	n=read();
	m=read();
	d=read();
	r=read();
	for(int i=1;i<=m;i++)
	{
		a[i]=read();
	}
	for(int i=1;i<=n;i++)
	{
		k=read();
		for(int j=1;j<=k;j++)
		{
			b[j]=read();
			c[j]=read();
			int start;
			g[m+m+b[j]].push_back({b[j],a[b[j]]});//口到当前厅 
			if(j==1) 
			{
				g[b[j]].push_back({b[j]+m,c[j]});//厅到当前台 
				start=b[j]+m;
			}
			else
			{
				g[start].push_back({b[j],c[j]});//台到沿线厅 
			}
		}
	}
	int s,t;
	for(int i=1;i<=r;i++)
	{
		cin>>s>>t;
		dij(m+m+s);
		cout<<dist[t]+a[t]<<"\n";
	}
	return 0;
}


