#include<bits/stdc++.h>
#define ll long long
#define infll 0x3f3f3f3f3f3f3f3f
#define N 5005
#define M 2000005
#define endl '\n'
#define ls root<<1
#define rs root<<1|1
#define F first
#define S second
using namespace std;
ll cc,t,n,k,dep[N],dp[N][25],ans=infll,vis[N];
vector<ll> v[N];
void dfs(ll x,ll fa){
	dep[x]=dep[fa]+1;
	dp[x][0]=fa;
	for(int i=1;i<=21;i++){
		dp[x][i]=dp[dp[x][i-1]][i-1];
	}
	for(int i=0;i<v[x].size();i++){
		if(v[x][i]!=fa) dfs(v[x][i],x);
	}
}
ll lca(ll x,ll y){
	ll cnt=0;
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=21;i>=0;i--){
		if(dep[x]-(1<<i)>=dep[y]){
			x=dp[x][i];
			cnt+=(1<<i);
		}
	}
	if(x==y) return cnt;
	for(int i=21;i>=0;i--){
		if(dp[x][i]!=dp[y][i]){
			cnt+=(1<<(i+1));
			x=dp[x][i];
			y=dp[y][i];
		}
	}
	return cnt+2;
}
void dfss(ll x,ll fa,ll mask){
	vis[x]=1;
	for(int i=0;i<v[x].size();i++){
		ll to=v[x][i];
		if(vis[to]==0&&to!=fa&&((1<<(to-1))&mask)) dfss(to,x,mask);
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>cc>>t;
	while(t--){
		ans=infll;
		cin>>n>>k;
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=1;i<n;i++){
			ll x,y;cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs(1,0);
		for(int mask=0;mask<(1<<n);mask++){
			if(__builtin_popcount(mask)!=k) continue;
			ll cur=0;
			for(int i=1;i<=n;i++) vis[i]=0;
			for(int i=1;i<=n;i++){
				if(((1<<(i-1))&mask)&&vis[i]==0){
					dfss(i,0,mask);cur++;
				} 
			}
			if(cur>2) continue;
			ll sum=0;
			for(int i=1;i<=n;i++){
				if((1<<(i-1))&mask) continue;
				ll yjh=infll;
				for(int j=1;j<=n;j++){
					if((1<<(j-1))&mask){
						yjh=min(yjh,lca(i,j));
					} 
				}
				sum=max(sum,yjh);
			}
			ans=min(ans,sum);
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2 
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/

