#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e3+5;
int n,a[N],t,c,d,dp[N][N];
struct Node{
	int l,r;
} p[N];
void solve(){
	int ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]-a[i-1]<=d){
			dp[i-1][i]=1;
		}
	}
	for(int i=1;i<=n-2;i++){
		for(int j=1;j<=2;j++){
			if(a[i+j]-a[i]<=d){
				dp[i][i+2]+=dp[i+j][i+2];
			}
		}
	}
	for(int k=4;k<=n;k++){
		for(int i=1;i<=n-k+1;i++){
			int l=i,r=i+k-1;
			for(int j=1;j<=3;j++){
				if(a[l+j]-a[l]<=d){
					dp[l][r]+=dp[l+j][r];
				}
			}
			if(dp[l][r]==2 && r-l>=d+1){
				ans++;
			}
		}
	}
	cout<<ans<<"\n";
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=0;
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}