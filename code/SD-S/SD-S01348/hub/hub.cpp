#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5;
ll c,T;
ll n,k;
vector<ll>e[N];
ll fa[N];
ll fd(ll x){
	if(x==fa[x])return x;
	return fa[x]=fd(fa[x]);
}
void  hb(ll x,ll y){
	x=fd(x),y=fd(y);
	fa[x]=y;
}
void solve() {
	cin>>n>>k;
	for(ll i=1;i<=n;i++)e[i].clear();
	for(ll i=1;i<n;i++){
		ll u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u); 
	}
	ll ans=n;
	for(ll s=1;s<(1<<n);s++){
		ll cn=0;
		for(ll j=1;j<=n;j++){
			if((s>>(j-1))&1){
				++cn;
			}
		}
		if(cn==k){
			for(ll i=1;i<=n;i++)fa[i]=i;
			for(ll i=1;i<=n;i++){
				for(auto j:e[i]){
					if(j>i&&((s>>(i-1))&1)&&((s>>(j-1))&1)){
						hb(j,i);
					}
				} 
			}
			ll cc=0;
			for(ll i=1;i<=n;i++){
				if(fa[i]==i&&((s>>(i-1))&1)){
					++cc;
				}
			}
			if(cc>2)continue;
			ll an=0;
			for(ll i=1;i<=n;i++){
				if((s>>(i-1))&1){
//				cout<<i<<' ';
				continue;
				}
				queue<pair<ll,pair<ll,ll> > >q;
				q.push({i,{0,0}});
				ll fl=0;
				while(q.size()){
					ll x=q.front().first,fax=q.front().second.first,dep=q.front().second.second;
					q.pop();
					if((s>>(x-1))&1){
						fl=dep;
						break;
					}
					for(auto y:e[x]){
						if(y==fax)continue;
						q.push({y,{x,dep+1}});
					}
				}
				an=max(an,fl);
			}
//			cout<<an<<'\n';
			ans=min(ans,an);
		}
	}
	cout<<ans<<"\n";
}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--)solve();
	return 0;
}
/*
0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10




*/
