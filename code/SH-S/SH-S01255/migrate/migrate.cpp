#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#define ll long long
using namespace std;
const int N=2e6+5;
int n;
ll d,x[N];
const int N_sml=5e3+5;
int dis[N_sml][N_sml],cnt[N_sml][N_sml];
void bfs(int s) {
	queue<int> q;
	q.push(s);
	while(!q.empty()) {
		int u=q.front(); q.pop();
		for(int v=u+1;v<=n and x[v]-x[u]<=d;v++)
			if(!dis[s][v]) {
				dis[s][v]=dis[s][u]+1;
				cnt[s][v]=1;
				q.push(v);
			} else if(dis[s][v]==dis[s][u]+1) cnt[s][v]+=cnt[s][u];
	}
}
void force() {
	ll ans=0;
	for(int u=1;u<=n;u++)for(int v=u;v<=n;v++) dis[u][v]=cnt[u][v]=0;
	for(int u=1;u<=n;u++) bfs(u);
	for(int u=1;u<=n;u++)for(int v=u+1;v<=n;v++) ans+=cnt[u][v]==2;
	cout<<ans<<'\n';
}
bool checkA() {
	ll dx=x[2]-x[1];
	for(int i=3;i<=n;i++)if(x[i]-x[i-1]!=dx) return false;
	return true;
}
void specialA() {
	ll dx=x[2]-x[1];
	if(2*dx<=d) cout<<max(0LL,n-2*(d/dx-1)-1)<<'\n';
	else cout<<0<<'\n';
}
void solve() {
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	if(n==1 or n==2) return cout<<0<<'\n',void();
	if(checkA()) return specialA(),void();
	return force(),void();
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int c,t; cin>>c>>t;
	while(t--) solve();
	return 0;
}
