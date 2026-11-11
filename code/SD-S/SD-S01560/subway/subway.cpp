#include<bits/stdc++.h>
#include<queue>
#define ll long long
#define mp make_pair
#define ft first
#define sd second
#define pb push_back
#define endl "\n"
using namespace std;
//bool st;
const ll N=5e5+5,INF=0x3f3f3f3f3f3f3f3f;
ll n,m,d,T;
ll a[N],f[510][510];
vector<pair<ll,ll> > wz[N];
//bool ed;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ll c;
	cin>>c>>n>>m>>d>>T;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1,le;i<=n;i++){
		cin>>le;
		for(int j=1;j<=le;j++){
			ll b,ti;
			cin>>b>>ti;
			wz[b].pb(mp(i,ti));
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)if(i!=j)
			f[i][j]=INF;
	for(int i=1;i<=m;i++){
		ll le=wz[i].size();
		for(int j=0;j<le;j++){
			for(int k=j+1;k<le;k++){
				f[wz[i][j].ft][wz[i][k].ft]=min(f[wz[i][j].ft][wz[i][k].ft],wz[i][j].sd+wz[i][k].sd);
				f[wz[i][k].ft][wz[i][j].ft]=min(f[wz[i][k].ft][wz[i][j].ft],wz[i][j].sd+wz[i][k].sd);
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(T--){
		ll x,y;
		ll ans=INF;
		cin>>x>>y;
		for(auto i:wz[x]){
			for(auto j:wz[y]){
				ans=min(ans,i.sd+j.sd+f[i.ft][j.ft]);
			}
		}
		ans+=a[x]+a[y];
		cout<<ans<<endl;
	}
	return 0;
} 
