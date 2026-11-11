#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int MAXN=5e3+10,MAXM=5e5+10;
int T=1;
int c,n,d;
int a[MAXN];
int dp[MAXN];
int ans;
void solve(){
	cin>>n>>d;
	memset(dp,0,sizeof(dp));
	ans=0;
	for(int i=1;i<=n;++i) cin>>a[i];
	if(n==1 or d>=a[n]-a[1]){
		cout<<0<<endl;
		return;
	}
	for(int i=1;i<n;++i){
		int r=0;
		for(int j=i+1;j<=n;++j){
			if(a[j]>a[i]+d){
				r=j;
				break;
			}
		}
		memset(dp,0,sizeof(dp));
		if(r-i-1==2 and r<=n and a[r-1]+d>=a[r] and a[r-2]+d>=a[r]){
			dp[r]=1;
			ans++;
			for(int j=r+1;j<=n;++j){
				if(a[j]<=a[j-1]+d and a[j]<=a[j-2]+d){
					if(dp[j-1] and dp[j-2]) continue;
					if(dp[j-1] and !dp[j-2]) continue;
					if(!dp[j-1] and dp[j-2]) continue;
				}
				else if(a[j]<=a[j-1]+d){
					if(dp[j-1]) dp[j]=1;
				}
				ans+=dp[j];
			}
		}
	}
	cout<<ans<<endl;
	//if(S_A()) return;
	return;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	//cout<<fixed<<setprecision(2);
	cin>>c>>T;
	while(T--) solve();
}
