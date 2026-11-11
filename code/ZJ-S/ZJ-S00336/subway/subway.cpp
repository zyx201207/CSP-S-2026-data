#include<bits/stdc++.h>
#include<queue>
#define ll long long
#define min(a,b) (a<b?a:b)
using namespace std;
inline ll read()
{
	ll f=1,x=0;char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return f*x;
}
int c,n,m,d,t_,i,j;
int w[500005],k[505];
vector<int>a[505],t[505];
int st,ed;
struct Edge{
	int to,dis,next;
}edge[2000005];
int head[1000005],cnt;
void add(int x,int y,int z)
{
	edge[++cnt]={y,z,head[x]};
	head[x]=cnt;
}
ll dis[500005];
//struct node{
//	int u;ll dis;
//}tmp;
//bool operator >(node x,node y)
//{
//	return x.dis>y.dis;
//}
//bool operator <(node x,node y)
//{
//	return x.dis<y.dis;
//}
//priority_queue<node,vector<node>,greater<node> >q;
//void dijkstra()
//{
//	memset(dis,0x3f,sizeof(dis));
//	memset(vis,0,sizeof(vis));
//	q.push((node){st,0});
//	dis[st]=0;
//	while(q.size())
//	{
//		tmp=q.top();
//		q.pop();
//		int u=tmp.u;
//		ll dis_=tmp.dis;
//		if(u==ed)return;
//		if(vis[u])continue;
//		vis[u]=1;
//		for(int i=head[u];i;i=edge[i].next)
//		{
//			int v=edge[i].to;
//			ll len=edge[i].dis;
//			if(dis[v]>dis_+len)
//			{
//				dis[v]=dis_+len;
//				q.push((node){v,dis[v]});
//			}
//		}
//		if(u>m)
//		{//可以坐地铁 
//			
//		}
//	}
//}
struct node{
	//节点,当前坐的是几号线,花了多久 
	int u,line,time;
}tmp;
queue<node>q;
bool vis[805][505];//节点，在哪条线
vector<int>change[500005];
int where[505][500005];
ll ans=1e18;
void bfs()
{// change表示当前节点可以换成那哪几条线 
	q.push({st,0,0});
	while(!q.empty())
	{
		tmp=q.front();
		int u=tmp.u,line=tmp.line,time=tmp.time;
//		cout<<u<<' '<<line<<' '<<time<<'\n';
		q.pop();
//		if(vis[u][line])continue;
		if(u==ed)
		{
			time+=t[line][where[line][u]];
//			cout<<"end "<<time<<'\n';
			ans=min(ans,time);
			continue;
		}
//		cout<<"not ed\n";
		vis[u][line]=1;
		//现在换乘
		int kkksc03=change[u].size();
		for(int i=0;i<kkksc03;i++)
		{
			int v=change[u][i];
			if(line==v)continue;
			if(line==0)
			{
				int time_=time+t[v][where[v][u]];
//				cout<<"now change:"<<v<<" new time="<<time_<<"\n";
				if(!vis[u][v])q.push({u,v,time_});
				continue;
			}
//			cout<<where[line][u]<<' '<<where[v][u]<<'\n';
			int time_=time+t[line][where[line][u]]+t[v][where[v][u]];
//			cout<<"now change:"<<v<<" new time="<<time_<<"\n";
			if(!vis[u][v])q.push({u,v,time_});
		}
		//现在坐地铁去其他地方
		if(line!=0)
		for(i=1;i<=k[line];i++)
		{
			int v=a[line][i];
			if(v==u)continue;
			if(vis[v][line])continue;
//			cout<<"now take the subway to "<<v<<" time="<<time<<'\n';
			q.push({v,line,time});
		}
	}
	cout
//		<<"finally ans="
		<<ans+w[st]+w[ed]<<'\n';
}
void solve1()
{
	//tmd太难了，今年拿不到S1=了555
	//CCF MYK
	//1~m表示地铁站
	//m+1~2m 表示站台
	while(t_--)
	{
		st=read();ed=read();
		memset(dis,0,sizeof(dis));
		memset(vis,0,sizeof(vis));
		ans=1e18;
		bfs();
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();t_=read();
	for(i=1;i<=m;i++)
		w[i]=read();
	for(i=1;i<=n;i++)
	{
		k[i]=read();
		a[i].resize(k[i]+5);
		t[i].resize(k[i]+5);
		for(j=1;j<=k[i];j++)
		{
			a[i][j]=read(),t[i][j]=read();
			where[i][a[i][j]]=j;
			change[a[i][j]].push_back(i);
		}
	}
	solve1();
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
本来想整活的，结果太难了，没空整
ok啊兄弟们，也是成功打完了所有暴力
特殊性质也是一个也不会
//freopen
//freopen
我要上人类迷惑行为大赏
酸酸甜甜! 
*/
