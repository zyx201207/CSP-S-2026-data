#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll C,T;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>T;
	while(T--){
		ll n,d;
		cin>>n>>d;
		ll ans=0;
		if(n>5000){
			cout<<0<<"\n";
			continue;
		}
		ll x[n+1]={0};
		ll dp[n+1][n+1];
		ll a[n+1][n+1]={0};
		memset(a,0,sizeof a);
		for(int i=1; i<=n; i++){
			cin>>x[i];
			dp[i][i]=0;
		}
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				dp[i][j]=abs(x[i]-x[j]);
			}
		}
		for(int l=2; l<=n; l++){
			for(int i=1; i<=n-l+1; i++){
				ll j=i+l-1;
				if(l==2) dp[i][j]=(abs(x[i]-x[j])<=d?abs(x[i]-x[j]):dp[0][0]),a[i][j]+=(dp[i][j]!=dp[0][0]); 
				else for(int k=i+1; k<j; k++){
					ll la=dp[i][j];
					dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
					if(dp[i][j]==la&&dp[i][j]!=dp[0][0]){
						a[i][j]++;
					}
					else if(dp[i][j]==dp[0][0]) a[i][j]=0;
					else a[i][j]=1;
				}
			}
		}
		ans=0;
		for(int i=1; i<n; i++){
			for(int j=i+1; j<=n; j++){
				if(a[i][j]==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//40-
