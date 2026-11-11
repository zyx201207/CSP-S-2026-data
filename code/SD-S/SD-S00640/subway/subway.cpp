#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q,T;
ll w[500005],dp[505][505],g[505][505];
struct edge{
	ll to,w;
};
vector<edge> a[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(int j=1;j<=k;j++){
			ll x,t;
			cin>>x>>t;
			a[x].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		g[i][i]=0;
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			g[i][j]=9000000009;
		}
	}
	for(int i=1;i<=m;i++){
		for(auto u:a[i]){
			for(auto v:a[i]){
				if(u.to==v.to) continue;
				g[u.to][v.to]=min(g[u.to][v.to],u.w+v.w);
			}
			
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=g[i][j];
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		ll x,y;
		cin>>x>>y;
		ll ans=w[x]+w[y];
		ans=ans+a[x][0].w+a[y][0].w+dp[a[x][0].to][a[y][0].to];
		for(auto u:a[x]){
			for(auto v:a[y]){
				ans=min(ans,w[x]+w[y]+dp[u.to][v.to]+u.w+v.w);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

