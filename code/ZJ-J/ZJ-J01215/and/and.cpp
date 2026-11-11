#include <bits/stdc++.h>

using namespace std;
const int N=2e5+5;
int n,m;
long long a[N];
long long dp[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long mx1=-1;
	long long jych=(1<<30)-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx1=max(mx1,a[i]);
		jych&=a[i];
	}
	if(m==1){
		cout<<mx1;
		return 0;
	}
	if(m==n){
		cout<<jych;
		return 0;
	}
	dp[0]=(1<<30)-1;
	for(int i=1;i<=n;i++){
		for(int j=min(i,m);j>=1;j--){
			dp[j]=max(dp[j],dp[j-1]&a[i]);
		}
	}
	cout<<dp[m];
	return 0;
}
