#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<vector<int>> cost;
struct Edge{
	int v,_id;};
const int MAXM=5e5+5;
vector<Edge> G[MAXM];
ll T[MAXM][202];
vector<bool> visited;
ll ans;
void dfs(int ex_id,int u,int y,ll res){
	if(u==y){
		ans=min(ans,res+T[u][ex_id]);
		return;
	}
	for(auto& c:G[u]){
		int v=c.v,next_id=c._id;
		if(!visited[v]){
			visited[v]=true;
			if(ex_id==next_id){
				dfs(ex_id,v,y,res);
			}
			else{
				dfs(next_id,v,y,res+T[u][ex_id]+T[u][next_id]);
			}
			
		}
		visited[v]=false;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	vector<ll> w(m+1);
	visited.resize(m+1,false);
	for(int i=1;i<=m;i++)for(int j=1;j<=n;j++)T[i][j]=0;
	cost.resize(n+1,vector<int>(n+1));
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		int kk;cin>>kk>>T[kk][i];
		for(int j=2;j<=k;j++){
			int acc;cin>>acc>>T[acc][i];
			G[kk].push_back({acc,i});
			G[acc].push_back({kk,i});
			kk=acc;}}
	while(q--){
		int x,y;cin>>x>>y;
		visited.resize(m+1,false);
		visited[x]=true;
		ans=1e18;
		dfs(0,x,y,0);
		cout<<w[x]+w[y]+ans<<"\n";
	}
	return 0;
}