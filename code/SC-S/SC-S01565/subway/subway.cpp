#include <bits/stdc++.h>
#define ll long long
using namespace std;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in" ,"r" ,stdin);
	freopen("subway.out" ,"w" ,stdout);
	ll c ,n ,m ,d ,q ,cnt = 0;
	cin>>c>>n>>m>>d>>q;
	vector<pair<ll ,ll>> g[(m+1)*d+m+1];
	vector<ll> w(m+1);
	for(ll i = 1;i <= m;i++){
		cin>>w[i];
	}
	for(ll i = 1;i <= n;i++){
		ll kk;
		cin>>kk;
		vector<ll> a(kk+1) ,b(m+1);
		for(ll j = 1;j <= kk;j++){
			ll t;
			cin>>a[j]>>t;
			if(!b[a[j]]){
				b[a[j]] = ++cnt;	
			}
			g[(m+1)*d+a[j]].push_back({b[a[j]] ,t});
			g[b[a[j]]].push_back({(m+1)*d+a[j] ,t});
		}
		for(ll j = 2;j <= kk;j++){
			g[b[a[j]]].push_back({b[a[j-1]] ,0});
			g[b[a[j-1]]].push_back({b[a[j]] ,0});
		}
	}
	while(q--){
		ll s ,t;
		cin>>s>>t;
		priority_queue<pair<ll ,ll> ,vector<pair<ll ,ll>> ,greater<pair<ll ,ll>>> q;
		q.push({(m+1)*d+s ,0});
		vector<ll> dis((m+1)*d+m+1 ,LLONG_MAX);
		vector<bool> vis((m+1)*d+m+1);
		dis[(m+1)*d+s] = 0;
		while(!q.empty()){
			ll e = q.top().first;
			q.pop();
			if(vis[e]){
				continue;
			}
			vis[e] = 1;
			for(auto i : g[e]){
				ll fs = i.first;
				ll se = i.second;
				if(dis[e]+se < dis[fs]){
					dis[fs] = dis[e]+se;
					q.push({fs ,dis[fs]});
				}
			}
		}
		cout<<dis[(m+1)*d+t]+w[s]+w[t]<<"\n";	
	}
	return 0;
}
//0 3 7 20 2
// 8 3 6 1 7 2 9
// 3 1 4 2 5 5 100
// 3 2 6 3 1 7 2
// 4 3 2 5 100 4 6 6 7
// 1 6
//2 3
