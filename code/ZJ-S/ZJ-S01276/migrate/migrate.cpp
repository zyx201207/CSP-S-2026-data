#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,T,n,d,a[N];
struct node{
	int dis,cnt;
}dp[N];
void dfs(int u,int dis){
	if(dp[u].dis==dis)dp[u].cnt++;
	else if(dp[u].dis>dis){
		dp[u].dis=dis;
		dp[u].cnt=1;
	}
	for(int i=u+1;i<=n;i++){
		if(a[i]-a[u]<=d)dfs(i,dis+1);
	}
}
void solve(){
	scanf("%lld%lld",&n,&d);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	int ans=0;
	for(int i=1;i<=n;i++){
		memset(dp,0x3f,sizeof(dp));
		dfs(i,0);
		for(int j=1;j<=n;j++)
			if(dp[j].cnt==2)ans++;
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--)solve();
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
