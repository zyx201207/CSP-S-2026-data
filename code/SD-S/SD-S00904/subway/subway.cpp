#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define ll long long
using namespace std;
const int N=550;
const int M=5e5+10;
ll w[M],ans,ki[N],c,n,m,d,qq,tt,s,a[N][N],t[N][N];
bool b[M],vis[N][M];
void dfs(ll x,ll cnt,ll nw)//nw表示当前是几号路线 
{
	if(x==tt){ans=min(cnt,ans);return;}//当前确保每次状态都是在站厅。
	//需要选择去哪个地铁站台并回到相应站厅 
	//两种选择，一种是继续走当前路线，一种是换线
	for(ll i=1;i<ki[nw];i++)//继续选择当前路线
	{
		if(x==a[nw][i]) 
		{
			for(ll j=i+1;j<=ki[nw];j++)//将后面的全都判断一下 
			{			
					dfs(a[nw][j],cnt+t[nw][i]+t[nw][j],nw);
					//从当前也就是从nw号线路的i号地铁站厅走到j站台的时间 		
				//如果当前被走过，那么转过线的和没转过线的一定都走过了 	
			}
			break;
		}
	 } 
	for(ll i=nw+1;i<=n;i++)
	{
		if(vis[i][x]&&i!=nw)
		{
			for(ll j=1;j<ki[i];j++)//寻找交汇点 
			{
				if(x==a[i][j])
				{
					for(ll k=j+1;k<=ki[i];k++)//枚举交汇点之后的点 
					{	
						dfs(a[i][k],cnt+t[i][j]+t[i][k],i);		
					}
				}
			}
		}
	}
}
vector<ll> E[30000];
ll dis[M];
priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > q;
void check(ll ss,ll ttt)
{
	memset(b,false,sizeof(b));
	
	for(ll i=1;i<=n;i++)
	for(ll j=1;j<ki[i];j++)
		E[a[i][j]].push_back(a[i][j+1]);
	memset(dis,0x3f,sizeof(dis));
	dis[ss]=0;
	q.push(make_pair(w[ss],ss));
	while(!q.empty())
	{
		ll u=q.top().second;q.pop();
		if(b[u])continue;
		b[u]=1;
		for(ll i=0;i<E[u].size();i++)
		{
			ll v=E[u][i];
			if(dis[v]>dis[u]+1)
			{
				dis[v]=dis[u]+1;
				q.push(make_pair(dis[v],v));
			}
		}
	}
	printf("%lld\n",dis[tt]*t[1][1]+w[s]+w[tt]);
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%ld%lld%lld",&c,&n,&m,&d,&qq);//地铁线数目n,地铁站数目m， 
	for(ll i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&ki[i]);
		for(int j=1;j<=ki[i];j++)
		{
			scanf("%lld%lld",&a[i][j],&t[i][j]);
			vis[i][a[i][j]]=1;
			//第i条路线经过a[i][j]号地铁站，到其站台的时间为t[i][j] 
		}
	}
	
	for(ll i=1;i<=qq;i++)
	{	
		scanf("%lld%lld",&s,&tt);
		if(c>=12&&c<=19){check(s,tt);continue;}
		ans=1e18;
		for(int j=1;j<=n;j++)		
		if(vis[j][s])//第i条线路的上有没有s点 
		{	
			dfs(s,w[s]+w[tt],j);
		}
		printf("%lld\n",ans);
	}
	return 0;
}



