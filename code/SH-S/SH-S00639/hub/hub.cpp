#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+9;
const ll INF=1e18;
ll n,k,ans,p[N],dst[N],g[20][20];
bool vst[N];
vector<int> to[N];
void work(){
	queue<ll> q;
	for(int i=1;i<=n;i++) dst[i]=INF,vst[i]=0;
	for(int i=1;i<=n;i++)
		if(p[i]){
			dst[i]=0;
			q.push(i);
		}
	ll c=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(p[i]&&p[j]&&g[i][j])
				c++;
	if(c<k-2) return;
	while(q.size()){
		ll u=q.front();q.pop();
		for(int i=0;i<(int)to[u].size();i++){
			ll v=to[u][i];
			if(dst[v]>dst[u]+1){
				dst[v]=dst[u]+1;
				q.push(v);
			}
		}
	}
	ll mx=0;
	for(int i=1;i<=n;i++) mx=max(mx,dst[i]);
	ans=min(ans,mx);
	return;
}
void dfs(ll x,ll cnt){
	if(cnt>k) return;
	if(n-x+1+cnt<k) return;
	if(x==n+1){
		if(cnt==k) work();
		return;
	}
	p[x]=1;
	dfs(x+1,cnt+1);
	p[x]=0;
	dfs(x+1,cnt);
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) to[i].clear();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			g[i][j]=0;
	for(int i=1;i<n;i++){
		ll u,v;cin>>u>>v;
		to[u].push_back(v);
		to[v].push_back(u);
		g[u][v]=g[v][u]=1;
	}
	ans=INF;
	dfs(1,0);
	cout<<ans<<endl;
	return;
}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int c,T;cin>>c>>T;
	while(T--) solve(); 
	return 0;
} 
