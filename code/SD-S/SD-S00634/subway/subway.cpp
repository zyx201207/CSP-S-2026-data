#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5;
struct edge{
	int v,w,nxt;
}E[M<<1];
struct node{
	int v,w;
	bool operator < (const node &p)const{
		return w>p.w;
	}
};
int head[M],tot;
void add(int u,int v,int w){
	E[++tot]=(edge){v,w,head[u]};head[u]=tot;
	E[++tot]=(edge){u,w,head[v]};head[v]=tot;
}
int dis[M];
bool vis[M];
priority_queue<node>Q;
int D(int st,int ed){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[st]=0;
	Q.push((node){st,0});
	while(!Q.empty()){
		int u=Q.top().v;Q.pop();
		if(vis[u])continue;
		vis[u]=true;
		for(int i=head[u];~i;i=E[i].nxt){
			int v=E[i].v,w=E[i].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				Q.push((node){v,dis[v]});
			}
		}
	}return dis[ed];
}
int w[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(head,-1,sizeof(head));
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		vector<int>a(k+1),t(k+1);
		for(int j=1;j<=k;j++)cin>>a[j]>>t[j];
		for(int j=1;j<=k;j++){
			for(int sd=j+1;sd<=k;sd++){
				add(a[j],a[sd],t[j]+t[sd]);
			}
		}
	}
	while(q--){
		int x,y;cin>>x>>y;
		cout<<w[x]+w[y]+D(x,y)<<"\n";
	}return 0;
}
