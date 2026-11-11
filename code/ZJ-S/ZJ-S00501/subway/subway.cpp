#include<bits/stdc++.h>
using namespace std;
#define ft first
#define sd second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vel;
typedef vector<vel> vevel;
typedef vector<pll> velp;
typedef vector<velp> vevelp;
typedef vector<bool> veb;
typedef string sig;
typedef priority_queue<ll> pql;
const ll MAXN=1e18;
void slv(){
	ll c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	vel w(m+3);
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	vevel lx(n+3);
	vel lxs(n+3);
	vevel a(n+3);
	for(int i=1;i<=n;i++){
		cin>>lxs[i];
		lx[i]=vel(lxs[i]+3);
		a[i]=vel(lxs[i]+3);
		for(int j=1;j<=lxs[i];j++){
			cin>>lx[i][j];
			cin>>a[i][j];
		}
	}
	vevelp hv(m+3);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=lxs[i];j++){
			hv[lx[i][j]].push_back({i,a[i][j]});
		}
	}
	vevelp g(n+3);
	for(int i=1;i<=m;i++){
		for(int j=0;j<hv[i].size();j++){
			for(int k=j+1;k<hv[i].size();k++){
				ll x=hv[i][j].ft,y=hv[i][k].ft;
				ll sum=hv[i][j].sd+hv[i][k].sd;
				g[x].push_back({y,sum});
				g[y].push_back({x,sum});
//				cout<<i<<" "<<x<<' '<<y<<' '<<sum<<'\n';
			}
		}
	}
	vevel ans(n+3,vel(n+3,MAXN));
	veb b(n+3);
	for(int i=1;i<=n;i++){
		ans[i][i]=0;
		b=veb(n+3);
		for(int tmp=1;tmp<n;tmp++){
			ll x=0,minn=MAXN;
			for(int j=1;j<=n;j++){
				if(ans[i][j]!=MAXN&&b[j]==0){
					if(minn>ans[i][j]){
						minn=ans[i][j];
						x=j;
					}
				}
			}
			b[x]=1;
			for(auto j:g[x]){
				ans[i][j.ft]=min(ans[i][j.ft],ans[i][x]+j.sd);
				
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<ans[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
	while(q--){
		ll x,y;
		cin>>x>>y;
		ll minn=MAXN;
		for(auto i:hv[x]){
			for(auto j:hv[y]){
				minn=min(ans[i.ft][j.ft]+i.sd+j.sd,min(minn,ans[j.ft][i.ft]+i.sd+j.sd));
			}
		}
		minn+=w[x]+w[y];
		cout<<minn<<'\n';
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll T=1;
//	cin>>T;
	while(T--){
		slv();
	}
	return 0;
}