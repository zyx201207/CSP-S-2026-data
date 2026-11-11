#include<bits/stdc++.h>
#define int long long

const int N=510;

const int M=5e5+10;

using namespace std;

int T;

int c;

int n,m,d,q;

int W[M];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')ret=ret*10+(ch&15),ch=getchar();
	return ret*f;
}

struct edge{
	int to,w;
};

vector<edge>e[N+M];

void add_e(int x,int y,int z){
	e[x].push_back((edge){y,z});
}

int dis[N+M],vis[N+M];

struct node{
	int x,dis;
	bool operator<(const node &b)const{return dis>b.dis;}
};

priority_queue<node>que;

void Dij(int st){
	while(!que.empty())que.pop();
	for(int i=1;i<=n+m;i++)dis[i]=1e18,vis[i]=0;
	dis[st]=0;
	que.push((node){st,0});
	while(!que.empty()){
		node now=que.top();
		que.pop();
		int u=now.x;
		if(vis[u])continue;
		vis[u]=1;
		int siz=e[u].size();
		for(int i=0;i<siz;i++){
			int v=e[u][i].to;
			if(dis[u]+e[u][i].w<dis[v]){
				dis[v]=dis[u]+e[u][i].w;
				que.push((node){v,dis[v]});
			}
		}
	}
}

//struct info{
//	int a,t;
//};
//
//vector<info>tmp[N];

void _solve(){
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)W[i]=read();
	for(int i=1;i<=n;i++){
		int k=read();
		while(k--){
			int a=read(),t=read();
			add_e(i,a+n,t),add_e(a+n,i,t);
		}
	}
	while(q--){
		int x=read(),y=read();
		Dij(n+x);
		int ans=W[x]+W[y]+dis[n+y];
		printf("%lld\n",ans);
	}
}

signed main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	T=1;
	while(T--)_solve();
	return 0;
}