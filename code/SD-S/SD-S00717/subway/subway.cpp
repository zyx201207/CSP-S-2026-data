#include<bits/stdc++.h>
#define int long long
using namespace std;
struct Node{
	int to,num;
	bool operator < (const Node &b) const{return num<b.num;}
	bool operator > (const Node &b) const{return num>b.num;}
};
const int N=405,M=505,MAXN=2e5+10,inf=1e18+1;
int c,n,m,d,Q,w[N],k[M],dis[MAXN],p[M][N];
bool vis[MAXN];
vector<Node> v[M],vec[N],g[MAXN];
int get_id(int i,int j)//第j层的第i个点 
{
	return m*(j-1)+i;	
}
int dij(int S,int T)
{
	priority_queue<Node,vector<Node>,greater<Node>> q;
	for(int i=1;i<=m*n;i++) dis[i]=inf;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
	{
		int g=get_id(S,i);
		dis[g]=p[S][i];
		q.push({g,p[S][i]});
	}
	while(!q.empty())
	{
		Node u=q.top();
		q.pop();
		
		if(vis[u.to]) continue;
		vis[u.to]=true;
		for(Node i:g[u.to])
		{
			if(vis[i.to]) continue;
			if(dis[i.to]>dis[u.to]+i.num)
			{
				dis[i.to]=dis[u.to]+i.num;
				q.push({i.to,dis[i.to]});
			}
		}
	}
	int ans=inf;
	for(int i=1;i<=n;i++)
	{
		int g=get_id(T,i);
		ans=min(ans,dis[g]+p[T][i]);
	}
	return ans;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&Q);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++)
		{
			int x,y;
			scanf("%lld%lld",&x,&y);
			v[i].push_back({x,y});
			vec[x].push_back({i,y});
			p[x][i]=y;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<vec[i].size();j++)
		{
			for(int k=0;k<j;k++)
			{
				int gi=get_id(i,vec[i][j].to),gj=get_id(i,vec[i][k].to),sum=vec[i][j].num+vec[i][k].num;
				g[gi].push_back({gj,sum});
				g[gj].push_back({gi,sum});
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<k[i];j++)
		{
			int gi=get_id(v[i][j-1].to,i),gj=get_id(v[i][j].to,i);
			g[gi].push_back({gj,0});
			g[gj].push_back({gi,0});
		}
	}
	while(Q--)
	{
		int xi,yi;
		scanf("%lld%lld",&xi,&yi);
		printf("%lld\n",dij(xi,yi)+w[xi]+w[yi]);
	}
	
	return 0;
}
//0 3 7 20 2
//8 3 6 1 7 2 9
//3 1 4 2 5 5 100
//3 2 6 3 1 7 2
//4 3 2 5 100 4 6 6 7
//1 6
//2 3

