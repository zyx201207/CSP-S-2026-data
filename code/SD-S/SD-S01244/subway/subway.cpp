#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;
	char g=getchar();
	while(g<'0'||g>'9'){
		if(g=='-')f=-1;
		g=getchar();
	}
	while(g>='0'&&g<='9'){
		x=x*10+g-'0';
		g=getchar();
	}
	return x*f;
}
int c,n,m,q,d;
int ch[500005],k[500005];
struct node{
	int id,dis;
	bool operator>(const node& a)const{return dis>a.dis;}
};
struct node1{
	int to,w;
};
vector<node1>a[505];
int dis[20005],vis[20005];
void dijkstra(int s,int t){
	priority_queue<node,vector<node>,greater<node> >q;
	for(int i=1;i<=m;i++){
		vis[i]=0;dis[i]=INT_MAX;
	}
	q.push({s,0});
	dis[s]=0;
	while(!q.empty()){
		node x=q.top();
		q.pop();
		int u=x.id;
		if(vis[u]==1)continue;
		vis[u]=1;
		for(int i=0;i<a[u].size();i++){
			int v=a[u][i].to,w=a[u][i].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({v,dis[v]});
			}
		}
	}
	int ans=dis[t]+ch[s]+ch[t];
	cout<<ans<<'\n';
}
void solveA(){
	for(int i=1;i<=n;i++){
		cin>>k[i];
		if(k[i]==0)continue;
		if(k[i]==1){
			int x=read(),tx=read(); 
		}
		if(k[i]==2){
			int x=read(),tx=read(),y=read(),ty=read();
			a[x].push_back({y,tx+ty});
			a[y].push_back({x,tx+ty});
		}
	}
	for(int i=1;i<=q;i++){
		int s=read(),ed=read();
		if(s>ed)swap(s,ed);
		dijkstra(s,ed);
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++){
		ch[i]=read();
	}
	solveA();
	return 0;
}

