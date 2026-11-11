#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pal pair<ll,ll>
#define fi first
#define se second
const ll MOD=1e9+7;
const ll N=5e5+10;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll n,m,dd,q,a[N],C,c[510][510],D;
vector<ll> d[N];
vector<pal> e[N];
void Solve(){
	cin>>C>>n>>m>>dd>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	memset(c,INF,sizeof(c));
	for(int i=0;i<=500;i++)c[i][i]=0;
	if(C<=6||(C>=24&&C<=25)){
		ll t=m;
		for(int i=1;i<=n;i++){
			ll x;
			cin>>x;
			for(int j=1;j<=x;j++){
				ll y,z;
				cin>>y>>z;
				t++;
				c[t][y]=z;
				c[y][t]=z;
				if(j>1)c[t][t-1]=c[t-1][t]=0;
			}
		}
		for(int i=1;i<=t;i++){
			for(int j=1;j<=t;j++){
				for(int k=1;k<=t;k++){
					c[j][k]=min(c[j][k],c[j][i]+c[i][k]);
				}
			}
		}
		while(q--){
			ll l,r;
			cin>>l>>r;
			cout<<a[l]+a[r]+c[l][r]<<'\n';
		}
		return;
	}
	if(C<=11){
		for(int i=1;i<=n;i++){
			ll x;
			cin>>x;
			if(x==1){
				ll y,z;
				cin>>y>>z;
				continue;
			}
			ll y,z,yy,zz;
			cin>>y>>z>>yy>>zz;
			c[y][yy]=min(c[y][yy],z+zz);
			c[yy][y]=min(c[yy][y],z+zz);
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				for(int k=1;k<=m;k++){
					c[j][k]=min(c[j][k],c[j][i]+c[i][k]);
				}
			}
		}
		while(q--){
			ll l,r;
			cin>>l>>r;
			cout<<a[l]+a[r]+c[l][r]<<'\n';
		}
		return;
	}
	if(C<=19){
		for(int i=1;i<=n;i++){
			ll x;
			cin>>x;
			for(int j=1;j<=x;j++){
				ll y,z;
				cin>>y>>z;
				D=z;
				d[y].push_back(i);
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=0;j<d[i].size();j++){
				for(int k=j+1;k<d[i].size();k++){
					c[d[i][j]][d[i][k]]=D*2;
					c[d[i][k]][d[i][j]]=D*2;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++)c[j][k]=min(c[j][k],c[j][i]+c[i][k]);
			}
		}
		while(q--){
			ll l,r;
			cin>>l>>r;
			ll ma=INF;
			for(int i=0;i<d[l].size();i++){
				for(int j=0;j<d[r].size();j++){
					ma=min(ma,c[d[l][i]][d[r][j]]+a[l]+a[r]+D*2);
				}
			}
			cout<<ma<<'\n';
		}
		return;
	}
	if(C>=20&&C<=23){
		for(int i=1;i<=n;i++){
			ll x;
			cin>>x;
			for(int j=1;j<=x;j++){
				ll y,z;
				cin>>y>>z;
				e[y].push_back({i,z});
			}
		}
		for(int i=1;i<=m;i++){
			if(e[i].size()==1)continue;
			c[e[i][0].fi][e[i][1].fi]=min(c[e[i][0].fi][e[i][1].fi],e[i][0].se+e[i][1].se);
			c[e[i][1].fi][e[i][0].fi]=min(c[e[i][1].fi][e[i][0].fi],e[i][0].se+e[i][1].se);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++)c[j][k]=min(c[j][k],c[j][i]+c[i][k]);
			}
		}
		while(q--){
			ll l,r;
			cin>>l>>r;
			ll ma=INF;
			for(int i=0;i<e[l].size();i++){
				for(int j=0;j<e[r].size();j++){
					ma=min(ma,c[e[l][i].fi][e[r][j].fi]+a[l]+a[r]+e[l][i].se+e[r][j].se);
				}
			}
			cout<<ma<<'\n';
		}
		return;
	}
} 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll T=1;//cin>>T;
	while(T--)Solve();
	return 0;
}
