#include<bits/stdc++.h>
using namespace std;
int m,n,d,q,c,w[500005],a[505][505],t[50005][505],dis[500005];
bool vis[500005];
struct node{
	int v,w;
	bool operator < (const node &o) const{
		return w>o.w;
	}
};
vector<node> G[500005];
priority_queue<node> PQ;
int dj(int x,int y){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	PQ.push({x,0});
	dis[x]=0;
	while(!PQ.empty()){
		int u=PQ.top().v;
		PQ.pop();
		if (!vis[u]){
			vis[u]=true;
			for (int i=0;i<G[u].size();i++){
				int v=G[u][i].v,w=G[u][i].w;
				if (!vis[v] && dis[v]>dis[u]+w){
					dis[v]=dis[u]+w;
					PQ.push({v,dis[v]});
				}
			}
		}
	}
	return dis[y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++) scanf("%d",w+i);
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		for (int j=1;j<=x;j++){
			scanf("%d%d",&a[i][j],&t[a[i][j]][i]);
			if (j>2){
				G[a[i][j]+(i-1)*m].push_back({a[i][j-1]+(i-1)*m,0});
				G[a[i][j-1]+(i-1)*m].push_back({a[i][j]+(i-1)*m,0});
			}
		}
	}
	for (int i=1;i<=m;i++){
		for (int j=1;j<=n;j++){
			if (t[i][j]>0){
				for (int k=j+1;k<=n;k++){
					if (t[i][k]>0){
						G[i+(j-1)*m].push_back({i+(k-1)*m,t[i][k]+t[i][j]});
						G[i+(k-1)*m].push_back({j+(k-1)*m,t[i][k]+t[i][j]});
					}
				}
			}
		}
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		int minn=2e9;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				minn=min(minn,dj(x+(i-1)*m,y+(j-1)*m));
			}
		}
		cout<<w[x]+w[y]+minn<<endl; 
	}
	return 0;
}//没调出来遗憾了 
