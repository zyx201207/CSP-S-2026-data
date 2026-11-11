//Dp[i][j]表示线路i到线路j的最小转换时间 
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll cnt,head[505],Dis[505][505],N,M,zt1,zt2,Tcosnow,Dp[505][505],vis[505],To,D,C,DD,Q,W[500005],Stanum,Sta,Tim;
ll u,v,sizeu,sizev,Ans;
struct zhantai
{
	ll p,tcos;//p表示第几条线路，tcos 表示站厅到站台花费的时间 
}zhtai;
struct edge
{
	ll to,next,d;
}e[500005]; 
struct pri
{
	ll id,nowdp;
	bool operator < (const pri &x) const
	{
		return nowdp>x.nowdp;//堆顶小 
	}
}Frt,Tes;
priority_queue<pri> q;
vector<zhantai> zt[500005];
void Add(ll from,ll to,ll dist)
{
	e[++cnt].next=head[from];
	e[cnt].to=to;
	e[cnt].d=dist;
	head[from]=cnt;
 } 
void Dij()
{
	//建边:先找最小距离，再建边 
	memset(Dis,63,sizeof(Dis));
	for(int i=1;i<=N;i++) Dis[i][i]=0;
	for(int i=1;i<=M;i++)
	{
		for(int j=0;j<zt[i].size();j++)
		{
			for(int k=j+1;k<zt[i].size();k++)
			{
				zt1=zt[i][j].p;
				zt2=zt[i][k].p;
				Tcosnow=zt[i][j].tcos+zt[i][k].tcos;
				if(Tcosnow<Dis[zt1][zt2])
				{
					Dis[zt1][zt2]=Tcosnow;
					Dis[zt2][zt1]=Tcosnow;
				}
			}
		}
	 } 
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			if(i==j) continue;
			Add(i,j,Dis[i][j]);//i>j,i<j一样都会做到 
		}
	 } 
	memset(Dp,63,sizeof(Dp));
	for(int i=1;i<=N;i++)//以 i 为出发点 
	{
		memset(vis,0,sizeof(vis));
		//q已经空
		Dp[i][i]=0;
		Frt.id=i;
		Frt.nowdp=0;
		q.push(Frt);
		while(!q.empty())
		{
			Frt=q.top();
			q.pop();
			if(vis[Frt.id]==1) continue;
			vis[Frt.id]=1;
			for(int j=head[Frt.id];j;j=e[j].next)
			{
				To=e[j].to;
				D=e[j].d;
				if(Frt.nowdp+D<Dp[i][To])
				{
					Dp[i][To]=Frt.nowdp+D;
					if(!vis[To])
					{
						Tes.id=To;
						Tes.nowdp=Frt.nowdp+D;
						q.push(Tes);
					}
				}
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&C,&N,&M,&DD,&Q);
	for(int i=1;i<=M;i++) scanf("%lld",&W[i]);
	for(int i=1;i<=N;i++)
	{
		scanf("%lld",&Stanum);
		for(int j=1;j<=Stanum;j++)
		{
			scanf("%lld%lld",&Sta,&Tim);
			zhtai.p=i;
			zhtai.tcos=Tim;
			zt[Sta].push_back(zhtai);
		}
	}
	//计算每两条线路的最快转换到达时间
	Dij();
	for(int i=1;i<=Q;i++)
	{
		scanf("%lld%lld",&u,&v);
		sizeu=zt[u].size();
		sizev=zt[v].size();
		Ans=1e18;
		for(int j=0;j<sizeu;j++)
		{
			for(int k=0;k<sizev;k++)
			{
				Ans=min(Ans,W[u]+W[v]+zt[u][j].tcos+zt[v][k].tcos+Dp[zt[u][j].p][zt[v][k].p]);
			}
		}
		printf("%lld\n",Ans);
	} 
	return 0;
 }
