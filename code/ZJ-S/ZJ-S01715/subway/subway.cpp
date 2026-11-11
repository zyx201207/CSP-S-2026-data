#include<bits/stdc++.h>
using namespace std;
#define re register
#define ll long long
#define forl(i,a,b) for(re ll i=a;i<=b;i++)
#define forr(i,a,b) for(re ll i=a;i>=b;i--)
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define pb push_back
#define pii pair<ll,ll>
#define x first
#define y second
ll c,n,m,d,q,x,y,ans,l;
ll a[500010];
vector<pii>v[500010];
ll f[510][510];
inline Min(ll&x,ll y){
	if(x>y) x=y;
}
void Solve(){
	cin>>c>>n>>m>>d>>q;
	forl(i,1,m) cin>>a[i];
	forl(i,1,n){
		cin>>l;
		forl(j,1,l) cin>>x>>y,v[x].pb({i,y});
	}
	forl(i,1,n) forl(j,1,n) f[i][j]=1e18;
	forl(i,1,n) f[i][i]=0;
	forl(i,1,m) for(auto j:v[i]) for(auto k:v[i]) if(j.x!=k.x) Min(f[j.x][k.x],j.y+k.y);
	forl(k,1,n) forl(i,1,n) forl(j,1,n) Min(f[i][j],f[i][k]+f[k][j]);
//	forl(i,1,n) forl(j,1,n) cout<<f[i][j]<<" \n"[j==n];
	forl(_,1,q){
		cin>>x>>y;
		ans=4e18;
		for(auto i:v[x]) for(auto j:v[y]) Min(ans,a[x]+a[y]+i.y+j.y+f[i.x][j.x]);
		cout<<ans<<endl;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	IOS;
	ll t=1;
//	cin>>t;
	while(t--) Solve();
	return 0;
}
