#include<bits/stdc++.h>
#define pb push_back
using namespace std;
long long c,d,q,n,m,w[500009],K[500009],u,v,ans;
vector<pair<long long,long long> > e[500009];
long long dp[509][509];
void solve(){
	memset(dp,0x3f,sizeof(dp));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++) dp[i][i]=0;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>K[i];
		for(int j=1;j<=K[i];j++){
			long long A,T;
			cin>>A>>T;
			e[A].pb({i,T});
			//a[i].pb(A),
			//t[i].pb(T);
		}
	}
/*
	for(int i=1;i<=m;i++,cout<<'\n'){
		for(int j=0;j<e[i].size();j++){
			cout<<e[i][j].first<<' '<<e[i][j].second<<'\n';
		}
	}
*/
	for(int i=1;i<=m;i++){
		for(int j=0;j<e[i].size();j++){
			int U=e[i][j].first;
			for(int k=j+1;k<e[i].size();k++){
				int V=e[i][k].first;
				dp[U][V]=min(dp[U][V],e[i][j].second+e[i][k].second);
				dp[V][U]=min(dp[V][U],e[i][j].second+e[i][k].second);
				//cout<<U<<' '<<V<<'\n';
			}
		}
	}


	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dp[i][j]=((dp[i][j]<dp[i][k]+dp[k][j])?dp[i][j]:dp[i][k]+dp[k][j]);
			}
		}
	}
/*
	for(int i=1;i<=n;i++,cout<<'\n'){
		for(int j=1;j<=n;j++){
			cout<<dp[i][j]<<' ';
		}
	}
*/
	for(int i=1;i<=q;i++){
		ans=1e18;
		cin>>u>>v;
		for(int j=0;j<e[u].size();j++){
			for(int k=0;k<e[v].size();k++){
				ans=min(dp[e[u][j].first][e[v][k].first]+e[u][j].second+e[v][k].second,ans);
			}
		}
		cout<<ans+w[u]+w[v]<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int T=1;//cin>>T;
	while(T--) solve();
}
/*
5 5 
1 2 4 8 9
*/
/*
diff subway7.out subway7.ans
*/