#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define inl inline
const int N=2e6+10;
using namespace std;
int c,t,n,d;
int a[N],vis[N],dis[N],cnt[N];
vector<pii> e[N];
inl void dij(int s){
	for(int i=0;i<=n;i++){
		dis[i]=1e18;
		vis[i]=0;
		cnt[i]=0;
	}
	priority_queue<pii,vector<pii>,greater<pii>> q;
	dis[s]=0;
	cnt[s]=1;
	q.push({0,s});
	while(!q.empty()){
		pii x=q.top();q.pop();
		int u=x.second,t=x.first;
		for(auto xx:e[u]){
			int v=xx.first,w=xx.second;
			if(dis[v]>t+w){
				dis[v]=t+w;
				q.push({t+w,v});
				cnt[v]=cnt[u];
			}else if(dis[v]==t+w){
				cnt[v]+=cnt[u];
			}
		}
	}
	return;
}
inl void init(){
	for(int i=1;i<=n;i++){
		e[i].clear();
		dis[i]=1e18;
		vis[i]=0;
		cnt[i]=0;
		a[i]=0;
	}
}
inl void solve(){
	cin>>n>>d;
	init();
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]<=d){
				e[i].push_back({j,1});
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		dij(i);
		for(int j=i+1;j<=n;j++){
			ans+=(cnt[j]==2);
		}
	}
	cout<<ans<<endl;
	return;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}