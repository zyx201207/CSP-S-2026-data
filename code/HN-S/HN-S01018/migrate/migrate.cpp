#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int c;
int n,d;
int a[N];
int dp[N];
int mi[N];
int ans;
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	ans=0;
	for(int i=1;i<=n;i++){
		dp[i]=1;
		for(int j=i+1;j<=n;j++){
			mi[j]=1e18;
			for(int k=j-1;k>=i;k--){
				if(a[k]+d>=a[j]){
					mi[j]=min(mi[j],mi[k]+1);
				}
				else break;
			}
			if(mi[j]==1e18) break;
			for(int k=j-1;k>=i;k--){
				if(a[k]+d<a[j]) break;
				if(mi[k]==mi[j]-1){
					dp[j]+=dp[k]; 
				}
			}
			if(dp[j]==2){
				ans++;
			}
		}
		for(int j=1;j<=n;j++) mi[i]=0,dp[i]=0;
	} 
	cout<<ans<<"\n";
	return ;
} 
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0),cin.tie(0);
	int oT_To=1;
	cin>>c>>oT_To;
	while(oT_To--) solve();
	return 0;
}


/*

*/ 
