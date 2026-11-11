#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
int n;
long long a[10005],dp[10005][10005];
unsigned long long ans,m;
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(i==j)continue;
			dp[i][j]=max(0ll,max(dp[i][j-1]+(i-j)*(a[j-1]-a[j]),dp[i-1][j]-(a[j]-a[i-1])));
			if(dp[i][j]<=m)ans=max(ans,(unsigned long long)(j-i+1));
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<dp[i][j]<<' ';
		}
		cout<<'\n';
	}
	cout<<ans;
	return 0;
}