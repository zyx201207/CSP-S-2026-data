#include<bits/stdc++.h>
#define PII pair<int,int>
#define PLI pair<long long,int>
#define fir first
#define sec second
using namespace std;
inline int read(){
	int x=0; char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9')
		x=(x<<3)+(x<<1)+(c^48),
		c=getchar();
	return x;
}
const int N=505,M=500005;
int n,m,d,p,w[M];
bool vis[M+N];
long long dis[M+N];
vector<PII > e[M+N];
long long dijkstra(int st,int ed){
	memset(vis,false,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	dis[st]=0;
	priority_queue<PLI > q;
	q.push({-dis[st],st});
	while(!q.empty()){
		int u=q.top().sec; q.pop();
		if(vis[u]) continue; vis[u]=true;
		for(PII v:e[u]){
			if(dis[u]+1LL*v.sec<dis[v.fir])
				dis[v.fir]=dis[u]+1LL*v.sec,
				q.push({-dis[v.fir],v.fir});
		}
	}
	return dis[ed]+1LL*(w[st]+w[ed]);
}
long long dijkstra2(int st,int ed){
	memset(vis,false,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	dis[st]=0;
	queue<int> q;
	q.push(st);
	while(!q.empty()){
		int u=q.front(); q.pop();
		if(vis[u]) continue; vis[u]=true;
		for(PII v:e[u]){
			if(dis[u]+1LL*v.sec<dis[v.fir])
				dis[v.fir]=dis[u]+1LL*v.sec,
				q.push(v.fir);
		}
	}
	return dis[ed]+w[st]+w[ed];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c=read();
	n=read(),m=read(),d=read(),p=read();
	for(int i=1;i<=m;i++)
		w[i]=read();
	int las=-1;
	bool tkey=true;
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			int a=read(),t=read();
			if(las==-1) las=t;
			else if(las!=t) tkey=false;
			e[m+i].push_back({a,t});
			e[a].push_back({m+i,t});
		}
	}
	if(tkey){
		while(p--){
			int x=read(),y=read();
			long long g=dijkstra2(x,y);
			printf("%lld\n",g);
		}
		return 0;
	}
	while(p--){
		int x=read(),y=read();
		long long g=dijkstra(x,y);
		printf("%lld\n",g);
	}
	return 0;
}
