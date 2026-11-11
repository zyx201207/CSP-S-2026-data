#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],dp[200005],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		/*for(int j=m;j>=1;j--){
			dp[j]=a[i];
			dp[j]=max(dp[j],(dp[j-1]&a[i]));
		}*/
	}
	sort(a+1,a+n+1);
	ans=a[n];
	for(int i=n;i>=n-m+1;i--){
		ans&=a[i];
	}
	//cout<<dp[m]<<endl;
	cout<<ans<<endl;
	return 0;
}
