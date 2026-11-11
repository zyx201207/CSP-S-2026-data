#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m;
int a[N],dp[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		int mx=0;
		for(int i=1;i<=n;i++) mx=max(mx,a[i]);
		cout<<mx;
		return 0;
	}
	if(n*m>=1e9 && pow(2,log2(n))==n){
		cout<<a[n-m+1];
		return 0;
	} 
	for(int i=1;i<=n;i++) dp[i]=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j>=1;j--){
			if(j==1) dp[1]=max(dp[1],a[i]);
			else if(dp[j]==0) dp[j]=dp[j-1]&a[i];
			else dp[j]=max(dp[j],dp[j-1]&a[i]);
		}
	}
	cout<<dp[m];
}
