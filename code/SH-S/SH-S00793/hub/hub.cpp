#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=100+10;
const ll inf=1e16;
vector <ll> es[N];
bool chs[N],vis[N];
ll d[N][N];
ll ans=inf;
void dfs(ll x,ll fa,ll s) {
	d[s][x]=d[s][fa]+1;
	for(ll i=0; i<es[x].size(); i++) {
		if(es[x][i]!=fa) {
			dfs(es[x][i],x,s);
		}
	}
	return;
}
void dfs2(ll x,ll fa) {
	vis[x]=true;
	for(ll i=0; i<es[x].size(); i++) {
		if(es[x][i]!=fa&&chs[es[x][i]]==true) {
			dfs2(es[x][i],x);
		}
	}
	return;
}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll c,t;
	cin >> c >> t;
	for(ll rd=1; rd<=t; rd++) {
		ans=inf;
		ll n,k;
		cin >> n >> k;
		for(ll i=0;i<n;i++){
			es[i].clear();
		}
		for(ll i=1; i<=n-1; i++) {
			ll u,v;
			cin >> u >> v;
			u--;
			v--;
			es[u].push_back(v);
			es[v].push_back(u);
		}
		for(ll i=0; i<n; i++) {
			d[i][i]=-1;
			dfs(i,i,i);
		}
		for(ll mk=0; mk<(1<<n); mk++) {
			if(__builtin_popcount(mk)==k) {
				for(ll j=0; j<n; j++) {
					vis[j]=false;
					if((mk&(1<<j))!=0) {
						chs[j]=true;
					} else {
						chs[j]=false;
					}
				}
				ll cnt=0;
				for(ll i=0;i<n;i++){
					if(!vis[i]&&chs[i]){
						dfs2(i,0);
						cnt++;
						if(cnt>2){
							break;
						} 
					}
				}
				if(cnt>2){
					continue;
				}
				ll res=0;
				for(ll i=0;i<n;i++){
					ll ctr=inf;
					for(ll j=0;j<n;j++){
						if(chs[j]==true){
							ctr=min(ctr,d[i][j]);
						}
					}
					res=max(res,ctr); 
				}
				ans=min(ans,res);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
