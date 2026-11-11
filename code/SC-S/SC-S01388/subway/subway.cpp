#include<bits/stdc++.h>
#define pii pair<int,int>
#define frein(x) freopen(x".in","r",stdin)
#define freout(x) freopen(x".out","w",stdout)
#define cinios cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
using ll=long long;
const int N=2e4+10;
int w[N];
int a[555][N];
int t[555][N];
vector<pii> g[N];
int dfs(int st,int ed){
	if(st==ed){
		return w[ed];
	}
	for(auto x:g[st]){
		auto v=x.first,ww=x.second;
		if(v==st) continue;
		return ww+w[v]+dfs(v,ed);
	}
}
int main(){
	frein("subway");
	freout("subway");
	cinios;
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			g[i].push_back({a[i][j],t[i][j]});
			g[a[i][j]].push_back({i,t[i][j]});
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;cin>>x>>y;
		cout<<dfs(x,y)<<"\n";
	}
	return 0;
}