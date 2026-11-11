#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const int N = 1e6 + 100;
template<typename TY>
void read(TY &s){
	ll x = 0, f = 1;
	char ch = getchar();
	while(ch < '0'||ch > '9'){
		if(ch=='-') f = -1;
		ch = getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	s = x * f;
}
int c,n,m,d,q,idx;
pair<int,pair<int,int> > qs[N];
ll ans[N];
ll w[N],dis[N];
bool done[N];
vector<pair<int,ll> > e[N];
void dij(int s){
	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > Q;
	for(int i=1;i<=idx;i++){
		dis[i] = 1e18;
		done[i] = false;
	}
	dis[s] = 0;
	Q.push({0,s});
	while(!Q.empty()){
		auto u = Q.top(); Q.pop();
		if(done[u.se]) continue;
		done[u.se] = true;
		for(auto x : e[u.se]){
			if(done[x.fi]) continue;
			if(dis[x.fi] > dis[u.se] + x.se){
				dis[x.fi] = dis[u.se] + x.se;
				Q.push({dis[x.fi],x.fi});
			}
		}
	}
}
void solve();
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(c); read(n); read(m); read(d); read(q);
	idx = m;
	for(int i=1;i<=m;i++){
		read(w[i]);
	}
	int k = 0,a = 0,t = 0;
	for(int i=1;i<=n;i++){
		read(k);
		idx++;
		for(int j=1;j<=k;j++){
			read(a); read(t);
			e[idx].push_back({a,t});
			e[a].push_back({idx,t});
		}
	}
	for(int i=1;i<=q;i++){
		read(qs[i].fi); read(qs[i].se.fi); qs[i].se.se = i;
	}
	sort(qs+1,qs+q+1);
	for(int i=1;i<=q;i++){
		if(qs[i].fi != qs[i-1].fi) dij(qs[i].fi);
		ans[qs[i].se.se] = dis[qs[i].se.fi] + w[qs[i].fi] + w[qs[i].se.fi];
	}
	for(int i=1;i<=q;i++){
		cout << ans[i] << '\n';
	}
	return 0;
}
