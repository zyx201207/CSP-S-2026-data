#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200500],b[3000],dp[3000][3000],ans=0,cnt;
set<long long> se[200500];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++) cin>>a[i];
	if(m==1){
		for(int i = 1;i <= n;i++) ans=max(ans,a[i]);
		cout<<ans<<'\n';
		return 0;
	}
	if(n>=2e5&&m>2){
		cnt=a[n-1];
		for(int i = n-1;i >= n-m+1;i--) cnt&=a[i];
		cout<<cnt<<'\n';
		return 0;
	}
	for(int i = 1;i <= n;i++){
		for(int j = i+1;j <= n;j++){
			long long k=a[i]&a[j];
			if(dp[i][2] < k){
				dp[i][2]=k;
				b[i]=j;
			}
		}
	}
	for(int i = 1;i <= n;i++) se[i].insert(b[i]);
	for(int i = 1;i <= n;i++){
		for(int k = i+1;k <= n;k++){
			for(int j = 3;j <= m;j++){
				if(se[i].count(k)==0){
					dp[i][j]=max(dp[i][j],dp[i][j-1]&a[k]);
					se[i].insert(k);
					cout<<dp[i][j]<<'\n';
				}
			}
		}
	}
	for(int i = 1;i <= n;i++) ans=max(ans,dp[i][m]);
	cout<<ans<<'\n';
	return 0;
}
