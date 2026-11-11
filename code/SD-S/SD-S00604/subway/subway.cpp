#include<bits/stdc++.h>
using namespace std;
const int M=5007;
int w[M],vis[505][M];
int c,n,m,d,q;
struct node{
	int v,w;
};
vector<node> g[505][M];
int x,y,ans=1e9+7;
void dfs(int s,int l,int xl){
	if (s==y){
		ans=min(ans,l+w[y]);
		return ;
	}
	for(auto e:g[xl][s]){
		if (vis[xl][e.v]==1) continue;
		vis[xl][e.v]=1;
		dfs(e.v,l+e.w,xl);
		vis[xl][e.v]=0;
	}
	for (int i=1;i<=n;i++){
		if (!g[i][s].empty()&&!vis[i][s]){
			for (auto e:g[i][s]){
				if (e.v==s){
					vis[i][s]=1;
					dfs(s,l+e.w,i);
					vis[i][s]=0;
					break;
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}
	int k,a[M],t[M];
	for (int i=1;i<=n;i++){
		cin>>k;
		for (int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
		for (int j=1;j<=k;j++){
			for (int p=1;p<=k;p++){
				g[i][a[j]].push_back({a[p],t[p]});
			}
		}
	}
	while(q--){
		cin>>x>>y;
		ans=1e9+7;
		for (int i=1;i<=n;i++){
			if (!g[i][x].empty()){
				for(auto e:g[i][x]){
					if (e.v==x){
						vis[i][x]=1;
						dfs(x,w[x]+e.w,i);
						vis[i][x]=0;
						break;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
}
