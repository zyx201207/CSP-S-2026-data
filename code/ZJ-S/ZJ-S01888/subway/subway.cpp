#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
const int N=511;
const int M=5e5+5;
vector<pair<int,int>> g[N];
int w[M],k[N];
bool vis[N];
int tans=1e18;
void dfs1(int u,int y,int ans){
	vis[u]=1;
	if(u==y){
		tans=min(ans,tans);
	}
	for(auto ooo:g[u]){
		int v=ooo.first,di=ooo.second;
		if(!vis[v]) dfs1(v,y,ans+di);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int v,lt;
		for(int j=1;j<=k[i];j++){
			int u,t;
			if(j==1){
				cin>>u>>t;	
				v=u,lt=t;
			} 
			else{
				cin>>u>>t;
				g[u].push_back({v,lt+t});
				g[v].push_back({u,lt+t});
			}
		}
	}
	while(q--){
		for(int i=1;i<=n;i++){
			vis[i]=0;
		}
		int x,y;
		cin>>x>>y;
		int ans=w[x]+w[y];
		tans=1e18;
		dfs1(x,y,ans);
		cout<<tans<<"\n";
	}	
	
	
	
	
	return 0;
}