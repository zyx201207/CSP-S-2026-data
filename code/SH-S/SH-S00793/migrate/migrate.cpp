#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e6+10;
const ll inf=2e18+1;
ll n,m;
ll x[N]; 
namespace brute{
	ll cnt[N]={};
	ll d[N]={};
	vector <ll> es[N];
	void bfs(ll s){
		queue <ll> q;
		q.push(s);
		cnt[s]=1;
		d[s]=0;
		while(!q.empty()){
			ll x=q.front();
			q.pop();
			for(ll i=0;i<es[x].size();i++){
				if(d[es[x][i]]==inf){
					d[es[x][i]]=d[x]+1;
					cnt[es[x][i]]+=cnt[x];
					q.push(es[x][i]);
				}else if(d[es[x][i]]==d[x]+1){
					cnt[es[x][i]]+=cnt[x];
				}
			}
		} 
		return;
	}
	int main(){
		for(ll i=1;i<=n;i++){
			es[i].clear();
		}
		ll ans=0;
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				if(i!=j&&abs(x[i]-x[j])<=m){
					es[i].push_back(j);
				} 
			}
		}
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				cnt[j]=0;
				d[j]=inf;
			} 
			bfs(i);
			for(ll j=1;j<=n;j++){
				if(cnt[j]==2){
					ans++;
				}
			}
		}
		cout << ans/2 << "\n";
		return 0;
	}
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll c,t;
	cin >> c >> t;
	for(ll rd=1; rd<=t; rd++) {
		cin >> n >> m;
		for(ll i=1; i<=n; i++) {
			cin >> x[i];
		}
		if(n==1){
			cout << 0 << "\n";
			continue;
		}
		brute::main();
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
