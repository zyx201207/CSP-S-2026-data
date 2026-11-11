#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fi first
#define se second
const int N=509,M=500009;
int c,n,m,dd,qq,w[M],d[N+M];
bool vis[N+M];
vector<pii> to[N+M];
int dijkstra(int s,int e){
	memset(d,0x3f3f3f3f,sizeof(d));
	queue<pii> q;
	q.push({s,0}),d[s]=0;
	while(!q.empty()){
		pii t=q.front();q.pop();
		int u=t.fi;
		vis[u]=1;
		for(pii tt:to[u]){
			int v=tt.fi,dis=tt.se;
			if(d[u]+dis<d[v])d[v]=d[u]+dis,vis[v]=0;
			if(!vis[v])vis[v]=1,q.push({v,d[v]});
		}
	}
	return d[e];
}
int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c))x=x*10+c-'0',c=getchar();
	return x*f;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),dd=read(),qq=read();
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1,k;i<=n;i++){
		k=read();
		for(int j=1,id,t;j<=k;j++)id=read(),t=read(),to[id].push_back({i+m,t}),to[i+m].push_back({id,t});
	}
	while(qq--){
		int x,y;
		x=read(),y=read();
		cout<<w[x]+w[y]+dijkstra(x,y)<<endl;
		memset(vis,0,sizeof(vis));
	}
	return 0;
}//56pts
