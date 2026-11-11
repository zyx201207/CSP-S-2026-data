#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
typedef pair<int,int> pii;
const int N=1e6+10;
const int M=1e3+10;
const int mod=1e9+7;
const int inf=1e17;
inline int mm(int X,int MOD=mod){
	return (X%MOD+MOD)%MOD;
}
int n,m;
int mx[N];
//都可以转换为跳两步 
int a[N];
int dp[N];
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx[i]=0;
		dp[i]=0;
	}
	int l=1,r=1;
	while(l<=n){
		while(a[r+1]-a[l]<=m&&r<n){
			r++;
		}
		mx[l]=r;
		l++;
	}
	int ans=0;
	dp[n]=1;
	for(int i=n-1;i>=1;i--){
		dp[i]=dp[mx[i]]+mx[i]-mx[i-1];
	}
//	for(int i=1;i<=n;i++){
//		cout<<dp[i]<<endl;
//	}
	for(int i=1;i<=n;i++){
		int v=mx[i];
		int u=v-1;
		int r=mx[u];
		int l=mx[u-1];
//		cout<<i<<' '<<l<<' '<<r<<endl;
		ans+=(r-l);
	}
	cout<<ans<<endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int Case,T;
	cin>>Case;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
