#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll w[500005],dp[505][505],a[500005][25],t[500005][25],ct[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	ll c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=1ll<<60;
		}
		dp[i][i]=0;
	}
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(int j=1;j<=k;j++){
			ll tmp1,tmp2;
			cin>>tmp1>>tmp2;
			++ct[tmp1],a[tmp1][ct[tmp1]]=i,t[tmp1][ct[tmp1]]=tmp2; 
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<ct[i];j++){
			for(int k=j+1;k<=ct[i];k++){
				dp[a[i][j]][a[i][k]]=dp[a[i][k]][a[i][j]]=min(dp[a[i][j]][a[i][k]],t[i][j]+t[i][k]);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	while(q--){
		ll x,y;
		cin>>x>>y;
		ll ans=1ll<<60;
		for(int i=1;i<=ct[x];i++){
			for(int j=1;j<=ct[y];j++){
				ans=min(ans,dp[a[x][i]][a[y][j]]+t[x][i]+t[y][j]);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
}
