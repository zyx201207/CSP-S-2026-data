#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const int maxm=5e5+9, maxn=509;
ll w[maxm]; int k[maxn];
const ll maxsd=(maxn+maxm*2+999)*8;
ll eto[maxsd]; int ew[maxsd]; ll enxt[maxsd], eh[maxsd>>1], ecnt;
bool vis[maxsd>>1]; ll ds[maxsd>>1];
void add(ll a, ll b, ll c) {
	eto[++ecnt]=b;
	ew[ecnt]=c;
	enxt[ecnt]=eh[a];
	eh[a]=ecnt;
}
void djk(ll f, ll t) {
	memset(vis, 0, sizeof vis); memset(ds, 0x3f, sizeof ds);
	priority_queue<P,vector<P>,greater<P> > pq;
	ds[f]=0; pq.push((P){0,f}); // A*???
	while (!pq.empty()) {
		P p=pq.top(); pq.pop();
		int x= p.second, cd=p.first;
		if (cd >= ds[t]) continue;
		if (vis[x]) continue; vis[x]=1;
		for (ll e=eh[x];e!=0;e=enxt[e]) {
			ll v=eto[e], w=ew[e];
			if (w+cd<ds[v]) {
				ds[v]=w+cd;	
				pq.push((P){w+cd, v});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int _,n,m,d,q; cin >> _ >> n >> m >> d >> q;
	for (int i=1;i<=m;i++) {
		cin>>w[i];
		add(i,i+m,w[i]); add(i+m,i,w[i]); 
	}
	for (int i=1;i<=n;i++) {
		cin >> k[i];
		for (int j=1;j<=k[i];j++) {
			int a,b; cin >> a >> b;
			add(i+2*m, a+m, b); add(a+m, i+2*m, b);
		}
	}
	for (int i=1;i<=q;i++) {
		int s, t; cin >> s >> t;
		djk(s, t); 
		for (int j=1;j<=m;j++) {
			if(s!=j) add(s, j, ds[j]), add(j, s, ds[j]);
		}
		printf("%d\n", ds[t]);
	}

	return 0;
}

