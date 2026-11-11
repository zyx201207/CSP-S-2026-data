#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,t,n,k,fa[17],dep[1000007],fat[1000007][21],vis[1000007];
vector<ll>G[1000007];
void dfs(ll u,ll f){
	dep[u]=dep[f]+1;
	fat[u][0]=f;
	for(ll i=1;i<=20;i++){
		fat[u][i]=fat[fat[u][i-1]][i-1];
	}

	for(auto p:G[u]){
		if(p==f)continue;
		dfs(p,u);
	}
	
	return;
}
ll LCA(ll x,ll y){
	if(dep[x]<dep[y])swap(x,y);
	for(ll i=20;i>=0;i--){
		if(dep[fat[x][i]]>=dep[y])x=fat[x][i];
	}
	if(x==y)return x;
	for(ll i=20;i>=0;i--){
		if(fat[x][i]!=fat[y][i]){
			x=fat[x][i];
			y=fat[y][i];
		}
	}
	return fat[x][0];
}
void fds(ll u,ll fr){
	vis[u]=1;
	for(auto p:G[u]){
		if(!fa[p]||p==fr)continue;
		fds(p,u);
	}
	return;
}
ll dist(ll x,ll y){
	return dep[x]+dep[y]-2*dep[LCA(x,y)];
}
void main1(){
	dfs(1,0);
	ll ans=INT_MAX;
	for(ll s=0;s<(1<<n);s++){
		if(__builtin_popcount(s)!=k)continue;
		for(ll i=1;i<=n;i++){
			fa[i]=(s>>i-1)&1;
			vis[i]=0;
		}
		ll cnt=0;
		for(ll i=1;i<=n;i++){
			if(!vis[i]&&fa[i])fds(i,0),cnt++;
		}
		ll now=0;
		if(cnt>2)continue;
		for(ll i=1;i<=n;i++){
			if(s&(1<<i-1))continue;
			ll sum=INT_MAX;
			for(ll j=1;j<=n;j++){
				if(s&(1<<j-1)){
					sum=min(sum,dist(i,j));
				}
			}
			now=max(now,sum);
			
			
		}
		ans=min(ans,now);
	}
	cout<<ans<<'\n';
	return;
}
bool check(ll x){
	
	ll fst=1;
	for(ll i=1;i<=n;i++){
		vis[i]=0;
		if(dep[i]>x&&G[i].size()==1&&(fst==1||dep[fst]<dep[i]))fst=i;
		
	}

	ll ft=fst;
	if(ft!=1)
	for(ll i=0;i<=20;i++){
		if(x&(1<<i))ft=fat[ft][i];
	}
	for(ll i=1;i<=n;i++){
		if(dist(i,ft)<=x)vis[i]=1;
	}
	ll lst=1;
	for(ll i=1;i<=n;i++){
		if(dep[i]>x&&G[i].size()==1&&!vis[i]&&(lst==1||dep[lst]<dep[i]))lst=i;
	}
	for(ll i=0;i<=20;i++){
		if(x&(1<<i))lst=fat[lst][i];
	}
	ll ans=0;
	for(ll i=1;i<=n;i++){
		ans=max(ans,min(dist(i,ft),dist(i,lst)));
	}
	return ans<=x;
}
void main2(){
	dfs(1,0);
	ll l=0,r=n;
	while(l<=r){
		ll m=l+r>>1;
		if(check(m))r=m-1;
		else l=m+1;
	}
	cout<<l<<'\n';
	return;
}
bool check1(ll x){
	if(x==1){
		return k>=n/2;
	}
	if(x>=n/2)return 1;
	ll ls=n;
	for(ll i=0;i<=20;i++){
		if(x&(1<<i))ls=fat[ls][i];
	}
	ll fs=1;
	fs+=x-1;
	fs+=k-2;
	return fs+x>ls-x;
}
void main3(){
	dfs(1,0);
	ll l=0,r=n;
	while(l<=r){
		ll m=l+r>>1;
		if(check1(m)){
			r=m-1;
		}else l=m+1;
	}
	cout<<l<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(ll i=1;i<=n;i++)G[i].clear();
		for(ll i=1;i<n;i++){
			ll u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		if(n<=10){
			main1();
		}else if(k<=2){
			main2();
		}else if(k==n){
			cout<<"0\n";
		}else{
			main3();
		}
	}
}
