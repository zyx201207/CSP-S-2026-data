#include<bits/stdc++.h>
#define PII pair<int,int> 
using namespace std;
int C,n,m,D,q,a[500010],e[1000010],ne[1000010],h[500010],w[1000010],idx,b[500010],c[500010],d[500010];
bool st[500010];
void add(int a,int b,int c)
{
	e[idx]=b;
	w[idx]=c;
	ne[idx]=h[a];
	h[a]=idx++;
}
map<PII,int>mp;
void dijkstra(int l,int r)
{
	memset(d,0x3f,sizeof d);
	memset(st,0,sizeof st);
	d[l]=w[l];
	priority_queue<PII,vector<PII>,greater<PII> >q;
	q.push({w[l],l});
	while(q.size())
	{
		auto t=q.top();
		q.pop();
		int u=t.second;
		if(u==r)break;
		if(st[u])continue;
		st[u]=1;
		for(int i=h[u];~i;i=ne[i])
		{
			int v=e[i],k=w[i];
			if(mp[{u,v}]==c[u]+a[u]+c[v]&&d[v]>d[u]+k)
			{
				d[v]=d[u]+k;
				q.push({d[v],v});
			}
			else if(d[v]>d[u]+k+a[u]+a[v])
			{
				d[v]=a[u]+k+a[u]+a[v];
				q.push({d[v],v});
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(h,-1,sizeof h);
	cin>>C>>n>>m>>D>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int t;
		cin>>t;
		for(int j=1;j<=t;j++)cin>>b[j]>>c[j];
		for(int j=1;j<=t;j++)
		{
			for(int k=j+1;k<=t;k++)
			{
				add(b[j],b[k],c[j]+a[j]+c[k]);
				mp[{b[j],b[k]}]=c[j]+a[j]+c[k];
			}
		}
	}                      
	while(q--)         
	{
		int l,r;
		cin>>l>>r;
		dijkstra(l,r);
		cout<<d[r]+a[r]<<'\n';
	}
	return 0;
}
             
             