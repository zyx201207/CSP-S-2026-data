#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c, n, m, d, q, w[500005], go[1005][1005], vis[1005][1005], cn[20005];
vector<pair<ll, ll>>vec[505], G[1005];
vector<ll>sta[20005];
void solve1(){
	for(ll i=1; i<=m; i++){
		for(ll j=1; j<=m; j++){
			go[i][j]=1e14;
		}
	}
	for(ll x=1; x<=n; x++){
		for(ll i=0; i<vec[x].size(); i++){
			for(ll j=i+1; j<vec[x].size(); j++){
				ll id1=vec[x][i].first, id2=vec[x][j].first, c1=vec[x][i].second, c2=vec[x][j].second;
				G[id1].push_back({id2, c1+c2});
				G[id2].push_back({id1, c1+c2});
			}
		}
	}
	for(ll x=1; x<=m; x++){
		go[x][x]=0;
		priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>que;
		que.push({0, x});
		while(que.size()){
			pair<ll, ll>tp=que.top();que.pop();
			ll id=tp.second;
			if(vis[x][id])continue;vis[x][id]=1;
			for(auto vn:G[id]){
				ll v=vn.first, w=vn.second+tp.first;
				if(go[x][v]>w){
					go[x][v]=w;
					que.push({w, v});
				}
			}
		}
	}
	while(q--){
		ll x, y;cin >> x >> y;
		cout<<go[x][y]+w[x]+w[y]<<'\n';
	}
	return;
}
ll wide(ll x, ll y){
	for(ll i=1; i<=m; i++)cn[i]=1e14;cn[x]=0;
	queue<ll>que;que.push(x);
	while(que.size()){
		ll tp=que.front();que.pop();
		for(auto vn:sta[tp]){
			for(auto vv:vec[vn]){
				if(vv.first==y)return cn[tp]+vv.second*2;
				if(cn[tp]+vv.second*2<cn[vv.first]){
					cn[vv.first]=cn[tp]+vv.second*2;
					que.push(vv.first);
				}
			}
		}
	}
	return 1e14;
}
void solve2(){
	for(ll x=1; x<=n; x++){
		for(auto v:vec[x]){
			sta[v.first].push_back(x);
		}
	}
	while(q--){
		ll x, y;cin >> x >> y;
		cout<<wide(x, y)+w[x]+w[y]<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(ll i=1; i<=m; i++)cin >> w[i];
	for(ll i=1; i<=n; i++){
		ll k;cin >> k;
		while(k--){
			pair<ll, ll>p;cin >> p.first >> p.second;
			vec[i].push_back(p);
		}
	}
	if(c<=11){//44·Ö 
		solve1();
	}
	else if(c<=15)solve2();//16·Ö£¿ 
	else{
		while(q--){
			ll x, y;cin >> x >> y;
			cout<<vec[0][0].second*2+w[x]+w[y]<<'\n';
		}
	}
	return 0;
}

