#include <iostream>
#include <cstdio>
#include <ctime>
#include <algorithm>
#define ll long long
using namespace std;
ll mymin(ll x,ll y) {return x<y?x:y;}
const ll INF=1e17;
const int M=5e5+5;
const int N=505;
int C,n,m,D,q;
ll w[M];
int vec[M][22],sz[M];
ll c[M][22];
ll d[N][N];
void solve() {
	cin>>C>>n>>m>>D>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int u=1;u<=n;u++)for(int v=1;v<u;v++) d[u][v]=d[v][u]=INF;
	for(int u=1,k;u<=n;u++) {
		cin>>k;
		for(int i=1,x;i<=k;i++) {
			ll t; cin>>x>>t;
			for(int y=1,v;y<=sz[x];y++) {
				v=vec[x][y];
				d[u][v]=d[v][u]=min(d[u][v],t+c[x][y]);
			}
			vec[x][++sz[x]]=u;
			c[x][sz[x]]=t;
		}
	}
	for(int k=1;k<=n;k++)
		for(int u=1;u<=n;u++)
			if(d[u][k]<INF)
				for(int v=1;v<=n;v++)
					d[u][v]=mymin(d[u][v],d[u][k]+d[k][v]);
	for(int a,b;q--;) {
		cin>>a>>b;
		ll ans=INF;
		for(int i=1,u;i<=sz[a];i++) {
			u=vec[a][i];
			for(int j=1,v;j<=sz[b];j++) {
				v=vec[b][j];
				ans=mymin(ans,c[a][i]+d[u][v]+c[b][j]);
			}
		}
		cout<<w[a]+ans+w[b]<<'\n';
	}
}
int main() {
//	clock_t st=clock();
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t=1;
	while(t--) solve();
//	clock_t ed=clock();
//	cout<<1.*(ed-st)/CLOCKS_PER_SEC;
	return 0;
}
