#include<bits/stdc++.h>
using namespace std;
int m,n,mx;
int dp[200010],a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(m==1){
		cout<<mx;
		return 0;
	}
	dp[0]=0x3f3f3f3f;
	dp[1]=a[1];
	for(int i=2;i<=n;i++){
		int mn=min(i,m);
		for(int j=mn;j>=1;j--){
			dp[j]=max(dp[j-1]&a[i],dp[j]);
		}
	}
	cout<<dp[m];
	return 0;
}
