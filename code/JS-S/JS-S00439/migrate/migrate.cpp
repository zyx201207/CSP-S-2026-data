#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e6+10,INF=1e18;
ll c,t,n,d;
ll x[N];
ll maxn=INF,cnt=0,ans=0;
void dfs(ll a,ll b,ll dep){
    dep++;
    if(x[b]-x[a]<=d){
        if(dep<maxn) maxn=dep,cnt=1;
        else if(dep==maxn) cnt++;
        else return;
    }
    for(ll i=a+1;i<=b;i++){
        if(x[i]-x[a]<=d) dfs(i,b,dep);
    }
}
void solve(){
    cin>>n>>d;
    for(ll i=1;i<=n;i++) cin>>x[i];
    ans=0;
    for(ll i=1;i<=n;i++){
        for(ll j=i+1;j<=n;j++){
            maxn=INF;cnt=0;
            dfs(i,j,0);
            if(cnt==2) ans++;
        }
    }
    cout<<ans<<'\n';
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>t;
    while(t--) solve();
    return 0;
}
