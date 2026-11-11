#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5005;
int c,T,n,cnt[N],ans,dis[N],dp[N];
ll x[N],d;
void solve(int u){
	memset(cnt,0,sizeof(int)*(n+5));
	dis[u]=0,dp[u]=1;
	deque<int>q;
	for(int v=u+1;v<=n;v++){
		while(!q.empty()&&dis[q.back()]>dis[v-1]) cnt[dis[q.back()]]-=dp[q.back()],q.pop_back();
		q.push_back(v-1),cnt[dis[v-1]]+=dp[v-1];
		while(!q.empty()&&x[v]-x[q.front()]>d) cnt[dis[q.front()]]-=dp[q.front()],q.pop_front();
		if(q.empty()) return ;
		dis[v]=dis[q.front()]+1,dp[v]=min(3,cnt[dis[q.front()]]);
		if(dp[v]==2) ans++;
	}
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	ans=0;
	for(int i=1;i<=n;i++) solve(i);
	cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>T;
	while(T--) solve();
	return 0;
}/*
*/

