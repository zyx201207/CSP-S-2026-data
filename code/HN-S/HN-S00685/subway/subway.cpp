#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=6e5+5,M=105;
struct node{
	int x,num;
	bool operator<(const node ot) const{
		return num>ot.num;
	}
};
int c,n,m,d,q,h,w[N],a[M][N],t[M][N];
int dis[N],vis[N];
vector<node> g[N];
//1: µØÌú¿Ú, 2: Õ¾Ìü, 3...: Õ¾Ì¨ 
void dijkstra(int s){
	priority_queue<node> q;
	memset(dis,0x3f,sizeof dis);
//	memset(vis,0,sizeof vis);
	dis[s]=0;vis[s]=1;q.push({s,0});
	while(!q.empty()){
		node now=q.top();q.pop();
//		if(vis[now.x]!=0) continue;
//		vis[now.x]=1;
		for(node e: g[now.x]){
			if(dis[e.x]>dis[now.x]+e.num){
				dis[e.x]=dis[now.x]+e.num;
				q.push({e.x,dis[e.x]});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;h=n+2;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		g[(i-1)*h+1].push_back({(i-1)*h+2,w[i]});
		g[(i-1)*h+2].push_back({(i-1)*h+1,w[i]});
	}
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			g[(a[i][j]-1)*h+2+i].push_back({(a[i][j]-1)*h+2,t[i][j]});
			g[(a[i][j]-1)*h+2].push_back({(a[i][j]-1)*h+2+i,t[i][j]});
//			if(j-1<1) continue;
			g[(a[i][j-1]-1)*h+2+i].push_back({(a[i][j]-1)*h+2+i,0});
			g[(a[i][j]-1)*h+2+i].push_back({(a[i][j-1]-1)*h+2+i,0});
		}
	}
	dijkstra(1);
//	for(node e: g[1]) cout<<e.x<<" "<<dis[e.x]<<" ";
//	cout<<"\n";
	for(int i=1,x,y;i<=q;i++){
		cin>>x>>y;
		dijkstra((x-1)*h+1);
		cout<<dis[(y-1)*h+1]<<"\n";
	}
	return 0;
}
