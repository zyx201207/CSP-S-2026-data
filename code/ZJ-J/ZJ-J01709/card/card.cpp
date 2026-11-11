#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	vector<vector<int> > dp(n+1,vector<int>(m+1,0));
	vector<int> cnt(m+1,0);
	dp[n][a[n]]=1;cnt[a[n]]=n;
	for(int i=n-1;i>=1;i--) {
		if(cnt[a[i]]!=0) {
			dp[i]=dp[cnt[a[i]]];
		}
		else {
			dp[i]=dp[i+1];
			dp[i][a[i]]++;
		}
		cnt[a[i]]=i;
	}
	for(int i=1;i<=m;i++) {
		int ans=0;
		for(int j=1;j<=n;j++) {
			ans+=dp[j][i];
		}
		printf("%d ",ans);
	}
	return 0;
}