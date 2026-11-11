#include<bits/stdc++.h>
using namespace std;
#define ft first
#define sd second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vel;
typedef vector<vel> vevel;
typedef vector<pll> velp;
typedef vector<velp> vevelp;
typedef vector<bool> veb;
typedef string sig;
typedef priority_queue<ll> pql;
const ll MAXN=1e18;
ll n,k;
vevel g;
veb is_t;
vel bcj;
ll ff(ll x){
	if(bcj[x]==x)return x;
	return bcj[x]=ff(bcj[x]);
}
bool check(){
	bcj=vel(n+3);
	for(int i=1;i<=n;i++){
		bcj[i]=i;
	}
	for(int i=1;i<=n;i++){
		if(is_t[i]){
			for(auto j:g[i]){
				if(is_t[j]){
					if(ff(i)!=ff(j)){
						bcj[ff(i)]=ff(j);
					}
				}
			}
		}
	}
	set<ll> st;
	for(int i=1;i<=n;i++){
		if(is_t[i]){
			st.insert(ff(i));
		}
	}
	if(st.size()<=2){
		return 1;
	}
	return 0;
}
ll dfs(ll x,ll fa){
	if(is_t[x])return 0;
	ll minn=MAXN;
	for(auto i:g[x]){
		if(i==fa)continue;
		minn=min(dfs(i,x)+1,minn);
	}
	return minn;
}
ll last=MAXN;
void fang(ll x,ll cnt){
	if(cnt>k){
		return;
	}
	if(x>n){
		if(cnt<k)return;
		if(check()){
			ll sum=0;
			for(int i=1;i<=n;i++){
				ll x=dfs(i,0);
				sum=max(x,sum);
			}
			last=min(last,sum);
		}
		return;
	}
	fang(x+1,cnt);
	is_t[x]=1;
	fang(x+1,cnt+1);
	is_t[x]=0;
}
void slv1(){
	fang(1,0);
	cout<<last<<'\n';
}

ll zx(ll x,ll fa,ll dep){
	ll maxn=dep;
	for(auto i:g[x]){
		if(i==fa){
			continue;
		}
		maxn=max(maxn,zx(i,x,dep+1));
	}
	return maxn;
}
ll fr1,fr2,fr1id,fr2id;
void dfs1(ll x,ll fa,ll dep){
	if(dep>fr1){
		fr1id=x;
		fr1=dep;
	}
	for(auto i:g[x]){
		if(i==fa)continue;
		dfs1(i,x,dep+1);
	}
}
void dfs2(ll x,ll fa,ll dep){
	if(dep>fr2){
		fr2id=x;
		fr2=dep;
	}
	for(auto i:g[x]){
		if(i==fa)continue;
		dfs2(i,x,dep+1);
	}
}
ll dfs3(ll x,ll fa,ll dep){
	if(x==fr1id||x==fr2id){
		return dep;
	}
	ll minn=MAXN;
	for(auto i:g[x]){
		if(i==fa){
			continue;
		}
		minn=min(minn,dfs3(i,x,dep+1));
	}
	return minn;
}
void slv2(){
	if(k==1){
		ll ans=MAXN;
		for(int i=1;i<=n;i++){
			ans=min(ans,zx(i,0,0));
		}
		cout<<ans<<'\n';
	}else if(k==2){
		fr1=fr2=0;
		dfs1(1,0,0);
		dfs2(fr1id,0,0);
		ll ans=0;
		for(int i=1;i<=n;i++){
			ans=max(ans,dfs3(i,0,0));
		}
		cout<<ans<<'\n';
	}else{
		cout<<(n+k-1)/k<<'\n';
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll T=1,c;
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		last=MAXN;
		g=vevel(n+3);
		is_t=veb(n+3);
		for(int i=1;i<n;i++){
			ll x,y;
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		if(n>=100){
			slv2();
		}else{
			slv1();
		}
	}
	return 0;
}