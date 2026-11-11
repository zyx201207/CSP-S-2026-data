#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
#define ll long long 
#define N 305
using namespace std;//40pts
int n;ll d;
ll x[N];
ll dp[N],dis[N],ans;
vector<int>G[N];
void solve(){
	ans=0;
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;i++){
		G[i].clear();
		scanf("%lld",x+i);
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(x[j]-x[i]>d)break;
			G[i].eb(j);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++)dis[j]=1e18,dp[j]=0;
		priority_queue<pii,vector<pii>,greater<pii>>q;
		q.emplace(0,i);
		dis[i]=0;
		dp[i]=1;
		while(!q.empty()){
			int u=q.top().se;
			ll w=q.top().fi;
			q.pop();
			if(dis[u]<w)continue;
			for(const int&v:G[u]){
				if(w+1<dis[v]){
					dis[v]=w+1;
					dp[v]=dp[u];
					q.emplace(dis[v],v);
				}else if(w+1==dis[v]){
					dp[v]+=dp[u];
				}
			}
		}
		for(int j=i+1;j<=n;j++){
			if(dp[j]==2)ans++;
		}
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t;
	scanf("%d",&t);
	scanf("%d",&t);
	while(t--)solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
