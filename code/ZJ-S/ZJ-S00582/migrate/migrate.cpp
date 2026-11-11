#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const ll N=2e6+10;
ll n,d,a[N],k[N],f[N],r[N],s[N];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;++i) cin>>a[i];
	ll ans=0;
	for(int i=1;i<=n;++i){
		k[i]=0,f[i]=1,r[0]=i,s[i]=1,s[i-1]=0;
		for(int j=i+1;j<=n&&a[j-1]+d>=a[j];++j) k[j]=1e9,f[j]=0,r[j-i]=0,s[j]=1;
		for(int j=i+1,o=i;j<=n&&a[j-1]+d>=a[j];++j){
			while(a[o]+d<a[j]) ++o;
			k[j]=k[o]+1,r[k[j]]=j;
			f[j]=s[r[k[j]-1]]-s[o-1];s[j]=s[j-1]+f[j];
			ans+=(f[j]==2);
		}
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,t;
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
