#include<bits/stdc++.h>
using namespace std;
const int N=505,M=130005,inf=2e9;
int c,n,m,D,Q,w[M],d[M],k,ans,S,T,W;
struct sta
{
	int a,t;
};
vector<sta>l[N];//line
struct edge
{
	int num,v,w,way;//num:what line?
};
vector<edge>g[N];
struct node
{
	int id,num,val,lst;
	friend bool operator<(node n1,node n2)
	{
		return n1.val>n2.val;
	}
};
node now;
priority_queue<node>q;
int bfs()
{
	while(!q.empty())
	{
//		cout<<"ddd\n";
		now=q.top();
		q.pop();
		int u=now.id,num=now.num,val=now.val,lst=now.lst;
		if(u!=S&&!num) continue;
//		cout<<u<<" line:"<<num<<" cost:"<<val<<"\n";
		if(u==T) return val;
		for(int i=0;i<g[u].size();i++)
		{
			int v=g[u][i].v,w=g[u][i].w,numv=g[u][i].num,way=g[u][i].way;
			if(d[v]>d[u]+w&&num==numv&&u!=v&&(way==0||way==W))
			{
				d[v]=d[u]+w;
				q.push({v,num,d[v],u});
			}
			else if(u==v&&lst!=u)
			{
				q.push({v,numv,d[u]+w,u});
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>D>>Q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k;
//		cout<<"worry\n";
		int lstt,lsta;
		for(int j=1;j<=k;j++)
		{
			int a,t;
			cin>>a>>t;
			l[i].push_back({a,t});
			g[a].push_back({i,a,t,0});
			if(j!=1)
			{
				g[a].push_back({i,lsta,lstt,-1});
				g[lsta].push_back({i,a,lstt,1});
			}
			lsta=a,lstt=t;
		}
		for(int j=0;j<l[i].size()-1;j++)
		{
			int u=l[i][j].a,v=l[i][j+1].a;
//			nums[u].push_back({i,l[i][j].t});
//			if(j==l[i].size()-1)
//			if(j==0||(j==l[i].size()-1))
//			{
//				int w=l[i][j].t;
//				g[u].push_back({i,v,w});
//				g[v].push_back({i,u,w});
//			}
//			else
//			{
			if(j!=0&&j!=l[i].size()-1)
			{
				g[u].push_back({i,v,0,0});
				g[v].push_back({i,u,0,0});
			}
				
//			}
		}
	}
//	for(int i=1;i<=m;i++)
//	{
//		for(int j=0;j<nums[i].size();j++)
//		{
//			cout<<i<<":"<<nums[i][j].num<<" "<<nums[i][j].val<<"\n";
//		}
//	}
//	for(int i=1;i<=m;i++)
//	{
//		for(int j=0;j<g[i].size();j++)
//		{
//			cout<<"way:"<<i<<"to"<<g[i][j].v<<" num:"<<g[i][j].num<<" cost:"<<g[i][j].w<<"way:"<<g[i][j].way<<"\n";
//		}
//	}
	while(Q--)
	{
		cin>>S>>T;
		ans=0;
		W=1;
		for(int i=1;i<=m;i++) d[i]=inf;
		d[S]=0;
		while(!q.empty()) q.pop();
		now.id=S,now.num=0,now.val=0,now.lst=-1;
		q.push(now);
		ans+=bfs();
//		cout<<"\n";
		swap(S,T);
		W=-1;
		for(int i=1;i<=m;i++) d[i]=inf;
		d[S]=0;
		while(!q.empty()) q.pop();
		now.id=S,now.num=0,now.val=0,now.lst=-1;
		q.push(now);
		ans+=bfs();
		ans=ans+w[S]+w[T];
		cout<<ans<<"\n";
	}
	
	
	return 0;
}