#include<bits/stdc++.h>
#define int long long
#define MAXN 500005
using namespace std;

inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}

int c,n,m,d,q;

int w[MAXN];

struct node{
	int to,val;
	operator < (node tmp)const{
		return tmp.val<val;
	}; 
};

int dis[MAXN];
bool vis[MAXN];

priority_queue<node> pq;

vector<node> edge[MAXN];

void Dijkstra(int s){
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	pq.push({s,0});
	while(!pq.empty()){
		node tmp=pq.top();
		pq.pop();
		int u=tmp.to;
		if(vis[u]) continue;
		vis[u]=1;
		for(auto e:edge[u]){
			int v=e.to,w1=e.val,w2=w[v]+w[u];
			if(dis[u]+w1+w2<dis[v]){
				dis[v]=dis[u]+w1+w2;
				pq.push({v,dis[v]});
			}
		}
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		int k;
		k=read();
		for(int j=1;j<=k;j++){
			int a,t;
			a=read();t=read();
			edge[j].push_back({a,t});
			edge[a].push_back({j,t});
		}
	}
	for(int i=1;i<=n;i++){
		int s,ed;
		s=read();ed=read();
		memset(vis,0,sizeof(vis));
		Dijkstra(s);
		printf("%lld\n",dis[ed]);
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
