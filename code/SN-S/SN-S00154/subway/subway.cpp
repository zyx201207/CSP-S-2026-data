#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool vis[200005];
int d[200005];
int w[200005];
vector<pair<int,int>>a[200005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,di,q,x;
	scanf("%d%d%d%d%d",&c,&n,&m,&di,&q);
	for(int i=0;i<m;i++)
		scanf("%d",&w[i]);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		pair<int,int> lst,y;
		scanf("%d%d",&lst.first,&lst.second);
		for(int j=1;j<x;j++)
		{
			scanf("%d%d",&y.first,&y.second);
			a[lst.first].push_back({lst.second+y.second,y.first});
			a[y.first].push_back({lst.second+y.second,lst.first});
		}
	}
	while(q--)
	{
		priority_queue<pair<int,int> >q;
		int s,t;
		scanf("%d%d",&s,&t);
//		q.clear();
		memset(d,0x3f,sizeof(d));
		memset(vis,0,sizeof(vis));
		q.push({0,s});
		d[s]=0;
		vis[s]=true;
		while(!q.empty())
		{
			int u=q.top().second;
			q.pop();
			if(vis[u])
				continue;
			vis[u]=true;
			for(auto i:a[u])
				if(d[i.second]>d[u]+i.first)
					d[i.second]=d[u]+i.first,q.push({-d[i.second],i.second});
		}
		printf("%d\n",d[t]+w[s-1]+w[t-1]);
	}
	return 0;
}

