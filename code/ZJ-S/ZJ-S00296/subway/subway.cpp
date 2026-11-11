#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<ll,ll>
#define x first
#define y second
const ll M=5e5+10;
vector<PII> g[M<<2];
ll dist[M<<2];
bool st[M<<2];
vector<PII> a[M];
ll anss[M];
void dj(ll l){
	memset(dist,0x3f,sizeof dist);
	memset(st,0,sizeof st);
	dist[l]=0;
	priority_queue<PII,vector<PII>,greater<PII> > q;
	q.push({0,l});
	while (!q.empty()){
		PII t=q.top();
		q.pop();
		ll u=t.y,w=t.x;
		if (st[u]) continue;
		st[u]=1;
		for (ll i=0;i<g[u].size();i++){
			PII v=g[u][i];
			ll ver=v.x,cost=v.y;
			if (dist[ver]>dist[u]+cost){
				dist[ver]=dist[u]+cost;
				q.push({dist[ver],ver});
			}
		}
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for (ll i=1;i<=m;i++){
		ll w;
		cin>>w;
		g[i].push_back({i+m,w});
		g[i+m].push_back({i,w});
	}
	ll cnt=0,cntt=0,ww=0;
	for (ll i=1;i<=n;i++){
		ll k;
		cin>>k;
		for (ll j=1;j<=k;j++){
			ll v,w;
			cin>>v>>w;
			cnt++;
			if (ww==w) cntt++;
			ww=w;
			g[2*m+i].push_back({m+v,w});
			g[m+v].push_back({2*m+i,w});
		}
	}
	if (q<=200){
		while (q--){
			ll l,r;
			cin>>l>>r;
			dj(l);
			ll ans=dist[r];
			cout<<ans<<'\n';
		}
	}
	else {
		for (ll i=1;i<=q;i++){
			ll l,r;
			cin>>l>>r;
			a[l].push_back({r,i});
		}
		for (ll i=1;i<=m;i++){
			if (a[i].size()==0) continue;
			dj(i);
			for (ll j=0;j<a[i].size();j++){
				PII t=a[i][j];
				anss[t.y]=dist[t.x];
			}
		}
		for (ll i=1;i<=q;i++) cout<<anss[i]<<'\n';
	}
	return 0;
}
