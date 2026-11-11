#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
int c,n,m,d,q,k[15],t[15][15],a[15][15],w[15],s,we,mi=1e15;
vector<pii> g[15];
bool jk[15][15];
bool vis[15];
void dfs(int x,int sum,int nw){
	if(vis[x]) return;
	if(x==we){
		mi=min(mi,sum);
		return;
	}
	vis[x]=1;
	for(int i=1;i<=n;++i){
		if(!jk[i][x]) continue;
		for(int j=1;j<=k[i];++j){
			dfs(a[i][j],sum+(i!=nw)*(t[x][i]+t[x][a[i][j]]),i);
		}
	}
	vis[x]=0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=1;i<=n;++i){
		cin>>k[i];
		for(int j=1;j<=k[i];++j){
			cin>>a[i][j]>>t[a[i][j]][i];
			jk[i][a[i][j]]=1;
		} 
	}
	while(q--){
		mi=1e15;
		cin>>s>>we;
		for(int i=1;i<=n;++i){
			if(!jk[i][s]) continue;
			dfs(s,w[s]+t[s][i],i);
		}
		cout<<mi<<endl;
	}
	return 0;
}