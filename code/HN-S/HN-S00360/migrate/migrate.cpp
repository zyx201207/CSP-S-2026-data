#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
constexpr int mod=998244353;
inline int MOD(int a){return (a%mod+mod)%mod;}
inline int add(int a,int b){return (a+b)%mod;}
inline int red(int a,int b){return (a-b+mod)%mod;}
inline int mul(int a,int b){return a*b%mod;}
constexpr int N=2e6+5;
int n,k,b[N],g[N],f[N],dp[N];
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++){
		int l=i,r=n;
		while(l<=r){
			int mid=(l+r)/2;
			if(b[mid]-b[i]<=k)l=mid+1;
			else r=mid-1;
		}
		g[i]=r;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int s=0,l=i;
		for(int j=i-1;j<=n;j++)dp[j]=0;
		dp[i]=1;dp[i+1]=-1;
		for(int j=i;j<=n;j++){
			dp[j]+=dp[j-1];
			int r=g[j];
			dp[l+1]+=dp[j];
			dp[r+1]-=dp[j];
			if(l==j)l=g[j];
		}
		for(int j=i+1;j<=n;j++)
			if(dp[j]==2)ans++;
	}
	cout<<ans<<endl;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,T=1;
	cin>>c>>T;
	while(T--)solve();
	return 0;
}
