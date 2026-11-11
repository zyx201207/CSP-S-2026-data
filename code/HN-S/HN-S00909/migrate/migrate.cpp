#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e6+10;
int n,d,c;
int a[maxn];
int dp[maxn];
int cnt[maxn];
void solve(){
	cin>>n>>d;
	cin>>a[1];
	int z=0;
	if(a[1]<=0){
		z=-a[1];
		a[1]=0;
	}
	for(int i=2;i<=n;i++){
		cin>>a[i];
		a[i]+=z;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			dp[j]=1e18;
			cnt[j]=0;
		}
		dp[i]=0;
		cnt[i]=1;
		for(int j=i;j<=n;j++){
			for(int k=i;k<=j;k++){
				if(a[j]-a[k]>d)continue;
				if(dp[j]>dp[k]+1){
					dp[j]=dp[k]+1;
					cnt[j]=cnt[k];
				}else if(dp[j]==dp[k]+1){
					cnt[j]+=cnt[k];
				}
			}
			if(cnt[j]==2){
				ans++;
			}
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}

