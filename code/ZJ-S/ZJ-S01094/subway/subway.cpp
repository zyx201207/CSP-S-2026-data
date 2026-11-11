#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5,M=5e2+5;
int c,n,m,d,q;
int w[N],k[N],h[N],res;
map<int,ll> a[N],t[N],mp;
////void dfs(int x,int y){
////	for(auto o:g[h[x]]){
////		for(int j=1;j<=k[o];j++){
////			if()
////		}
////	}
////}
map<int,ll> dis[M];
int mpp[N];
struct node{
	ll v,w;
};
vector<node> g[N];
struct f{
	ll dis,v;
	bool operator>(const f& a)const{return dis>a.dis;}
};
int vis[N];
priority_queue<f,vector<f>,greater<f>> p;
ll sum=0;
void dij(int s){
	for(int i=1;i<=m;i++) dis[s][i]=1e18,vis[i]=0;
	p.push({0,s});dis[s][s]=0;
	while(!p.empty()){
		int u=p.top().v;p.pop();
		if(vis[u]) continue;
		vis[u]=1;
//		if(q==1) cout<<u<<' '<<dis[s][u]<<'\n';
		for(auto o:g[h[u]]){
			int v=o.v,w=o.w;
//			cout<<v<<' ';
			for(int j=1;j<=k[v];j++){
//				cout<<a[j][v]<<' '<<dis[s][a[j][v]]<<'\n';
				if(dis[s][a[j][v]]>dis[s][u]+w+t[j][v]){
//					cout<<a[j][v]<<'\n';
					dis[s][a[j][v]]=dis[s][u]+w+t[j][v];
					p.push({dis[s][a[j][v]],a[j][v]});
				}
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[j][i]>>t[j][i];
			if(!mp[a[j][i]]){
				mp[a[j][i]]=1;
				h[a[j][i]]=++res;
			}
//			g[a[j][i]].push_back({h[a[j][i]],t[j][i]});
			g[h[a[j][i]]].push_back({i,t[j][i]});
//			if(a[j][i]==2) cout<<h[a[j][i]]<<'\n';
		}
	}
//	cout<<g[h[2]][1].v<<' '<<g[h[2]][0].v<<'\n';
	if(q>m) for(int i=1;i<=m;i++) dij(i);
	while(q--){
		int x,y;cin>>x>>y;
		sum=0;
		sum+=w[x]+w[y];
//		dfs(x,y);
//		cout<<dis[1][3]<<'\n';
		if(q>m) cout<<sum+dis[x][y]<<'\n';
		else{
			if(mpp[x]) cout<<dis[x][y]+sum<<'\n';
			else if(mpp[y]) cout<<dis[y][x]+sum<<'\n';
			else dij(x),mpp[x]=1,cout<<dis[x][y]+sum<<'\n';
		}
	}
	return 0;
}