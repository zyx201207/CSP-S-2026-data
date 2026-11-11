#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,k,f[2000010]={},cnt=0,dp[2010][2010]={},ans=1e9;
bool mp[2000010]={},flag[2000010]={};
vector<int>g[2000010]={};
int count(int x){
	int cnt=0;
	while(x) cnt+=x&1,x>>=1;
	return cnt;
}
void init(int x){
	do f[x]=x,mp[x]=false;while(x--);
}
int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
}
void join(int x,int y){
	x=find(x),y=find(y);
	if(x!=y) f[x]=y;
}
bool check(int mask){
	init(n);
	cnt=0;
	for(int i=1;i<=n;i++) for(int j=0;j<g[i].size();j++) if(((mask>>(i-1))&1)&&((mask>>(g[i][j]-1))&1)) join(i,g[i][j]);
	for(int i=1;i<=n;i++) if(!((mask>>(i-1))&1)) f[i]=0;
	for(int i=1;i<=n;i++) mp[find(f[i])]=true;
	for(int i=1;i<=n;i++) cnt+=mp[i];
	for(int i=1;i<=n;i++) flag[i]=(mask>>(i-1))&1;
	return cnt<3;
}
void solve(){
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dp[i][j]=1e9;
	for(int i=1,u,v;i<n;i++) scanf("%lld%lld",&u,&v),g[u].push_back(v),g[v].push_back(u),dp[u][v]=dp[v][u]=1;
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
	ans=1e9;
	for(int i=0;i<(1<<n);i++) if(count(i)==k&&check(i)){
		int ma=-1e9;
		for(int j=1;j<=n;j++){
			int tmp=1e9;
			if(flag[j]) continue;
			for(int k=1;k<=n;k++) if(j!=k&&flag[k]) tmp=min(tmp,dp[j][k]);
			ma=max(ma,tmp);
		}
		ans=min(ans,ma);
	}
	printf("%lld\n",ans);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--) solve();
	return 0;
}
