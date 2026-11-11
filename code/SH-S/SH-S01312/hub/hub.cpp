#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll biao=30;
ll a[biao],st[biao][5],n,k,d[biao],tid;
vector<ll> v[biao];

void dfs(ll node,ll father){
	d[node]=d[father]+1,st[node][0]=father;
	for(ll i=1;i<5;i++) st[node][i]=st[st[node][i-1]][i-1];
	
	for(ll i=0;i<v[node].size();i++){
		ll j=v[node][i];
		if(j==father) continue;
		dfs(j,node);
	}
}

ll lca(ll x,ll y){
	if(d[x]<d[y]) swap(x,y);
	for(ll i=4;i>=0;i--) if(d[st[x][i]]>=d[y]) x=st[x][i];
	if(x==y) return x;
	for(ll i=4;i>=0;i--) if(st[x][i]!=st[y][i]) x=st[x][i],y=st[y][i];
	return st[x][0];
}

ll dis(ll x,ll y){return d[x]+d[y]-2*d[lca(x,y)];}

ll fa[biao];
ll findf(ll x){
	if(x==fa[x]) return x;
	return fa[x]=findf(fa[x]); 
}

void mergem(ll x,ll y){
	x=findf(x),y=findf(y);
	fa[x]=y;
}

ll ans,used[biao];
void query(){
	for(ll i=1;i<=n;i++) fa[i]=i,used[i]=0;
	for(ll i=1;i<=k;i++) used[a[i]]=1;
//	for(ll i=1;i<=k;i++) cout<<a[i]<<" ";cout<<'\n';
	
	for(ll i=1;i<=n;i++){
		if(!used[i]) continue;
		for(ll j=0;j<v[i].size();j++){
			if(used[v[i][j]]) mergem(i,v[i][j]);
		}
	}
	
	ll cnt=0;
	for(ll i=1;i<=n;i++) if(used[i] && findf(i)==i) cnt++;
	
	if(cnt>2) return;
	
//	cout<<"***\n";
	ll now=0;
	for(ll i=1;i<=n;i++){
		ll mm=1e18;
		for(ll j=1;j<=k;j++) mm=min(mm,dis(i,a[j]));
//		cout<<i<<" "<<mm<<'\n';
		now=max(now,mm);
	}
//	if(now==1){
//		cout<<cnt<<'\n';
//		for(ll i=1;i<=k;i++) cout<<a[i]<<" ";cout<<'\n';
//	}
//	cout<<now<<":\n";
	ans=min(ans,now);
}

void mei(ll node,ll cnt){
	if(node==n+1){
		if(cnt!=k) return;
		query();
		return;
	}
	
	mei(node+1,cnt);
	a[cnt+1]=node,mei(node+1,cnt+1);
}

void solve(){
	cin>>n>>k;
	for(ll i=1;i<=n;i++) v[i].clear();
	for(ll i=1;i<=n;i++){
		for(ll j=0;j<5;j++) st[i][j]=0;
		d[i]=0;
	}
	for(ll i=1;i<n;i++){
		ll x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	
	dfs(1,0);
//	for(ll i=1;i<=n;i++){
//		for(ll j=1;j<=n;j++) cout<<lca(i,j)<<" ";
//		cout<<'\n';
//	}
	ans=1e18;
	mei(1,0);
	cout<<ans<<'\n';
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	ll t;
	cin>>tid>>t;
	while(t--) solve();
	
	return 0;
}
