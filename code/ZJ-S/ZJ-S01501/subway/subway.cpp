#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,di,q,w[500005];
int s,d[5005][5005];
struct bb{
	int k,h,z;
};
struct dd{
	int zt,u;
};
bool vis[50005];
vector<bb>e[500005];
void dfs(int u,int t,int jl,int y){
	if(u==y)s=min(s,jl);
	if(vis[u]==1&&u!=0)return;
	vis[u]=1;
	for(int i=0;i<e[u].size();i++){
		int v=e[t][i].h,z=e[t][i].z,k=e[t][i].k;
		if(vis[v]==1&&v!=0)continue;
		dfs(v,k,jl+z,y);
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>c>>n>>m>>di>>q;
	for(int i=1;i<=m;i++)
	  cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int i=1,a,b;i<=k;i++){
			cin>>a>>b;//tree
			e[0].push_back({k,a,b});
			e[a].push_back({0,0,0});
		}
	}
    while(q--){
    	int a,b;
    	cin>>a>>b;
    	s=INT_MAX;
    	memset(vis,0,sizeof(vis));
		dfs(a,-1,w[a],b);
    	cout<<s<<'\n';
	}
}
