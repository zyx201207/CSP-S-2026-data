#include<bits/stdc++.h>
#define pb push_back
#define int long long 

using namespace std;

const int N=5005,inf=1e18;
int n,a[N],d,dis[N],cnt[N],c,t;
vector<int> g[N];
bool vis[N][N];
void add(int u,int v){
	g[u].pb(v);
}
int bfs(int s){
	int res=0;
	for(int i=1;i<=n;i++) dis[i]=inf,cnt[i]=0;
	queue<int> q;
	q.push(s);dis[s]=0;cnt[s]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int v:g[u]){
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				cnt[v]=cnt[u];
				q.push(v);
			}else if(dis[v]==dis[u]+1){
				cnt[v]++;
			}
		}
	}
	for(int i=s+1;i<=n;i++){
		if(cnt[i]==2) res++;
	}
	return res;
}
void solve(){
	int ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(llabs(a[i]-a[j])<=d){
				add(i,j);
			}
		}
	}
	for(int i=1;i<=n;i++)
		ans+=bfs(i);
	cout<<ans<<"\n";
	for(int i=1;i<=n;i++) g[i].clear();
}
int32_t main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--) solve();
}