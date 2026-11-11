// 44
#include<bits/stdc++.h>
using namespace std;
int read(){
	int x;
	scanf("%d",&x);
	return x;
}
const int N=510,M1=1e3+10,M2=2e3+10;
int w[M1];
struct edge{
	int to,w;
};vector<edge>vc[M2];
struct node{
	int u;
	long long dis;
	friend bool operator<(const node&cmp1,const node&cmp2){
		return cmp1.dis>cmp2.dis;
	}
};
long long f[M1][M2];
bool vis[M2];
void dijkstra(int s){
	memset(vis,0,sizeof(vis));
	priority_queue<node>pq;
	pq.push({s,0}),f[s][s]=0;
	while(!pq.empty()){
		node tp=pq.top();pq.pop();
		int u=tp.u;
		long long dis=tp.dis;
		if(vis[u])
			continue;
		vis[u]=true;
		for(edge it:vc[u]){
			int v=it.to,w=it.w;
			long long temp=dis+w;
			if(temp<f[s][v])
				pq.push({v,temp}),f[s][v]=temp;
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c=read(),n=read(),m=read(),d=read(),Q=read(),cnt=m;
	for(int i=1;i<=m;++i)
		w[i]=read();
	for(int i=1;i<=n;++i){
		int k=read();++cnt;
		while(k--){
			int a=read(),t=read();
			vc[a].push_back({cnt,t});
			vc[cnt].push_back({a,t});
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=m;++i)
		dijkstra(i);
	while(Q--){
		int u=read(),v=read();
		printf("%lld\n",w[u]+w[v]+f[u][v]);
	}
	return 0;
}
