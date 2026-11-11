#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
//#define mod 998244353
#define INF 1'000'000'000'000'000'000
#define bcstr basic_string
#define i128 __int128
using namespace std;
int qx,T,n,k;
bcstr<int> e[1000005];
int dep[1000005],siz[1000005];
int mx,mx2;
void dfs(int u,int fa){
	dep[u]=dep[fa]+1,siz[u]=1;
	for(auto v:e[u]) if(v!=fa) dfs(v,u);
}
void dfs2(int u,int fa,int d){
	if(dep[u]>=d){
		if(siz[u]>=mx) mx2=mx,mx=siz[u];
		else if(siz[u]>mx2) mx2=siz[u];
		return;
	}
	for(auto v:e[u]) if(v!=fa) dfs2(v,u,d);
}
bool check(int d){
	for(int i=1;i<=n;i++){
		mx=mx2=0,dfs(i,0),dfs2(i,0,d);
		if(mx+mx2>=k) return true;
	}
	return false;
}
int lower_bound_(int l,int r){
	int res=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)) res=mid,r=mid-1;
		else l=mid+1;
	}
	return res;
}
void work(){
	cin>>n>>k,dep[0]=-1;
	for(int i=1;i<=n;i++) e[i].clear();
	for(int i=1,u,v;i<n;i++) cin>>u>>v,e[u]+=v,e[v]+=u;
	if(qx>10) cout<<n/k<<'\n';
	else cout<<lower_bound_(0,n)<<'\n';
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>qx>>T;
	while(T--) work(); 
	return 0;
}
