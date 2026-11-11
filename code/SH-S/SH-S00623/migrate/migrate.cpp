#include<bits/stdc++.h>
#define pll pair<ll,ll>
#define mkp make_pair
#define fi first
#define se second
using namespace std;
typedef long long ll;
const ll N=2e6+9;
const ll INF=5e18;
/*
the distance of 1 - i-1 to i is like this
4 4 3 2 2 1 1 1 X
for the first 1, we refer to it as p,if (j,p) is legal, then (j,i) is ok 
all the 1 place isn't ok
and the 2 which can be reached by the second 1 is ok
NP?
let's try it!
nonono, it need to have only two
Nooooooooooooooooooooooooooooo
well, we can use the count of at least two path minus at least three path to do it 
unfixable
uh...
two hours to go
there is hope
why it failed when the n is big?
why why why
i don't get it
*/
ll cid,Tcase;
ll n,d,x[N],f[4][N],g[N],h[N];
bool ok[N];
void solve(){
	for(ll i=0;i<=n;i++) f[0][i]=f[1][i]=f[2][i]=f[3][i]=g[i]=h[i]=0;
	ll p=1,p0=1,p1=1,p2=1;
	x[n+1]=x[n+2]=INF;
	for(ll i=2;i<=n;i++){
		while(x[i]-x[p]>d) p++;
		while(x[p+0]-x[p0]>d) p0++;
		while(x[p+1]-x[p1]>d) p1++;
		while(x[p+2]-x[p2]>d) p2++;
		//[p0,p1) -> 1    [p1,p2) -> 2
		f[0][i]=i-1;
		if(p==i) continue;
		g[i]=i-p;
		h[i]=max(p2-p1,0ll);
		ok[i]=(p1>p0+1);
		f[1][i]=f[1][p]+(i-p);
		f[2][i]=f[2][p]+max(p-p1,0ll);
		if(p0>=p1) f[2][i]+=f[1][p]-g[p]-f[2][p];
		f[3][i]=f[3][p]+max(p-p2,0ll);
		if(p0+1>=p1&&p1<p) f[3][i]+=f[2][p]-((p1==p0+1&&ok[p])?h[p0]:0)-f[3][p];
		if(p0>=p2) f[3][i]+=f[1][p]-g[p]-f[2][p];
//		cout<<i<<" "<<p<<" "<<p0<<" - "<<p1<<" - "<<p2<<" -> "<<f[1][i]<<" "<<f[2][i]<<' '<<f[3][i]<<'\n';
	}
	ll ans=0;
	for(ll i=1;i<=n;i++) ans+=f[2][i]-f[3][i];
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>cid>>Tcase;
	while(Tcase--){
		cin>>n>>d;
		for(ll i=1;i<=n;i++) cin>>x[i];
		solve();
	}
	return 0;
}
