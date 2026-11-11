#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,m,a[N],dp[N],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		dp[0]=0x7fffffff;
		for(int j=m;j>=1;j--) dp[j]=max((dp[j-1]&a[i]),dp[j]);
	}
	cout<<dp[m];
	return 0;
}
