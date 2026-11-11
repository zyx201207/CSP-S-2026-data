#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int c,n,m,d,q,w[N],a[1005][1005],t[1005][1005],dp[1005][1005],k[1005],f[1005];
vector<int> lx[1005];
void dfs(int x,int i,int j){
	for(auto v:lx[x]){
		if(f[v]) continue;
		if(x==v){
			dp[x][v]=w[x]+t[x][v];
			continue;
		}
		dp[i][v]=min(dp[i][v],dp[i][x]-w[x]+t[x][x]+t[x][v]+w[v]);
		if(v==j) return;
		f[x]=1;
		dfs(v,i,j);
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][a[i][j]];
			if(i==a[i][j]) continue;
			lx[i].push_back(a[i][j]);
			lx[a[i][j]].push_back(i);
		}
	}
	while(q--){
		memset(dp,1e6,sizeof(dp));
		memset(f,0,sizeof(f));
		int x,y;
		cin>>x>>y;
		f[x]=1;
		for(auto v:lx[x]){
			if(x==v){
				dp[x][v]=w[x]+t[x][v];
				continue;
			}
			dp[x][v]=min(dp[x][v],w[x]+t[x][x]+t[x][v]+w[v]);
		}
		for(auto v:lx[x]){
			dfs(v,x,y);
		}
		cout<<dp[x][y]<<'\n';
	}
	return 0; 
}
//Oct31==Dec25?