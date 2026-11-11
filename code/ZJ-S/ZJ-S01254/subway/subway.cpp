#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int c,n,m,d,q;
int dis[2000][2000],w[maxn];
bool vis[maxn];
struct node{
	int v,w;
};
vector<node> g[maxn];
int a[maxn],t[maxn];
void dfs(int x,int s){
	for(auto i:g[x]){
		int v=i.v,w=i.w;
		if(vis[v]) continue;
		dis[s][v]=min(dis[s][v],dis[s][x]+w);
		vis[v]=1;
		dfs(v,s);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	memset(dis,0x3f,sizeof dis);
	while(n--){
		int k;
		cin>>k;
		for(int i=1;i<=k;i++){
			cin>>a[i]>>t[i];
		}
		for(int i=1;i<k;i++){
			for(int j=i+1;j<=k;j++){
				g[a[i]].push_back({a[j],t[i]+t[j]});
				g[a[j]].push_back({a[i],t[i]+t[j]});
			}
		}	
	}	
	for(int i=1;i<=m;i++){
		memset(vis,0,sizeof vis);
		dis[i][i]=0;
		vis[i]=1;
		dfs(i,i);
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<min(dis[x][y],dis[y][x])+w[x]+w[y]<<'\n';
	}
	
	return 0;
}
