#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back 
int c,n,m,d,q;
ll w[500005];
int k[505];
ll dp[505][505];
vector<ll> t[500005];
vector<int> a[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			int a1; ll t1;scanf("%d%lld",&a1,&t1);
			a[a1].pb(i);
			t[a1].pb(t1);
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dp[i][j]=1e15;
	for(int i=1;i<=n;i++)dp[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<a[i].size();j++){
			for(int k=j+1;k<a[i].size();k++){
				dp[a[i][j]][a[i][k]]=min(dp[a[i][j]][a[i][k]],t[i][j]+t[i][k]);
				dp[a[i][k]][a[i][j]]=dp[a[i][j]][a[i][k]];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dp[j][k]=min(dp[j][k],dp[j][i]+dp[i][k]);
			}
		}
	} 
	while(q--){
		ll ans=1e18;
		int x,y;scanf("%d%d",&x,&y);
		for(int i=0;i<a[x].size();i++){
			for(int j=0;j<a[y].size();j++){
				ans=min(ans,w[x]+w[y]+t[x][i]+t[y][j]+dp[a[x][i]][a[y][j]]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
