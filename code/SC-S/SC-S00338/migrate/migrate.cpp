#include<bits/stdc++.h>
#define ll long long
#define maxn 2000006
using namespace std;
ll a[maxn];
ll dis[maxn];
ll only[maxn];
ll fa[maxn];
ll n;
ll m,d;
ll p[maxn];
ll lb[maxn];
ll pls[maxn];
ll bf(ll ed){
	for(ll i=1;i<=ed;i++){
		dis[i]=1000000000;
	}
	dis[ed]=0;
	for(ll i=ed-1;i>=1;i--){
		dis[i]=dis[min(fa[i],ed)]+1;
	}
	for(ll i=0;i<=ed;i++){
		lb[i]=ed;
	}
	for(ll i=ed;i>=1;i--){
		lb[dis[i]]=i;
	}
	pls[ed]=1;
	ll tot=0;
	pls[ed+1]=0;
	for(ll i=ed-1;i>=1;i--){
		pls[i]=pls[i+1];
		ll pl;
		pl=pls[lb[dis[min(fa[i],ed)]]]-pls[min(fa[i],ed)+1];
		if(pl==2){
			tot++;
		}
		if(pl>2){
			pl=3;
		}
		pls[i]+=pl;
	}
	return tot;
}
ll work(vector<ll> v){
	ll m=v.size();
	for(ll i=1;i<=m;i++){
		p[i]=v[i-1];
	}
	ll rt=2;
	
	for(ll i=1;i<m;i++){
		while(rt<m&&p[rt+1]-p[i]<=d){
			rt++;
		}
		//son[rt].push_back(i);
		fa[i]=rt;
	}
	ll ret=0;
	for(ll i=1;i<=m;i++){
		ret+=bf(i);
	}
	return ret;
	/**
	for(ll i=1;i<=m;i++){
		dis[i]=100000000;
	}
	dis[m]=0;
	for(ll i=m-1;i>=1;i--){
		dis[i]=dis[fa[i]]+1;
	}
	for(ll i=0;i<=m;i++){
		lb[i]=m;
	}
	for(ll i=m;i>=1;i--){
		lb[dis[i]]=i;
	}
	for(ll i=1;i<m;i++){
		if(dis[fa[i]-1]!=dis[fa[i]]){
			only[fa[i]]++;
			only[fa[i]]+=only[i];
		}
	}
	ll lt=1;
	for(ll i=2;i<=m;i++){
		while(p[lt]<p[i]-d) lt++;
		
	} 
	**/ 
}
void init(){
	cin>>n>>d;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	vector<ll> v;
	ll ans=0;
	for(ll i=1;i<=n;i++){
		if((!v.size())||a[i]-*v.rbegin()<=d){
			v.push_back(a[i]);
		}
		else{
			ans+=work(v);
			v.clear();
			v.push_back(a[i]);
		}
	}
	ans+=work(v);
	v.clear();
	cout<<ans<<"\n";
}
ll ok[maxn];
void dc(){
	cin>>n>>d;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<0<<"\n";
		return;
	}
	if(a[2]-a[1]>d){
		cout<<0<<"\n";
		return;
	}
	ll m=n;
	for(ll i=1;i<=m;i++){
		p[i]=a[i];
	}
	ll rt=2;
	for(ll i=1;i<m;i++){
		while(rt<m&&p[rt+1]-p[i]<=d){
			rt++;
		}
		//son[rt].push_back(i);
		fa[i]=rt;
	}
	for(ll i=1;i<=m;i++){
		dis[i]=1000000000;
	}
	dis[m]=0;
	for(ll i=m-1;i>=1;i--){
		dis[i]=dis[min(fa[i],m)]+1;
	}
	for(ll i=0;i<=m;i++){
		lb[i]=m;
	}
	for(ll i=m;i>=1;i--){
		lb[dis[i]]=i;
	}
	pls[m]=1;
	
	pls[m+1]=0;
	for(ll i=m-1;i>=1;i--){
		pls[i]=pls[i+1];
		ll pl;
		pl=pls[lb[dis[min(fa[i],m)]]]-pls[min(fa[i],m)+1];
		if(pl==2){
			ok[i]=1;
		}
		else{
			ok[i]=0;
		}
		if(pl>2){
			pl=3;
		}
		pls[i]+=pl;
	}
	for(ll i=m-1;i>=1;i--){
		ok[i]+=ok[i+1];
	}
	ll ans=0;
	for(ll i=m;i>=1;i--){
		ans+=ok[i];
	}
	cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,t;
	cin>>c>>t;
	while(t--){
		if(c==11||c==12){
			dc();
		}
		else init();
	}
}