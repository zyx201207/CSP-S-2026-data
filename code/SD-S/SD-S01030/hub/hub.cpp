#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pal pair<ll,ll>
#define fi first
#define se second
const ll MOD=1e9+7;
const ll N=5e5+10;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll n,m,b[N],s,C,c[N],vis[N];
vector<ll> a[N];
queue<ll> q;
void dfss(ll x,ll fa){
	vis[x]=1;
	for(int i=0;i<a[x].size();i++){
		if(a[x][i]==fa||b[a[x][i]]==0)continue;
		dfss(a[x][i],x);
	}
}
void dfs(ll x,ll y){
	if(x==n+1&&y==0){
		ll t=0;
		for(int i=1;i<=n;i++)vis[i]=0;
		for(int i=1;i<=n;i++){
			if(b[i]&&!vis[i])t++,dfss(i,0);
		}
		if(t>2)return;
		for(int i=1;i<=n;i++){
			c[i]=0;
			if(b[i])q.push(i),c[i]=1;
		}
		while(!q.empty()){
			ll x=q.front();
			q.pop();
			for(int i=0;i<a[x].size();i++){
				if(!c[a[x][i]]){
					c[a[x][i]]=c[x]+1;
					q.push(a[x][i]);
				}
			}
		}
		ll ma=0;
		for(int i=1;i<=n;i++)ma=max(ma,c[i]-1);
		s=min(s,ma);
		return;
	}
	if(n-x+1<y)return;
	b[x]=1;
	if(y)dfs(x+1,y-1);
	b[x]=0;
	dfs(x+1,y);
}
void Solve(){
	cin>>n>>m;
	s=INF;
	for(int i=1;i<=n;i++)a[i].clear(),b[i]=0;
	for(int i=1;i<n;i++){
		ll x,y;
		cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1,m);
	cout<<s<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll T;cin>>C>>T;
	while(T--)Solve();
	return 0;
}
