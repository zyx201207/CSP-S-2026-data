#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,w;
};
vector<node>g[500505];
long long c,n,m,d,q,a[505],dis[500505],vis[500505];
int solve(int s,int end){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0x3f,sizeof(vis));
	dis[s]=0;
	queue<node>q;
	q.push({s,0});
	while(!q.empty()){
		//cout<<"!\n";
		node t=q.front();
		q.pop();
		//vis[t.u]=1;
		for(int i=0;i<g[t.u].size();i++){
			node v=g[t.u][i];
			//if(vis[v.u])continue;
			if(dis[v.u]>dis[t.u]-v.w){
				dis[v.u]=dis[t.u]-v.w;
				q.push(v);
			}
		}
	}
	return dis[end];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		int l;
		cin>>l;
		for(int j=1;j<=l;j++){
			int aa,tt;
			cin>>aa>>tt;
			g[500000+aa].push_back({i,-tt});
			g[i].push_back({500000+aa,-tt});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<solve(x+500000,y+500000)+a[x]+a[y]<<"\n";
	}
	return 0;
}
