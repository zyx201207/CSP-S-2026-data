#include<bits/extc++.h>
using namespace std;
constexpr int MAXN=2e3+1;
unsigned int n,m,a[MAXN];
unsigned long long dp[MAXN][MAXN],ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		dp[i][1]=a[i];
		for(int j=1;j<i;j++){
			for(int k=1;k<=j;k++){
				dp[i][k+1]=max(dp[i][k+1],dp[j][k]&a[i]);
			}
		}
		ans=max(dp[i][m],ans);
	}
	cout<<ans;
	return 0;
}
