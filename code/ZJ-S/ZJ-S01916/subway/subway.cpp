#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e3+5;
const int M=1e6+5;
struct node{
	int u,len;
	friend bool operator < (node t1,node t2){
		return t1.len>t2.len;
	}
};
int n,m,cnt,d,q;
int x[N],t[N],k[N];
int dis[N][N],vis[N][N];
int h[M],w[M],to[M],nxt[M];
void add(int a,int b,int c){
	cnt++;
	w[cnt]=c;
	to[cnt]=b;
	nxt[cnt]=h[a];
	h[a]=cnt;
} 
void dijkstra(int x){
	priority_queue<node>q;
	for(int i=1;i<=m;i++)
		dis[x][i]=1e15,vis[x][i]=0;
	q.push({x,0});
	dis[x][x]=0;
	while(!q.empty()){
		int u=q.top().u;
		int len=q.top().len;
		q.pop();
		if(vis[x][u]) continue;
		else vis[x][u]=true;
		for(int i=h[u];i;i=nxt[i])
			if(dis[x][to[i]]>len+w[i]){
				dis[x][to[i]]=len+w[i];
				if(!vis[x][to[i]]) q.push({to[i],dis[x][to[i]]});
 			}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;
	cin>>c>>n>>m>>d>>q;
	if(c<=11){
		for(int i=1;i<=m;i++)
			cin>>k[i];
		for(int i=1;i<=n;i++){
			int len;
			cin>>len;
			for(int j=1;j<=len;j++)
				cin>>x[j]>>t[j];
			for(int j=1;j<=len;j++)
			for(int k=1;k<=len;k++){
				if(j==k) continue;
				add(x[j],x[k],t[j]+t[k]);
			}
		}
		for(int i=1;i<=m;i++)
			dijkstra(i);
		while(q--){
			int u,v;
			cin>>u>>v;
			cout<<dis[u][v]+k[u]+k[v]<<"\n";
		}
		return 0;
	}
	return 0;
}