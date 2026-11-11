#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5009;
ll c,T,n,d,x[N],f[N][N],cnt[N][N];
vector<ll> to[N];
queue<ll> q;
void solve(){
    cin>>n>>d;
    for(ll i=1;i<=n;i++) cin>>x[i];
    for(ll i=1;i<=n;i++) to[i].clear();
    for(ll i=1;i<=n;i++)
	for(ll j=i+1;j<=n;j++)
	    if(abs(x[i]-x[j])<=d)
		to[i].push_back(j),to[j].push_back(i);
    for(ll s=1;s<=n;s++){
	fill(f[s]+1,f[s]+n+1,1e18);
	fill(cnt[s]+1,cnt[s]+n+1,0);
	f[s][s]=0,cnt[s][s]=1;
	while(q.size()) q.pop();
	q.push(s);
	while(q.size()){
	    ll u=q.front(); q.pop();
	    for(ll i=0;i<to[u].size();i++)
		if(f[s][to[u][i]]==1e18)
		    f[s][to[u][i]]=f[s][u]+1,cnt[s][to[u][i]]=cnt[s][u],q.push(to[u][i]);
		else if(f[s][to[u][i]]==f[s][u]+1)
		    cnt[s][to[u][i]]=min(cnt[s][to[u][i]]+cnt[s][u],(ll)1e9);
	}
    }
    ll ans=0;
    for(ll i=1;i<=n;i++)
	for(ll j=i+1;j<=n;j++)
	    if(cnt[i][j]==2) ans++;
    cout<<ans<<"\n";
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--) solve();
    return 0;
}
