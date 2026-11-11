#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m;
long long dp[2*N],a[2*N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i]=1;
	}
	
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			dp[j]=max(dp[j],dp[j-1]&a[i]);
		}
	}
	cout<<dp[m];
	return 0;
}
/*4 2
3 15 12 12*/
