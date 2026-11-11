#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e6+5;
ll n,d;
ll a[N],cnt[N],dis[N],vis[N];
vector<ll>e[N];
void bfs(ll root){
	queue<pair<ll,ll> >q;
	q.push({root,0});
	vis[root]=1;
	while(!q.empty()){
		ll u=q.front().first,dep=q.front().second;
		q.pop();
		for(ll i=0;i<e[u].size();i++){
			ll v=e[u][i];
			if(!vis[v]){
				cnt[v]++;
				vis[v]=1;
				dis[v]=dep+1;
				q.push({v,dep+1});
			}
			else if(dep+1==dis[v]){
				cnt[v]++;
				q.push({v,dep+1});
			}
		}
	}
}
void solve(){
	memset(a,0,sizeof a);
	memset(e,0,sizeof e);
	memset(vis,0,sizeof vis);
	cin>>n>>d;
	for(ll i=1;i<=n;i++){	
		cin>>a[i];
		for(ll j=i-1;j>=1;j--){
			if(a[i]-a[j]>d) break;
			e[j].push_back(i);
		}
	}
	ll ans=0;
	for(ll i=1;i<=n;i++){
		memset(cnt,0,sizeof cnt);
		memset(vis,0,sizeof vis);
		bfs(i);
		for(ll j=i+1;j<=n;j++)
			if(cnt[j]==2){
				ans++;
			}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,_;
	cin>>c>>_;
	while(_--) solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
