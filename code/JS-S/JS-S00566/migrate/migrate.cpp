#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
using ll=long long;
ll n,T,C,dis[N],d,a[N],c[N],ans;
bool vis[N];
vector<ll> g[N];
#define pb emplace_back
using pii=pair<ll,ll>;
#define mk make_pair
#define fi first
#define se second
priority_queue<pii,vector<pii>,greater<pii> > q;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>C>>T;
    while(T--){
        cin>>n>>d;ans=0;
        for(ll i=1;i<=n;i++) cin>>a[i],g[i].clear();
        for(ll i=1,p;i<=n;i++){
            p=upper_bound(a+1,a+1+n,a[i]+d)-a-1;
            for(ll j=i+1;j<=p;j++) g[i].pb(j),g[j].pb(i);
        }
        for(ll s=1;s<=n;s++){
            for(ll i=1;i<=n;i++) dis[i]=1e18,c[i]=0,vis[i]=0;
            q.push(mk(0,s));dis[s]=0;c[s]=1;
            while(q.size()){
                ll x=q.top().se;q.pop();
                if(vis[x]) continue;vis[x]=1;
                for(ll y:g[x]){
                    if(dis[x]+1<dis[y]) dis[y]=dis[x]+1,c[y]=c[x],q.push(mk(dis[y],y));
                    else if(dis[x]+1==dis[y]) c[y]+=c[x];
                }
            }
            for(ll i=s+1;i<=n;i++) ans+=(c[i]==2);
        }
        cout<<ans<<'\n';
    }
    return 0;
}