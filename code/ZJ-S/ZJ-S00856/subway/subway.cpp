#include<bits/stdc++.h>
#define fir first
#define sec second
typedef long long ll;
using namespace std;
const int N=500010;
int c,n,m,d,ques,k[N],a[510][30],used[N];
ll w[N],t[510][30],dis[N];
struct node{
	int v;
	ll dis;
	bool operator <(const node& x)const
	{
		return dis>x.dis;
	}
};
vector<node> mp[N*25];
void add(int u,int v,int w)
{
	mp[u].push_back(node{v,w});
	mp[v].push_back(node{u,w});
}
void dij(int s)
{
	memset(dis,0x7f,sizeof dis);
	memset(used,0,sizeof used);
	dis[s]=0;
	priority_queue<node> q;
	q.push(node{s,0});
	while(!q.empty())
	{
		int u=q.top().v;
		q.pop();
		for(node x:mp[u])
		{
			int v=x.v,va=x.dis;
			if(used[v]) continue;
			used[v]=1;
			if(dis[v]>dis[u]+va)
			{
				dis[v]=dis[u]+va;
				q.push(node{v,dis[v]});
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&ques);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++)
		{
			scanf("%d%lld",&a[i][j],&t[i][j]);
			add(a[i][j]+n,i,t[i][j]);
		}
	}
	while(ques--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		dij(x+n);
		printf("%lld\n",dis[y+n]+w[x]+w[y]);
	}
	return 0;
}


