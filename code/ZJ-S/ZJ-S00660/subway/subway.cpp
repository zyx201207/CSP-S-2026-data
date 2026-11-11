#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[500005],k[505],ans;
struct node{
	int a,t;
};
vector<node> g[505];
void dfs(int x,int y,int sum){
	if(sum>ans) return;
	if(x==y){
		ans=min(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		int ind=-1;
		bool f=0;
		for(int j=0;j<g[i].size();j++){
			if(f) dfs(g[i][j].a,y,sum+g[i][ind].t+g[i][j].t);
			if(g[i][j].a==x){
				ind=j;
				f=1;
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int u,v;
			cin>>u>>v;
			g[i].push_back({u,v});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ans=9e18;
		dfs(x,y,0);
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
//n500 m500005 kihe500005 d20 q100005
