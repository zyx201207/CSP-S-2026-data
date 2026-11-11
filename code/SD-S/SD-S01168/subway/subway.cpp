#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
using namespace std;
const int N=510;
const int M=5e5+100;
const ll inf=1e18;
int rd()
{
	int x=0,y=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')y=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	return x*y;
}
int c,n,m,d,q,ln[M];
int vec[M][21][2],val[M];
ll dis[N][N];
void floyd()
{
	rep(k,1,n)rep(i,1,n)rep(j,1,n)if(dis[i][k]!=inf&&dis[k][j]!=inf)
		dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=rd();n=rd();m=rd();d=rd();q=rd();
	rep(i,1,m)val[i]=rd();
	rep(i,1,n)
	{
		int len=rd();
		rep(j,1,len)
		{
			int a=rd(),b=rd();
			vec[a][++ln[a]][0]=i;
			vec[a][ln[a]][1]=b;
		}
	}
	rep(i,1,n)rep(j,1,n)dis[i][j]=inf;
	rep(i,1,n)dis[i][i]=0;
	rep(i,1,m)rep(j,1,ln[i])rep(k,j+1,ln[i])
	{
		int u=vec[i][j][0],v=vec[i][k][0];
		dis[u][v]=min(dis[u][v],(ll)vec[i][j][1]+vec[i][k][1]);
		dis[v][u]=dis[u][v];
	}
	//rep(i,1,n)rep(j,1,n)printf("%d %d %lld\n",i,j,dis[i][j]);
	floyd();
	rep(i,1,q)
	{
		int x=rd(),y=rd();
		ll ans=inf;
		rep(j,1,ln[x])rep(k,1,ln[y])
			ans=min(dis[vec[x][j][0]][vec[y][k][0]]+vec[x][j][1]+vec[y][k][1],ans);
		ans=ans+val[x]+val[y];
		printf("%lld\n",ans);
	}
	return 0;
}

