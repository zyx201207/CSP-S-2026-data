#include <bits/stdc++.h>
#define N 503
#define M 500003
using namespace std;
struct node{
	int v,w;
};
priority_queue<node>Q,emp;
vector<node>vec_st[M],vec[N];
int c,n,m,d,q,w[M],a[M],t[M],dis[N];
bool vis[N];
bool operator<(node s1,node s2){
	return s1.w>s2.w;
}
void Dijkstra(int s){
	memset(dis,0x3f,sizeof dis),memset(vis,0,sizeof vis),Q=emp;
	dis[s]=0;
	Q.push({s,0});
	while(!Q.empty()){
		int u=Q.top().v;
		Q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(unsigned i=0;i<vec[u].size();i++){
			int v=vec[u][i].v,w=vec[u][i].w;
			if(vis[v]) continue;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				Q.push({v,dis[v]});
			}
		}
	}
	return;
}
int main(){
	freopen("tmpp","r",stdin);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,a,t;j<=k;j++){
			cin>>a>>t;
			vec_st[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		if(vec_st[i].size()<=1) continue;
		for(unsigned j=0;j<vec_st[i].size()-1;j++){
			for(unsigned k=j+1;k<vec_st[i].size();k++){
				int x=vec_st[i][j].v,y=vec_st[i][k].v;
				vec[x].push_back({y,vec_st[x][y].w+vec_st[x][y].w});
				vec[y].push_back({x,vec_st[x][y].w+vec_st[x][y].w});
			}
		}
	}
	for(int i=1,x,y,ans=0x3f3f3f3f;i<=q;ans=0x3f3f3f3f,i++){
		cin>>x>>y;
		for(unsigned j=0;j<vec_st[x].size();j++){
			for(unsigned k=0;k<vec_st[y].size();k++){
				int u=vec_st[x][j].v,v=vec_st[y][k].v;
				Dijkstra(u);
				for(unsigned o=0;o<vec[u].size();o++){
					for(unsigned p=0;p<vec[v].size();p++){
						ans=min(::w[x]+vec[u][o].w+dis[v]+vec[v][p].w+::w[y],ans);
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
