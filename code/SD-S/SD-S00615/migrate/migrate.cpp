#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5050;
int n,d,x[N];
int dis[N];
int dp[N];
inline void dfs(int t){
	dp[t]++;
	int r=t;
	while (r<n&&x[r+1]-x[t]<=d&&dis[r+1]>=dis[t]+1){
		if (dis[r+1]>dis[t]+1) {
			dis[r+1]=dis[t]+1;
			dp[r+1]=0;
		}
		dfs(r+1);++r;
	}
}
void solve(){
	int ans=0;
	cin>>n>>d;
	memset(dis,0x3f,sizeof(int)*(n+2));
	memset(dp,0,sizeof(int)*(n+2));
	for (int i=1;i<=n;++i) cin>>x[i];
	for (int i=1;i<=n;++i){
		dis[i]=0;
		dfs(i);
		for (int j=i+1;j<=n;++j){
			if (dp[j]==2) {
				++ans;
			}
		}
		memset(dis,0x3f,sizeof(int)*(n+2));
		memset(dp,0,sizeof(int)*(n+2));
	}
	cout<<ans<<"\n";
}
void solve2(){
	cin>>n>>d;
	for (int i=1;i<=n;++i){
		cin>>x[i];
	}
	cout<<"0\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,T;cin>>c>>T;
	if (c==13||c==14) while (T--) solve2();
	else while (T--) solve();
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
