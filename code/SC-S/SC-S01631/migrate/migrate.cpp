#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,_;
void solve(){
	int n,d,cnt=0;
	cin>>n>>d;
	vector<int> a(n+10,0);
	vector<pair<int,int> > dp(n+10,{0,1e9});
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		dp[i]={1,0};
		for(int l=i+1;l<=n;l++){
			dp[l].second=1e9;
			for(int j=l-1;j>=i;j--){
				if(a[l]-a[j]>d)
					break;
				if(dp[l].second==dp[j].second+1)
					dp[l].first+=dp[j].first;
				else if(dp[l].second>dp[j].second)
					dp[l].second=dp[j].second+1,dp[l].first=dp[j].first;
			}
			if(dp[l].first==2)
				cnt++;
		}
	}
	cout<<cnt<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>_;
	while(_--){
		solve();
	}
}