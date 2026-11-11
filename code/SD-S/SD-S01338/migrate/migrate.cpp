#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
const int N=2e6+10;
const int INF=0x7f7f7f7f;
/*====================*/
int a[N],cnt[N],ans=0;
/*====================*/
void Solve(void){
	int n,d;cin>>n>>d;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(abs(a[i]-a[j])<=d){
				if(i==1||i==n) cout<<1;
				else cout<<2;
				return ;
			}
		}
	}
	vector<int>dp(n,0);dp[1]=dp[2]=dp[3]=0;
	for(int i=4;i<=n;++i) dp[i]=i/d+1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n-d;++j){
			for(int k=1;k<=d;++k){
				if(dp[i-k]+k==dp[i]) cnt[i]++;
			}
		}
	}
	for(int i=1;i<=n;++i) if(cnt[i]==2) ans++;
	cout<<ans<<endl;
}
/*====================*/
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;cin>>c>>T;
	while(T--) Solve();
	return 0;
}
