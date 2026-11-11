#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int c,n,m,d,p,w[N],x,y,ans=1e18,vh[N];
struct nod{
	int y,s;
};
vector<nod>g[N];
void dfs(int id,int s){
	if(id==y){
		ans=min(ans,s);
		return;
	}
	for(int i=0;i<g[id].size();i++){
		if(vh[g[id][i].y]==0){
			vh[g[id][i].y]=1;
			dfs(g[id][i].y,s+g[id][i].s);
			vh[g[id][i].y]=0;
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			g[i+m].push_back(nod{a,t});
			g[a].push_back(nod{i+m,t});
		}
	}
	for(int i=1;i<=p;i++){
		cin>>x>>y;
		ans=1e18;
		dfs(x,w[x]+w[y]);
		cout<<ans<<endl;
	}
	return 0;
}

