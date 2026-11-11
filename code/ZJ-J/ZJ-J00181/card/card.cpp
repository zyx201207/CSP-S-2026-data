#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[300010];
int r[500010];
int cnt[500010];
int ans[300010];
vector<int> dp[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--){
		int it=i+1;
		while(it<n && a[i]!=a[it]) it++;
		r[i]=min(it,n);
	}
	dp[n].push_back(a[n]);
	ans[a[n]]++;
	cnt[a[n]]++;
	for(int i=n-1;i>=1;i--){
		if(cnt[a[i]]>0) dp[i]=dp[r[i]];
		else{
			dp[i].push_back(a[i]);
			for(int j=0;j<dp[i+1].size();j++){
				dp[i].push_back(dp[i+1][j]);
			}
		}
		cnt[a[i]]++;
		for(int j=0;j<dp[i].size();j++){
			ans[dp[i][j]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
