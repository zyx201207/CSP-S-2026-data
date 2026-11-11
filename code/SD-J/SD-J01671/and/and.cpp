#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=5e5+5;
int n,m,a[N],dp[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			dp[j]=max(dp[j],dp[j-1]&a[i]);
		}
	}
	cout<<dp[m];	
	return 0;
}	
