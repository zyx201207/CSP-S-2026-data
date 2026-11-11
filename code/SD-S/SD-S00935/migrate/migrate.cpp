#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll c,T;
ll a[100010];
vector<ll> e[100010];
ll t[100010];
ll vis[100010];
void solve(){
	ll n,d;
	cin>>n>>d;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		e[i].clear();
	}
	ll ans=0;
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		for(ll j=i+1;j<=n;j++){
			if(a[j]-a[i]>d) break;
			e[i].push_back(j);
			e[j].push_back(i);
		}
	}
	for(ll i=1;i<=n;i++){
		fill(vis,vis+100010,0);
		fill(t,t+100010,0);
		queue<ll> q,nq;
		q.push(i);
		vis[i]=1;
		while(!nq.empty()||!q.empty()){
			while(!q.empty()){
				ll u=q.front();
				q.pop();
				for(auto v:e[u]){
					if(vis[v]) continue;
					t[v]++;
					nq.push(v);
				}
			}
			for(ll j=1;j<=n;j++){
				if(j==i) continue;
				if(t[j]==2) ans++;
				t[j]=0;
			}
			while(!nq.empty()){
				ll u=nq.front();
				nq.pop();
				vis[u]=1;
				q.push(u);
			}
		}
	}
	cout<<ans/2<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
} 
