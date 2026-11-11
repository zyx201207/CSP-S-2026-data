#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e2+10,maxm=5e5+10;
const ll inf=1e18+10;
int c,n,m,d,q;
int w[maxm],k[maxn],cnt[maxm];
ll dis[maxn][maxn];
struct MIO{
	int a,t;
};
struct ATI{
	int line_id,station_id;
};
vector<ATI>id[maxm];//下标从 0 开始 
vector<MIO>line[maxn];//下标从 1 开始
int read()
{
	int ret=0,w=1;char ch=0;
	while(ch<'0'||ch>'9') {if(ch=='-') w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {ret=(ret<<3)+(ret<<1)+(ch^48);ch=getchar();}
	return ret*w;
}
ll lmin(ll x,ll y) {return x<=y?x:y;}
void input()
{
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++)
	{
		k[i]=read();
		line[i].resize(k[i]+1);
		for(int j=1;j<=k[i];j++)
		{
			line[i][j].a=read(),line[i][j].t=read();
			id[line[i][j].a].push_back((ATI){i,j});
			cnt[line[i][j].a]++;
		}
	}
}
void pre()
{
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=inf;
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<cnt[i];j++) for(int k=0;k<cnt[i];k++)
		{
			if(j==k) continue;
			int lidj=id[i][j].line_id,sidj=id[i][j].station_id;
			int lidk=id[i][k].line_id,sidk=id[i][k].station_id;
			dis[lidj][lidk]=lmin(dis[lidj][lidk],(ll)line[lidj][sidj].t+(ll)line[lidk][sidk].t);
			dis[lidk][lidj]=lmin(dis[lidk][lidj],(ll)line[lidj][sidj].t+(ll)line[lidk][sidk].t);
		}
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
		dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
}
void deal()
{
//	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cout<<"dis["<<i<<"]["<<j<<"]="<<dis[i][j]<<'\n';
	while(q--)
	{
		int x,y;ll ans=inf;
		x=read(),y=read();
	//	cout<<"x="<<x<<" y="<<y<<'\n';
		for(int i=0;i<cnt[x];i++) for(int j=0;j<cnt[y];j++)
		{
			int sidi=id[x][i].station_id,sidj=id[y][j].station_id;
			int lidi=id[x][i].line_id,lidj=id[y][j].line_id;
//			cout<<"i="<<i<<" j="<<j<<" sidi="<<sidi<<" sidj="<<sidj<<'\n';
//			cout<<"lidi="<<id[x][i].line_id<<" lidj="<<id[y][j].line_id<<'\n';
//			cout<<"valx="<<line[id[x][i].line_id][sidi].t<<" valy="<<line[id[y][j].line_id][sidj].t<<'\n';
			ans=lmin(ans,dis[lidi][lidj]+line[id[y][j].line_id][sidj].t+line[id[x][i].line_id][sidi].t);
		}
		printf("%lld\n",ans+(ll)w[x]+(ll)w[y]);
	}
}
void solve()
{
	input();
	pre();
	deal();
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int test=1;
	while(test--) solve();
	return 0;
}