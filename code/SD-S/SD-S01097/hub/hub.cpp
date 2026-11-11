#include<iostream>
#include<vector>
using namespace std;
const int N=1e6+10;
int _,T,n,k,ans;
bool p[N],vis[N];int sps[N],spx[N];
vector<int> e[N];
void te(int u,int fa){
	vis[u]=1;
	for(auto v:e[u]){
		if(v==fa||!p[v]) continue;
		te(v,u);
	}
}
bool check(){
	for(int i=1;i<=n;i++) vis[i]=0;
	int ans=0;
	for(int i=1;i<=n;i++) if(!vis[i]&&p[i]) ans++,te(i,0); 
	return (ans==2);
}
void solve(int u,int fa){
	if(p[u]) sps[u]=spx[u]=0;
	for(auto v:e[u]){
		if(v==fa) continue;
		solve(v,u);spx[u]=min(spx[u],spx[v]+1);
	}
	for(auto v:e[u]){
		if(v==fa) continue;
		sps[v]=min(sps[v],spx[u]+1);
	}
}
void dfs(int x,int sum){
	if(sum>k) return ;
	if(x==n){
//		cout<<x<<" "<<sum<<"\n";
//		for(int i=1;i<=n;i++) cout<<p[i]<<" ";
//		cout<<"\n";
		if(sum!=k||!check()) return;
		for(int i=1;i<=n;i++) sps[i]=N,spx[i]=N;
		solve(1,0);
		int mx=0;
		for(int i=1;i<=n;i++) mx=max(mx,min(sps[i],spx[i]));
		ans=(!ans)?mx:min(ans,mx);
		return ;
	}
	p[x+1]=1,dfs(x+1,sum+1),p[x+1]=0,dfs(x+1,sum);
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>_>>T;
	while(T--){
		cin>>n>>k;ans=0;
		for(int i=1;i<=n;i++) e[i].clear(),p[i]=0;
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			e[u].push_back(v),e[v].push_back(u);
		}
		dfs(0,0);
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
