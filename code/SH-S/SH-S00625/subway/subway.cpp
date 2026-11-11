#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> pii;
int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while('0'<=c&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}
/*
地铁口没有用，除了一开始和结束都用不到这个 
坐地铁是不需要时间的，只有走路算时间 
500地铁数量，站台5e5，询问1e5 
一个站最多20个地铁，400条路径 
把地铁路线看成点 
换乘要走站，出站也要走站台 
ki之和是5e5的 
预处理从第i个地铁到第j个地铁，怎么走最快 
只需要有直接交集的处理就行了 
对于每个地铁站，直接暴力处理两两之间关系 
d是20，而且k之和5e5，最坏情况2e8，达不到这个情况，不会每个站台都有20个地铁 
边的数量控制到n^2以内，对于每个询问，有20种开局方式
每种，dijkstra处理地铁到另一个地铁的最快速度，On^2logn 
最后枚举20种结局方式看看哪个最优 
100pts
*/
const int N=505,M=5e5+5;
int c,n,m,d,T;
int w[M];
vector<pii>g[M];
int p[N][N];
vector<pii>e[N];
int dis[N][N];
bool v[N];
void dijkstra(int st){
	memset(v,0,sizeof v);
	dis[st][st]=0;
	priority_queue<pii,vector<pii>,greater<pii> >q;
	q.push({0,st});
	while(!q.empty()){
		int x=q.top().second;
		q.pop();
		if(v[x])continue;
		v[x]=1;
		for(pii y:e[x]){
			if(!v[y.first]&&dis[st][x]+y.second<dis[st][y.first]){
				dis[st][y.first]=dis[st][x]+y.second;
				q.push({dis[st][x]+y.second,y.first});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),T=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			int x=read(),y=read();
			g[x].push_back({i,y});
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=p[i][j]=1e18;
	for(int k=1;k<=m;k++){
		for(int i=0;i<g[k].size();i++){
			for(int j=i+1;j<g[k].size();j++){
				pii x=g[k][i],y=g[k][j];
				p[x.first][y.first]=min(p[x.first][y.first],x.second+y.second);
				p[y.first][x.first]=p[x.first][y.first];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(p[i][j]!=1e18)e[i].push_back({j,p[i][j]});
		}
	}
	while(T--){
		int st=read(),ed=read(),ans=1e18;
		for(pii fr:g[st]){
			int x=fr.first;
			if(dis[x][x]!=0)dijkstra(x);
			for(pii to:g[ed]){
				int y=to.first;
				ans=min(ans,w[st]+fr.second+dis[x][y]+to.second+w[ed]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
