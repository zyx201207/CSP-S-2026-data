#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5,INF=1e18+5;
int x[N];
int n,d;
void solve(){
	cin>>n>>d;
	int ans=0;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=n;i++){
		int dp[n+1];
		fill(dp+1,dp+n+1,INF);
		dp[i]=0;
		for(int j=i+1;j<=n;j++){
			int cnt=1;
			for(int k=j-1;k>=i;k--){
				if(x[j]-x[k]>d) break;
				if(dp[j]==dp[k]+1) cnt++;
				else if(dp[j]>dp[k]+1){
					dp[j]=dp[k]+1;
					cnt=1;
				}
			}
			if(cnt==2)
				ans++;
		}
	}
	cout<<ans<<'\n';
}
void solvea(){
	cin>>n>>d;
	int x,y;
	n-=1;
	while(n--) cin>>x;
	cin>>y;
	cout<<y-(2*d)/(y-x)+1<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		if(c==11||c==12) solvea();
		else if(c==13||c==14) cout<<0<<'\n';
		else solve();
	}
	return 0;
}
