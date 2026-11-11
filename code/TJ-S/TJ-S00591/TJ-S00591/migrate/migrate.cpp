#include<bits/stdc++.h>
#define int long long
#define cen cout << "\n"
#define cs cout << " "
using namespace std;
const int N=5009;
int x[N],n,d;
int dp[N][N],cnt[N][N];
void f(){
	int n,d;cin >> n >> d;
	for(int i=1;i<=n;i++)cin >> x[i];
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dp[i][j]=4e18,cnt[i][j]=0;
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)if(x[j]-x[i]<=d)dp[i][j]=dp[j][i]=cnt[i][j]=cnt[j][i]=1;
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
		if(dp[i][k]+dp[k][j]==dp[i][j])cnt[i][j]+=cnt[i][k]*cnt[k][j];
		if(dp[i][k]+dp[k][j]<dp[i][j])dp[i][j]=dp[i][k]+dp[k][j],cnt[i][j]=cnt[i][k]*cnt[k][j];
	}
	int ans=0;
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)ans+=cnt[i][j]==2;
	cout << ans;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int c,t;cin >> c >> t;
	while(t--){
		f();
		cen;
	}
	return 0;
}

