#include<bits/stdc++.h>
using namespace std;
#define int long long
int w[500005];
struct node{
	int v,g;
};
int a[505][500005];
int k[505];
int t[505][500005];
map<int,int> vis;
vector<node> G[100005];
int c,n,m,d,q,x,y;
int dfs(int ans,node u,node fa){
	vis[u.v]=1;
	if(u.v==y) return ans;
	for(node f:G[u.v]){
		if(f.v==fa.v&&f.g==fa.g) continue;
		if(vis[f.v]) continue;
		ans=max(ans,dfs(ans+t[a[u.g][u.v]][u.g]+t[a[u.g][u.v]][f.g],f,u));
	}
	return 0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j];
			cin>>t[i][j];
		}
		for(int j=2;j<=k[i];j++){
			G[j-1].push_back({j,i});
			G[j].push_back({j-1,i});
		}
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		cin>>x>>y;
		ans+=w[x]+w[y];
		ans+=dfs(ans,{x,0},{0,0});
		cout<<ans;
	}
	return 0;
}