#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int w[N];
int c,n,m,d,q;
vector<int> g[N];
void dfs(int x,int fa,int y){
	for(int i=0;i<g[x].size();j++){
		int u=g[i][x];
		if(u==y){
			f[u]=1;
			return;
		}
		if(u==fa) continue;
		dfs(u,x,y);
		f[x]=min(f[x],f[u]+w[x]+t[u][x]);
	}
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			int x;
			cin>>x;
			g[i].push_back(x);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		solve(x,0,y);
	}
} 
