#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pii pair < int,int >
#define fi first
#define se second
#define vi vector < int >
const int N=1e4+5;
int a[N];
int dp[N][N];
void solve(){
	int n,d;cin>>n>>d;
	if(n>=N){
		cout<<"CSP-S RP++"<<endl;
		exit(0);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i][i]=1;
	}
	for(int len=1;len<=n;len++){
		for(int left=1;left+len-1<=n;left++){
			int right=left+len-1;
			for(int k=left;k<right;k++){
				if(a[k+1]-a[k]>d) continue;
//				cout<<"[debug]:"<<left<<' '<<k<<' '<<right<<endl;
				dp[left][right]+=dp[left][k]*dp[k+1][right];
			}
			if(dp[left][right]>2) dp[left][right]=3;
		}
	}
	int ans=0;
	for(int l=1;l<n;l++){
		for(int r=l+1;r<=n;r++){
			ans+=(dp[l][r]==2);
//			cout<<dp[l][r]<<' ';
		}
//		cout<<endl;
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,t;cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
