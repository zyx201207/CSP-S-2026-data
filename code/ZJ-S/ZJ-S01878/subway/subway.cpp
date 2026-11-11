#include<bits/stdc++.h>
#define for1(i,x,y,k) for(int i=x;i<=y;i+=k)
#define for2(i,x,y,k) for(int i=x;i>=y;i-=k)
#define int long long
#define pb push_back
#define pf push_front
#define md (t[p].l+t[p].r>>1)
#define mi (lc+rc>>1)
#define mid (l+r>>1)
#define maotai mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define pii pair<int,int>
using namespace std;
const int N=1e3+5;
int c,n,m,d,q,k,x,y;
int w[N],a[N],t[N];
int dp[N][N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(dp,0x3f,sizeof(dp));
	for1(i,1,m,1){
		cin>>w[i];
		dp[i][i]=0;
	}
	for1(i,1,n,1){
		cin>>k;
		for1(j,1,k,1)
			cin>>a[j]>>t[j];
		for1(j,1,k,1){
			for1(kk,1,k,1){
				dp[a[j]][a[kk]]=min(dp[a[j]][a[kk]],t[j]+t[kk]);
				dp[a[kk]][a[j]]=min(dp[a[kk]][a[j]],t[j]+t[kk]);
			}
		}
	}
	for1(i,1,m,1){
		for1(j,1,m,1){
			for1(kk,1,m,1)
				dp[i][j]=min(dp[i][j],dp[i][kk]+dp[kk][j]);
		}
	}
	while(q--){
		cin>>x>>y;
		cout<<min(dp[x][y],dp[y][x])+w[x]+w[y]<<'\n';
	}
	return 0;
}
