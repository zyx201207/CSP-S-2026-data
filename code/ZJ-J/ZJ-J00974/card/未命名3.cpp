#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N=3e3+5;
const int mod=1e9+7;
const double eps=1e-6;
int n,a[N],m,dp[N][N],ans;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		dp[i][1]=a[i];
		for(int j=2;j<=min(m,i);j++){
			for(int k=1;k<i;k++)
				dp[i][j]=max(dp[i][j],(int)dp[k][j-1]&a[i]);
		}
		ans=max(ans,dp[i][m]);
	}
	cout<<ans<<'\n';
}
signed main(){
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("and3.in","r",stdin);
//	freopen("and.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--)solve();
	return 0;
}

