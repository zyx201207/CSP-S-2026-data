#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
struct req
{
	long long id;
	long long x,y;
};
req que[500005];
vector<pair<long long,long long>> edge[500005];	//把一条线路缩成一个点。1~m为出站口， m+1~2m为站厅，2m+1~2m+n为一条地铁。 
priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> > > pq;
long long dis[500005];
long long ans[500005];
bool cmp(req a,req b)
{
	return a.x<b.x;
}
void dij(long long x)
{
	pq.push({0,x});
	while(!pq.empty())
	{
		auto top=pq.top();
		pq.pop();
		long long now,d;
		d=top.first;
		now=top.second;
		for(long long i=0;i< edge[now].size();i++)
		{
			auto nxt=edge[now][i];
			long long w,v;
			w=nxt.first;
			v=nxt.second;
			
			if(w+d<dis[v])
			{
				pq.push({w+d,v});
				dis[v]=w+d;
//				cout<<v<<" "<<w+d<<endl;
			}
		}
	}
	while(!pq.empty())
	{
		auto top=pq.top();
		pq.pop();
		long long u,d;
		d=top.first;
		u=top.second;
		dis[u]=d;
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++)
	{
		long long w; 
		cin>>w;
		edge[i].push_back({w,i+m});
		edge[i+m].push_back({w,i});
	}
	for(long long i=1;i<=n;i++)
	{
		long long k;
		cin>>k;
		long long id=2*m+i;
		for(long long j=1;j<=k;j++)
		{
			// i号线，第j站
			long long a,t;
			cin>>a>>t;
			long long sta=m+a;
			edge[id].push_back({t,sta});
			edge[sta].push_back({t,id});
		}
	}
	
	
	for(long long Q=1;Q<=q;Q++)
	{
		long long x,y;
		cin>>x>>y;
		que[Q]={Q,min(x,y),max(x,y)};	//小优化 
	}
	
	sort(que+1,que+q+1,cmp);
//	for(long long i=1;i<=q;i++)
//	{
//		cout<<que[i].x<<" "<<que[i].y<<" "<<que[i].id<<endl;
//	}
	long long Q=1;
	while(Q<=q)
	{
		memset(dis,0x3f,sizeof dis);
		
		long long x,y,id;
		x=que[Q].x,y=que[Q].y,id=que[Q].id;
		dij(x);
//		cout<<x<<" "<<y<<" "<<id<<endl;
		ans[id]=dis[y];
		while(que[++Q].x==x)	ans[que[Q].id]=dis[que[Q].y];
	}
	for(long long Q=1;Q<=q;Q++)	cout<<ans[Q]<<endl;
	return 0;
}

// 验收完成 A
// 验收完成 B

// 回家看龙族去吧 
