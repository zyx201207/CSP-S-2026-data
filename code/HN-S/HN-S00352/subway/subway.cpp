#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
const int N=510,M=5e5+10;
struct node{
	int v,t;
};
int me[M];
vector<node> g[M];
int w[M];
int x,y;
bool vis[M];
int res=0;
void dfs(int u,int ans){
	ans+=me[u];
	if(u==y){
		res=ans;
		return ;
	}
	for(int i=0;i<g[u].size();i++){
		node next=g[u][i];
		if(vis[next.v]) continue;
		vis[next.v]=true;
		dfs(next.v,ans+next.t);
		
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>n>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
//		g[i].resize(k);
		for(int j=1;j<=k;j++){
			node u;
			cin>>u.v>>u.t;
			if(u.v==i){
				me[i]=u.t;
			}
			else{
				g[i].push_back(u);
			}
		}
	}
	while(q--){
		memset(vis,0,sizeof(vis));
		cin>>x>>y;
		dfs(x,0);
		cout<<res+w[x]+w[y]<<endl;
	}
	
}
