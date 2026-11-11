#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PII;
const int N=510,M=5e5+10,T=1010;
const long long MAX=0x3f3f3f3f3f3f3f3f;
int task,n,m,d,q;
LL w[M],v[M+20*M];
vector<PII> sub[M],point[M];
vector<PII> g[M+20*M];
int cnt[M];
LL dis[T][T],res[M+20*M];
void init()
{
	/*
	 建图
	对于个相同的点，分为n*c+x个点，两两连边，代价为出台+进台
	对于每条线路，相邻建边，代价0
	*/
	// 对于每条线路，相邻建边，代价0
	for(int i=1;i<=n;i++)
		for(int j=0;j<(int)sub[i].size()-1;j++)
		{
			g[sub[i][j].first].emplace_back(PII{sub[i][j+1].first,0});
			g[sub[i][j+1].first].emplace_back(PII{sub[i][j].first,0});
		}
	// 对于个相同的点，分为n*c+x个点，两两连边，代价为出台+进台
	for(int i=1;i<=m;i++)
	{
		for(int l=0;l<(int)point[i].size();l++)
			for(int r=0;r<(int)point[i].size();r++)
			{
				if(l==r) continue;
				LL val=point[i][l].second+point[i][r].second;
				g[point[i][l].first].emplace_back(PII{point[i][r].first,val});
			}
	}
}
void bfs(int st,int en)
{
	queue<int> q;
	for(int i=1;i<=m;i++)
		for(int j=0;j<=cnt[i];j++)
			res[j*m+i]=MAX;
	for(int i=0;i<=cnt[st];i++)
		q.emplace(m*i+st),res[m*i+st]=w[st]+v[m*i+st];
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		for(auto to:g[u])
		{
			if(res[to.first]>res[u]+to.second)
				res[to.first]=res[u]+to.second,q.emplace(to.first);
		}
	}
	if(m<=1010)
		for(int i=1;i<=m;i++)
			for(int j=0;j<=cnt[i];j++)
				dis[st][i]=min(dis[st][i],res[j*m+i]+w[i]+v[m*j+i]);
	else
		for(int j=0;j<=cnt[en];j++)
			dis[0][0]=min(dis[0][0],res[j*m+en]+w[en]+v[m*j+en]);
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&task,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++)
	{
		int len,x;
		LL t;
		scanf("%d",&len);
		while(len--)
		{
			scanf("%d%lld",&x,&t);
			point[x].emplace_back(PII{cnt[x]*m+x,t});
			cnt[x]++,x=(cnt[x]-1)*m+x;
			v[x]=t,sub[i].emplace_back(PII{x,t});
		}
	}
	init();//建图
//	for(int i=1;i<=m+2;i++)
//	{
//		cout<<i<<":";
//		for(auto to:g[i])
//			cout<<to.first<<" ";
//		cout<<endl;
//	}
	memset(dis,0x3f,sizeof(dis));
	if(m<=1010) for(int i=1;i<=m;i++) bfs(i,0);
//	for(int i=1;i<=m;i++)
//	{
//		for(int j=1;j<=m;j++)
//			cout<<dis[i][j]<<" ";
//		cout<<endl;
//	}
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(m<=1010) printf("%lld\n",dis[x][y]);
		else dis[0][0]=MAX,bfs(x,y),printf("%lld\n",dis[0][0]);
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/