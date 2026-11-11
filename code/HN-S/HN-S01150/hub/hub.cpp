#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll c,t,n,k,d[100001],f[100001][22],lj[11],ans=1e18;
vector<ll>a[100001];
void dfs(ll x,ll fa){
	d[x]=d[fa]+1;
	f[x][0]=fa;
	for(ll k=1;k<=5;k++) f[x][k]=f[f[x][k-1]][k-1];
	for(ll i=0;i<a[x].size();i++){
		ll y=a[x][i];
		if(y==fa) continue;
		dfs(y,x);
	}
}
ll lca(ll x,ll y){
	if(d[x]<d[y]) swap(x,y);
	for(ll k=5;k>=0;k--)
		if(d[f[x][k]]>d[y]) x=f[x][k];
	if(x==y) return x;
	for(ll k=5;k>=0;k--)
		if(f[x][k]!=f[y][k]){
			x=f[x][k];
			y=f[y][k];
		}
	return f[x][0];
}
ll sum(){
	ll minn=0;
	for(ll i=1;i<=n;i++){
		ll minn2=1e18;
		for(ll j=1;j<=k;j++){
			ll num=lca(i,lj[j]);
			minn2=min(minn2,d[i]+d[lj[j]]-2*d[num]);
		}
		minn=max(minn,minn2);
	}
	return minn;
}
void dfs1(ll x,ll y){
	if(x==k){
		ans=min(ans,sum());
		return ;
	}
	for(ll i=y;i<=n;i++){
		lj[x+1]=i;
		dfs1(x+1,i+1);
	}
}
void solve1(){
	ans=1e18;
	dfs1(0,1);
	cout<<ans<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(ll i=1;i<=n;i++) a[i].clear();
		for(ll i=1;i<n;i++){
			ll u,v;
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		d[0]=0;
		dfs(1,0);
		if(k<=10) solve1();
	}
	return 0;
}

