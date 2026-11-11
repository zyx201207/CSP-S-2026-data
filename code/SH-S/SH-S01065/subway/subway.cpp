#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N=505,M=500005,D=23,INF=1e18+9;
ll c,n,m,d,q,w[M],top[M],a[M][D],b[M][D];
ll f[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;++i){
		cin>>w[i];
	}
	for(ll i=1;i<=n;++i){
		for(ll j=1;j<=n;++j){
			f[i][j]=INF;
		}
		f[i][i]=0;
	}
	ll k,x,y,u,v,ww;
	for(ll i=1;i<=n;++i){
		cin>>k;
		u=i;
		for(ll j=1;j<=k;++j){
			cin>>x>>y;
			for(ll o=1;o<=top[x];++o){
				v=a[x][o];
				ww=y+b[x][o];
				if(ww<f[u][v]){
					f[u][v]=f[v][u]=ww;
				}
			}
			top[x]++;
			a[x][top[x]]=i;
			b[x][top[x]]=y;
		}
	}
	for(ll k=1;k<=n;++k){
		for(ll i=1;i<=n;++i)if(i!=k){
			for(ll j=1;j<=n;++j)if(j!=i&&j!=k){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		cin>>x>>y;
		ll ans=INF;
		for(ll i=1;i<=top[x];++i){
			u=a[x][i];
			for(ll j=1;j<=top[y];++j){
				v=a[y][j];
				ans=min(ans,w[x]+b[x][i]+f[u][v]+b[y][j]+w[y]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
