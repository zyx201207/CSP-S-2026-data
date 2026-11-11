#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const ll N=2e6+10;
ll c,t,n,k,v[N],ans=1e18,f[N],d[N];
vector<ll>g[N];
ll find(ll x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void hb(ll x,ll y){
	ll tx=find(x),ty=find(y);
	if(tx!=ty) f[tx]=ty;
}
void ff(int u,int sum){
	if(u==n+1){
		if(sum<k||sum>k) return ;
		for(int i=1;i<=n;++i) f[i]=(v[i]?i:0);
		for(int i=1;i<=n;++i)
			if(v[i])
				for(ll j:g[i])
					if(v[j])
						hb(i,j);
		map<ll,bool>m;
		for(int i=1;i<=n;++i) if(v[i]) m[find(i)]=1;
		if(m.size()>2) return ;
		for(int i=1;i<=n;++i) d[i]=(v[i]?0:100000000);
		queue<ll>q;
		for(int i=1;i<=n;++i) if(v[i]) q.push(i);
		ll sum=0;
		while(q.size()){
			ll u=q.front();q.pop();
			for(ll vv:g[u]){
				if(d[vv]<114514) continue;
				d[vv]=d[u]+1,sum=d[vv],q.push(vv);
			}
		}
		ans=min(ans,sum);
		return ;
	}
	v[u]=1;
	ff(u+1,sum+1);
	v[u]=0;
	ff(u+1,sum);
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;ll u,v;ans=1e18;
		for(int i=1;i<=n;++i) g[i].clear();
		for(int i=1;i<n;++i) cin>>u>>v,g[u].pb(v),g[v].pb(u);
		ff(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}
