#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
int c,n,m,d,q,w[500010];
vector<pair<int,int> > ve[400010];
struct way{
	int k,a[50010],t[50010];
}e[510];
int dis[400010];
bool vis[400010];
inline int dij(int s,int t)
{
	for(int i=1;i<=2*m;i++) dis[i]=2e9,vis[i]=0;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	dis[s]=0;
	q.push({0,s});
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vis[u]==1) continue;
		vis[u]=1;
		for(auto t:ve[u])
		{
			int v=t.first,w=t.second;
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
	return dis[t];
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=m;i++)
	{
		ve[i].push_back({m+i,w[i]});
		ve[m+i].push_back({i,w[i]});
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&e[i].k);
		for(int j=1;j<=e[i].k;j++)
		{
			scanf("%d%d",&e[i].a[j],&e[i].t[j]);
		}
	}
	for(int l=1;l<=n;l++)
	{
		for(int i=1;i<=e[l].k;i++)
		{
			for(int j=1;j<=e[l].k;j++)
			{
				if(i==j) continue;
				ve[m+e[l].a[i]].push_back({m+e[l].a[j],e[l].t[i]+e[l].t[j]});
				ve[m+e[l].a[j]].push_back({m+e[l].a[i],e[l].t[i]+e[l].t[j]});
				ve[e[l].a[i]].push_back({e[l].a[j],e[l].t[i]+e[l].t[j]});
				ve[e[l].a[j]].push_back({e[l].a[i],e[l].t[i]+e[l].t[j]});
			}
		}
		/*
		ve[m+e[l].a[i]].push_back({m+e[l].a[j],e[l].t[i]+e[l].t[j]});
		ve[m+e[l].a[j]].push_back({m+e[l].a[i],e[l].t[i]+e[l].t[j]});
		ve[e[l].a[i]].push_back({e[l].a[j],e[l].t[i]+e[l].t[j]});
		ve[e[l].a[j]].push_back({e[l].a[i],e[l].t[i]+e[l].t[j]});
		*/
	}
	while(q--)
	{
		int s,t;
		scanf("%d%d",&s,&t);
		printf("%d\n",dij(s,t)+w[s]+w[t]);
	}
	return 0;	
} 
