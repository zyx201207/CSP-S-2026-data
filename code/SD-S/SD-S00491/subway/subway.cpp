#include<bits/stdc++.h>
using namespace std;
long long w[666];
long long dis[500005],a[500005],T[500005];
bool vis[500005];
int c,n,m,d,q,t,k,y;
struct node{
	long long u,v;
	node(long long u,long long v):u(u),v(v){}
};
vector<node> G[500005];
void bfs(int x)
{
	for(int i=i;i<=m;i++)
	{
		dis[i]=100000000000LL;
		vis[i]=false;
	}
	queue<int> q;
	q.push(x);
	dis[x]=0;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		if(!vis[u])
		{
			int l=G[u].size();
			for(int i=1;i<=l;i++)
			{
				int v=G[u][i].v;
				if(!vis[v])
				{
					q.push(v);
					dis[v]=min(dis[v],dis[u]+1);
					break;
				}//return;			
			}		
		}
		vis[u]=true;
	}
}
int main(){
	freopen("subway5.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	if(c<=3&&n==1)
	{
		scanf("%d",&k);
		for(int j=1;j<=k;j++)scanf("%lld%lld",&a[j],&T[j]);
		while(q--)
		{
			int st,ed;
			scanf("%d%d",&st,&ed);
			printf("%lld\n",w[st]+w[ed]+T[st]+T[ed]);
		}
	}
	if(c>=12&&c<=19)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&k);
			for(int j=1;j<=k;j++)scanf("%lld%d",&a[j],&t);
			for(int j=1;j<=k;j++)
			{
				for(int g=j;g<=k;g++)
				{
					G[a[j]].push_back(node{a[j],a[g]});
					G[a[g]].push_back(node{a[g],a[j]});
				}
			}
		}
		while(q--)
		{
			int st,ed;
			scanf("%d%d",&st,&ed);
			bfs(st);
			printf("%lld\n",dis[ed]*t*2+w[st]+w[ed]);
		}
	}
	return 0;
}

