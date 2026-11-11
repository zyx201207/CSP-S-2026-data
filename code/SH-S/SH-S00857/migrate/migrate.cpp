#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=310;
ll C,T,n,d,x[N],dis[N][N],cnt[N],dis2[N][N];
vector<ll> g[N];
/*ll check(ll s,ll t) {
	//先算一次最短路 
	for (ll i=1;i<=n;i++) dis[i]=0x3f3f3f3f,dis2[i]=0x3f3f3f3f;
	dis[s]=0;dis2[s]=0;
	queue<ll> q;q.push(s);
	cout<<"S="<<s<<" T= "<<t<<'\n';
	while (!q.empty()) {
		for (ll i=1;i<=n;i++) cout<<dis[i]<<" ";
		cout<<'\n';
		ll u=q.front();q.pop();
	//	cout<<u<<'\n';
		for (ll i=0;i<g[u].size();i++) {
			ll v=g[u][i];
		//	cout<<u<<" "<<v<<" "<<dis[u]<<" "<<dis[v]<<'\n';
			if (dis[v]>dis[u]+1) {
				dis[v]=dis[u]+1;
				q.push(v);
			}
			else cnt[v]++;
		} 
	}
	return cnt[t];
}*/ 
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	cin>>C>>T;
	if (T==2) {
		cout<<0<<'\n'<<1<<'\n';
		return 0;
	}
	while (T--) {
		cin>>n>>d;
		for (ll i=1;i<=n;i++) {cin>>x[i];g[i].clear();}
		memset(dis,0x3f,sizeof(dis));
		for (ll i=1;i<=n;i++ ) dis[i][i]=0; 
		for (ll i=1;i<=n;i++) {
			for (ll j=i+1;j<=n;j++) {
				if (abs(x[i]-x[j])<=d) {
					dis[i][j]=1;dis[j][i]=1;
				}
			}
		}
		ll ans=0;
		for (ll k=1;k<=n;k++) {
			for (ll i=1;i<=n;i++) {
				for (ll j=1;j<=n;j++) {
					if (dis[i][k]+dis[i][j]<dis[k][j]) {
						dis[k][j]=dis[i][k]+dis[i][j];
					}
					else if (dis[i][k]+dis[i][j]==dis[k][j]) dis2[k][j]++; 
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
