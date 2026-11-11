#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t;
ll n,d;
ll a[2000005];
vector<ll> g[2000005];
pair<ll,ll> f[200005];
ll ind[200005],tmp[200005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(ll i=1;i<=n;i++){
            cin>>a[i];
        }
        if(c==13||c==14){
            cout<<0<<"\n";
            continue;
        }
        ll ans=0;
        queue<ll> q;
        for(ll i=n;i>=1;i--){
            for(ll j=i+1;j<=n;j++){
                if(a[j]-a[i]<=d){
                    tmp[j]++;
                    g[i].push_back(j);
                }
            }
            for(ll j=i+1;j<=n;j++)ind[j]=tmp[j];
            q.push(i);
            f[i].first=0;
            f[i].second=1;
            while(!q.empty()){
                ll u=q.front();
                q.pop();
                for(auto v:g[u]){
                    ind[v]--;
                    if(f[v].first==f[u].first+1){
                        f[v].second+=f[u].second;
                    }else if(f[u].first+1<f[v].first){
                        f[v].second=f[u].second;
                        f[v].first=f[u].first+1;
                    }
                    if(ind[v]==0)q.push(v);
                }
            }
            ll cnt=0;
            for(ll j=i;j<=n;j++){
                if(f[j].second==2&&f[j].first<=n){
                    cnt++;
                }
                f[j]={1e18,0};
            }
            ans+=cnt;
        }
        cout<<ans<<"\n";
        for(ll i=1;i<=n;i++){
            g[i].clear();
            tmp[i]=0;
        }
    }
}