#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e6+5,inf=1e18;
ll wk,T,n,d,a[N],cnt[N],dis[N];
vector<ll> G[N];
bool vis[N];
inline void solve1(){
	for(int i=1;i<=n;i++) G[i].clear();
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]>d) break;
			G[i].push_back(j);
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) cnt[j]=vis[j]=0,dis[j]=inf;
		queue<ll> q;
		q.push(i);cnt[i]=1;dis[i]=0;
		while(q.size()){
			ll u=q.front();
			q.pop();
			if(vis[u]) continue;
			if(cnt[u]==2){
				ans++;
			}
			vis[u]=1;
			for(auto v:G[u]){
				if(vis[v]) continue;
				if(dis[v]>=dis[u]+1){
					cnt[v]+=cnt[u];
					dis[v]=dis[u]+1;
					q.push(v);
				}
			}
		}
//		for(int j=1;j<=n;j++) cout<<dis[j]<<" ";cout<<"\n";
//		for(int j=1;j<=n;j++) cout<<cnt[j]<<" ";cout<<"\n";
	}
	cout<<ans<<"\n";
} 
inline void solve2(){
	ll ans=0;
	ll t=upper_bound(a+1,a+1+n,a[1]+d+1)-a-2;
	if(t<=1) cout<<"0\n";
	else cout<<max(0ll,n-2*t+2-1)<<"\n";
}
signed main(){
	ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>wk>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n<=300) solve1();
		else solve2();
	}
	return 0;
}
/*
边数可以达到n^2级别，非常劣需要考虑优化建图 
每个点出发跑一边bfs是O(n(n+m))的但是m=n^2 
感觉答案并不会很大 
0 1
5 2
1 2 3 4 5
*/
