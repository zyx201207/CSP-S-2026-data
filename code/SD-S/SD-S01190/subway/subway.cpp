#include<bits/stdc++.h>
#include<chrono>
#define ms microseconds
#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define N 1000005
#define M 505
using namespace std;
using namespace chrono;
typedef pair<ll,int> pli;
auto Star=system_clock::now();
auto GetTime(){return (double)(duration_cast<ms>(system_clock::now()-Star).count())*ms::period::num/ms::period::den;}
void PrintTime(){cout<<"Cost="<<GetTime()<<endl;}
int read()
{
	int t=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)) t=t*10+ch-48,ch=getchar();
	return t*f;
}
const ll inf =0x3f3f3f3f3f3f3f3f;
int n,m;
ll W[N];
ll e[M][M],dis[M][M];bool vis[M];
//map<int,pii>book2;//[m]->(n,d)
//map<pii,int>book1;//(n,d)->m
vector<pair<int,ll> >a[N];
int fst[M*M],nxt[M*M*2],to[M*M*2],idx=-1;ll w[M*M*2];
void add(int x,int y,ll z){idx++;nxt[idx]=fst[x];fst[x]=idx;to[idx]=y;w[idx]=z;}
void dijkstra(int S)
{
	int i,j;
	priority_queue<pli,vector<pli>,greater<pli> >q;
	for(i=1;i<=m;i++) dis[S][i]=inf;
	memset(vis,0,sizeof(vis));
	dis[S][S]=0;q.push(mp(0,S));
//	printf("S=%d\n",S);
	while(!q.empty())
	{
		
		int x=q.top().se;q.pop();
//		printf("x=%d\n",x);
		if(vis[x]) continue; vis[x]=1;
		for(i=fst[x];~i;i=nxt[i])
		{
			int y=to[i];
//			printf("y=%d\n",y);
			if(dis[S][y]>dis[S][x]+w[i])
			{
				dis[S][y]=dis[S][x]+w[i];
				q.push(mp(dis[S][y],y));
			}
		}
	}
	return ;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(fst,-1,sizeof(fst));
	int C=read(),i,j,k;
	m=read(),n=read();int d=read(),q=read();
	for(i=1;i<=n;i++) W[i]=read();
	
	for(i=1;i<=m;i++)
	{
		int len=read();
		for(j=1;j<=len;j++)
		{
			int x=read(),y=read();
			a[x].pb(mp(i,y));
//			book1[mp(x,a[x].size()-1)]=i;
		}
		
	}
	
	memset(e,0x3f3f,sizeof(e));
	for(i=1;i<=n;i++)
	{
	
		int len=a[i].size();
		for(j=0;j<len;j++)
		{
			for(k=j+1;k<len;k++)
			{
				int p1=a[i][j].fi,p2=a[i][k].fi;
				e[p1][p2]=e[p2][p1]=min(e[p1][p2],a[i][j].se+a[i][k].se);//从p1到p2的最短换乘 
			}
		}
	}
	for(i=1;i<=m;i++)  for(j=i+1;j<=m;j++) 
	{
		add(i,j,e[i][j]),add(j,i,e[j][i]);
//		printf("i=%d j=%d\n",i,j);
	}
	for(i=1;i<=m;i++){dijkstra(i);}
	
	while(q--)
	{
		int st=read(),en=read();
		ll ans=inf;
		for(i=0;i<a[st].size();i++)
		{
			for(j=0;j<a[en].size();j++)
			{
				int p1=a[st][i].fi,p2=a[en][j].fi;
				ans=min(ans,W[st]+W[en]+a[st][i].se+a[en][j].se+dis[p1][p2]);
			}
		}
		printf("%lld\n",ans);
	}
//	PrintTime();
	return 0;
	fclose(stdin);
	fclose(stdout);

}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3


*/
