#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int nmax=1e6+5;
const int inf=1e18;
int n,m,a[nmax];
int dp[nmax],cent;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=4;i<=n;i++){
		int pos=lower_bound(a+1,a+n+1,a[i]-m)-a;
		int s=(pos+i-1)*(i-pos+1)/2-(dp[i-1]-dp[i-pos-1]);
		dp[i]=dp[i-1]+s;
	}
	cout<<dp[n]<<endl;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//	freopen("migrate2.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	
	int T=1;cin>>cent>>T;
	while(T--)
	solve();
	
	return 0;
} 
