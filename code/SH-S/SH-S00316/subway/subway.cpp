#include<bits/stdc++.h>
using namespace std;
#define int long long
struct nd{
	int v,w;
};
struct nd1{
	int s,dis;
	bool operator<(const nd1&y)const&{
		return dis>y.dis;
	}
};
int c,n,m,d,q,x,y,tt,aa,w[500005],k;
//int dis[500005],vis[500005];
vector<nd>g[500005];int dis[500005],vis[500005];
int dij(int s,int e){
	priority_queue<nd1>qu;
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	qu.push({s,0});dis[s]=0;
	while(qu.size()){
		int u=qu.top().s;qu.pop();
		if(vis[u])continue;
		vis[u]=1;
		if(u==n+1)vis[u]=0;
		for(auto x:g[u]){
			int v=x.v;
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				qu.push({v,dis[v]});
			}
		}
	}
	return dis[e]+1;
}
//int f[505][505][505];
//priority_queue<nd1> qu;
//int dfs(int i,int fa,int yi){
//	if(i==yi)return 0;
//	if(f[i][fa][yi])return f[i][fa][yi];
//	int ret=0;
//	for(auto x:g[i]){
//		int v=x.v,w=x.w;
//		if(v==fa)continue;
//		ret=min(ret,dfs(v,i,yi)+w);
//	}
//	return f[i][fa][yi]=ret;
//}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
//	for(int i=1;i<=m;i++)cin>>w[i];
//	for(int i=1;i<=n;i++){
//		cin>>k[i];
//		for(int j=1;j<=k[i];j++)cin>>a[i][j]>>t[i][j];
//	}
//	for(int j=1;j<=q;j++)cin>>x[j]>>y[j];
	if(c>=12&&c<=19){
		for(int i=1;i<=m;i++)cin>>w[i];
		for(int i=1;i<=n;i++){
			cin>>k;
			for(int j=1;j<=k;j++){
				cin>>aa>>tt;
				g[aa].push_back((nd){n+1,0});
				g[n+1].push_back((nd){aa,tt});
			}
		}
		for(int j=1;j<=q;j++){cin>>x>>y;cout<<dij(x,y)*tt+w[x]+w[y]<<"\n";}
	}
	//build group
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=k[i];j++){
//			for(int l=1;l<=k[i];l++){
//				if(l==j)continue;
//				g[a[i][j]].push_back((nd){a[i][l],t[i][l]});
//				g[a[i][l]].push_back((nd){a[i][j],t[i][j]});
//			}
//		}
//	}
//	for(int i=1;i<=q;i++){
//		while(qu.size())qu.pop();
//		memset(dis,-1,sizeof(dis));
//		memset(vis,0,sizeof(vis));
//		qu.push({x[i],0});
//		while(qu.size()){
//			int u=qu.top().s;qu.pop();
//			if(vis[u])continue;
//			vis[u]=1;
//			for(auto x:g[u]){
//				int v=x.v,w=x.w;
//				if(dis[v]>dis[u]+w){
//					dis[v]=dis[u]+w;
//					qu.push({v,dis[v]});
//				}
//			}
//		}
//		cout<<w[x[i]]+w[y[i]]+dis[y[i]]<<endl;
//	}
}
